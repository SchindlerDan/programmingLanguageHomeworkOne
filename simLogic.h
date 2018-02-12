//this file will be the library that holds the simulation logic header
//
#ifndef _LifeGame_
#define _LifeGame_
#include <stdio.h>
#include <stdlib.h>
//#include"simLogic.c"

/**Simulate is the method that actually runs the logic
 *
 *@param boardx is the pointer to the board. The board is a character array.
 *@param rows is used alongside columns to perform the logic required to check for nearby living cells
 *@param columns is used alongside rows to perform the logic required to check for nearby living cells
 * 
 * @return int Returns whether the method ran successfully (1)
 * */
int simulate(char* boardx, int rows, int columns);

/**Displays the board in its current state
 *
 *
 *@param board the pointer tot he board that is to be displayed. The board is a character array.
 *@param rows is used alongside columns to perform the logic required to properly display the correct number of rows anc columns.
 *@param columns is used alongside rows to perform the logic required to properly display the correct number of rows and columns.
 * 
 *@return int returns whether or not the method ran successfully (1)
 *
 * */
int displayBoard(char* board, int rows, int columns);
#endif
