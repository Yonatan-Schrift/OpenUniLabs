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


int is_command(const char *command)
{
    int command_index;

    /* Check for NULL input */
    if (!command)
    {
        return UNDEFINED_COMMAND;
    }

    /* Iterate through commands array to find matching command */
    for (command_index = 0; commands[command_index].name != NULL; command_index++)
    {
        if (strcmp(commands[command_index].name, command) == 0)
        {
            return command_index;
        }
    }

    /* Check for an illegal comma */
    if (command[strlen(command) - 1] == ',')
    {
        return ILLEGAL_COMMA;
    }

    /* No matching command found */
    return UNDEFINED_COMMAND;
}

char *read_command(void)
{
    char cur;
    char *buffer, *command;
    size_t capacity, index;

    /* Initialize variables */
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

commandValue *split_command(const char *string)
{
    commandValue *output;
    char *input_copy, *token, **args;
    int param_count, i;

    output = malloc(sizeof(commandValue));
    if (!output)
    {
        fprintf(stderr, "Failed memory allocation\n");
        return NULL;
    }

    /* Copies the command since strtok changes the string. */
    input_copy = copy_string(string);
    printf("origin is: %s\n", input_copy);

    /* Splits the string, The first part with a whitespace and the rest with commas. */
    /* The first token will always be the command, so I'll check if it's a valid command. */
    token = strtok(input_copy, " ");
    token = clean_arg(token);

    /* Validates the command and saves the index of the command in the commands array. */
    output->index = is_command(token);

    if(output->index < SUCCESS_CODE) {
        /* If we recieve an error code, returns the output without any args, and with the error code. */
        free(input_copy);
        return output;
    }

    param_count = commands[output->index].param_count;

    args = allocate_str_array(param_count);

    output->cmd = &commands[output->index];

    
    /* Saves all the given arguments from the string into a string array */
    for (i = 0; token != NULL; i++)
    {
        printf("token is: %s\n", token);
        token = strtok(NULL, ",");
        args[i] = clean_arg(token);
    }

    /* Edge case:
     * strtok will ignore this comma because there's nothing after it, so we have to check for it.
     */
    if (string[strlen(string) - 1] == ',')
    {
        if (args[param_count - 1] != NULL)
        {
            output->index = EXTRA_VARS;
        }
    }

    free(input_copy);
    free(token);

    output->args = args;

    return output;
}

int run_command(commandValue *command)
{
    const Command *cmd = command->cmd; 

    /* if the command has an error, return the error. */
    if (command->index < SUCCESS_CODE)
    {
        return command->index;
    }

    /* run the command (saved in the struct) */
    return cmd->func(command);
}

void free_command(commandValue *command)
{
    int i;

    if (command == NULL)
    {
        return;
    }

    if (command->args != NULL)
    {
        for (i = 0; i < string_array_len(command->args); i++)
        {
            if (command->args[i] != NULL)
            {
                free(command->args[i]);
                command->args[i] = NULL; /* Prevent double-free */
            }
        }
        free(command->args);
        command->args = NULL;
    }

    free(command);
}