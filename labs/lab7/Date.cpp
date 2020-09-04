/****************
Shana Slavin
sslavin
Lab 7
Lab Section: 004
Nashrat Humaira
****************/


#include "Date.hpp"

// Just an array of strings. Access a month using:
// Date::MONTHS[0] ---> "JANUARY"
const string Date::MONTHS[] = {
  "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY",
  "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER",
  "NOVEMBER", "DECEMBER"
};

// Default, just make sure the fields are set to something
Date::Date() {
  this->month = 1;
  this->day = 1;
  this->year = 1000;
}
Date::~Date() {}

// Compare function which is true if lhs is earlier than rhs
bool Date::compare(const Date& lhs, const Date& rhs) {
  //compares strings
  if(lhs.get_year() < rhs.get_year()){
    if(lhs.get_year() == rhs.get_year()){
      if(lhs.get_month() < rhs.get_month()){
        if(lhs.get_month() == rhs.get_month()){
          if(lhs.get_day() < rhs.get_day()){
            return false;
          }
        }
      }
    }
  }
  else{
    return true;
  }
return true;
}

// Sample getter/setter
int Date::get_month() const {
  return this->month;
}
void Date::set_month(int month) {
  this->month = month - 1;
}

// IMPLEMENT OTHER GETTERS AND SETTERS
int Date::get_year() const{
  return this -> year;
}

void Date::set_year(int year){
  this -> year = year;
}

int Date::get_day() const{
  return this -> day;
}

void Date::set_day(int day){
  this -> day = day;
}


// Returns a well formatted string representation of this Date
string Date::print() {

  stringstream out;

  out << setw(10) << Date::MONTHS[this->month];
  out << setw(3) << get_day();
  out << setw(5) << get_year() << endl;

  return out.str();

}
