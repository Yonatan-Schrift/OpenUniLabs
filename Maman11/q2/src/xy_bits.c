/*
 * Created by yonatan on 10/11/24.
 * Maman 11, Q2
 */

#include <stdio.h>          /* used for input / output */
#include "../h/bit_utils.h" /* used for bit conversion */

int main()
{
    unsigned long x, y;
    char bitX[BIT_SIZE];
    char *answer;

    /* Scans for 2 Unsigned Longs from input */
    printf("Enter x: \n");
    scanf("%lu", &x);

    printf("Enter y: \n");
    scanf("%lu", &y);

    /* Sets the 12th bit of x. */
    x |= (1 << 12);

    /* Checks if the 6th bit of y is set. */
    if (y & (1 << 6))
    {
        answer = "YES";
    }
    else
    {
        answer = "NO";
    }

    convertLongToBinary(x, bitX);
    printf("\nX after setting the 12th bit: %s in binary, %lu in decimal \n", bitX, x);
    printf("Is bit 6 set in y? %s\n", answer);

    return 0;
}
