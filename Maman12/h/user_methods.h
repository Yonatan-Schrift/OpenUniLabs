/*
 * Maman 12
 *
 * This file includes methods that recieve user input and process it.
 * 
 * Yonatan Schrift
 * 18/12/2024
 */



#ifndef USER_METHODS_H
#define USER_METHODS_H

#include "../h/adjacency.h"

/**
 * @brief Reads matrix input from user and displays it.
 * 
 * The function prompts the user to enter values for each element
 * in the adjacency matrix, saves it, and then displays 
 * the complete matrix.
 *
 * @param mat The adjacency matrix to be filled and displayed
 */
void readAndDisplayMat(adjmat mat);

/**
 * @brief Reads a path from user input and checks if it's a valid path in the given adjacency matrix.
 * 
 * @note Invalid inputs and exit sequence (-1,-1 or EOF) will return -1.
 * 
 * @param mat The adjacency matrix representing the tree
 * @return TRUE if the path is valid, FALSE if invalid, -1 for exit
 */
int readAndCheckPath(adjmat mat);

#endif /* USER_METHODS_H */