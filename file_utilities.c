//I forgot that we needed to include the .h file -Dan
#include "file_utilities.h"

int read_file( char* filename, char** buffer){
    //used some code from CIS 241
    FILE *in;
int i = 0;
	
	free(*buffer);	
//TODO add a input to take in a string
	printf("\nDo we make it to the load function?\n");
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
	printf("\n the address of *buffer is %u\n", *buffer);	
	//free(*buffer);	
	printf("There are %d rows and %d columns in your file \n", rows, columns);
    	int size = rows * columns;
	*buffer = malloc((size + 2) * sizeof(char));
	printf("\n malloc just called. address is now %u\n", *buffer);
	(*buffer)[0] = rows;

	printf("\n saved rows = %d\n", rows);
	(*buffer)[1] = columns;
	printf("\n saved columns = %d\n", columns);

	for(i = 0; i < size; i++){
//		printf("\n inside for loop, iteration %d\n", i);
		fscanf(in, "%d", (*buffer)[i + 2]);
		printf("%c is the thing in spot %d\n", (*buffer)[i + 2], i);
	}
	printf("\n finished load for loop\n");





	//https://stackoverflow.com/questions/10575544/difference-between-array-type-and-array-allocated-with-malloc
    //used Stack Overflow to decide how to create the 2d arrayi
    /**
	char* map = malloc(rows * columns * sizeof(char*));
	//*buffer = malloc(rows * columns * sizeof(char));
	for(i = 0; i < (rows * columns); i++){
		map[i] = 'x';
	}
    //char map[rows][columns];
    int x = 0;
    int y = 0;
	printf("hello there\n");
	printf("\nAddress of *buffer is %u", *buffer);
    //aasked Brendon Murthum and Tanner Gibson about fscanf
    //went to tutorialspoint.com to confirm that C for loops are created like java and C++ for loops
    int test = 0;
	for(x = 0; x < columns; x++ )
    {
        for(y = 0; y < rows; y++)
      {
	//       	fscanf(in, "%c ", &(map[(y * rows) + x]));
//		fscanf(in, "%c ", (*buffer)[(y * rows) + x]);
        	printf("%c\n", map[(y * rows) + x]);
//      		printf("%c ", (*buffer)[(y * rows) + x]);
	}
    }

	printf("\nhowdy friendo\n");
	//*buffer = map;
	printf("\n in file utilities, final address of *buffer is %u and map is %u\n", *buffer, map);
    //*buffer = malloc(sizeof(char) * (rows * columns));
	printf("greetings comrade\n");	
//	for(i = 0; i < rows * columns; i++){
//		*buffer[i] = 'x';
//	}
 	for(i = 0; i < (rows * columns); i +=1){
		//printf("%c\n", *buffer[i]);
//		printf("%c", map[i]);
		(*buffer)[i] = map[i];
//	printf(" %d\n", i);
	}
//	free(map);

//    for(x = 0; x < rows; x++)
//    {
//        for(y = 0; y < columns; y++)
//        {
//            printf("%c", map[(x * rows) + y]);
//        }
//
//    }
 */
    return 1; //(rows * columns);
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
