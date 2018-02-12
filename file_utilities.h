#ifndef _LifeGame_
#define _LifeGame_
#include <stdlib.h>
#include <stdio.h>
//probably wrong but i got mad and "fixed" it -emy
//int read_file( char* filename, char** buffer);
//I fixed it by putting it back

/**This method is used to load a file
 *
 *@param fileName is the string for the name of the file that we are trying to load.
 *@param buffer is a pointer to a pointer to a character array which we use to properly load the board.
 *
 *@return int returns the size of the board.
 * */
int read_file(const char* filename, char** buffer);

/**This method is used to save a file
 *
 *@param filename is the string for the name that the file will be saved under.
 *@param buffer is the pointer to the character array (board) that we are saving.
 *@param size is the size of the board.
 *
 *@return int returns whether or not the method ran successfully (1)
 * */
int write_file( char* filename, char *buffer, int size);






#endif
