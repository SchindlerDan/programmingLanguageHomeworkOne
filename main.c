#include <stdio.h>
#include <stdlib.h>
#include "file_utilities.h"
#include "simLogic.h"

int main(int argc, const char** argv)
{

    //int numRow = (int)argv[1];
    //int numCol = (int)argv[2];

	printf("%d\n", argc);

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
int size;
 
	//boardTotal = malloc(1 * sizeof(char*));
//to see if it starts on a load
    if(argc>1)
    {
	
	//boardIndividual = malloc(sizeof(char) * 1);
	//boardIndividual[0] = 'x';
	boardTotal = malloc(sizeof(char*));
        //*boardTotal = boardIndividual;
	//boardIndividual = malloc(sizeof(char));
	*boardTotal = boardIndividual;
	printf("The address of *boardTotal is %u and the address of boardIndividual is %u\n", *boardTotal, boardIndividual);
	//printf("\n The address of the &boardIndividual is %u\n", &boardIndividual);
	//I wrote this  -emy
      char* filename = argv[1];
	//boardTotal = malloc(sizeof(char));
	printf("\n calling read_file\n");
	printf("attempting to read file %s\n", filename);
        size = read_file(filename, boardTotal);
	//size = read_file(filename, &boardIndividual);
	printf("\nread file done being called\n");
	//boardIndividual = *boardTotal;
	printf("\n final address of boardIndividual is %u\n", boardIndividual);
    }else{
	size = 0;
    printf("Please enter the number of rows you would like: \n");
    scanf("%d", &rows);
    printf("Please enter the number of columns you would like: \n");
    scanf("%d", &columns);
	size = rows * columns;
	printf("%d %d are the dimensions of your board", rows, columns);
    boardIndividual = (char *)malloc(size * sizeof(char));
    //boardTotal = &boardIndividual;
  	for(i = 0; i < size; i++){
		boardIndividual[i] = 120;
//		printf("%d \n", i);
//		printf("%c is the character in that index\n", boardIndividual[i]);
//		//printf("%u is the address of that index\n", boardIndividual[i]);
	}
	
	}
	printf("\n%d\n",size);
	
	int quit = 0;
    //int times = 0;
    //for(times = 0; times < rows * columns; times++){
//		if(times % (columns) == 0){
//			printf("\n");
//		}
//		printf("%c ", boardIndividual[times]);

//	}


    while(quit == 0)
    {
        //char choice;
        int times=0;
        //check for next input
        printf("\nq to quit, w to write, a to add a living cell, r to run one time, m to run many times, l to load: \n");
        //take input entered
        //stack overflow to figure out how to ignore extra white space
        //https://stackoverflow.com/questions/20712572/how-to-ignore-whitespaces-in-fscanf
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
            //printf("hi");
            times=1;
        }else if(choice == 'm'){
            //it wont just take times but it will work if i do this
            int input;
            printf("enter number of generations: \n");
            scanf("%d", &input);
            times=input;
	}else if(choice == 'w'){
		//used https://stackoverflow.com/questions/6282198/reading-string-from-input-with-space-character   
		char* fileName = malloc(sizeof(char) * 100);
		//fget(fileName, 100, stdin);
		
		printf("please type in the file name complete with file type\n");	
		scanf("%s", fileName);
		boardBackup = malloc(sizeof(char) * ((size) + 2));
		printf("You save a %d by %d map\n", rows, columns);
		boardBackup[0] = rows;
		boardBackup[1] = columns;
		for(i = 0; i < (size); i++){
			boardBackup[i + 2] = boardIndividual[i];
		}
		write_file(fileName, boardBackup, (size) + 2);
		printf("salutations friend, saving complete");
		
		free(fileName);
	}else if(choice == 'a'){
		int x;
		int y;
	//	char cont = 'y';
	//	while('y' == cont || 'Y' == cont){
			printf("\nPlease enter the X coordinate\n");
			scanf("%d", &x);
			printf("\nPlease enter the Y coordinate\n");
			scanf("%d", &y);
			boardIndividual[(y * columns) + x] = 'o';	
//			displayBoard(boardIndividual, rows, columns);
	//}	
		
//		printf("\nLet us get this party started\n");
//		displayBoard(boardIndividual, rows, columns);
	}//removed load here because we already have load as a command line input
	//else if(choice == 'l'){
	//	printf("Hello friendo");
		
	//}

        for(times;times>0;times--)
        {
		printf("\nWe made it to the loop\n");
              simulate(boardIndividual, rows, columns);
            //for loop for checking death rates and breeding rates
        }
	
	displayBoard(boardIndividual, rows, columns);
//	for(times = 0; times < rows * columns; times++){
//		if(times % (columns) == 0){
//			printf("\n");
//		}
//		printf("%c ", boardIndividual[times]);

//	}
    }

	free(boardIndividual);
	free(boardTotal);
}
