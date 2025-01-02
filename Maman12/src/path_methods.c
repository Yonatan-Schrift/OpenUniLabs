/*
 * Maman 12
 *
 * This file includes methods for finding a path between 2 nodes in a tree.
 * 
 * Yonatan Schrift
 * 18/12/2024
 */

#include "../h/path_methods.h"


int path(adjmat mat, int u, int v)
{
    int i = 0;
    
    return recursePath(mat, u, v, i);
}


int recursePath(adjmat mat, int u, int v, int i)
{   
    /* Edge case: u or v are outside the matrix - return FALSE */
    if((u >= N) || (v >= N)) {
        return FALSE;
    }
    /* Edge case: u and v are the same - return TRUE */
    if(u == v) {
        return TRUE;
    }
    /* Base case: u and v are connected. */
    if (mat[u][v] == 1)
    {
        return TRUE;
    }

    /* Base case: there is no where to continue searching - u and v are not connected. */
    if (i >= N)
    {
        return FALSE;
    }

    /* If i is a root for v, goes up in the tree to the next node (i). */
    if (mat[i][v] == 1)
    {
        return recursePath(mat, u, i, 0);
    }

    /* Moves i by one. */
    return recursePath(mat, u, v, i + 1);
}