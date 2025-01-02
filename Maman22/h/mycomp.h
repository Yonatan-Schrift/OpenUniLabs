/*
 * Maman 22
 * Yonatan Schrift
 *
 * Header file for mycomp.c
 * Contains function declarations for the complex number calculator menu and main function.
 *
 * 23.12.2024
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


/** 
 * @brief Executes the main program loop.
 * Reads user input command, parses it, and executes the corresponding operation.
 *
 * @return:
 *   STOP_CODE when stop command is received
 *   Any other return codes based on command execution
 */
int run(void);

#endif /* MYCOMP_H */