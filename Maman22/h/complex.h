/*
 * Maman 22
 * Yonatan Schrift
 *
 * Header file containing function declarations for complex number operations
 *
 * This file contains the function declarations for performing various operations
 * on complex numbers including initialization, arithmetic operations, and absolute value calculation.
 *
 * 23.12.2024
 */

#ifndef COMPLEX_H
#define COMPLEX_H

#define FAILED_CODE -1
#define STOP_CODE -2

/**
 * @brief Represents a complex number with real and imaginary parts
 *
 * A structure that defines a complex number containing two components:
 * a real part and an imaginary part, both represented as double precision
 * floating-point numbers.
 *
 * @note The imaginary part represents the coefficient of i (√-1)
 */
typedef struct complex
{
    double real;
    double imaginary;
} complex;

complex *comp_vars[6]; /* Definition for A-F (6 variables) */

/**
 * @brief Assigns values to a complex number
 * @param num Pointer to the complex number to modify
 * @param real_part The real part value to assign
 * @param imaginary_part The imaginary part value to assign
 */
void read_comp(complex *num, double real_part, double imaginary_part);

/**
 * @brief Prints a complex number in the format (a + bi)
 * @param num The complex number to print
 */
void print_comp(complex *num);

/**
 * @brief Initializes a complex number to zero (0 + 0i)
 * @param num Pointer to the complex number to initialize
 */
void init_comp(complex *num);

/**
 * @brief Adds two complex numbers and prints the result
 * @param A First complex number operand
 * @param B Second complex number operand
 */
void add_comp(complex *A, complex *B);

/**
 * @brief Subtracts two complex numbers and prints the result
 * @param A First complex number operand
 * @param B Second complex number operand to subtract from A
 */
void sub_comp(complex *A, complex *B);

/**
 * @brief Multiplies a complex number by a real number and prints the result
 * @param A The complex number to multiply
 * @param m The real number multiplier
 */
void mult_comp_real(complex *A, double m);

/**
 * @brief Multiplies a complex number by an imaginary number and prints the result
 * @param A The complex number to multiply
 * @param m The imaginary number multiplier
 */
void mult_comp_img(complex *A, double m);

/**
 * @brief Multiplies two complex numbers and prints the result
 * @param A First complex number operand
 * @param B Second complex number operand
 */
void mult_comp_comp(complex *A, complex *B);

/**
 * @brief Calculates and prints the absolute value of a complex number
 * @param A The complex number to calculate absolute value for
 */
void abs_comp(complex *A);


/**
 * Converts a character representation to a complex number.
 * 
 * @param ch Pointer to a character string containing a single character ('A' through 'F')
 *           representing one of the predefined complex variables
 * @return The corresponding complex number if valid input, or a complex number
 *         initialized to 0+0i if invalid input
 * 
 * The function validates the input character and converts it to the corresponding
 * complex variable stored in the comp_vars array. Valid inputs are uppercase
 * letters 'A' through 'F'. For invalid inputs (NULL pointer or character outside
 * the valid range), returns a complex number initialized to zero.
 */
complex *char_to_comp(char *ch);

#endif /* COMPLEX_H */