//this code is for running the simulation logic
//
//
//
#include "simLogic.h"

//to help explain my logic, I talk about a 3x3 grid. This is what I mean:
// [1] [2] [3]
// [4] [5] [6]
// [7] [8] [9]



simulate(char* board, int rows, int columns){
	//char* board = *boardx;
	int size = (rows * columns);
	int i= 0;
	//this for loop will have several if statements. Each if statement is used to help prevent an index out of bounds error. example: if( i < columns) then don't check for any above cells
	int count;
	//printf("%u is the address of our board \n", **board);
	//printf("%u is the address of a farther spot in our array", *(board + 1));
	//for(i = 0; i < size; i++){
	//	printf("%d is the size\n", size);
	//}


	//printf("we made it to simLogic!\n");
	//printf("%c is the characer on the board\n", board[1]);
	for(i = 0; i < size; i++){
//		 printf("The cell is %c \n", board[i]);
	//	printf("does this print?\n");
		//used to track number of living cells nearby
		count = 0;
		//let's just get the special cases out of the way first
		//this if handles the first cell. 1 on a 3x3 grid
	//	printf("Here's the zeroth special case\n");
		if(i == 0){
	//		printf("1\n");
	//		printf("%c is the character in the board\n", board[1]);
			if(board[1] == 111){

				count++;
			}
//			printf("2\n");
			if(board[columns] == 'o'){
				count++;
			}
//			printf("3\n");
			if(board[i + columns + 1] == 'o'){//this checks diagonally down right. spot '5' on a 3x3 grid
				count++;

			}

		}
		//printf("Here's the first special case\n");
		//this is the second major special case, the last cell. cell 9 on a 3x3 grid
		else if(i == (rows * columns) - 1){
	//		printf("Here's the first special case\n");
			if(board[i - 1] == 'o'){
				count++;
			}
			if(board[i - columns] == 'o'){
				count++;
			}
			//this checks diagonally up left. spot 5 on a 3x3 grid
			if(board[i - (columns + 1)] == 'o'){
				count ++;
			}


		}
		//printf("second special case\n");
		//these ifs will check the top right spot. spot 3 on a 3x3 grid
		else if(i == columns - 1){
	//		 printf("second special case\n");
			if(board[i - 1] == 'o'){
				count++;
			}

			if(board[i + columns] == 'o'){
				count++;
			}
			//This checks Diagonally down and left. Spot 5 on a 3x3 grid
			if(board[i + (columns - 2)] == 'o'){
				count++;
			}


		}
		//printf("Third special case\n");
		//these ifs will check the bottom left spot. Spot 7 on a 3x3 grid
		else if(i == (rows * columns) - (columns - 1) - 1){
	//		printf("Third special case\n");

			if(board[i + 1] == 'o'){
                                count++;
                        }

                        if(board[i - columns] == 'o'){
                                count++;
                        }
			//this checks diagonally up and right. Spot 5 on a grid
                        if(board[i - (columns - 1)] == 'o'){
                                count++;
                        }


		}
	//	printf("Fourth Special case \n");
		//these ifs will check the rest of the top row. Spot 2 on a 3x3 grid
		else if(i > 0 && i < columns - 1){
	//		printf("Fourth Special case \n");
			if(board[i - 1] == 'o'){
                                count++;
                        }

                        if(board[i + 1] == 'o'){
                                count++;
                        }

                        if(board[i + columns] == 'o'){
                                count++;
                        }

			//this if checks diagonally down left. Spot 4 on a 3x3 grid
			if(board[i + (columns - 1)] == 'o'){
                                count++;
                        }
			//this if checks diagonally down right. Spot 6 on a 3x3 grid
                        if(board[i + columns + 1] == 'o'){
                                count++;
                        }




		}
		//printf("fifth special case \n");
		//these ifs will check the rest of the bottom row. Spot 8 on a 3x3 grid
		else if(i < columns - 1 && i > (rows * columns) - (columns + 1)){
	//		printf("fifth special case \n");

			if(board[i - 1] == 'o'){
                                count++;
                        }

                        if(board[i + 1] == 'o'){
                                count++;
                        }

                        if(board[i + columns] == 'o'){
                                count++;
                        }
			//this if checks diagonally up left, spot 4 on a 3x3 grid
			if(board[i - (columns + 1)] == 'o'){
                                count++;
                        }
			//this if checks diagonally up right, spot 6 on a 3x3 grid
                        if(board[i - (columns - 1)] == 'o'){
                                count++;
                        }




		}
		//printf("sixth special case\n");
		//these ifs will check the rest of the left hand column. Spot 4 on a 3x3 grid
		else if(i != 0 && i != size - (columns) && i % columns == 0){
	//		 printf("sixth special case\n");
			if(board[i + 1] == 'o'){
//				printf("inside if statement\n");
                                count++;
                        }
	//		printf("1\n");
                       	if(board[i + columns] == 'o'){
                               	count++;
                        }
	//		printf("2\n");
                        if(board[i - columns] == 'o'){
                                count++;
                        }
	//		printf("3\n");
			//this if checks diagonally up right, spot 2 on a 3x3 grid
			if(board[i - (columns - 1)] == 'o'){
                                count++;
                        }
	//		printf("4\n");
			//this if checks diagonally down right, spot 8 on a 3x3 grid
                        if(board[i + (columns + 1)] == 'o'){
                                count++;
                        }
	//		printf("end of sixth special case \n");

		}
		//printf("seventh special case \n");
		//these ifs will check the rest of the right hand column. spot 6 on a 3x3 grid
		else if(i % (columns - 1) == 0){
	//		printf("seventh special case \n");



                        if(board[i + columns] == 'o'){
                                count++;
                        }

                        if(board[i - columns] == 'o'){
                                count++;
                        }
			if(board[i - 1] == 'o'){
                                count++;
                        }
			//this if will check diagonally up left,  spot 2 on a 3x3 grid
			if(board[i - (columns + 1)] == 'o'){
                                count++;
                        }
			//this if will check diagonally down left, spot 8 on a 3x3 grid
			if(board[i + (columns - 1)] == 'o'){
                                count++;
                        }



		}

		//these ifs will check the rest of the board. Spot 5 on a 3x3 grid
		else{
	//		 printf("On to the body of cell\n");
			if(board[i + 1] == 'o'){
                                count++;
                        }
			if(board[i - 1] == 'o'){
                                count++;
                        }
			if(board[i + columns] == 'o'){
                                count++;
                        }
			if(board[i - columns] == 'o'){
                                count++;
                        }
			//this if checks diagonally up left, spot 1 on a 3x3 grid
			if(board[i - (columns + 1)] == 'o'){
                                count++;
                        }
			//this if checks diagonally up right, spot 3 on a 3x3 grid
			if(board[i - (columns - 1)] == 'o'){
                                count++;
                        }
			//this if checks diagonally down left, spot 7 on a 3x3 grid
			if(board[i + (columns - 1)] == 'o'){
                                count++;
                        }
			//this if checks diagonally down right, spot 9 on a 3x3 grid
			if(board[i + columns + 1] == 'o'){
                                count++;
                        }




		}



	//printf("checking if a cell should live or die\n");
	//these next two ifs decide if the cell changes states (from live to dead or the other way around)
	if(board[i] == 'o' && count > 3 || count < 2){
		board[i] = 'x';
	}else if(board[i] == 'x' && count == 3){
		board[i] = 'o';

	}



	}



//	printf("The cell is %c \n", board[i]);



	//return board;
	return 1;
}



displayBoard(char* board, int rows, int columns){
	int i, j;
	for(i = 0; i < (rows * columns); i++){
		//printf("%c", board[i]);
		if(i % columns == 0){
			printf("\n");
		}
		printf("%c ", board[i]);



	}
	printf("\n");







	return 1;
}
