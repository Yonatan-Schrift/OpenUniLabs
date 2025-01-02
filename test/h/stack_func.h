
#ifndef STACK_FUNC_H
#define STACK_FUNC_H

#define MAX 20
#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'


/**
 * @brief Structure representing a stack.
 */
typedef struct
{
  char stack[MAX]; /**< Array to hold stack elements. */
  int top;        /**< Index of the top element in the stack. */
} Stack;

/**
 * @brief Push a value to the stack.
 * 
 * @param value The value to push to the stack.
 */
void push(double value);

/**
 * @brief Pop the top element from the stack.
 * 
 * @return The top element of the stack.
 */
double pop();





#endif /*  STACK_FUNC_H */