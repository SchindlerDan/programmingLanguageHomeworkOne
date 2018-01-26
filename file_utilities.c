//I forgot that we needed to include the .h file -Dan
#include "file_utilities.h"


int read_file( char* filename, char** buffer){
	//used some code from CIS 241
	FILE *in;

	in = fopen("blank1010.txt", "r");
	if(in == NULL){
		printf("This file could not be found");
		exit(1);
	}
	int columns;
	int rows;
	fscanf(in,"%d", &columns);
	fscanf(in, "%d", &rows);

	//https://stackoverflow.com/questions/10575544/difference-between-array-type-and-array-allocated-with-malloc
	//used Stack Overflow to decide how to create the 2d arrayi
	char* map = malloc(rows * columns * sizeof(char));

	//char map[rows][columns];
	int x;
	int y;
	//aasked Brendon Murthum and Tanner Gibson about fscanf
	//went to tutorialspoint.com to confirm that C for loops are created like java and C++ for loops
	for(x = 0; x < rows; x++ ){
		for(y = 0; y < columns; y++){
			fscanf(in, "%c", map[(x * rows) + y]);
		}
	}

	free(*buffer);
	*buffer = map;

	for(x = 0; x < rows; x++){
		for(y = 0; y < columns; y++){
			printf("%c", map[(x * rows) + y]);
		}
	
	}

}



int write_file( char* filename, char *buffer, int size){




}
