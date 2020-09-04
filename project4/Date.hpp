#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
//#include <stdlib>
#include <sstream>
using namespace std;

class Date
{
  private:
    int month;
    int day;
    int year;


  public:

    //Constructors
    Date();
    Date(int month, int day, int year);

    //getters
    void set_month(int month);
    void set_day(int day);
    void set_year(int year);

    //setters
    int get_month();
    int get_day();
    int get_year();



};
#endif
