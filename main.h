#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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
void _openf(char *file_name);
int _parsel(char *tmpb, int line_number, int fmt);
void _readf(FILE *);
int _charlenght(FILE *);
void _sfunc(char *, char *, int, int);

/* Stack operations */
stack_t *_makeN(int n);
void _freeN(void);
void _stkprint(stack_t **, unsigned int);
void _stkadd(stack_t **, unsigned int);
void _qadd(stack_t **, unsigned int);

void _xfun(op_func, char *, char *, int, int);

void _tprint(stack_t **, unsigned int);
void _tpop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void _nsawp(stack_t **, unsigned int);

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

