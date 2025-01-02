#include "../h/commandFuncs.h"
#include "../h/strFunc.h"
#include "../h/argumentFuncs.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *clean_arg( char *arg)
{
    char *output;
    int i, j;
    int len;

    if (arg == NULL || *arg == '\0')
    {
        return NULL;
    }

    len = strlen(arg);
    
    /* Allocating memory with the same length as arg. */
    output = malloc((len+1) * sizeof(char));

    if (!output)
    {
        fprintf(stderr, "Failed memory allocation\n");
        return NULL; /* Memory allocation failed */
    }

    /* Copy non-whitespace characters */
    for (i = 0, j = 0; i < len; i++)
    {
        if (!isspace(arg[i]))
        {
            output[j] = arg[i];
            j++;
        }
    }
    output[j] = '\0'; /* Ensure the string is null-terminated */
    return output;
}

int verify_arguments(char **args, int command_index)
{
    char *cur_arg;
    int param_count, i, verify_arg;
    ArgType type;

    param_count = commands[command_index].param_count;

    if (find_double_comma(args) == EXTRA_COMMA)
    {
        return EXTRA_COMMA;
    }

    verify_arg = verify_argument_count(param_count, args);
    /* Checks if the amount of arguments is correct. */
    if (verify_arg < 0) 
    {   
        /* Theres an error in the argument count */
        /* Returns the error code */
        return verify_arg;
    }

    /* Checks if each argument is the correct type. */
    for (i = 0; i < param_count; i++)
    {
        type = commands[command_index].param_types[i];
        cur_arg = args[i];

        verify_arg = verify_argument_type(type, cur_arg);
        if (verify_arg <0)
        {
            /* Theres an error in the argument type */
            /* Returns the error code */
            return verify_arg;
        }
    }
    
    

    return SUCCESS_CODE;
}

int verify_argument_count(int req_param_count, char **args)
{
    int args_count = string_array_len(args);

    if (args_count > req_param_count)
    {   
        return EXTRA_VARS;
    }
    else if (args_count < req_param_count)
    {   
        return MISSING_VARS;
    }

    return SUCCESS_CODE;
}

int verify_argument_type(int req_arg_type, char *arg)
{
    int len;
    if (!arg)
    {
        return FAILED_CODE;
    }
    len = strlen(arg);
    switch (req_arg_type)
    {
        case ARG_COMPLEX:
        {
            /* Edge case: missing a comma between 2 args */
            if (len == 2 && arg[0] >= 'A' && arg[0] <= 'F' && arg[1] >= 'A' && arg[1] <= 'F') 
            {
                return MISSING_COMMA;
            }
            /* Check if arg is a single uppercase letter A-F */
            if (len != 1 || is_complex(arg) == INVALID_COMP)
            {
                return INVALID_COMP;
            }
            break;
        }
        case ARG_DOUBLE:
        {
            /* try to convert the string to double */
            if (str_to_double(arg) == INVALID_DOUBLE)
            {
                
                return INVALID_DOUBLE;
            }
            break;
        }
    }
    return SUCCESS_CODE;
}

int find_double_comma(char **args)
{
    int i;
    if (!args)
        return FAILED_CODE;

    for (i = 0; args[i] != NULL; i++)
    {
        if (args[i][0] == '\0')
        {
            return EXTRA_COMMA;
        }
    }
    return SUCCESS_CODE;
}

int is_complex(char *ch) 
{
    if (!ch || ch[0] < 'A' || ch[0] > 'F') {        
        return INVALID_COMP;
    }
    
    return SUCCESS_CODE;
}