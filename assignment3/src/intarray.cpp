/*
 * File: intarray.cpp
 * ------------------
 * This file inplements the intarray.h interface.
 */

#include "error.h"
#include "intarray.h"
#include "console.h"
/*
 * Implementation notes: IntArray constructor and destructor
 * ---------------------------------------------------------
 * The constructor allocates an array to hold the values and initializes
 * each element to 0; the constructor must also store the effective size
 * in the variable nElements.  The destructor must take responsibility
 * for freeing the dynamic array.
 */

IntArray::IntArray(int n) {
   /* TODO: Implement a constructor IntArray(n) that creates an IntArray object with
    * n elements, each of which is initialized to 0.
    */
   array = new int[n];
   for (int index_in_array = 0; index_in_array < n; index_in_array++ ){
       array[index_in_array] = 0;
   }
   nElements = n;
}

IntArray::~IntArray() {
    /* TODO: Implement a destructor that frees any heap storage allocated by the IntArray.
     */
    delete[]array;
}

/*
 * Implementation notes: size, get, and put
 * ----------------------------------------
 * Given the data structure, each of these methods is straightforward.
 */

int IntArray::size() {
    /* TODO: Implement a method size() that returns the number of elements in the IntArray.
     */
    return nElements;
}

int IntArray::get(int index) {
    /* TODO: Implement a method get(k) that returns the element at position k. If k is outside the
     * vector bounds, get should call error with an appropriate message.
     */
    if (index <= nElements && index >= 0) return array[index];
    else error("try appropriate index input");
}

void IntArray::put(int index, int value) {
    /* TODO: Implement a method put(k, value) that assigns value to the element at position k.
     * As with get, the put method should call error if k is out of bounds.
     */
    if (index <= nElements && index >= 0) array[index] = value;
    else error("try appropriate index input");
}

/*
 * Implementation notes: operator []
 * ---------------------------------
 * The selction operator is identical to get except for the fact that it
 * returns its result by reference.
 */

int & IntArray::operator[](int index) {
    /* TODO: Implement operator[], it should check to make sure that
     * the index k is valid. If it is, the operator[] method should return
     * the element by reference so that clients can assign a new value to
     * a selection expression.
     */
    if (index <= nElements && index >= 0) return array[index];
    else error("try appropriate index input");
}

/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * These methods make it possible to pass a IntArray by value or
 * assign one IntArray to another.
 */

IntArray::IntArray(const IntArray & src) {
    /* TODO: Implement deep copying constructor.
     */
    array = new int[nElements]; //implement deep copying from here
    for (int index_in_array = 0; index_in_array < nElements; index_in_array ++){
        array[index_in_array] = src.array[index_in_array];
    }
    nElements = src.nElements;
  //end of the deep copying

}

IntArray & IntArray::operator=(const IntArray & src) {
    /* TODO: Implement deep copying assignment operator.
     */
    if (this != &src){
        delete [] array;
        array = new int[nElements]; //implement deep copying from here
        for (int index_in_array = 0; index_in_array < nElements; index_in_array ++){
           array[index_in_array] = src.array[index_in_array];
        }
        nElements = src.nElements;
    }//end of the deep copying
    return *this;
}


