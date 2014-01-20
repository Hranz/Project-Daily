/*
   Programmers: Kris Larson
   Date: January 20, 2014
   
   Description: Testing the use of extern.
   
*/

#include <iostream>
using namespace std;

extern int sum;
 
int sumDouble_Extern(int one, int two) {
   sum = one + two;
   
   if (one == two)
      return sum * 2;
   else
      return sum;
}
