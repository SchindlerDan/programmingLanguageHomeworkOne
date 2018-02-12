
#include "file_utilities.h"

int read_file( char* filename, char** buffer)
{
    //used some code from CIS 241
    /**Used to track the file we're pulling information from */
    FILE *in;
    /**Used in a loop later on */
    int i = 0;
    /**Used as in intermediate step between pulling from the file and placing data into the board */
    char temp = 'a';
    /**Next two variables track the number of columns and rows in the board */
    int columns = 0;    
    int rows = 0;
    /**Tracks size of the board */
    int size = 0;

    free(*buffer);


    in = fopen(filename, "r");
    if(in == NULL)
    {
        printf("This file could not be found");
        exit(1);
    }



    fscanf(in, "%c ", &rows);
    fscanf(in, "%c ", &columns);

    size = rows * columns;
    *buffer = malloc((size + 2) * sizeof(char));

    (*buffer)[0] = rows;


    (*buffer)[1] = columns;

    //This for loop scans in data from the loaded file and writes it to to the board.
    for(i = 0; i < size; i++)
    {

        fscanf(in, "%c ", &temp);
        (*buffer)[i + 2] = temp;
    }





    //https://stackoverflow.com/questions/10575544/difference-between-array-type-and-array-allocated-with-malloc
    //used Stack Overflow to decide how to create the 2d arrayi
    
    
    //asked Brendon Murthum and Tanner Gibson about fscanf
    //went to tutorialspoint.com to confirm that C for loops are created like java and C++ for loops
    
    
    return 1; //(rows * columns);
}


int write_file( char* filename, char *buffer, int size)
{
    /**used to write to the output file. */
    FILE *out;
    /**Used in a loop */
    int i = 0;
    
    
    //Once again used some code from a CIS 241 assignment
    out =fopen(filename, "w");
    
    if(out == NULL)
    {
        printf("File could not be found or created");
    }

    //This for loop writes each character from the board onto the file.
    for(i = 0; i < size; i++)
    {
        fprintf(out, "%c ", buffer[i]);

    }
    return 1;
}
