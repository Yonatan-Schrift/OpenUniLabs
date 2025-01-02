/*
 * Created by yonatan on 10/11/24.
 */

#include <stdlib.h>
#include "../h/bit_utils.h"

/* A method to convert an unsigned long to binary (in the form of a string) */
void convertLongToBinary(unsigned long n, char *binary)
{
    int i;
    int bitSize = BIT_SIZE - 1;

    /* Ensure the last character is the null terminator */
    binary[BIT_SIZE] = '\0';

    /* Iterate over the bits of the unsigned long */
    for (i = bitSize; i >= 0; i--)
    {

        binary[bitSize - i] = ((n >> i) & 1) ? '1' : '0';
    }
}
