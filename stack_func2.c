#include "monty.h"

/**
 * nop - Does do nothing.
 * @stack: The pointer to pointer pointing top node of stack.
 * @lne_nmbr: A interger represent line_number of the op_code.
 */
void nop(stack_t **stack, unsigned int lne_nmbr)
{
	(void)stack;
	(void)lne_nmbr;
}

/**
 * nodes_swap - Func swaps top two elems the stack.
 * @stack: The pointer to pointer point to top node of stack.
 * @ln_nmbr: A interger represent the line_number of the opcode.
 */
void nodes_swap(stack_t **stack, unsigned int ln_nmbr)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		erro_2(8, ln_nmbr, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * nodes_add - Func adds the top two elements of the stack.
 * @stack: A pointer to pointer point to top node of stack.
 * @lne_nmbr: A interger represent the line_number of the op_code.
 */
void nodes_add(stack_t **stack, unsigned int lne_nmbr)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		erro_2(8, lne_nmbr, "add");
	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nodes_sub - Fun adds the top two elements of stack.
 * @stack: A pointer to pointer point to top node of  stack.
 * @lne_nmbr: A interger represent the line_number of the opcode.
 */
void nodes_sub(stack_t **stack, unsigned int lne_nmbr)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		erro_2(8, lne_nmbr, "sub");
	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * nodes_div - Func adds the top two elements of stack.
 * @stack: A pointer to pointer point to top node of stack.
 * @lne_nmbr: A interger represent the line_number of the opcode.
 */
void nodes_div(stack_t **stack, unsigned int lne_nmbr)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		erro_2(8, lne_nmbr, "div");
	if ((*stack)->n == 0)
		erro_2(9, lne_nmbr);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
