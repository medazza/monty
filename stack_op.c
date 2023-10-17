#include "monty.h"

/**
 * nodes_mul - Func adds the top two elmts of stack.
 * @stack: A pointer to  pointer point to top node of  stack.
 * @lne_nmbr: A interger represent the line_number of the op_code.
 */
void nodes_mul(stack_t **stack, unsigned int lne_nmbr)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		erro_2(8, lne_nmbr, "mul");
	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nodes_mod - Fun adds the top two elmnts of stack.
 * @stack: A pointer to pointer point to top node of stack.
 * @lne_nmbr: A interger represent the line_number of the op_code.
 */
void nodes_mod(stack_t **stack, unsigned int lne_nmbr)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		erro_2(8, lne_nmbr, "mod");
	if ((*stack)->n == 0)
		erro_2(9, lne_nmbr);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
