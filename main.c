#include <stdio.h>
#include <stdlib.h>
#include "file_utilities.h"
#include "simLogic.h"

int main(int argc, const char** argv)
{



    //used code from an assignment from CIS 241
    
    
    /** next three variables are pointers for the board*/
    char** boardTotal;
    char* boardIndividual;
    char* boardBackup;
    /**Used for user input for desired file names. Used in save and load. */
    char* filename;
    /**Used to track user choice: saving, adding a cell, quiting, or running the simulation */
    char choice;
    /**Next two variables hold the number of rows and columns in the board respectively */
    int rows;
    int columns;
    /**Used later on for a loop */
    int i;
    /**Tracks rows * columns */
    int size;
    /**Tracks whether the user has chosen to quit the program or not */
    int quit;
    /**Tracks the number of times the simulation should run */
    int times;

    /**The next two variables are used to track the x and y coordinate of a living cell the user wishes to add */
    int x;
    int y;
    //to see if it starts on a load
    if(argc>1)
    {

        
        boardTotal = malloc(sizeof(char*));
        filename = argv[1];
        boardBackup = malloc(sizeof(char));

        *boardTotal = boardBackup;
        
        size = read_file(filename, boardTotal);

        
        rows = (*boardTotal)[0];
        columns = (*boardTotal)[1];
        size = rows * columns;
        boardIndividual = malloc(size * sizeof(char));
	//This loop writes from the loaded board onto our simulation board.
        for(i = 0; i < size; i++)
        {

            boardIndividual[i] = (*boardTotal)[i + 2];
        }

        displayBoard(boardIndividual, rows, columns);
        //free(filename);
        free(boardBackup);
        free(boardTotal);
    }
    else if(argc > 2)
    {
        /** 
        *Went to: 
        *
        *https://stackoverflow.com/questions/523237/how-to-read-in-numbers-as-command-arguments
        *and 
        *https://www.tutorialspoint.com/c_standard_library/c_function_atoi.html
        *and 
        *https://stackoverflow.com/questions/12091059/how-to-parse-integer-command-line-arguments-in-c
        * */
        //rows = atoi(argv[1]);
        //columns = atoi(argv[2]);
        sscanf(argv[1], "%d", &rows);
        sscanf(argv[2], "%d", &columns);
        size = rows * columns;
        printf("\nThe dimensions of your board are %d by %d\n", rows, columns);
        boardIndividual = malloc(size * sizeof(char));
        for(i = 0; i < size; i++)
        {
            boardIndividual[i] = 120;
        }
        displayBoard(boardIndividual, rows, columns);
    
    }
    else
    {
        size = 0;
        printf("Please enter the number of rows you would like: \n");
        scanf("%d", &rows);
        printf("Please enter the number of columns you would like: \n");
        scanf("%d", &columns);
        size = rows * columns;
        printf("%d %d are the dimensions of your board", rows, columns);
        boardIndividual = (char *)malloc(size * sizeof(char));
        //Initializes the board to all dead cells.
        for(i = 0; i < size; i++)
        {
            boardIndividual[i] = 120;

        }
        displayBoard(boardIndividual, rows, columns);
    }


    quit = 0;

    while(quit == 0)
    {

        times = 0;
        //check for next input
        printf("\nq to quit, w to write, a to add a living cell, r to run one time, m to run many times: \n");
        //take input entered
        //stack overflow to figure out how to ignore extra white space
        //https://stackoverflow.com/questions/20712572/how-to-ignore-whitespaces-in-fscanf
        scanf(" %c", &choice);
        
        if(choice == 'q')
        {
            printf("bye\n");
            quit = 1;
            
        }
        else if(choice == 'r')
        {
            
            times = 1;
        }
        else if(choice == 'm')
        {
            
            printf("enter number of generations: \n");
            scanf("%d", &times);
            
        }
        else if(choice == 'w')
        {
            //used https://stackoverflow.com/questions/6282198/reading-string-from-input-with-space-character
            filename = malloc(sizeof(char) * 100);
            

            printf("please type in the file name complete with file type\n");
            scanf("%s", filename);
            boardBackup = malloc(sizeof(char) * ((size) + 2));
            printf("You save a %d by %d map\n", rows, columns);
            boardBackup[0] = rows;
            boardBackup[1] = columns;
            for(i = 0; i < (size); i++)
            {
                boardBackup[i + 2] = boardIndividual[i];
            }
            write_file(filename, boardBackup, (size) + 2);
            printf("saving complete");
            free(boardBackup);
            free(filename);
        }
        else if(choice == 'a')
        {
                    
            printf("\nPlease enter the X coordinate\n");
            scanf("%d", &x);
            printf("\nPlease enter the Y coordinate\n");
            scanf("%d", &y);
            boardIndividual[(y * columns) + x] = 'o';
            displayBoard(boardIndividual, rows, columns);
        }
        //Runs the simulation for the number of generations that the user entered earlier.
        for(times; times>0; times--)
        {

            simulate(boardIndividual, rows, columns);

            displayBoard(boardIndividual, rows, columns);
        }
        printf("\n");
        //displayBoard(boardIndividual, rows, columns);
    }

    free(boardIndividual);
    free(boardTotal);
}
