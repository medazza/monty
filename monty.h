#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file_tools.c */
void file_open(char *name_of_file);
int line_parse(char *buf, int line_num, int format);
void file_read(FILE *f_d);
void func_finder(char *opcode, char *value, int line_n, int format);
void call_func(op_func func, char *op, char *val, int l_num, int format);

/*main.c*/
stack_t *node_create(int n);
void nodes_free(void);
void adding_t_queue(stack_t **nw_nde, __attribute__((unused))unsigned int l_n);


/* stack_func1.c file*/
void add_t_stack(stack_t **nw_node, __attribute__((unused))unsigned int l_num);
void stack_print(stack_t **stack, unsigned int l_nu);
void top_pop(stack_t **stack, unsigned int l_number);
void top_print(stack_t **stack, unsigned int l_nmbr);

/* stack_func2.c file*/
void nop(stack_t **stack, unsigned int lne_nmbr);
void nodes_swap(stack_t **stack, unsigned int ln_nmbr);
void nodes_add(stack_t **stack, unsigned int lne_nmbr);
void nodes_sub(stack_t **stack, unsigned int lne_nmbr);
void nodes_div(stack_t **stack, unsigned int lne_nmbr);

/* stack_op.c */
void nodes_mul(stack_t **stack, unsigned int lne_nmbr);
void nodes_mod(stack_t **stack, unsigned int lne_nmbr);

/* stack_strings.c  */
void char_print(stack_t **stack, unsigned int lne_nmbr);
void str_print(stack_t **stack, __attribute__((unused))unsigned int lne_nbr);
void rotl(stack_t **stack, __attribute__((unused))unsigned int l_nbr);
void rotr(stack_t **stack, __attribute__((unused))unsigned int l_nbr);

/*Error hanlding*/
void erro_1(int e_code, ...);
void erro_2(int e_code, ...);
void string_erro(int e_code, ...);

#endif
