#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/* File operations */
void ofile(char *file_name);
int parse_line(char *buffer, int line_number, int format);
void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);

/* Stack operations */
stack_t *create_node(int n);
void _nfree(void);
void _stkprint(stack_t **, unsigned int);
void _stkadd(stack_t **, unsigned int);
void _qadd(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

void _tprint(stack_t **, unsigned int);
void _tpop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void _nswap(stack_t **, unsigned int);

/* Math operations with nodes */
void _nadd(stack_t **, unsigned int);
void _nsub(stack_t **, unsigned int);
void _ndiv(stack_t **, unsigned int);
void _nmul(stack_t **, unsigned int);
void _nmod(stack_t **, unsigned int);

/* String operations */
void _charprint(stack_t **, unsigned int);
void _strprint(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/* Error handling */
void _er(int error_code, ...);
void _erA(int error_code, ...);
void _erS(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif

