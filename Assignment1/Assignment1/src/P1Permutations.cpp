/*
 * File: P1Permutations.cpp
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "P1Permutations.h"
using namespace std;

/* Function definition */

int P1Permutations() {
   int n, k;
   cout << "Enter the number of objects (n): ";
   cin >> n;
   cout << "Enter the number to be chosen (k): ";
   cin >> k;
   cout << "permutations(n, k) = " << permutations(n, k) << endl;
   return 0;
}

/* Function definition */
int permutations(int n, int k)
{
   // TODO
int numberofper=1;//set initial value of permutation
if (k>n)
{
    return 0;
}
else if (k==n||k==0)//if k equals to 0 or n, the permurarion value would be 1
{
    return 1;
}
else
{
    for (int i=n;i>=n-k+1;i--)
    {
      numberofper*=i;//p(n,k)=n*...(n-k+1)
    }
return numberofper;
}
}
