/**
 * Maman 22
 * 
 * @file commandFuncs.h
 * @brief Header file containing function declarations for command processing operations
 * 
 * This header file declares functions that handle command processing
 * and related operations for the project.
 * 
 * @author Yonatan Schrift
 * @date 23.12.2024
 * 
 */

#include "complex.h"
#include "argumentFuncs.h"
#include "complexHandlers.h"
#ifndef COMMAND_FUNCS_H
#define COMMAND_FUNCS_H

#define MAX_PARAMS 3

/* return values for each specific case */
#define SUCCESS_CODE 0
#define FAILED_CODE -1
#define STOP_CODE -2
#define UNDEFINED_COMMAND -3
#define EXTRA_VARS -4
#define MISSING_VARS -5
#define EXTRA_COMMA -6
#define ILLEGAL_COMMA -7
#define MISSING_COMMA -8
#define INVALID_DOUBLE -9
#define INVALID_COMP -10

struct Command;
struct commandValue;

/**
 * @brief A structure representing a command in the program
 *
 * This structure stores information about a command, including its parameters,
 * type, and any associated data needed for command execution.
 */
typedef struct Command
{
    const char *name;
    int (*func)(struct commandValue *command);
    int param_count;
    ArgType param_types[MAX_PARAMS];
} Command;

/**
 * @brief A structure to hold command data and its value
 *
 * The commandValue structure is used to store a command and its associated value,
 * allowing for organized handling of command-line inputs and processing.
 *
 * @note the index value is also used to save error codes in the command.
 */
typedef struct commandValue
{
    const Command *cmd;
    char **args;
    int index;
} commandValue;

extern const Command commands[];

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
char *read_command(void);

/**
 * Executes a command based on the provided commandValue structure.
 *
 * @param command Pointer to a commandValue structure containing the command to execute
 *               and its arguments. If NULL, treats as EOF and returns STOP_CODE.
 *
 * @return Returns:
 *         - SUCCESS_CODE  if command executes successfully
 *         - STOP_CODE  if command is NULL (EOF)
 *         - Error codes (negative values) if command validation fails:
 *           - UNDEFINED_COMMAND: Command not found
 *           - ILLEGAL_COMMA: Illegal comma in command
 *           - MISSING_VARS: Missing required arguments
 *           - EXTRA_VARS: Too many arguments provided
 *           - Any other error codes returned by the specific command function
 *
 * @note The function frees the commandValue structure and its contents after execution
 */
int run_command(commandValue *Command);

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
commandValue *split_command(const char *command);

/**
 * Checks if a given string is a valid command and returns its index in the commands array.
 *
 * @param command The string to check if it's a valid command
 * @return The index of the command in the commands array if found,
 *         UNDEFINED_COMMAND if the command is not found or input is NULL,
 *         ILLEGAL_COMMA if the command ends with a comma
 */
int is_command(const char *command);

/**
 * @brief Frees all memory allocated for a commandValue struct.
 *
 * This function deallocates all memory associated with a commandValue struct,
 * including the array of argument strings and the struct itself.
 * It safely handles NULL pointers and sets freed pointers to NULL to prevent double-free.
 *
 * @param command Pointer to the commandValue struct to be freed.
 *                If NULL, function returns without doing anything.
 */
void free_command(commandValue *command);

#endif /* COMMAND_FUNCS_H */