
#include "../h/getchh.h"
#include <stdio.h>

Flag flag = EMPTY;
int buf;

int getchh(void) {
    if (flag == FULL) {
        flag = EMPTY;
        return buf;
    }
    else {
        return getchar();
    }
} /* getchh() */

void ungetchh(int c) {
    if (flag == EMPTY) {
        flag = FULL;
        buf = c;
        }

        /* If buffer is FULL */
        else {
            printf("Error: Buffer is full, can't enter more information to the buffer.\n");
    }
} /* ungetchh() */