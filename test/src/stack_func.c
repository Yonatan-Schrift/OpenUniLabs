
#include "../h/stack_func.h"
#include <stdio.h>
#include <stdlib.h>

int sp = 0; /* Stack pointer */
double val[MAX];

void push(double value) {
	/* If stack is not full */
    if(sp < MAXVAL) {
        val[sp++] = value;
    } else {
        printf("Error: stack full, can't push %4f.\n", value);
    }
} /* push() */

double pop() {
    /* If stack is not empty */
    if(sp > 0) {
        return val[--sp];
    } else {
        printf("Error: Can't pop() from empty stack.\n");
        return 0.0;
    }
} /* pop() */

