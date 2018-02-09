#include <stdio.h>
#include <stdlib.h>
#include "file_utilities.h"
#include "simLogic.h"

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
	//boardTotal = malloc(1 * sizeof(char*));
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
	printf("%d %d are the dimensions of your board", rows, columns);
    boardIndividual = (char *)malloc(rows * columns * sizeof(char));
    //boardTotal = &boardIndividual;
    	for(i = 0; i < rows * columns; i++){
		boardIndividual[i] = 120;
		printf("%d \n", i);
		printf("%c is the character in that index\n", boardIndividual[i]);
		//printf("%u is the address of that index\n", boardIndividual[i]);
	}
	boardIndividual[3] = 'o';
	boardIndividual[0] = 'o';
	boardIndividual[1] = 'o';
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
        i//https://stackoverflow.com/questions/20712572/how-to-ignore-whitespaces-in-fscanf
        scanf(" %c", &choice);
        //do the selection
        //
        //printf("%u is the address of our array\n", boardIndividual[0]);
	//printf("%u is the address of a deeper point in our array\n", boardIndividual[1]);
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
		fget(fileName, 100, stdin);
		
		
		scanf("%[^\n]%*c", fileName);
		boardBackup = malloc(2 + (sizeof(char) * rows * columns));
		boardBackup[0] = rows;
		boardBackup[1] = columns;
		for(i = 0; i < (rows * columns); i++){
			boardBackup[i + 2] = boardIndividual[i];
		}
		write_file(fileName, boardBackup, rows * columns);
		printf("salutations friend, saving complete");
	}else if(choice == 'a'){
		int x;
		int y;
		char cont = 'y';
		while('y' == cont || 'Y' == cont){
			printf("Please enter the X coordinate");
			scanf("%d", &x);
			printf("Please enter the Y coordinate");
			scanf("%d", &y);
			boardIndividual[(y * columns) + x] = 'o';	
	}	
		
		printf("Let us get this party started");
		displayBoard(&boardIndividual, rows, columns);
	}//removed load here because we already have load as a command line input
	//else if(choice == 'l'){
	//	printf("Hello friendo");
		
	//}


        for(times;times>0;times--)
        {
		printf("We made it to the loop\n");
              simulate(&boardIndividual, rows, columns);
            //for loop for checking death rates and breeding rates
        }
	//displayBoard(&boardIndividual, rows, columns);
	for(times = 0; times < rows * columns; times++){
		if(times % (columns) == 0){
			printf("\n");
		}
		printf("%c ", boardIndividual[times]);
	
	}
    }

	free(boardIndividual);
	free(boardTotal);
}
