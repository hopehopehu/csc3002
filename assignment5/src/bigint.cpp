/*
 * File: bigint.cpp
 * ----------------
 * This file implements the bigint.h interface.
 */

#include <cctype>
#include <string>
#include "bigint.h"
#include "error.h"
using namespace std;

/*
 * Implementation notes: BigInt constructor
 * ----------------------------------------
 * The code for this constructor offers a minimal implementation
 * that matches what we would expect on an exam.  In a more
 * sophisticated implementation, it would make sense to include
 * a test to avoid storing leading zeros in the linked list.  In
 * this implementation, calling BigInt("00042") creates a
 * BigInt with a different internal representation than
 * BigInt("42"), which is probably a bad idea.
 */

BigInt::BigInt(string str) {
    //TODO
    Cell* start;
    start = NULL;
    string pro_str;
    bool emit = true;
    int i = 0;
    int begin;
    while (emit==true){//to emit the leading 0
        i++;
        if (str[i] != '0'){
            emit = false;
        }
    }
    for (begin = i; begin < str.length();start++){
        Cell* digits = NULL;
        digits->finalDigit = str[begin];
        digits->leadingDigits = NULL;
        digits = start;
        start->leadingDigits = digits;
    }

}

/*
 * Implementation notes: BigInt destructor
 * ---------------------------------------
 * The code for the destructor is similar to that of the other
 * classes that contain a linked list.  You need to store the
 * pointer to the next cell temporarily so that you still have
 * it after you delete the current cell.
 */

BigInt::~BigInt() {
    //TODO
    while(start!=NULL){
        Cell* cp = start;
        start = cp->leadingDigits;
        delete cp;
    }
}



/*
 * Implementation notes: toString
 * ------------------------------
 * This method could also be written as a wrapper method that
 * calls a recursive function that creates the reversed string
 * one character at a time.
 */

string BigInt::toString() const {
    //TODO
    Cell *cp = start;
    string pro_str;
    int i = 0;
    while (cp->leadingDigits!=NULL){
        pro_str[i] = cp->finalDigit;
        i++;
        cp = cp->leadingDigits;
    }
    return pro_str;
}

/*
 * Implementation notes: operator+ and operator*
 * ------------------------------
 * Implement operator+ and operator*, make BigInt surpport addition and
 * multiplication.
 */

BigInt BigInt::operator+(const BigInt & b2) const {
    //TODO
    Cell * cp = start;
    Cell * cp_b2 = b2.start;
    int i = 0;
    int temp;
    int len1 = 0;
    int len2 = 0;
    while (cp->leadingDigits!=NULL){
        len1++;
    }
    while(cp_b2->leadingDigits!=NULL){
        len2++;
    }
    if (len2>=len1){
        while (i <= len1){
            i++;
            temp = cp->finalDigit + cp_b2->finalDigit;
            if(temp>=10){
                string str_temp = to_string(temp);
                cp->finalDigit = str_temp[0];
                cp->finalDigit = str_temp[1];
            }
            else{
                cp->finalDigit = temp;
            }
        }
        while(i<=len2 && i>len1){
            i++;
            temp = cp->finalDigit + cp_b2->finalDigit;
            if(temp>=10){
                string str_temp = to_string(temp);
                cp->finalDigit = str_temp[0];
                cp->finalDigit = str_temp[1];
            }
            else{
                cp->finalDigit = temp;
            }
        }
    }
    return cp;
}

BigInt BigInt::operator*(const BigInt & b2) const {
    //TODO
    Cell * cp = start;
    Cell * cp_b2 = b2.start;
    int i = 0;
    int temp;
    int len1 = 0;
    int len2 = 0;
    while (cp->leadingDigits!=NULL){
        len1++;
    }
    while(cp_b2->leadingDigits!=NULL){
        len2++;
    }
    if (len2>=len1){
        while (i <= len1){
            i++;
            temp = cp->finalDigit * cp_b2->finalDigit;
            if(temp>=10){
                string str_temp = to_string(temp);
                cp->finalDigit = str_temp[0];
                cp->finalDigit = str_temp[1];
            }
            else{
                cp->finalDigit = temp;
            }
        }
        while(i<=len2 && i>len1){
            i++;
            temp = cp->finalDigit * cp_b2->finalDigit;
            if(temp>=10){
                string str_temp = to_string(temp);
                cp->finalDigit = str_temp[0];
                cp->finalDigit = str_temp[1];
            }
            else{
                cp->finalDigit = temp;
            }
        }
    }
    return cp;
}


