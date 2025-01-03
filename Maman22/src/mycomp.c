/*
 * Maman 22
 * Yonatan Schrift
 *
 * This file includes the main function.
 *
 * 23.12.2024
 */

#include "../h/complex.h"
#include "../h/mycomp.h"
#include "../h/commandFuncs.h"
#include <stdio.h>
#include <stdlib.h>
void print_error(int error);

int main(void)
{
    complex A, B, C, D, E, F;
    extern complex *comp_vars[6];
    int run_value;

    /* Initialize all complex numbers using pointers */
    init_comp(&A);
    init_comp(&B);
    init_comp(&C);
    init_comp(&D);
    init_comp(&E);
    init_comp(&F);

    /* Initialize array after variable initialization */
    comp_vars[0] = &A;
    comp_vars[1] = &B;
    comp_vars[2] = &C;
    comp_vars[3] = &D;
    comp_vars[4] = &E;
    comp_vars[5] = &F;
    
    printf("Complex Number Calculator\n");
    printf("-------------------------\n");
    printf("Please enter the command you would like to use:\n\n");
    
    help();
    
    do {
        run_value = run();
        print_error(run_value);
    } while(run_value != STOP_CODE);


    return SUCCESS_CODE; /* Return 0 on success */
}


void help(void) {
    printf("\nAvailable Commands:\n");
    printf("------------------\n");
    printf("read_comp <A-F>, <real>, <imaginary>  - Save a complex number\n");
    printf("print_comp <A-F>                      - Print a complex number\n");
    printf("add_comp <A-F>, <A-F>                 - Add two complex numbers\n");
    printf("sub_comp <A-F>, <A-F>                 - Subtract two complex numbers\n");
    printf("mult_comp_real <A-F>, <real>          - Multiply by a real number\n");
    printf("mult_comp_img <A-F>, <real>           - Multiply by an imaginary number\n");
    printf("mult_comp_comp <A-F>, <A-F>           - Multiply two complex numbers\n");
    printf("abs_comp <A-F>                        - Calculate absolute value\n");
    printf("stop                                  - Exit program\n\n");
}


int run(void) {
    char* command_str;
    commandValue *full_command;

    printf("\nEnter command: \n");

    command_str = read_command(); /* Read the command from the user */
    printf("Entered command is %s\n", command_str); /* Display the entered command */

    full_command = split_command(command_str); /* Parse the command into its components */
    free(command_str); /* Free the memory allocated for the raw command string */


    return run_command(full_command); /* Execute the parsed command and return its result */
}

void print_error(int error) {
    switch(error) {
        case SUCCESS_CODE: {
            /* There's no need to print anything */
            return;
        }
        case FAILED_CODE: {
            printf("Unknown error \n");
            return;
        }
        case STOP_CODE: {
            printf("\nGoodbye! Thanks for using my program! \n");
            return;
        }
        case EXTRA_VARS: {
            printf("Extraneous text after end of command\n");
            return;
        }
        case MISSING_VARS: {
            printf("Missing parameter(s)\n");
            return;
        }
        case UNDEFINED_COMMAND: {
            printf("Undefined command name\n");
            return;
        }
        case EXTRA_COMMA: {
            printf("Multiple consecutive commas\n");
            return;
        }
        case ILLEGAL_COMMA: {
            printf("Illegal comma\n");
            return;
        }
        case MISSING_COMMA: {
            printf("Missing comma\n");
            return;
        }
        case INVALID_DOUBLE: {
            printf("Invalid parameter - not a number\n");
            return;
        }
        case INVALID_COMP: {
            printf("Invalid complex variable name\n");
            return;
        }
    }
}
