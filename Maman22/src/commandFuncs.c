/*
 * Maman 22
 * Yonatan Schrift
 *
 * 23.12.2024
 */

#include "../h/strFunc.h"
#include "../h/commandFuncs.h"
#include "../h/complexHandlers.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>

const Command commands[] = {
    {"read_comp", read_comp_handle, 3, {ARG_COMPLEX, ARG_DOUBLE, ARG_DOUBLE}},
    {"print_comp", print_comp_handle, 1, {ARG_COMPLEX}},
    {"add_comp", add_comp_handle, 2, {ARG_COMPLEX, ARG_COMPLEX}},
    {"sub_comp", sub_comp_handle, 2, {ARG_COMPLEX, ARG_COMPLEX}},
    {"mult_comp_real", mult_comp_real_handle, 2, {ARG_COMPLEX, ARG_DOUBLE}},
    {"mult_comp_img", mult_comp_img_handle, 2, {ARG_COMPLEX, ARG_DOUBLE}},
    {"mult_comp_comp", mult_comp_comp_handle, 2, {ARG_COMPLEX, ARG_COMPLEX}},
    {"abs_comp", abs_comp_handle, 1, {ARG_COMPLEX}},
    {"stop", stop, 0, {0}},
    {NULL, NULL, 0, {0}} /* Terminator entry */
};

/**
 * Checks if a given string is a valid command and returns its index in the commands array.
 *
 * @param command The string to check if it's a valid command
 * @return The index of the command in the commands array if found,
 *         UNDEFINED_COMMAND if the command is not found or input is NULL,
 *         ILLEGAL_COMMA if the command ends with a comma
 */
int is_command(const char *command)
{
    int command_index;

    /* Return UNDEFINED_COMMAND if the input string is null */
    if (!command)
    {
        return UNDEFINED_COMMAND;
    }

    /* Iterate through 'commands' array to find matching command */
    for (command_index = 0; commands[command_index].name != NULL; command_index++)
    {
        if (strcmp(commands[command_index].name, command) == 0)
        {
            /* Command found, return its index */
            return command_index;
        }
    }

    /* If the last character of the command is a comma, return ILLEGAL_COMMA */
    if (command[strlen(command) - 1] == ',')
    {
        return ILLEGAL_COMMA;
    }

    /* No matching command found */
    return UNDEFINED_COMMAND;
}

/**
 * Reads a command from standard input character by character.
 * Dynamically allocates memory for the command string, doubling the buffer size when needed.
 *
 * @return A pointer to the dynamically allocated string containing the command,
 *         or NULL if:
 *         - Memory allocation fails
 *         - EOF is encountered with no input
 *
 * @note The returned string must be freed by the caller when no longer needed
 */
char *read_command(void)
{
    char cur;
    char *buffer, *command;
    size_t capacity, index;

    /* Initialize variables:
    * capacity: Initial size of the dynamic buffer.
    * index: Tracks the current position in the buffer.
    */
    capacity = 8; /* starting size for the command */
    index = 0;

    /* Allocating initial memory */
    command = (char *)malloc(capacity);
    if (!command)
    {
        fprintf(stderr, "Failed memory allocation\n");
        return NULL; /* Memory Allocation Error */
    }

    /* Read input character by character */
    while ((cur = getchar()) != EOF && cur != '\n')
    {
        if (index >= capacity - 1)
        {
            /* Buffer is too small, double the capacity */
            buffer = realloc(command, capacity * 2);
            if (!buffer)
            {
                free(command);
                return NULL; /* Memory Allocation Error */
            }
            command = buffer;
            capacity *= 2;
        }
        command[index++] = cur;
    }

    /* Handle EOF when no input is given */
    if (index == 0 && cur == EOF)
    {
        free(command);
        return NULL;
    }

    /* Null-terminate the string */
    command[index] = '\0';
    return command;
}

/**
 * Splits a command string into its command and arguments.
 *
 * This function takes a command string and parses it into a commandValue structure
 * containing the command index, command pointer, and an array of argument strings.
 * The command is validated against the commands array and argument parsing follows
 * these rules:
 * - First token is split by whitespace (command name)
 * - Subsequent tokens are split by commas (arguments)
 * - Arguments are cleaned of whitespace
 * - Checks for correct number of arguments based on command definition
 *
 * @param command The input string containing the command and arguments
 * @return A pointer to a newly allocated commandValue structure containing:
 *         - index: Command index or error code if validation fails
 *         - cmd: Pointer to the command definition
 *         - args: Array of argument strings (NULL-terminated)
 *         Returns NULL if memory allocation fails or input is NULL
 *
 * Error codes returned in commandValue->index:
 * - UNDEFINED_COMMAND: Command name not found
 * - ILLEGAL_COMMA: Command ends with illegal comma
 * - MISSING_VARS: Too few arguments provided
 * - EXTRA_VARS: Too many arguments provided
 * - FAILED_CODE: Memory allocation failure
 *
 * @note: Caller is responsible for freeing the returned structure using free_command()
 */
commandValue *split_command(const char *string)
{
    commandValue *output;
    char *input_copy, *token, *cleaned_arg, **args;
    int param_count, i, j;

    /* Handle empty string (usually EOF) */
    if (!string)
    {
        return NULL;
    }

    /* Allocate memory for the commandValue structure */
    output = malloc(sizeof(commandValue));
    if (!output)
    {
        fprintf(stderr, "Failed memory allocation\n");
        return NULL;
    }

    /* Copy the input string because strtok modifies it */
    input_copy = copy_string(string);
    if (!input_copy)
    {
        output->index = FAILED_CODE;
        return output;
    }
    
    /* Split the string by the first whitespace to extract the command */
    token = strtok(input_copy, " ");
    cleaned_arg = clean_arg(token);

    /* Validate the command and store its index */
    output->index = is_command(cleaned_arg);
    free(cleaned_arg);

    if (output->index < SUCCESS_CODE)
    {
        /* If an error occurs, clean up and return */
        free(input_copy);
        output->args = NULL;
        return output;
    }

    /* Retrieve the expected number of parameters for the command */
    param_count = commands[output->index].param_count;

    /* Allocate memory for the arguments array, including NULL terminator */
    args = malloc((param_count + 1) * sizeof(char *));
    if (!args)
    {
        free(input_copy);
        fprintf(stderr, "Failed memory allocation\n");
        output->args = NULL;
        return output; /* Memory allocation failed */
    }

    args[param_count] = NULL; /* NULL-terminating the array */

    /* Store the reference to the command structure */
    output->cmd = &commands[output->index];

    /* Extract each argument, separated by commas */
    for (i = 0; i < param_count; i++)
    {
        token = strtok(NULL, ",");
        if (!token)
        {
            /* Handle missing arguments and clean up allocated memory */
            output->index = MISSING_VARS;
            output->args = NULL;
            
            for (j = 0; j < i; j++)
            {
                free(args[j]);
            }
            free(args);
            free(input_copy);
            
            return output;
        }
        args[i] = clean_arg(token); /* Clean (remove whitespaces) each argument */
    }

    /* Handle edge cases, such as extra arguments or trailing commas */
    if (output->index >= SUCCESS_CODE)
    {
        /* Check for extra text at the end */
        token = strtok(NULL, ",");
        
        if (token != NULL)
        {
            /* Clean up allocated memory before setting error */
            for (i = 0; i < param_count; i++)
            {
                free(args[i]);
            }
            free(args);
            free(input_copy);

            output->args = NULL;
            output->index = EXTRA_VARS;

            return output;
        }

        /* Check for comma at the end */
        else if (string[strlen(string) - 1] == ',')
        {
            if (args[param_count - 1] != NULL)
            {
                /* Clean up allocated memory before setting error */
                for (i = 0; i < param_count; i++)
                {
                    free(args[i]);
                }
                free(args);
                free(input_copy);

                output->args = NULL;
                output->index = EXTRA_VARS;

                return output;
            }
        }
    }
    free(input_copy);

    output->args = args;

    return output;
}

int run_command(commandValue *command)
{
    const Command *cmd;
    int cmd_index; /* only used for failures before running the command */

    /* Handle NULL input - usually EOF */
    if (!command)
    {
        return STOP_CODE;
    }

    cmd = command->cmd;

    /* if the command has an error, return the error. */
    if (command->index < SUCCESS_CODE)
    {
        cmd_index = command->index;
        command->args = NULL;
        free_command(command);
        
        return cmd_index;
    }

    /* run the command (saved in the struct) */
    return cmd->func(command);
}

void free_command(commandValue *command)
{
    int i, arr_len;

    if (command == NULL)
    {
        return;
    }

    if (command->args != NULL)
    {
        arr_len = string_array_len(command->args);
        for (i = 0; i < arr_len; i++)
        {
            if (command->args[i] != NULL)
            {
                free(command->args[i]);  /* Frees each string in the array */
                command->args[i] = NULL; /* Prevent double-free */
            }
        }
        /* Free the array itself */
        free(command->args);
        command->args = NULL;
    }
    /* Free the commandValue struct itself */
    free(command);
}