/*
 * File: TestCalendar.cpp
 * ----------------------
 * This file tests the calendar.h interface.
 */

#include <iostream>
#include "P2calendar.h"
using namespace std;
using namespace P2;
int P2calendar() {
   Date moonLanding(20, JULY, 1969);
   cout << "moonLanding = " << moonLanding.toString() << endl;
   return 0;
}
