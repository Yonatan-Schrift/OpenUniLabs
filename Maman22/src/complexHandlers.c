/* 
 * Maman 22
 * Yonatan Schrift
 * 01.01.2025
 */

#include "../h/complexHandlers.h"
#include "../h/complex.h" /* For the basic functions */
#include "../h/commandFuncs.h" /* For commandValue type */
#include "../h/strFunc.h" /* for conversion to double */
#include <stdio.h>

int read_comp_handle(commandValue *command) {
    complex *comp;
    double real_part, imaginary_part;
    int verify_arg;

    /* Verifying the amount of arguments and types of them. */
    verify_arg = verify_arguments(command->args, command->index);
    if(verify_arg < SUCCESS_CODE) {
        free_command(command);
        return verify_arg;
    }

    comp = char_to_comp(command->args[0]);
    real_part = str_to_double(command->args[1]);
    imaginary_part = str_to_double(command->args[2]);

    printf("Saving %s = %.2f, %.2fi\n", command->args[0], real_part, imaginary_part);
    read_comp(comp, real_part, imaginary_part);

    free_command(command);

    return SUCCESS_CODE;
}

int print_comp_handle(commandValue *command) {
    complex *comp;
    int verify_arg;

    /* Verifying the amount of arguments and types of them. */
    verify_arg = verify_arguments(command->args, command->index);
    if(verify_arg < SUCCESS_CODE) {
        free_command(command);
        return verify_arg;
    }

    comp = char_to_comp(command->args[0]);

    print_comp(comp);

    free_command(command);

    return SUCCESS_CODE;
}

int add_comp_handle(commandValue *command) {
    complex *compA, *compB;
    int verify_arg;

    /* Verifying the amount of arguments and types of them. */
    verify_arg = verify_arguments(command->args, command->index);
    if(verify_arg < SUCCESS_CODE) {
        free_command(command);
        return verify_arg;
    }

    compA = char_to_comp(command->args[0]);
    compB = char_to_comp(command->args[1]);

    add_comp(compA, compB);

    free_command(command);

    return SUCCESS_CODE;
}

int sub_comp_handle(commandValue *command) {
    complex *compA, *compB;
    int verify_arg;

    /* Verifying the amount of arguments and types of them. */
    verify_arg = verify_arguments(command->args, command->index);
    if(verify_arg < SUCCESS_CODE) {
        free_command(command);
        return verify_arg;
    }

    compA = char_to_comp(command->args[0]);
    compB = char_to_comp(command->args[1]);

    sub_comp(compA, compB);

    free_command(command);
    return SUCCESS_CODE;
}

int mult_comp_real_handle(commandValue *command) {
    complex *comp;
    double mult;
    int verify_arg;

    /* Verifying the amount of arguments and types of them. */
    verify_arg = verify_arguments(command->args, command->index);
    if(verify_arg < SUCCESS_CODE) {
        free_command(command);
        return verify_arg;
    }

    comp = char_to_comp(command->args[0]);
    mult = str_to_double(command->args[1]);

    mult_comp_real(comp, mult);

    free_command(command);

    return SUCCESS_CODE;
}

int mult_comp_img_handle(commandValue *command) {
    complex *comp;
    double mult;
    int verify_arg;

    /* Verifying the amount of arguments and types of them. */
    verify_arg = verify_arguments(command->args, command->index);
    if(verify_arg < SUCCESS_CODE) {
        free_command(command);
        return verify_arg;
    }
    comp = char_to_comp(command->args[0]);
    mult = str_to_double(command->args[1]);

    mult_comp_img(comp, mult);

    free_command(command);

    return SUCCESS_CODE;
}

int mult_comp_comp_handle(commandValue *command) {
    complex *compA, *compB;
    int verify_arg;

    /* Verifying the amount of arguments and types of them. */
    verify_arg = verify_arguments(command->args, command->index);
    if(verify_arg < SUCCESS_CODE) {
        free_command(command);
        return verify_arg;
    }

    compA = char_to_comp(command->args[0]);
    compB = char_to_comp(command->args[1]);

    mult_comp_comp(compA, compB);

    free_command(command);

    return SUCCESS_CODE;
}

int abs_comp_handle(commandValue *command) {
    complex *comp;
    int verify_arg;

    /* Verifying the amount of arguments and types of them. */
    verify_arg = verify_arguments(command->args, command->index);
    if(verify_arg < SUCCESS_CODE) {
        free_command(command);
        return verify_arg;
    }

    comp = char_to_comp(command->args[0]);

    abs_comp(comp);

    free_command(command);

    return SUCCESS_CODE;
}

int stop(commandValue *command) {
    int verify_arg;

    /* Verifying the amount of arguments and types of them. */
    verify_arg = verify_arguments(command->args, command->index);
    if(verify_arg < SUCCESS_CODE) {
        free_command(command);
        return verify_arg;
    }
    
    free_command(command);
    
    return STOP_CODE;
}
