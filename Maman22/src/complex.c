/*
 * Maman 22
 * Yonatan Schrift
 * 23.12.2024
 */

#include "../h/complex.h" /* complex type */
#include "../h/mathFuncs.h" /* getSign() method */
#include "../h/argumentFuncs.h"  
#include "../h/commandFuncs.h" /* Used for error codes */
#include <math.h> /* pow(), sqrt() */
#include <stdio.h>

complex *comp_vars[6]; /* Definition for A-F (6 variables) */

void init_comp(complex *num)
{
    num->imaginary = 0.0;
    num->real = 0.0;
}

void read_comp(complex *num, double real_part, double imaginary_part)
{
    num->real = real_part;
    num->imaginary = imaginary_part;
}

void print_comp(complex *num)
{
    char operand = '+';
    operand = getSign(num->imaginary);

    printf("%.2f %c (%.2f)i\n\n", num->real, operand, fabs(num->imaginary));
}

void add_comp(complex *A, complex *B)
{
    complex ans;

    read_comp(&ans, (A->real + B->real), (A->imaginary + B->imaginary));

    print_comp(&ans);
}

void sub_comp(complex *A, complex *B)
{
    complex ans;

    read_comp(&ans, (A->real - B->real), (A->imaginary - B->imaginary));

    print_comp(&ans);
}

void mult_comp_real(complex *A, double m)
{
    complex ans;
    
    read_comp(&ans, (m * A->real), (m * A->imaginary));

    print_comp(&ans);
}

void mult_comp_img(complex *A, double m)
{
    complex ans;

    read_comp(&ans, -(m * A->imaginary), (m * A->real));

    print_comp(&ans);
}

void mult_comp_comp(complex *A, complex *B)
{
    complex ans;
    double realPart, compPart;

    realPart = ((A->real * B->real) - (A->imaginary * B->imaginary));
    compPart = ((A->real * B->imaginary) + (A->imaginary * B->real));

    read_comp(&ans, realPart, compPart);

    print_comp(&ans);
}

void abs_comp(complex *A)
{
    double ans;
    double realPart, imgPart;

    realPart = pow(A->real, 2);
    imgPart = pow(A->imaginary, 2);

    ans = sqrt(realPart + imgPart);

    printf("%.2f\n\n", ans);
}

complex *char_to_comp(char *ch)
{
    int index;

    /* Validate input */
    if (is_complex(ch) == INVALID_COMP)
    {
        return NULL;
    }

    /* Convert char to array index (A=0, B=1...) */
    index = ch[0] - 'A';

    return comp_vars[index];
}
