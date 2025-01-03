/**
 * Maman 22
 * 
 * @file strFunc.h
 * @brief Header file containing string manipulation functions
 * 
 * This file contains declarations of functions for string manipulation
 * and processing operations.
 * 
 * @author Yonatan Schrift
 * @date 23.12.2024
 */

#ifndef STR_FUNC_H
#define STR_FUNC_H

#include "complex.h"

/**
 * @brief Creates a new copy of a string in dynamically allocated memory
 * 
 * @param origin The source string to copy
 * @return char* Pointer to the newly allocated copy of the string, or NULL if allocation fails
 * 
 * This function allocates new memory and copies the contents of the origin string.
 * The caller is responsible for freeing the returned memory when no longer needed.
 */
char *copy_string(const char *origin);


/**
 * @brief Calculates the length of a NULL-terminated array of strings
 * 
 * @param args Pointer to array of string pointers (char*), must be NULL-terminated
 * @return Number of strings in array before NULL terminator, or FAILED_CODE if args is NULL
 */
int string_array_len(char **args);


/**
 * @brief Converts a string to a double value.
 * 
 * @param str The string to convert to double
 * @return The converted double value, or INVALID_DOUBLE if conversion fails
 *         (when the string cannot be converted to a valid number)
 */
double str_to_double(char* str);

/**
 * Converts a character representation of a complex variable to its corresponding complex pointer.
 * 
 * @param ch Pointer to a string containing a single character ('A' through 'F')
 *           representing the complex variable to be retrieved
 * 
 * @return Pointer to the corresponding complex number if valid input,
 *         NULL if the input is invalid
 * 
 * @note Valid inputs are uppercase letters A through F, representing the
 *       complex variables stored in comp_vars array
 *       The function maps 'A' to index 0, 'B' to index 1, etc.
 */
complex *char_to_comp(char *ch);

#endif /* STR_FUNC_H */