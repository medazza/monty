#include "monty.h"

/**
 * add_t_stack - It's adds node to the stack.
 * @nw_node: The pointer to new node.
 * @l_num: Interger represent line number of the op_code.
 */
void add_t_stack(stack_t **nw_node, __attribute__((unused))unsigned int l_num)
{
	stack_t *temp;

	if (nw_node == NULL || *nw_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nw_node;
		return;
	}
	temp = head;
	head = *nw_node;
	head->next = temp;
	temp->prev = head;
}


/**
 * stack_print - It's adds node to the stack.
 * @stack: The pointer to pointer pointing top node of the stack.
 * @l_nu: line_number of  the op_code.
 */
void stack_print(stack_t **stack, unsigned int l_nu)
{
	stack_t *temp;

	(void) l_nu;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * top_pop - func that adds node to the stack.
 * @stack: The pointer to pointer pointing to top node the stack.
 * @l_number: interger representing line_number of the op_code.
 */
void top_pop(stack_t **stack, unsigned int l_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		erro_2(7, l_number);
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * top_print - Func prints the top node the stack.
 * @stack: The pointer to pointer pointing to top node of stack.
 * @l_nmbr: interger represent the line number of the op_code.
 */
void top_print(stack_t **stack, unsigned int l_nmbr)
{
	if (stack == NULL || *stack == NULL)
		erro_2(6, l_nmbr);
	printf("%d\n", (*stack)->n);
}
