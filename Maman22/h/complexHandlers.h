/**
 * Maman 22
 *
 * @file complexHandlers.h
 * @brief Header file containing complex number handling functions and utilities
 *
 * This file provides declarations for functions and data structures used
 * to perform operations on complex numbers. It includes basic arithmetic
 * operations, comparison utilities, and other complex number manipulations.
 *
 * @author Yonatan Schrift
 * @date 02.01.2025
 */


#ifndef COMPLEX_HANDLERS_H
#define COMPLEX_HANDLERS_H

#include "commandFuncs.h"

/**
 * @brief Handles the 'read_comp' command which reads and stores a complex number.
 * 
 * The function validates the input arguments, converts string arguments to appropriate types,
 * and calls read_comp to store the complex number.
 *
 * @param command A pointer to commandValue struct containing the command arguments and index
 * @return SUCCESS_CODE (0) if successful, error code (< 0) if verification fails
 */
int read_comp_handle(commandValue *command);

/**
 * @brief Handles the print command for a complex number.
 *
 * This function takes a command structure containing a complex number identifier,
 * verifies the arguments are valid, and prints the complex number in the format "a + bi".
 * Frees the command structure before returning.
 *
 * @param command Pointer to commandValue structure containing arguments
 * @return SUCCESS_CODE (0) if successful, error code (< 0) if verification fails
 */
int print_comp_handle(commandValue *command);

/**
 * @brief Handles the addition operation between two complex numbers
 *
 * This function takes a command structure containing two complex number identifiers,
 * performs input validation, adds the two complex numbers, and frees the command structure.
 * The addition result is handled by the add_comp function.
 *
 * @param command Pointer to commandValue structure containing the operation arguments
 * @return SUCCESS_CODE (0) if successful, error code (< 0) if verification fails
 */
int add_comp_handle(commandValue *command);

/**
 * @brief Handles the subtraction command between two complex numbers
 *
 * This function takes a command structure containing two complex number identifiers,
 * subtracts the second complex number from the first one, and prints the result.
 * The function verifies arguments before performing the operation and frees the command structure.
 *
 * @param command Pointer to commandValue structure containing complex number identifiers
 * @return SUCCESS_CODE (0) if successful, error code (< 0) if verification fails
 */
int sub_comp_handle(commandValue *command);

/**
 * @brief Handles the multiplication of a complex number with a real number command.
 *
 * Takes a complex number and real number as arguments, multiplies them using mult_comp_real(),
 * and frees the command structure afterwards.
 *
 * @param command Pointer to a commandValue structure containing the command arguments
 * @return SUCCESS_CODE (0) if successful, error code (< 0) if verification fails
 */
int mult_comp_real_handle(commandValue *command);

/**
 * @brief Handles the multiplication of a complex number by an imaginary number.
 *
 * Takes a command value containing a complex number identifier and a scalar imaginary number,
 * verifies the arguments, performs the multiplication, and frees the command.
 *
 * @param command Pointer to a commandValue structure containing the command arguments
 *
 * @return SUCCESS_CODE (0) if successful, error code (< 0) if verification fails
 */
int mult_comp_img_handle(commandValue *command);

/**
 * @brief Handles multiplication of two complex numbers command.
 *
 * Takes two complex numbers from the command arguments
 * and calls the multiplication function with them.
 *
 * @param command Pointer to a commandValue structure containing the command arguments
 *
 * @return SUCCESS_CODE (0) if successful, error code (< 0) if verification fails
 */
int mult_comp_comp_handle(commandValue *command);

/**
 * @brief Handles the calculation of the absolute value of a complex number.
 *
 * Verifies the arguments, converts the input to a complex number,
 * calculates its absolute value, and frees the command.
 *
 * @param command Pointer to a commandValue structure containing the command arguments
 * @return SUCCESS_CODE (0) if successful, error code (< 0) if verification fails
 */
int abs_comp_handle(commandValue *command);

/**
 * @brief Handles the stop command for the complex number calculator.
 *
 * Verifies arguments and frees allocated memory before stopping program execution.
 *
 * @param command Pointer to a commandValue struct containing the command arguments
 * @return SUCCESS_CODE (0) if successful, error code (< 0) if verification fails
 */
int stop(commandValue *command);

#endif /* COMPLEX_HANDLERS_H */