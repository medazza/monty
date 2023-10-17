#include "monty.h"

/**
 * char_print - Func prints the Ascii value.
 * @stack: A pointer to pointer point to top node of stack.
 * @lne_nmbr: A interger represent the line_number of the op_code.
 */
void char_print(stack_t **stack, unsigned int lne_nmbr)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_erro(11, lne_nmbr);
	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_erro(10, lne_nmbr);
	printf("%c\n", ascii);
}

/**
 * str_print - Func prints a string.
 * @stack: A pointer to pointer point to top node of stack.
 * @lne_nbr: A interger represent the line_number of the op_code.
 */
void str_print(stack_t **stack, __attribute__((unused))unsigned int lne_nbr)
{
	int ascii;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	temp = *stack;
	while (temp != NULL)
	{
		ascii = temp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - Fun rotates first node of stack to the bottom.
 * @stack: A pointer to pointer point to top node of  stack.
 * @l_nbr: Interger represent the line_number of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int l_nbr)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - Fun rotates last node of the stack to top.
 * @stack: A pointer to pointer point to top node of  stack.
 * @l_nbr: A interger represent the line_number of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int l_nbr)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
