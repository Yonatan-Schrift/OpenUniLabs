/**
 * Maman 22
 *
 * @file mycomp.h
 * @brief Header file containing declarations for a complex number calculator
 * 
 * The user is greeted and given a command list, then the program will read 
 * and process the commands until the user enters "stop".
 *
 * @author Yonatan Schrift
 * @date 23.12.2024
 */

#ifndef MYCOMP_H
#define MYCOMP_H


/**
 * @brief Main function for the complex number calculator program.
 *
 * Initializes 6 complex number variables (A-F) and their corresponding pointers.
 * Provides an interactive command-line interface for performing operations on complex numbers.
 * Displays help menu and processes user commands until 'stop' command is received.
 *
 * @return SUCCESS_CODE (0) on successful program completion
 */
int main(void);

/**
 * @brief Prints help information about the program's usage and commands.
 * 
 * This function displays a list of available commands and their descriptions,
 * helping users understand how to use the program correctly.
 */
void help(void);

/*
 * Starts a command prompt loop for the complex number calculator.
 * Reads user input, parses the command, and executes it.
 * 
 * Returns:
 *   - SUCCESS_CODE (0) if command executed successfully
 *   - STOP_CODE if stop command entered to exit program
 *   - Various error codes for invalid input/commands:
 *     FAILED_CODE, EXTRA_VARS, MISSING_VARS, UNDEFINED_COMMAND,
 *     EXTRA_COMMA, ILLEGAL_COMMA, MISSING_COMMA, INVALID_DOUBLE,
 *     INVALID_COMP
 */
int run(void);

/**
 * Prints an error message based on the given error code.
 * 
 * The function maps different error codes to their corresponding error messages
 * and prints them to stdout. The error codes and their messages are:
 * 
 * SUCCESS_CODE (0)     - No error message (silent)
 * FAILED_CODE          - "Unknown error"
 * STOP_CODE           - Goodbye message
 * EXTRA_VARS          - "Extraneous text after end of command"
 * MISSING_VARS        - "Missing parameter(s)"
 * UNDEFINED_COMMAND   - "Undefined command name"
 * EXTRA_COMMA         - "Multiple consecutive commas"
 * ILLEGAL_COMMA       - "Illegal comma"
 * MISSING_COMMA       - "Missing comma"
 * INVALID_DOUBLE      - "Invalid parameter - not a number"
 * INVALID_COMP        - "Invalid complex variable name"
 *
 * @param error The error code to be processed
 */
void print_error(int error);

#endif /* MYCOMP_H */