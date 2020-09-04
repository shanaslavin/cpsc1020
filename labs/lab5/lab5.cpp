/****************
Shana Slavin
sslavin
Lab 5
Lab Section: 004
Nashrat Humaira
****************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "lab5.h"

using namespace std;

void bubble_sort(int unsortedArray[], int length){

  //initializing variables
  int i;
  int numOfSwaps = 1;
  //bubble sorting
  while(numOfSwaps != 0){
    numOfSwaps = 0;
    for(i = 0; i < length - 1; i++){
      if(unsortedArray[i] > unsortedArray[i + 1]){
          numOfSwaps++;
          std::swap(unsortedArray[i], unsortedArray[i+1]);
      }
    }
  }
}

int main(int argc, char *argv[]){

  //initializing variables
  int array = 0;
  int length = 0;
  int i = 0;
  //opening input file
  ifstream inputPtr;
  //checks if file opened correctly
  inputPtr.open(argv[1]);
  if(!inputPtr.is_open()){
    cout << "File failed to open." << endl;
    return 0;
  }
  else{

    while(!inputPtr.eof()){
      inputPtr >> array;
      length++;
    }
  }

  int unsortedArray[length];
  int num = 0;
  int sortedArray[length];
  inputPtr.clear();
  inputPtr.seekg(0, std::ios::beg);
  //calls bubble sort
  bubble_sort(unsortedArray, length);

  for(i = 0; i < length; i++){
    num = unsortedArray[i];
    sortedArray[i] = num;
  } 

  //opening output file
  ofstream outputPtr;
  outputPtr.open(argv[2]);
  //checks if file opened correctly
  if(!outputPtr.is_open()){
    cout << "File failed to open." << endl;
    return 0;
  } 
  else{
    for(i = 0; i < length; i ++){
      outputPtr << sortedArray[i] << endl;

    }

  }

  inputPtr.close();
  outputPtr.close();

  return 0;
}
