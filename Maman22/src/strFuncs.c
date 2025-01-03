

#include "../h/strFunc.h"
#include "../h/commandFuncs.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *copy_string(const char *origin)
{
    /* Allocate memory for new string (length + null terminator) */
    char *copy = malloc(strlen(origin) + 1);
    if (!copy)
    {
        fprintf(stderr, "Failed memory allocation\n");
        return NULL; /* Memory allocation failed */
    }
    /* Copy the string contents to new memory */
    strcpy(copy, origin);

    return copy;
}

int string_array_len(char **args)
{
    int count = 0;

    if (args == NULL)
    {
        return FAILED_CODE;
    }

    /* Count strings until NULL terminator is found */
    while (args[count] != NULL)
    {
        count++;
    }
    return count;
}

double str_to_double(char *str)
{
    double number;
    char *endptr;

    number = strtod(str, &endptr);
    if (endptr == str)
    {
        return INVALID_DOUBLE;
    }
    return number;
}

complex *char_to_comp(char *ch)
{
    int index;

    /* Validate input */
    if (is_complex(ch) == INVALID_COMP)
    {
        return NULL;
    }

    /* Convert char to array index (A=0, B=1...) */
    index = ch[0] - 'A';

    return comp_vars[index];
}