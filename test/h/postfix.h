#ifndef POSTFIX_H
#define POSTFIX_H

/**
 * @brief Processes a postfix expression.
 *
 * This function takes a postfix expression and processes it accordingly.
 * The specific details of the processing are implementation-dependent.
 */
void processPostFix(void);

/**
 * @brief Get the next operator or numeric operand from input.
 *
 * @param s Array to store the operator or operand.
 * @return The type of the next operator or numeric operand.
 */
int getop(char s[]);

#endif /* POSTFIX_H */