
/**
 * @file argumentFuncs.h
 * @brief Header file containing function declarations for argument handling
 *
 * @author Yonatan Schrift
 * @date 23.12.2024
 */

#ifndef ARGUMENT_FUNCS_H
#define ARGUMENT_FUNCS_H

/* Type definition for argument types */
typedef enum
{
    ARG_COMPLEX,
    ARG_DOUBLE
} ArgType;

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
char *clean_arg(char *arg);

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
int verify_arguments(char **args, int command_index);

/**
 * Verifies if the number of provided arguments matches the required parameter count.
 *
 * @param req_param_count The required number of parameters for the command
 * @param args Array of argument strings to verify
 *
 * @return SUCCESS_CODE if argument count matches required parameters,
 *         EXTRA_VARS if too many arguments provided,
 *         MISSING_VARS if too few arguments provided
 */
int verify_argument_count(int req_param_count, char **args);

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
int verify_argument_type(int req_arg_type, char *arg);

/**
 * Checks if there are any consecutive commas in the arguments array by looking for empty strings.
 *
 * @param args An array of strings containing the command arguments
 *
 * @return SUCCESS_CODE if no consecutive commas found
 *         EXTRA_COMMA if consecutive commas detected (empty string found)
 *         FAILED_CODE if args is NULL
 */
int find_double_comma(char **args);

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
int is_complex(char *ch);

#endif /* ARGUMENT_FUNCS_H */