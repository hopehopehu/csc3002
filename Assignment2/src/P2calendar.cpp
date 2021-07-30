/*
 * File: calendar.cpp
 * ------------------
 * This file implements the calendar.h interface
 */

#include <string>
#include "P2calendar.h"
#include "error.h"
#include "strlib.h"
using namespace std;

/*
 * Implementation notes: monthToString
 * -----------------------------------
 * The monthToString function must return some value if the month does not
 * match any of the enumeration constants.  Here, as in the Direction
 * type, the function returns ???.
 */
namespace P2 {
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

    Month operator++(Month & month, int) {
       Month old = month;
       month = Month(month + 1);
       return old;
    }

    /*
     * Implementation notes: Constructors
     * ----------------------------------
     * There are three constructors for the Date class.  The default
     * constructor creates a Date with a zero internal value that must
     * be assigned a new value before it is used.  The others initialize
     * the date from the arguments by calling the private initDate method.
     */

    Date::Date() {
       /* Empty */
    }

    Date::Date(int day, Month month, int year) {
       initDate(day, month, year);
    }

    Date::Date(Month month, int day, int year) {
       initDate(day, month, year);
    }

    int Date::getDay() {
       return day;
    }

    Month Date::getMonth() {
       return month;
    }

    int Date::getYear() {
       return year;
    }

    /*
     * Implementation notes: toString
     * ------------------------------
     * The toString method uses the getters to perform the translation into
     * day/month/year values.
     */

    string Date::toString() {
      return integerToString(day)+'/'+monthToString(month)+'/'+integerToString(year);
      // To do
    }

    string Date::capitalize(string str) {
       if (str == "") return "";
       return toUpperCase(str.substr(0, 1)) + toLowerCase(str.substr(1));
    }

    void Date::initDate(int dd, Month mm, int yyyy) {
       if (dd < 1 || dd > daysInMonth(mm, yyyy)) {
          error("Specified date does not exist in the calendar");
       }
       day = dd;
       month = mm;
       year = yyyy;
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
        }  // Same as problem 1, just copy your answer here
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
