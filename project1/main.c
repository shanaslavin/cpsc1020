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


int main(int argc, char *argv[])
{

  /*Create any variables need*/

  int i;
  int row = 0;
  int col = 0;
  int* height = (int *) malloc (1 * sizeof(int));
  int* width = (int *) malloc (1 * sizeof(int));
  int choice = 0;
  int** outarr;
  int** array;
  int** genInputArr;
  int** outInputArr;

  /*1.  Create a file pointer for the file that you will read from
   *2.  Check to make sure the file pointer is opened sucessfully */
  FILE *inputPtr;
  inputPtr = fopen(argv[1], "r");
  if(inputPtr == NULL){
    printf("Error opening file.\n");
  }

  FILE *outputPtr;
  outputPtr = fopen(argv[2], "w");
  if(outputPtr == NULL){
    printf("Error opening file.\n");
  }


  fscanf(inputPtr, "%i", &row);
  fscanf(inputPtr, "%i", &col);



  /*Call printMenu() This starts the program.  The Selection returned will
   *determine the steps needed next.
   */


  choice = printMenu();

  if(choice == 1){
    array = allocateMemory(row, col);
    outarr = allocateMemory(row, col);
    option1(inputPtr, outputPtr, row, col, array, outarr);
    for(i = 0; i < row; i++){
      free(array[i]);
      free(outarr[i]);
    }
  }
  if(choice == 2){
      getHW(height, width);
      row = *height;
      col = *width;
      genInputArr = allocateMemory(row, col);
      outInputArr = allocateMemory(row, col);
      option2(outputPtr, row, col, outInputArr, genInputArr);
      for(i = 0; i < row; i++){
        free(genInputArr[i]);
        free(outInputArr[i]);
      }
    }
  if(choice == 3){
      option3();
  }
  if(choice == 4){
      option4();
  }



  /*After everything is complete you should free any remaining allocated memory
   *and close and open file pointers.*/

  fclose(inputPtr);
  fclose(outputPtr);


  free(height);
  free(width); 

  return 0;

}
