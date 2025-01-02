/*
 * Maman 12
 *
 * This file includes the main method.
 * 
 * Yonatan Schrift
 * 18/12/2024
 */

#include "../h/adjacency.h"
#include "../h/user_methods.h"

#include <stdio.h>


int main(void) {
    /* Initializing variables that will be used in the method. */
    adjmat mat;
    int ans;

    readAndDisplayMat(mat);
    
    printf("\nHey user! now input 2 values from the tree, and the program will check if the first one is a root for the second. \n");
    printf("The output is: %d\n", readAndCheckPath(mat));

    printf("\nHello again user! For this final part of the assignment, the program will do the same thing as before, but infinitely!");
    printf("\nThat means the program will scan for u and v, until you input (-1,-1) or EOF.\n");
    /* Continuesly scans until the method fails (EOF or (-1,-1)). */
    while((ans = readAndCheckPath(mat))!= -1) {
        printf("The output is: %d\n\n", ans);
    }
    
    printf("\n\nGoodbye!\n");

    return 0;
}




