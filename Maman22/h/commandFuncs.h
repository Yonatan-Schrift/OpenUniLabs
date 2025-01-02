/* 
 * Maman 22
 * Yonatan Schrift
 * 
 * Header file containing function declarations for commands.
 * 
 * 23.12.2024
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
typedef struct Command{
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
typedef struct commandValue {
    const Command *cmd;
    char **args;
    int index;
} commandValue;


extern const Command commands[];



/**
 * Reads a command from standard input.
 * Dynamically allocates memory to store the command string.
 * Reads characters until newline or EOF is encountered.
 * 
 * @return Pointer to dynamically allocated string containing the command,
 *         or NULL if memory allocation fails or EOF is encountered with no input
 */
char *read_command(void);


/**
 * Executes a command based on the provided commandValue structure.
 * 
 * @param command A pointer to a commandValue structure containing the command details to execute
 * @return STOP_CODE if the command is "stop"
 *         FAILED_CODE if the command is invalid or fails to execute
 *         The return value of the command's function otherwise
 * 
 * The function checks if the command is "stop" or invalid first. If neither,
 * it executes the command's associated function stored in the commandValue struct.
 */
int run_command(commandValue *Command);


/**
 * Splits a command string into its components (command name and arguments).
 * Creates and returns a commandValue struct containing the parsed command information.
 * 
 * @param command The input command string to be parsed
 * @return A pointer to a newly allocated commandValue struct containing:
 *         - index: Command index in commands array (FAILED_CODE if invalid, STOP_CODE if "stop")
 *         - cmd: Pointer to the matching Command struct 
 *         - args: Array of parsed argument strings
 *         Returns NULL if memory allocation fails
 *         Caller is responsible for freeing returned struct using free_command()
 *
 * The function:
 * 1. Validates the command name
 * 2. Splits arguments on commas
 * 3. Cleans and processes each argument
 * 4. Handles error cases like illegal commas and undefined commands
 */
commandValue *split_command(const char *command);


/**
 * Determines if the given string represents a valid command.
 * 
 * @param command The command string to validate
 * @return The index of the command in the commands array if found,
 *         STOP_CODE if the command is "stop",
 *         FAILED_CODE if the command is invalid or NULL was passed
 * 
 * @note Checks for illegal trailing commas in the command string
 */
int is_command(const char * command);

/**
 * Frees all memory associated with a commandValue struct.
 * This includes freeing the array of argument strings and the struct itself.
 * Safely handles NULL pointers for both the struct and its members.
 *
 * @param command Pointer to the commandValue struct to be freed
 */
void free_command(commandValue *command);
#endif /* COMMAND_FUNCS_H */