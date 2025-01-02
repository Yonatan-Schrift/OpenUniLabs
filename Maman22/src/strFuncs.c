

#include "../h/strFunc.h"
#include "../h/commandFuncs.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char **allocate_str_array(int size) {
    char **args;
    args = malloc((size) * sizeof(char *) + 1);
    if (!args)
    {
        fprintf(stderr, "Failed memory allocation\n");
        return NULL; /* Memory allocation failed */
    }

    args[size] = NULL; /* NULL-terminating the array */
    return args;
}

char *copy_string(const char *origin) {
    /* Allocate memory for new string (length + null terminator) */
    char *copy = (char *)malloc(strlen((origin) + 1));
    if (!copy)
    {
        fprintf(stderr, "Failed memory allocation\n");
        return NULL; /* Memory allocation failed */
    }
    /* Copy the string contents to new memory */
    strcpy(copy, origin);

    return copy;
}


int string_array_len(char **args) {
    int count = 0;

    /* Count strings until NULL terminator is found */
    while (args[count] != NULL)
    {
        count++;
    }
    return count;
}

double str_to_double(char* str) {
    double number;
    char *endptr;
    
    number = strtod(str, &endptr);
    if (endptr == str) {
        return INVALID_DOUBLE;
    }
    return number;
}