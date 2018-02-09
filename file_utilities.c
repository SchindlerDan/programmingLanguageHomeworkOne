//I forgot that we needed to include the .h file -Dan
#include "file_utilities.h"

int read_file( char* filename, char** buffer){
    //used some code from CIS 241
    FILE *in;
int i = 0;	
//TODO add a input to take in a string
	printf("Do we make it to the load function?");
    in = fopen(filename, "r");
    printf("%s is the name of the file\n", filename);
	if(in == NULL)
    {
        printf("This file could not be found");
        exit(1);
    }
    int columns = 0;
    int rows = 0;
    //fscanf(in,"%d", &columns);
    fscanf(in, "%c ", &rows);
	fscanf(in, "%c ", &columns);
	
	
	printf("There are %d rows and %d columns in your file \n", rows, columns);
    //https://stackoverflow.com/questions/10575544/difference-between-array-type-and-array-allocated-with-malloc
    //used Stack Overflow to decide how to create the 2d arrayi
    char* map = malloc(rows * columns * sizeof(char));
	for(i = 0; i < (rows * columns); i++){
		map[i] = 'x';
	}
    //char map[rows][columns];
    int x = 0;
    int y = 0;
	printf("hello there\n");
    //aasked Brendon Murthum and Tanner Gibson about fscanf
    //went to tutorialspoint.com to confirm that C for loops are created like java and C++ for loops
    int test = 0;
	for(x = 0; x < columns; x++ )
    {
        for(y = 0; y < rows; y++)
        {
            fscanf(in, "%c ", &map[(y * rows) + x]);
        	printf("%c\n", map[(y * rows) + x]);
	}
    }
	printf("howdy friendo\n");
    *buffer = malloc(sizeof(char) * (rows * columns));
	printf("greetings comrade\n");	
	for(i = 0; i < rows * columns; i++){
		*buffer[i] = 'x';
	}
    	for(i = 0; i < (rows * columns); i +=1){
		//printf("%c\n", *buffer[i]);
		printf("%c\n", map[i]);
		*buffer[i] = map[i];
	printf("%d\n", i);
	}
	free(map);

//    for(x = 0; x < rows; x++)
//    {
//        for(y = 0; y < columns; y++)
//        {
//            printf("%c", map[(x * rows) + y]);
//        }
//
//    }
    return 0;
}


int write_file( char* filename, char *buffer, int size)
{
    //when we call this method from our main, we need to construct a new array in the main that includes the row and column numbers as the first two characters
    FILE *out;
	printf("about to save a file of size %d\n", size);
    //Once again used some code from a CIS 241 assignment
    out =fopen(filename, "w");
	printf("Do we make it to the save function?\n");
    if(out == NULL)
    {
        printf("File could not be found or created");
    }

    int i = 0;

    for(i = 0; i < size; i++)
    {
        fprintf(out, "%c ", buffer[i]);
        //fprintf(out, " ");
    }
return 0;
}
