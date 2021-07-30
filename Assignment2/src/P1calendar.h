/*
 * File: calendar.h
 * ----------------
 * This interface exports some useful types and functions for working
 * with calendar data.
 */

#ifndef _P1calendar_h
#define _P1calendar_h

#include <string>
int P1calendar();
/*
 * Type: Month
 * -----------
 * This enumerated type defines constant names for the months.  To be
 * consistent with conventional usage, the internal value for JANUARY
 * is 1 rather than 0.
 */

namespace P1 {
    enum Month {
       JANUARY = 1,
       FEBRUARY,
       MARCH,
       APRIL,
       MAY,
       JUNE,
       JULY,
       AUGUST,
       SEPTEMBER,
       OCTOBER,
       NOVEMBER,
       DECEMBER
    };

    /*
     * Function: monthToString
     * Usage: string str = monthToString(month);
     * -----------------------------------------
     * Returns the name of the specified month as a string.  The name
     * appears entirely in uppercase, just as the constant names do.
     */

    std::string monthToString(Month month);

    /*
     * Function: daysInMonth
     * Usage: int nDays = daysInMonth(month, year);
     * --------------------------------------------
     * Returns the number of days in the specified month and year.
     */

    int daysInMonth(Month month, int year);

    /*
     * Function: isLeapYear
     * Usage: if (isLeapYear(year)) . . .
     * ----------------------------------
     * Returns true if the specified year is a leap year.
     */

    bool isLeapYear(int year);
}



#endif
