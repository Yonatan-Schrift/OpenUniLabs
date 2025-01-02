/*
  Created by yonatan on 11/13/24.
*/

#ifndef Q2_BIT_UTILS_H
#define Q2_BIT_UTILS_H
#define BIT_SIZE (sizeof(unsigned long) * 8) /* Saving the bit size. */

/*  A method to convert an unsigned long to binary in the form of string. 
 * Usage: 
 *   unsigned long num = 1;
 *   char binary[BIT_SIZE + 1];
 * 
 *   convertLongToBinary(num, binary);
 *  
 * Output:
 *   num = 00000000000000000000000000000001
 */
void convertLongToBinary(unsigned long n, char *binary);

#endif
