#include "main.h"

/**
 * _er - Prints error by code.
 * @erC: The error codes
 */
void _er(int erC, ...)
{
	va_list ag;
	char *op;
	int ln;

	va_start(ag, erC);
	switch (erC)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			ln = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", ln, op);
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
	_freeN();
	exit(EXIT_FAILURE);
}

/**
 * _erA - handles errors.
 * @erC: The error codes.
 */
void _erA(int erC, ...)
{
	va_list ag;
	char *op;
	int ln;

	va_start(ag, erC);
	switch (erC)
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
			ln = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", ln, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	_freeN();
	exit(EXIT_FAILURE);
}

/**
 * _erS - handles errors.
 * @erC: The error codes.
 */
void _erS(int erC, ...)
{
	va_list ag;
	int ln;

	va_start(ag, erC);
	ln = va_arg(ag, int);
	switch (erC)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
			break;
		default:
			break;
	}
	_freeN();
	exit(EXIT_FAILURE);
}
