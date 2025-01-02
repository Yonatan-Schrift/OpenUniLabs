/*
 * Maman 12
 *
 * This file includes methods that recieve user input and process it.
 * 
 * Yonatan Schrift
 * 18/12/2024
 */


#include "../h/user_methods.h"
#include "../h/path_methods.h"

#include <stdio.h>
#include <ctype.h>


void readAndDisplayMat(adjmat mat) {
    /* i: column index, j: row index */
    int i, j;
    char current;
    i = 0, j = 0;

    /* Prompt user for matrix input */
    printf("Hey user! input the values for an adjacency matrix with the size of %d.\n", N);
    printf("You can input the values in any format you want, only the digits will be read. \n");
    printf("Don't forget! The digits need to be 1 or 0.\n\n");

    /* Read matrix values from input */
    while(j < N) {
        current = getchar();
    
        /* Skip non-digit characters */
        if (!isdigit(current)) {
            printf("NOT A DIGIT! only enter 1 or 0. \n");
            continue;
        }
        /* Skip any value that isn't 1/0. */
        if(current != '1' && current != '0') {
            printf("You can only input 1 or 0 into the matix, otherwise it might not work D:\n");
            continue;
        }
        
        /* Convert ASCII digit to integer and store */
        mat[j][i] = current - '0';

        /* Move to next position */
        i++;

        /* Move to next row when current row is full */
        if(i >= N) {
            i = 0;
            j++;
        }
    }

    /* Display the completed matrix */
    for(i = 0; i < N; i++) {
        printf("| ");
        for(j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("|\n");
    }
}


int readAndCheckPath(adjmat mat) {

    /* u: the starting node, v: destination node (root) */
    int u, v;
    /* stores return value from scanf for error checking */
    int result;

    /* Scans for u, v from the user, also checks for EOF. */
    printf("Enter u (the root): \n");
    result = scanf("%d", &u);
    if (result == EOF) {
        return -1;
    }
    printf("Enter v (the node): \n");
    result = scanf("%d", &v);
    if (result == EOF) {
        return -1;
    }

    /*  Check termination condition (-1,-1) and validate matrix bounds. */
    if((u == -1 && v == -1)) {
        return -1;
    }
    printf("Nicely done! u = %d, v = %d\n", u, v);
    /* Check if path exists from u to v using adjacency matrix */
    return path(mat, u, v);
}
