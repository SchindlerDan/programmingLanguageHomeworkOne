#include <stdio.h>
#include <stdlib.h>
#include "file_utilities.h"
#include "simLogic.h"
#include "simLogic.c"
int main(int argc, const char** argv)
{

    //int numRow = (int)argv[1];
    //int numCol = (int)argv[2];



    //used code from an assignment from CIS 241
    FILE *in, *out;
    char ch;
    //next three variables are pointers for the board as well as the previous board
    char** boardTotal;
    char* boardIndividual;
    char* boardBackup;
    char choice;
    int rows;
    int columns;
	int i;
	boardTotal = malloc(1 * sizeof(char*));
//to see if it starts on a load
    if(argc>2)
    {
        //I wrote this  -emy
      char* filename = argv[1];

        read_file(filename, boardTotal);
    }else{
    printf("Please enter the number of rows you would like: \n");
    scanf("%d", &rows);
    printf("Please enter the number of columns you would like: \n");
    scanf("%d", &columns);
    boardIndividual = malloc(rows * columns * sizeof(char));
    *boardTotal = boardIndividual;
    	for(i = 0; i < rows * columns; i++){
		boardIndividual[i] = 'x';
		printf("%d ", i);
	}
	}	
    int quit = 0;
    while(quit == 0)
    {
        //char choice;
        int times=0;
        //check for next input
        printf("q to quit, w to write, a to add a living cell, r to run one time, m to run many times, l to load: \n");
        //take input entered
        //stack overflow to figure out how to ignore extra white space
        //https://stackoverflow.com/questions/20712572/how-to-ignore-whitespaces-in-fscanf
        scanf(" %c", &choice);
        //do the selection
       if(choice=='q')
        {
            printf("bye\n");
            quit=1;
        }
        else if(choice =='r'){
            printf("hi");
            times=1;
        }else if(choice == 'm'){
            //it wont just take times but it will work if i do this
            int input;
            printf("enter number of generations: \n");
            scanf("%d", &input);
            times=input;
	}else if(choice == 'w'){
		printf("salutations friend");
	}else if(choice == 'a'){
		printf("Let us get this party started");
	}else if(choice == 'l'){
		printf("Hello friendo");
		
	}


        for(times;times>0;times--)
        {
		printf("We made it to the loop");
              simulate(boardTotal,rows,columns);
            //for loop for checking death rates and breeding rates
        }
	displayBoard(boardTotal, rows, columns);

    }

	free(boardIndividual);
	free(boardTotal);
}
