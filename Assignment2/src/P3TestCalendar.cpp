/*
 * File: TestCalendar.cpp
 * ----------------------
 * This file tests the calendar.h interface.
 */

#include <iostream>
#include "P3calendar.h"
using namespace std;
using namespace P3;
#include "console.h"
int P3calendar() {
   Date moonLanding(20, JULY, 1969);
   Date kennedyAssassination(NOVEMBER, 22, 1963);
   Date newYearsEve(DECEMBER, 31, 2011);
   Date inaugurationDay(21, JANUARY, 2013);
   Date electionDay(6, NOVEMBER, 2012);
   cout << "moonLanding = " << moonLanding << endl;
   cout << "kennedyAssassination = " << kennedyAssassination << endl;
   cout << boolalpha;
   cout << "moonLanding < kennedyAssassination = "
        << (moonLanding < kennedyAssassination) << endl;
   cout << "moonLanding > kennedyAssassination = "
        << (moonLanding > kennedyAssassination) << endl;
   cout << "moonLanding == kennedyAssassination = "
        << (moonLanding == kennedyAssassination) << endl;
   cout << "moonLanding == moonLanding = "
        << (moonLanding == moonLanding) << endl;
   cout << "inaugurationDay - electionDay = "
        << (inaugurationDay - electionDay) << endl;
   Date day = newYearsEve;
   cout << "New Year's Eve = " << day++ << endl;
   cout << "New Year's Day = " << day << endl;
   for (Date d = electionDay; d <= inaugurationDay; d++) {
      cout << d << endl;
   }
   return 0;
}
