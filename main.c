#include <stdio.h>
#include <stdlib.h>
#include "file_utilities.h"
#include "simLogic.h"
int main(int argc, const char** argv)
{

    int numRow = argv[1];
    int numCol = argv[2];



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
//to see if it starts on a load
    if(argc>2)
    {
        //I wrote this  -emy
      const char* filename= argv[3];
        
        read_file(filename, boardTotal);
    }else{
    printf("Please enter the number of rows you would like");
    scanf("%d", &rows);
    printf("Please enter the number of columns you would like");
    scanf("%d", &columns);
    boardIndividual = malloc(rows * columns * sizeof(char));
    *boardTotal = boardIndividual;
    }
    int quit=0;
    while(quit==0)
    {
        //char choice;
        int times=0;
        //check for next input
        printf("q to quit, w to write, a to add a living cell, r to run one time, m to run many times");
        //take input entered
        //stack overflow to figure out how to ignore extra white space
        //https://stackoverflow.com/questions/20712572/how-to-ignore-whitespaces-in-fscanf
        scanf(" %c", &choice);
        //do the selection
       if(choice=='q')
        {
            printf("bye");
            quit=1;
        }
        else if(choice =='r'){
            printf("hi");
        }else if(choice == 'm'){
	    printf("hello there");
	}else if(choice == 'w'){
		printf("salutations friend");
	}else if(choice == 'a'){
		printf("Let us get this party started");
	}


        for(times;times>0;times--)
        {
            //for loop for checking death rates and breeding rates
        }

    }


}
