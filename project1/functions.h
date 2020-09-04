/***************************
Shana Slavin
sslavin
CPSC 1020 Fall 2017
Due Date: September 29, 2017
Instructor: Dr. Yvon Feaster
****************************/



#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/*THESE ARE THE FUNCTIONS I USED IN MY PROJECT.  YOU ARE NOT REQUIRED TO USED
 *THESE EXACT FUNCTIONS.  */

/*If the user selects to read the data from a file and stores it in the 2D
 *array this function will need to be called.  It reads in the data from the
 *file and stores it in the 2D array (double pointer) passed to the function.
 */
void readData(FILE*, int **, int, int);

/*This function loops though each element of the 2D array, first determining
 *if the value of the element is a mine.  If it is a mine then put a -1 in that
 *element of the 2D array. If it is not then check each of its
 *neighbors to determine if there are any mines in any adjoining elements.
 *This means you need to check the element directly above, above left, above
 *right, directly to the left, directly to the right, directly below, below
 *left and below right. If there is a mine adjoining the current element
 *increment a counter. After you have checked all neighbors assign the counter
 *value to a second 2D array.
 *
 *This will require nested for loops.  looping through each row (height) and col
 *(width).  Using a series of if else check if the value is a 1 then this is a
 *mine set the outArray to -1, otherwise check all neighboring cells counting
 *all mines.  Then set the outArray to equal to the count of mines.*/
void checkNeighbors(int **, int **, int, int);

/*This function prints the values of each element in the outArray to the output
 *file.
 *Using nested loops to loop throught each element of the outArray, print the
 *value of the element, unless it is a -1.  If it is -1, print 'X' rather than
 *-1*/
void printOutput(FILE*, int **, int, int);

/*This function prints the values of each element in the outArray to the screen
 *rather than to a file*/
void printOut(int **, int, int);

/*This function dynamically allocates memory for a 2D array.
 *You need to return the double pointer.
 *1.	Create a temporary double pointer.  Malloc the memory for this double
 *    array using the method we discussed in class.
 */
int** allocateMemory(int, int);

/*This function is the starting point for the program. Provide the user with the
 *four avaialable selections for this program. See specification document for
 *the 4 possible selections.
 *Be sure to validate the user input.
 *
 *Steps:
 *1. print the initial message to the user.
 *2. Use scanf to read the data from the user.
 *3. Check the validity of the user data.  If the user entered incorrect data
 *   tell the user they have entered incorrect data and ask them to try again
 *   continue this until the user enters a correct selection.*/
int printMenu();

/*This function uses rand() to randomly generate the row and col to determine
 *where the mines will be placed.  Make sure you do not try to place a mine in
 *one location multiple times.  The number of mines should be 15% of the totals
 *number of elements in the 2D array.
 *Steps:
 *1. Initialize the allocated memory to 0.
 *2. Seed the random generator using time.  Look up srand() and rand().
 *3. Create a variable to hold the number of mines that need to be generated.
 *4. Create the position for the mines.  This will require you to generate two
 *   numbers: 1 for row and 1 for the column of the 2D array.
 *4b.Make sure you are not trying to place a mine in the same place multiple
 *   times.
*/
void generateBoard(int, int, int** )
;
/*This is the recursive function that allows the the user to play the advanced
 *version of the game to be played*/
void propogateGuess(int, int, int, int, int**, int**);

/*I use this to get the height and width values for selection 2, 3, and 4.
 *This is where I ask the user to enter the height and width.  I also tell them
 *the values must be between 5 and 20.  Make sure you validate the data.  If the
 *data entered by the user is incorrect, tell them they have entered incorrect
 *data and ask them to re-enter.*/
void getHW(int*, int*);

/*This is the functions needed for section 1.  The function readData,
 *checkNeighbors, printOutput is called.*/
void option1(FILE*, FILE*, int, int, int**, int**);

/*This function is needed for selection 2.  You will need to calculate the
 *number of mines necessary.  Tell the user how many mines will be randomly
 *generated.  I then call a function created to generate the board.  Now that
 *the board is generated call the function to check the surrounding neighbors.
 *After this is complete call printOutput to print the outArray*/
void option2(FILE*, int, int, int**, int**);

/*This selection depends on the task of selection 2 being complete, so I called
 *the option2 function first then the function that allows the user to play the
 *basic game.  Used for the EC*/
void option3();

/*This selection depends on the task of selection 2 being complete, so I called
 *the option2 function first then the function that allows the user to play the
 *advanced version of the game.  Used for the EC*/
void option4();

/*These are Extra Credit functions*/
void playBasicGame(int, int, int**);
void playAdvanceGame(int,int, int**);

#endif
