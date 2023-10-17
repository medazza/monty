#include "monty.h"

/**
 * erro_1 - Prints appropiate error messages determined by their error code.
 * @e_code: The error codes are the following:
 * (1) => User doesn't give any file or more than 1 file the program.
 * (2) => File provided isn't a file that can be open or read.
 * (3) => File provided contains invalid instruction.
 * (4) => The program is unable to memory alloc more.
 * (5) => The parameter passed to the instruction (push) is not an intger.
 */
void erro_1(int e_code, ...)
{
	va_list ag;
	char *op;
	int lne_n;

	va_start(ag, e_code);
	switch (e_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			lne_n = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", lne_n, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	nodes_free();
	exit(EXIT_FAILURE);
}

/**
 * erro_2 - more handles errors.
 * @e_code: The error codes are the following:
 * (6) => use when the stack it empty for pint.
 * (7) => use when the stack it empty for pop.
 * (8) => use when stack is too short for opera.
 * (9) => The division by zero(0).
 */
void erro_2(int e_code, ...)
{
	va_list ag;
	char *op;
	int lne_n;

	va_start(ag, e_code);
	switch (e_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			lne_n = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", lne_n, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	nodes_free();
	exit(EXIT_FAILURE);
}

/**
 * string_erro - String handles errors.
 * @e_code: Error codes are the following:
 * (10) => IF the number inside node is outside the ASCII bounds.
 * (11) => IF the stack is empty.
 */
void string_erro(int e_code, ...)
{
	va_list ag;
	int lne_num;

	va_start(ag, e_code);
	lne_num = va_arg(ag, int);
	switch (e_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", lne_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", lne_num);
			break;
		default:
			break;
	}
	nodes_free();
	exit(EXIT_FAILURE);
}
