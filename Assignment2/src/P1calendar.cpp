/*
 * File: calendar.cpp
 * ------------------
 * This file implements the calendar.h interface
 */

#include <string>
#include "P1calendar.h"
using namespace std;

/*
 * Implementation notes: monthToString
 * -----------------------------------
 * The monthToString function must return some value if the month does not
 * match any of the enumeration constants.  Here, as in the Direction
 * type, the function returns ???.
 */

namespace P1 {

    string monthToString(Month month) {
       switch (month) {
        case JANUARY:   return "JANUARY";
        case FEBRUARY:  return "FEBRUARY";
        case MARCH:     return "MARCH";
        case APRIL:     return "APRIL";
        case MAY:       return "MAY";
        case JUNE:      return "JUNE";
        case JULY:      return "JULY";
        case AUGUST:    return "AUGUST";
        case SEPTEMBER: return "SEPTEMBER";
        case OCTOBER:   return "OCTOBER";
        case NOVEMBER:  return "NOVEMBER";
        case DECEMBER:  return "DECEMBER";
        default:        return "???";
       }
    }

    /*
     * Implementation notes: daysInMonth
     * ---------------------------------
     * This function is a reasonably literal translation of the old rhyme:
     *
     *    Thirty days has September
     *    April, June, and November
     *    All the rest have 31
     *    Excepting February alone
     *    Which has 28 in fine
     *    And each leap year 29
     */

    int daysInMonth(Month month, int year) {
    if (month==4 or month==9 or month==6 or month==11){
        return 30;
     }
    else if (month==2){
    if (isLeapYear(year)){
        return 29;
    }
    else{
        return 28;
    }
   }
    else{
        return 31;
    }     // To do
   }

    /*
     * Implementation notes: isLeapYear
     * --------------------------------
     * This function simply encodes the rule for determining leap years:
     * a leap year is any year divisible by 4, except for years ending in 00,
     * in which case the year must be divisible by 400.
     */

    bool isLeapYear(int year) {
       return ((year % 4 == 0) && (year % 100 != 0))
            || (year % 400 == 0);
    }
}

