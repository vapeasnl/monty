#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <unistd.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include <ctype.h>

/**
 * struct stack_s --
 * @n: --
 * @prev: --
 * @next: --
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s --
 * @opcode: --
 * @f: --
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
stack_t *head = NULL;
typedef void (*op_func)(stack_t **, unsigned int);
void _fopen(char *file_name);
int _lparse(char *buffer, int line_number, int format);
void _fread(FILE *);
int len_chars(FILE *);
void _sfunc(char *, char *, int, int);
stack_t *create_node(int n);
void free_nodes(void);
void _printstk(stack_t **, unsigned int);
void _stkadd(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);
void _exefunc(op_func, char *, char *, int, int);
void _printtop(stack_t **, unsigned int);
void _tpop(stack_t **, unsigned int);
void _nop(stack_t **, unsigned int);
void _nswap(stack_t **, unsigned int);
void _nadd(stack_t **, unsigned int);
void _nsub(stack_t **, unsigned int);
void _ndiv(stack_t **, unsigned int);
void _nmul(stack_t **, unsigned int);
void _nmod(stack_t **, unsigned int);
void _printchar(stack_t **, unsigned int);
void _printstr(stack_t **, unsigned int);
void _rotl(stack_t **, unsigned int);
void _er(int error_code, ...);
void _erA(int error_code, ...);
void _erS(int error_code, ...);
void _rotr(stack_t **, unsigned int);
#endif

