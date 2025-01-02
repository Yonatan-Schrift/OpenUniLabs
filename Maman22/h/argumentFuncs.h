#ifndef ARGUMENT_FUNCS_H
#define ARGUMENT_FUNCS_H

/* Type definition for argument types */
typedef enum {
    ARG_COMPLEX,
    ARG_DOUBLE
} ArgType;



/**
 * Cleans a string by removing all whitespace characters.
 * 
 * @param arg The string to be cleaned. Can be NULL.
 * @return A newly allocated string with all whitespace removed, or NULL if:
 *         - The input string is NULL
 *         - Memory allocation fails
 * @note The caller is responsible for freeing the returned string.
 */
char *clean_arg(char *arg);


/**
 * Verifies if the given arguments match the expected format for a command.
 * The function checks both the number of arguments and their types.
 * 
 * @param args Array of string arguments to verify
 * @param command_index Index of the command in the global commands array to check against
 * @return SUCCESS_CODE (0) if arguments are valid, FAILED_CODE (-1) if validation fails
 * 
 * The function performs the following checks:
 * - Verifies the number of arguments matches the command's expected parameter count
 * - Checks for double commas in the argument list
 * - Validates each argument matches its expected type (complex or double)
 */
int verify_arguments(char **args, int command_index);


/**
 * Verifies that the number of arguments passed matches the required number of parameters.
 *
 * @param req_param_count The required number of parameters for the command
 * @param args Array of argument strings to verify
 * @return SUCCESS_CODE if the number of arguments matches required parameters,
 *         FAILED_CODE if there are too many or too few arguments
 *
 * @note Prints appropriate error messages if the argument count is incorrect:
 *       - "Extraneous text after end of command" if too many arguments
 *       - "Missing X parameter(s)" if too few arguments
 */
int verify_argument_count(int req_param_count, char **args);


/**
 * Verifies if a given argument matches the required argument type.
 * 
 * @param req_arg_type The required argument type (ARG_COMPLEX or ARG_DOUBLE)
 * @param arg The argument string to verify
 * @return SUCCESS_CODE if argument matches required type, FAILED_CODE otherwise
 *
 * For ARG_COMPLEX:
 * - Validates that arg is a single uppercase letter A-F
 * - Checks for missing comma between arguments
 *
 * For ARG_DOUBLE:
 * - Validates that arg can be converted to a valid double number
 *
 * Prints appropriate error message if validation fails.
 */
int verify_argument_type(int req_arg_type, char *arg);


/**
 * @brief Checks for consecutive commas in the command arguments
 * 
 * Searches through an array of argument strings and checks if any argument
 * is an empty string, which indicates consecutive commas in the original input.
 *
 * @param args Array of argument strings to check
 * @return SUCCESS_CODE if no consecutive commas found, FAILED_CODE if consecutive commas found or args is NULL
 */
int find_double_comma(char **args);


/**
 * @brief Checks if a string represents a valid complex variable name.
 *
 * Validates if the given string represents a valid complex variable name,
 * which must be a single uppercase letter between 'A' and 'F'.
 *
 * @param ch Pointer to the string to validate
 * @return SUCCESS_CODE (0) if valid, FAILED_CODE (-1) if invalid or NULL input
 */
int is_complex(char *ch);

#endif /* ARGUMENT_FUNCS_H */