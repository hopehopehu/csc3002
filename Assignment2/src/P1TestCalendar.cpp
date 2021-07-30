/*
 * File: TestCalendar.cpp
 * ----------------------
 * This file tests the calendar.h interface.
 */

#include <iostream>
#include "P1calendar.h"
#include "simpio.h"
using namespace std;
using namespace P1;

int P1calendar() {
   int year;
   cout << "Enter a year: ";
   cin >> year;
   for (Month month = JANUARY; month <= DECEMBER; month = Month(month + 1)) {
      cout << monthToString(month) << " has " << daysInMonth(month, year)
           << " days." << endl;
   }
   return 0;
}

