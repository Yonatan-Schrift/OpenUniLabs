/**
 * Maman 22
 * 
 * @file complex.h
 * @brief Header file containing declarations for complex number operations
 * 
 * This file contains the declarations of functions and data structures
 * for working with complex numbers. The complex number data type and
 * related operations are defined here.
 * 
 * @author Yonatan Schrift
 * @date 23.12.2024
 */

#ifndef COMPLEX_H
#define COMPLEX_H

/**
 * @brief Represents a complex number with real and imaginary parts
 *
 * A structure that defines a complex number containing two components:
 * a real part and an imaginary part, both represented as double precision
 * floating-point numbers.
 *
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

#endif /* COMPLEX_H */