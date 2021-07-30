/*
 * File: TestIntArray.cpp
 * ----------------------
 * Tests the IntArray class.
 */

#include <iostream>
#include <string>
#include "intarray.h"
#include "strlib.h"
using namespace std;

/* Function prototypes */

void test(string str, int value, int expected);
int P1_test();
int P2a_test();
int P2b_test();

/* Function implementations */

/*
 * Function: test
 * Usage: test(str, value, expected);
 * ----------------------------------
 * Generates a line of test output, making sure that the value of value
 * is equal to the expected parameter.
 */

void test(string str, int value, int expected) {
   cout << str << " -> " << value;
   if (value != expected) cout << " (should be " << expected << ")";
   cout << endl;
}


/*
 * Function: P1_test
 * Usage: P1_test();
 * ----------------------------------
 * A test function for problem 1.
 */
int P1_test() {
   IntArray array(5);
   test("array.size()", array.size(), 5);
   for (int i = 0; i < 5; i++) {
      test("array.get(" + integerToString(i) + ")", array.get(i), 0);
      cout << "array.set(" << i << ", " << i << ");" << endl;
      array.put(i, i);
      test("array.get(" + integerToString(i) + ")", array.get(i), i);
   }
   return 0;
}

/*
 * Function: P2a_test
 * Usage: P2a_test();
 * ----------------------------------
 * A test function for problem 2(a).
 */
int P2a_test() {
   IntArray array(5);
   test("array.size()", array.size(), 5);
   for (int i = 0; i < 5; i++) {
      test("array[" + integerToString(i) + "]", array[i], 0);
      cout << "array[" << i << "] = " << i << ";" << endl;
      array[i] = i;
      test("array[" + integerToString(i) + "]", array[i], i);
   }
   return 0;
}

/*
 * Function: P2b_test
 * Usage: P2b_test();
 * ----------------------------------
 * A test function for problem 2(b).
 */
int P2b_test() {
   IntArray v1(5);
   test("v1.size()", v1.size(), 5);
   for (int i = 0; i < 5; i++) {
      test("v1[" + integerToString(i) + "]", v1[i], 0);
      cout << "v1[" << i << "] = " << i << ";" << endl;
      v1[i] = i;
      test("v1[" + integerToString(i) + "]", v1[i], i);
   }
   IntArray v2;
   v2 = v1;
   test("v2.size()", v2.size(), 5);
   for (int i = 0; i < 5; i++) {
      test("v2[" + integerToString(i) + "]", v2[i], i);
   }
   return 0;
}

/* Test program */
int main(){

    cout<<"Problem1 test:"<<endl;
    P1_test();
    cout<<"Problem2_a test:"<<endl;
    P2a_test();
    cout<<"Problem2_b test:"<<endl;
    P2b_test();


    return 0;
}



