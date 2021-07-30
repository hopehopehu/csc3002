/*
 * File: MergeSort.cpp
 * -------------------
 * This file implements the merge sort algorithm using arrays rather
 * than vectors.
 */

#include <iostream>
using namespace std;

/* Function prototypes */

void sort(int array[], int n);
void printArray(int array[], int n);
void merge(int array[], int *arr1, int leftcount, int *arr2, int rightcount);

/* Main program */

int P3MergeSort() {
   int array[] = { 56, 25, 37, 58, 95, 19, 73, 30 };
   sort(array, 8);
   printArray(array, 8);
   return 0;
}
/*
 * Function: sort
 * Usage: sort(array, n);
 * ----------------------
 * Sorts the first n elements of the vector into increasing order using
 * the merge sort algorithm, which consists of the following steps:
 *
 * 1. Copy the array into an array allocated on the stack.
 * 2. Divide the new array into two halves by manipulating the indices.
 * 3. Sort each half of the array recursively
 * 4. Merge the two halves back into the original one.
 */

void sort(int array[], int n) {
    int mid = n / 2;
    int *arr1 = new int[mid];
    int *arr2 = new int[n-mid];
    if (mid == 1) return;
    for (int iter_index = 0; iter_index < mid; iter_index++){
        arr1[iter_index] = array[iter_index];
    }
    for (int iter_index = mid; iter_index < n; iter_index++){
        arr2[iter_index - mid] = array[iter_index];
    }
    sort(arr1, mid);
    sort(arr2, n - mid);//end of sorting
    int array_start, arr1_start, arr2_start;
    array_start = 0;
    arr1_start = 0;
    arr2_start = 0;
    while (arr1_start < mid && arr2_start < n - mid){
        if (arr1[arr1_start] < arr2[arr2_start]){
            array[array_start++] = arr1[arr1_start++];
        }
        else{
            array[array_start++] = arr2[arr2_start++];
        }
    }
    while(arr1_start < mid) array[array_start++] = arr1[arr1_start++];
    while(arr2_start < n - mid) array[array_start++] = arr2[arr2_start++];
    delete [] arr1;
    delete [] arr2;
    //TODO
}

/*
 * Function: printArray
 * Usage: printArray(array, n);
 * ----------------------------
 * Prints the elements of the array on a single line with the elements
 * enclosed in braces and separated by commas.
 */

void printArray(int array[], int n) {
   cout << "{ ";
   for (int i = 0; i < n; i++) {
      if (i > 0) cout << ", ";
      cout << array[i];
   }
   cout << " }" << endl;
}
