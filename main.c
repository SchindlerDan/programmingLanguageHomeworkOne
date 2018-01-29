#include <stdio.h>
#include <stdlib.h>
#include "file_utilities.h"

int main(int argc, const char** argv)
{

    int numRow = argv[1];
    int numCol = argv[2];



    //used code from an assignment from CIS 241
    FILE *in, *out;
    char ch;
//to see if it starts on a load
    if(argc>3||argc==2)
    {
        //I wrote this  -emy
      const char* filename= argv[3];
        char** buffer;
        read_file(filename,buffer);
    }
    else
    {
        //create a blank file of specifed size
    }
    //game loop
    int quit=0;
    while(quit==0)
    {
        char choice;
        int times=0;
        //check for next input
        printf("q to quit, w to write, l to load, r to run once, m to run many");
        //take input entered
        //stack overflow to figure out how to ignore extra white space
        //https://stackoverflow.com/questions/20712572/how-to-ignore-whitespaces-in-fscanf
        scanf(" %c",&choice);
        //do the selection
       if(choice=='q')
        {
            printf("bye");
            quit=1;
        }
        else{
            printf("hi");
        }


        for(times;times>0;times--)
        {
            //for loop for checking death rates and breeding rates
        }

    }


}
