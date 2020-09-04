#include "Date.hpp"

const string Date::MONTHS[] = {
  "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY",
  "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER",
  "NOVEMBER", "DECEMBER"
};

Date::Date() {
  this->month = 1;
  this->day = 1;
  this->year = 1000;
}

bool Date::compare(const Date& lhs, const Date& rhs) {
  if (lhs.year == rhs.year) {
    if (lhs.month == rhs.month) {
      return lhs.day <= rhs.day;
    } else {
      return lhs.month < rhs.month;
    }
  } else {
    return lhs.year < rhs.year;
  }
}

Date::~Date() {}

int Date::get_month() const { return this->month; }
void Date::set_month(int month) { this->month = month; }

int Date::get_day() const { return this->day; }
void Date::set_day(int day) { this->day = day; }

int Date::get_year() const { return this->year; }
void Date::set_year(int year) { this->year = year; }

string Date::print() {
  stringstream out;
  out << left
      << setw(10) << Date::MONTHS[this->month-1] << ' '
      << setw(3)  << this->day << ' '
      << setw(5)  << this->year;
  return out.str();
}
