#include "monty.h"

/**
 * file_open - only opens a file given.
 * @name_of_file: the file name_path
 * Return: void
 */
void file_open(char *name_of_file)
{
	FILE *f_d = fopen(name_of_file, "r");

	if (name_of_file == NULL || f_d == NULL)
		erro_1(2, name_of_file);

	file_read(f_d);
	fclose(f_d);
}

/**
 * file_read - only reads a file given.
 * @f_d: pointer to file descriptor
 * Return: void
 */
void file_read(FILE *f_d)
{
	int line_num, format = 0;
	char *buf = NULL;
	size_t lenght = 0;

	for (line_num = 1; getline(&buf, &lenght, f_d) != -1; line_num++)
	{
		format = line_parse(buf, line_num, format);
	}
	free(buf);
}

/**
 * line_parse - Separates each of the line into tokens
 *              to determine which function to call.
 * @buf: a line from the file
 * @line_num: the line number
 * @format:  storage format. If 0 Nodes will be entered -> stack.
 *           if 1  will be entered ->  queue.
 * Return: Returns 0 if the opcode: stack.otherwise 1: queue.
 */
int line_parse(char *buf, int line_num, int format)
{
	char *opcode, *value;
	const char *delimter = "\n ";

	if (buf == NULL)
		erro_1(4);

	opcode = strtok(buf, delimter);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delimter);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	func_finder(opcode, value, line_num, format);
	return (format);
}

/**
 * func_finder - find the appropriate func for the opcode
 * @opcode: opcode
 * @value: arg of opcode
 * @format:  storage format. If 0 Nodes will be entered -> stack.
 *                        if 1 nodes will be entered -> queue.
 * @line_n: The line number
 * Return: void
 */
void func_finder(char *opcode, char *value, int line_n, int format)
{
	int ind;
	int flag;

	instruction_t func_list[] = {
		{"push", add_t_stack},
		{"pall", stack_print},
		{"pint", top_print},
		{"pop", top_pop},
		{"nop", nop},
		{"swap", nodes_swap},
		{"add", nodes_add},
		{"sub", nodes_add},
		{"div", nodes_div},
		{"mul", nodes_mul},
		{"mod", nodes_mod},
		{"pchar", char_print},
		{"pstr", str_print},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;
	for (flag = 1, ind = 0; func_list[ind].opcode != NULL; ind++)
	{
		if (strcmp(opcode, func_list[ind].opcode) == 0)
		{
			call_func(func_list[ind].f, opcode, value, line_n, format);
			flag = 0;
		}
	}
	if (flag == 1)
		erro_1(3, line_n, opcode);
}

/**
 * call_func - it's calls the required func.
 * @func: Pointer the function that is to be called.
 * @op: string represent the op_code.
 * @val: string represent the numeric value.
 * @l_num: the line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered -> stack.
 *                            if 1 nodes will be entered -> queue.
 */
void call_func(op_func func, char *op, char *val, int l_num, int format)
{
	stack_t *node;
	int flag;
	int ind;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			erro_1(5, l_num);
		for (ind = 0; val[ind] != '\0'; ind++)
		{
			if (isdigit(val[ind]) == 0)
				erro_1(5, l_num);
		}
		node = node_create(atoi(val) * flag);
		if (format == 0)
			func(&node, l_num);
		if (format == 1)
			adding_t_queue(&node, l_num);
	}
	else
		func(&head, l_num);
}
