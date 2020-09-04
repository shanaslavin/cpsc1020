#include <iostream>
#include <algorithm>
#include <fstream>
#include "src/date/Date.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
  ifstream input(argv[1]);
  ofstream output(argv[2]);

  int num_dates;
  input >> num_dates;

  Date dates[num_dates];

  int month, day, year;
  int count = 0;
  while ((input >> month >> day >> year) && count <= num_dates ) {
    dates[count].set_month(month);
    dates[count].set_day(day);
    dates[count].set_year(year);
    count++;
  }

  sort(&dates[0], &dates[num_dates], Date::compare);

  for(int i = 0; i < num_dates; i++) {
    output << dates[i].print() << '\n';
  }

  return 0;
}
