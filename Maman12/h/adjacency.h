/*
 * Maman 12
 *
 * This file includes the main method.
 * 
 * Yonatan Schrift
 * 18/12/2024
 */

#ifndef ADJACENCY_H
#define ADJACENCY_H

#define N 4

enum boolean {
    FALSE = 0,
    TRUE = 1
};
typedef int adjmat[N][N];

/**
 * @brief Main program to work with adjacency matrix operations
 *
 * This program performs the following operations:
 * 1. Reads and displays an adjacency matrix
 * 2. Performs a single path check between two nodes
 * 3. Continuously checks paths between pairs of nodes until terminated
 *
 * The program is terminated when the user inputs (-1,-1) or EOF.
 *
 * @return int Returns 0 on successful execution
 */
int main(void);

#endif /* ADJACENCY_H */