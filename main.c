#include "monty.h"
stack_t *head = NULL;
/**
 * main - The entry point
 * @argc: args count
 * @argv: args vector
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_open(argv[1]);
	nodes_free();
	return (0);
}

/**
 * node_create - Func that's creates a node.
 * @n: The number to go inside the node.
 * Return: Upon sucess a pointer to node. Else: NULL.
 */
stack_t *node_create(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		erro_1(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * nodes_free - Func frees nodes in stack.
 */
void nodes_free(void)
{
	stack_t *temp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * adding_t_queue - Adds a node to the queue.
 * @nw_nde: Pointer to the new node.
 * @l_n: line number of the opcode.
 */
void adding_t_queue(stack_t **nw_nde, __attribute__((unused))unsigned int l_n)
{
	stack_t *temp;

	if (nw_nde == NULL || *nw_nde == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nw_nde;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *nw_nde;
	(*nw_nde)->prev = temp;
}
