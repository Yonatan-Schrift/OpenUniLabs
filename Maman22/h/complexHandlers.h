#ifndef COMPLEX_HANDLERS_H
#define COMPLEX_HANDLERS_H

#include "commandFuncs.h"


/**
 * Handles the read_comp command by parsing command arguments and storing complex number values.
 * 
 * @param command Pointer to a commandValue structure containing the command arguments
 * @return SUCCESS_CODE (0) if the operation was successful
 *         FAILED_CODE (-1) if argument verification failed
 * 
 * This handler:
 * 1. Verifies command arguments are valid
 * 2. Converts first arg to complex number reference
 * 3. Converts second and third args to real and imaginary parts
 * 4. Stores the complex number values
 * 5. Frees the command structure
 */
int read_comp_handle(commandValue *command);

/**
 * Handles the 'print_comp' command operation - prints the complex number from memory
 * 
 * @param command Pointer to a commandValue structure containing the command arguments
 * 
 * @return SUCCESS_CODE (0) if the operation was successful
 *         FAILED_CODE (-1) if argument verification failed
 * 
 * @note Frees the command structure before returning
 */
int print_comp_handle(commandValue *command);

/**
 * Handles the addition operation between two complex numbers.
 * 
 * This function processes a command to add two complex numbers (A+B), It verifies the command arguments before performing
 * the operation.
 * 
 * @param command Pointer to a commandValue structure containing the command arguments
 * 
 * @return SUCCESS_CODE (0) if the operation was successful
 *         FAILED_CODE (-1) if argument verification failed
 */
int add_comp_handle(commandValue *command);


/**
 * Handles the subtraction operation between two complex numbers.
 * 
 * Takes a command structure containing two complex number identifiers,
 * verifies the arguments, performs the subtraction operation and frees the command.
 *
 * @param command Pointer to a commandValue structure containing the command arguments
 * @return SUCCESS_CODE (0) if the operation was successful
 *         FAILED_CODE (-1) if argument verification failed
 */
int sub_comp_handle(commandValue *command);

/**
 * Handles the multiplication of a complex number with a real number command.
 * 
 * Takes a complex number and real number as arguments, multiplies them using mult_comp_real(),
 * and frees the command structure afterwards.
 *
 * @param command Pointer to a commandValue structure containing the command arguments
 * 
 * @return SUCCESS_CODE (0) if the operation was successful
 *         FAILED_CODE (-1) if argument verification failed
 */
int mult_comp_real_handle(commandValue *command);

/**
 * Handles the multiplication of a complex number by an imaginary number.
 * 
 * Takes a command value containing a complex number identifier and a scalar imaginary number,
 * verifies the arguments, performs the multiplication, and frees the command.
 * 
 * @param command Pointer to a commandValue structure containing the command arguments
 * 
 * @return SUCCESS_CODE (0) if the operation was successful
 *         FAILED_CODE (-1) if argument verification failed
 */
int mult_comp_img_handle(commandValue *command);

/**
 * Handles multiplication of two complex numbers command. 
 * 
 * Takes two complex numbers from the command arguments
 * and calls the multiplication function with them.
 *
 * @param command Pointer to a commandValue structure containing the command arguments
 * 
 * @return SUCCESS_CODE (0) if the operation was successful
 *         FAILED_CODE (-1) if argument verification failed
 *
 */
int mult_comp_comp_handle(commandValue *command);

/**
 * Handles the calculation of the absolute value of a complex number.
 * 
 * Verifies the arguments, converts the input to a complex number,
 * calculates its absolute value, and frees the command.
 *
 * @param command Pointer to a commandValue structure containing the command arguments
 * 
 * @return SUCCESS_CODE (0) if the operation was successful
 *         FAILED_CODE (-1) if argument verification failed
 */
int abs_comp_handle(commandValue *command);

/**
 * Handles the stop command for the complex number calculator.
 * 
 * Verifies arguments and frees allocated memory before stopping program execution.
 * 
 * @param command Pointer to a commandValue struct containing the command arguments
 * @return SUCCESS_CODE (0) if the operation was successful
 *         FAILED_CODE (-1) if argument verification failed
 */
int stop(commandValue *command);

#endif /* COMPLEX_HANDLERS_H */