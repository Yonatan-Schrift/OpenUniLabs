/**
 * @file argumentFuncs.c
 * @brief Functions that handle command line argument parsing and validation
 * 
 * This file contains functions responsible for processing and validating
 * command line arguments passed to the program, ensuring they meet the 
 * required format and constraints.
 * * 
 * @author Yonatan Schrift
 * @date 23.12.2024
 */
#include "../h/commandFuncs.h"
#include "../h/strFunc.h"
#include "../h/argumentFuncs.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * Cleans a string argument by removing all whitespace characters.
 *
 * @param arg The input string to be cleaned.
 *
 * @return A newly allocated string with all whitespace characters removed,
 *         or NULL if:
 *         - Input is NULL
 *         - Input is empty string
 *         - Memory allocation fails
 *
 * @note The caller is responsible for freeing the returned string.
 */
char *clean_arg( char *arg)
{
    char *output = NULL;
    int i , j;
    int len;

    if (arg == NULL || *arg == '\0')
    {
        return NULL; /* Return NULL if the input is null or an empty string */
    }

    len = strlen(arg);
    
    /* Allocating memory with the length of arg. */
    output = malloc(len + 1); /* +1 for the null terminator */
    if (!output)
    {
        fprintf(stderr, "Failed memory allocation\n");
        return NULL; /* Memory allocation failed */
    }

    /* Iterate through the input string and copy only non-whitespace characters */
    for (i = 0, j = 0; i < len; i++)
    {
        if (!isspace(arg[i]))
        {
            output[j] = arg[i];
            j++;
        }
    }
    output[j] = '\0'; /* Null-terminate the output string */
    return output;
}

/**
 * Verifies that the given arguments match the requirements of the specified command.
 * Checks both the number of arguments and their types.
 *
 * @param args Array of argument strings to verify
 * @param command_index Index of the command in the global commands array
 *
 * @return SUCCESS_CODE if arguments are valid,
 *         EXTRA_COMMA if there are consecutive commas,
 *         EXTRA_VARS if too many arguments provided,
 *         MISSING_VARS if too few arguments provided,
 *         INVALID_COMP if complex number argument is invalid,
 *         INVALID_DOUBLE if double argument is invalid,
 *         MISSING_COMMA if comma is missing between arguments
 */
int verify_arguments(char **args, int command_index)
{
    char *cur_arg;
    int param_count, i, verify_arg;
    ArgType type;

    param_count = commands[command_index].param_count;

    /* Detect and report consecutive commas in arguments */
    if (find_double_comma(args) == EXTRA_COMMA)
    {
        return EXTRA_COMMA;
    }

    verify_arg = verify_argument_count(param_count, args);
    /* Checks if the amount of arguments is correct. */
    if (verify_arg < SUCCESS_CODE) 
    {   
        /* Detected an error code */
        /* Returns the error code */
        return verify_arg;
    }

    /* Loop through each argument and verify its type against the expected type. */
    for (i = 0; i < param_count; i++)
    {
        type = commands[command_index].param_types[i];
        cur_arg = args[i];

        verify_arg = verify_argument_type(type, cur_arg);
        if (verify_arg < SUCCESS_CODE)
        {
            /* Detected an error code */
            /* Returns the error code */
            return verify_arg;
        }
    }

    return SUCCESS_CODE;
}

/**
 * Verifies if the number of provided arguments matches the required parameter count.
 *
 * @param req_param_count The required number of parameters for the command
 * @param args Null-terminated array of argument strings to verify
 *
 * @return SUCCESS_CODE if argument count matches required parameters,
 *         EXTRA_VARS if too many arguments provided,
 *         MISSING_VARS if too few arguments provided
 */
int verify_argument_count(int req_param_count, char **args)
{
    int args_count = string_array_len(args);

    if (args_count > req_param_count)
    {   
        /* Too many arguments were provided */
        return EXTRA_VARS;
    }
    else if (args_count < req_param_count)
    {   
        /* Too few arguments were provided */
        return MISSING_VARS;
    }

    return SUCCESS_CODE;
}

/**
 * Verifies if a given argument matches the required argument type.
 *
 * @param req_arg_type The required argument type (ARG_COMPLEX or ARG_DOUBLE)
 * @param arg The argument string to verify
 * 
 * @return SUCCESS_CODE if verification passes, or one of the following error codes:
 *         FAILED_CODE - if arg is NULL
 *         MISSING_COMMA - if complex argument format indicates missing comma
 *         INVALID_COMP - if complex argument is invalid
 *         INVALID_DOUBLE - if double argument is invalid
 */
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
            /* Use is_complex to validate if the argument is a valid complex number. */
            if (len != 1 || is_complex(arg) == INVALID_COMP)
            {
                return INVALID_COMP;
            }
            break;
        }
        case ARG_DOUBLE:
        {
            /* Attempt to convert the argument to a double. */
            if (str_to_double(arg) == INVALID_DOUBLE)
            {
                
                return INVALID_DOUBLE;
            }
            break;
        }
    }
    return SUCCESS_CODE;
}

/**
 * Checks if there are any consecutive commas in the arguments array by looking for empty strings.
 *
 * @param args An array of strings containing the command arguments
 *
 * @return SUCCESS_CODE if no consecutive commas found
 *         EXTRA_COMMA if consecutive commas detected (empty string found)
 *         FAILED_CODE if args is NULL
 */
int find_double_comma(char **args)
{
    int i;
    /* Return FAILED_CODE if the input array is null */
    if (!args)
        return FAILED_CODE;

    /* Iterate through the argument array until a null pointer is encountered */
    for (i = 0; args[i] != NULL; i++)
    {
        /* An empty string indicates a consecutive comma (,,) in the input */
        if (args[i][0] == '\0')
        {
            return EXTRA_COMMA;
        }
    }
    return SUCCESS_CODE;
}

/**
 * @brief Validates if a string represents a valid complex matrix variable (A-F)
 *
 * @param ch A string containing a single character to be validated
 *
 * @return SUCCESS_CODE if the character is a valid complex matrix variable (A-F),
 *         INVALID_COMP if the character is not a valid complex matrix variable
 *
 * @note A valid complex matrix variable is a single uppercase letter from A to F
 */
int is_complex(char *ch) 
{
    /* Check if the input string is null or the character is outside the range A-F */
    if (!ch || ch[0] < 'A' || ch[0] > 'F') {        
        return INVALID_COMP;
    }
    
    return SUCCESS_CODE;
}