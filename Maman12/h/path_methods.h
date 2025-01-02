/*
 * Maman 12
 *
 * This file includes methods for finding a path between 2 nodes in a tree.
 * 
 * Yonatan Schrift
 * 18/12/2024
 */

#ifndef PATH_METHODS_H
#define PATH_METHODS_H

#include "../h/adjacency.h"

/**
 * @brief Determines if there exists a path between two nodes in a tree.
 *
 * @param mat The adjacency matrix representing the tree
 * @param u The destination root index
 * @param v The starting node index
 * @return TRUE if a path exists from node v to node u, FALSE otherwise
 *
 * @note uses the recursive method recursePath() for searching in the matrix.
 */
int path(adjmat mat, int u, int v);

/**
 * @brief Recursively searches for a path between two nodes in a tree.
 * 
 * @param mat The adjacency matrix representing the tree
 * @param u The destination node
 * @param v The source node
 * @param i The current length of the path being checked
 * @return Returns TRUE if a path exists between u and v, FALSE otherwise
 */
int recursePath(adjmat mat, int u, int v, int i);

#endif /* PATH_METHODS_H */