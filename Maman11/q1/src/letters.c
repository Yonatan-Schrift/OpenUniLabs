/*
 * Created by yonatan on 7/11/24.
 * Maman 11, Q1
 */

#include <stdio.h>  /* used for input and output */
#include <ctype.h>  /* used for character manipulation */

#define TRUE 1
#define FALSE 0
#define QUOTE_CHAR '\"'
#define PERIOD_CHAR '.'

/*
 * The main method, it scans char by char, changes it following the 5 given rules and prints it.
 *
 * RULES:
 * 1. The first letter of a sentence must be uppercase.  :D
 * 2. Text inside quotes must be uppercase.              :D
 * 3. Every other text must be lowercase.                :D
 * 4. Digits are not printed.                            :D
 * 5. Any other ascii character is left as is.           :D
*/
int main(void)
{
    int sentenceStart = TRUE; /* the index of the start of the sentence. */
    int inQuote = FALSE; /* a flag for when the program is inside a quote. */
    char ch; /* the character currently being read from the input. */

    printf("Hey user! enter some text: \n\n");

    /* Creates the string by saving it one character after another, into a character array with a dynamic length. */
    while ((ch = (char)getchar()) != EOF) {

        /* skips any digit. */
        if (isdigit(ch)) {
            continue;
        }

        /* the first character in a sentence should be uppercase if it's a letter. */
        else if (sentenceStart == TRUE) {
            sentenceStart = FALSE;

            /* if the character is a letter, make it uppercase. */
            if (isalpha(ch)) {
                ch = (char)toupper(ch);
            }

            /* if the character is a quote, set inQuote. */
            else if (ch == QUOTE_CHAR) {
                inQuote = !inQuote;
            }

            /* if the character is a space, continue. */
            else if (isspace(ch)) {
                sentenceStart = TRUE;
            }
        }

        /* if the program is inside a quote, make the character uppercase. */
        else if (inQuote == TRUE) {

            if (ch == QUOTE_CHAR) {
                inQuote = FALSE;
            }
            if (islower(ch)) {
                ch = (char)toupper(ch);
            }
        }

        /* if the character is a period, set sentenceStart. */
        else if (ch == PERIOD_CHAR) {
            sentenceStart = TRUE;
        }

        /* if the character is a quote, set inQuote. */
        else if (ch == QUOTE_CHAR) {
            inQuote = TRUE;
        }

        /* every other letter is lowercase. */
        else if (isupper(ch)) {
            ch = (char)tolower(ch);
        }

        /* prints the character */
        putchar(ch);
    }
    return 0;
}
