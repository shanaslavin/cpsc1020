/***************************
Shana Slavin
sslavin
CPSC 1020 Fall 2017
Due Date: September 29, 2017
Instructor: Dr. Yvon Feaster
****************************/



#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <time.h>


/*Use this file to implement the functions you have listed in your header file*/
void readData(FILE* inputPtr, int **array, int row, int col){


  int i, j;

  for(i = 0; i < row; i++) {
    for(j = 0; j < col; j++) {
      fscanf(inputPtr, "%i", &array[i][j]);
    }
  }
}


void checkNeighbors(int** array, int** outarr, int row, int col){
  int currow, curcol;
  int mine = -1;

  //sets everything to 0
  for(currow = 0; currow < row; currow++){
    for(curcol = 0; curcol < col; curcol++){
      outarr[currow][curcol] = 0;
    }
  }

  //places mines
  for(currow = 0; currow < row; currow++){
    for(curcol = 0; curcol < col; curcol++){
      if(array[currow][curcol] == 1){
        outarr[currow][curcol] = mine;
      }
    }
  }

  //finds mines and changes neighbors
  for(currow = 0; currow < row; currow++){
    for(curcol = 0; curcol < col; curcol++){
      // If mine, check neighbors
      if(outarr[currow][curcol] == mine){
        //top
        if(currow-1 >= 0){
          if(outarr[currow-1][curcol] != mine){
            outarr[currow-1][curcol]++;
          }
        }
          //below
        if(currow+1 < row){
          if(outarr[currow+1][curcol] != mine){
            outarr[currow+1][curcol]++;
          }
        }
          //below left
        if(curcol-1 >= 0){
          if(currow-1 >= 0){
            if(outarr[currow-1][curcol-1] != mine){
              outarr[currow-1][curcol-1]++;
            }
          }
        }
          //below right
        if(curcol+1 > 0){
          if(currow-1 >= 0){
            if(outarr[currow-1][curcol+1] != mine){
              outarr[currow-1][curcol+1]++;
            }
          }
        }
        //right
        if(curcol-1 >= 0){
          if(outarr[currow][curcol-1] != mine){
            outarr[currow][curcol-1]++;
           }
         }
          //top left
        if(curcol+1 < col){
          if(currow+1 < row){
            if(outarr[currow+1][curcol+1] != mine){
              outarr[currow+1][curcol+1]++;
            }
          }
        }
          //top right
        if(curcol-1 >= 0){
          if (currow+1 < row) {
            if(outarr[currow+1][curcol-1] != mine){
              outarr[currow+1][curcol-1]++;
            }
          }
        }
          //left
        if(curcol+1 < col){
          if(outarr[currow][curcol+1] != mine){
            outarr[currow][curcol+1]++;
          }
        }
      }
    }
  }
}

void printOutput(FILE* outputPtr, int **outarr, int row, int col){
  int i, j;

  //replaces mines with X
  for (i = 0; i < row; i++ ) {
    for(j = 0; j < col; j++){
      if(outarr[i][j] < 0){
        fprintf(outputPtr, "X ");
      }
      else{
      fprintf(outputPtr, "%i ", outarr[i][j]);
    }
    }
    fprintf(outputPtr, "\n");
  }

}


void printOut(int **outarr, int row, int col){
  int i, j;

  printf("\n");

  for (i = 0; i < row; i++ ) {
    for(j = 0; j < col; j++){
      if(outarr[i][j] < 0){
        printf("X ");
      }
      else{
      printf("%i ", outarr[i][j]);
    }
   }
   printf("\n");
  }
}


int **allocateMemory(int row, int col){

  int i;
  int **arr;

  arr = (int **) malloc (row * sizeof(int *));
    for(i = 0; i < row; i++){
      arr[i] = (int *) malloc (col * sizeof(int));
    }
  return arr;
}




int printMenu(){

  int choice = 0;
  int loop = 0;

  printf("**************************************************************\n");
  printf("                Welcome to Avoid the Mines                    \n");
  printf("         Please choose one of the options below               \n");
  printf("         1: Read the board information from a file            \n");
  printf("         2: Randomly generate the board information           \n");
  printf("         3: Randomly generate the board and play basic        \n");
  printf("         4: Randomly generate the board in play advanced      \n");
  printf("                  Type 1, 2, 3, or 4 and return               \n");
  printf("**************************************************************\n");

  scanf("%d", &choice);

  while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
    printf("Cannot recognize user data. Please re-enter your input.\n");

    printf("**************************************************************\n");
    printf("                Welcome to Avoid the Mines                    \n");
    printf("         Please choose one of the options below               \n");
    printf("         1: Read the board information from a file            \n");
    printf("         2: Randomly generate the board information           \n");
    printf("         3: Randomly generate the board and play basic        \n");
    printf("         4: Randomly generate the board in play advanced      \n");
    printf("                  Type 1, 2, 3, or 4 and return               \n");
    printf("**************************************************************\n");

    scanf("%d", &choice);
  }

return (choice);

}

void generateBoard(int row, int col, int** genInputArr){

  int numOfMines = row * col * .15;
  printf("%i", numOfMines);
  int i, j;
  int minesPlaced;
  int mine = 1;
  int rowMine;
  int colMine;

  for(i = 0; i < row; i++){
    for(j = 0; j < col; j++){
      genInputArr[i][j] = 0;
    }
  }

  srand(time(NULL));

  for(minesPlaced = 0; minesPlaced < numOfMines; minesPlaced++){
    rowMine = rand()%row;
    colMine = rand()%col;
    if(genInputArr[rowMine][colMine] != mine){
      genInputArr[rowMine][colMine] = mine;
    }
    else{
      numOfMines++;
    }

  }


}


//void propogateGuess(int, int, int, int, int**, int**);


void getHW(int* height, int* width){

  printf("Enter an integer between 5 and 20 for height and width.\n");
  scanf("%d %d", height, width);

  while(*height < 5 || *height > 20 || *width < 5 || *width > 20){
      printf("Error reading input. Enter an integer between 5 and 20 for height and width.\n");
      scanf("%i %i", height, width);
  }
}


void option1(FILE* inputPtr, FILE* outputPtr, int row, int col, int** array, int** outarr){

  readData(inputPtr, array, row, col);
  checkNeighbors(array, outarr, row, col);
  printOutput(outputPtr, outarr, row, col);

}




void option2(FILE* outputPtr, int row, int col, int** genInputArr, int** outInputArr){

  generateBoard(row, col, genInputArr);
  checkNeighbors(genInputArr, outInputArr, row, col);
  printOutput(outputPtr, outInputArr, row, col);


}


void option3(){

  printf("I have chosen not to complete this option.\n");

}




void option4(){

  printf("I have chosen not to complete this option. \n");

}


//void playBasicGame(int, int, int**);
//void playAdvanceGame(int,int, int**);
