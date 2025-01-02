#ifndef STR_FUNC_H
#define STR_FUNC_H

#define FAILED_CODE -1
#define STOP_CODE -2


/**
 * @brief Copies a string from origin to a new allocated memory
 * 
 * @param origin The source string to be copied
 * @return char* A pointer to the newly allocated and copied string, or NULL if allocation fails
 * 
 * This function performs a deep copy of the input string by:
 * 1. Allocating new memory for the copy
 * 2. Copying the contents of the original string
 * 
 * @note The caller is responsible for freeing the returned string
 * @warning Returns NULL and prints error message if memory allocation fails
 */
char *copy_string(const char *origin);

/**
 * @brief Counts the number of arguments in a NULL-terminated array of strings
 * 
 * @param args A NULL-terminated array of strings to be counted
 * @return int The number of strings in the array (excluding the NULL terminator)
 * 
 * This function counts the number of strings in a NULL-terminated array by
 * iterating through the array until it encounters the NULL terminator.
 * The array must be properly NULL-terminated to avoid undefined behavior.
 */
int string_array_len(char **args);

/**
 * @brief Converts a string to a double value
 * 
 * @param str The string to convert to double
 * @return double Returns the converted number if successful, FAILED_CODE if conversion fails
 * 
 * This function attempts to convert a string representation of a number to a double.
 * If the conversion fails (i.e., if the string doesn't represent a valid number),
 * it returns FAILED_CODE.
 */
double str_to_double(char* str);

#endif /* STR_FUNC_H */