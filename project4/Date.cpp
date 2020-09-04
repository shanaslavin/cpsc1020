#include "Date.hpp"
#include <string>
#include <iostream>
//#include <stdlib>
#include <sstream>
using namespace std;

//Constructors
//Default
Date::Date(){
  month = 0;
  day = 0;
  year = 0;
}
//Regular
Date::Date(int month, int day, int year){
  this->month = month;
  this->day = day;
  this->year = year;
}

//Setters
void Date::set_month(int month){
  this->month = month;
}

void Date::set_day(int day){
  this->day = day;
}

void Date::set_year(int year){
  this->year = year;
}

//Getters
int Date::get_month(){
  return month;
}

int Date::get_day(){
  return day;
}

int Date::get_year(){
  return year;
}
