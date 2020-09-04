/****************
Shana Slavin
sslavin
Lab 7
Lab Section: 004
Nashrat Humaira
****************/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Date.hpp"

using namespace std;

int main(int argv, char* argc[]){

  //initializing variables
  int numOfDates = 0;
  int i = 0;
  int month = 0;
  int day = 0;
  int year = 0;

  //opening files
  ifstream(inputPtr);
  inputPtr.open(argc[1]);
  ofstream(outputPtr);
  outputPtr.open(argc[2]);

  //read in how many dates to sort though
  inputPtr >> numOfDates;

  Date dates[numOfDates];

  for(i = 0; i < numOfDates; i++){
    inputPtr >> month;
    inputPtr >> day;
    inputPtr >> year;
    dates[i].set_month(month);
    dates[i].set_day(day);
    dates[i].set_year(year);

  }

  //calling sort function
  sort(&dates[0], &dates[numOfDates], Date::compare);

  //calling print function
  for(i = 0; i < numOfDates; i++){
    outputPtr << dates[i].print();
  }

  inputPtr.close();
  outputPtr.close();

return 0;

}
