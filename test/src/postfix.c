#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../h/stack_func.h"
#include "../h/postfix.h"
#include "../h/getchh.h"

int getop(char s[])
{
	int i = 0, c;
	while ((c = getchh()) == ' ' || c == '\t')
		;

	if (!isdigit(c) && c != '.')
	{
		/* The character is not part of a number, (probably an operator) */
		return c;
	}

	s[i++] = c;

	if (isdigit(c))
	{
		/* Collect integer part */
		while (isdigit(s[i++] = c = getchh()))
			;
	}
	if (c == '.')
	{
		/* Collect fraction part */
		while (isdigit(s[i++] = c = getchh()))
			;
	}
	s[--i] = '\0';
	if (c != ' ' && c != '\t')
	{
		ungetchh(c);
	}

	return NUMBER;
}

void processPostFix()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2)
				{
					push(pop() / op2);
				}
				else
				{
					printf("error: zero divisor\n");
				}
				break;
			case '\n':
				printf("\t%.4f\n", pop());
				break;
			default:
				printf("Error: unknown command %c\n", type);
				break;

		} /* switch */
	} /* while */
} /* processPostFix */