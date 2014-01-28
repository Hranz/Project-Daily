/*
   Programmer: Kristoffer Larson
   
   Description: State if input values are within 10
   	of 100 or 200.
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

bool nearHundred(int n);

int main() {
   bool go = true;
   int n;
   cout << "Please enter an integer: ";
   cin >> n;
   
   if (nearHundred(n))
      printf("%d is within 10 of 100 or 200", n);
   else
      printf("%d isn't within 10 of 100 or 200", n);
	return 0;
}

bool nearHundred(int n) {
   if (abs(n) >= 90 && abs(n) <= 110)
      return true;
   else if (abs(n) >= 190 && abs(n) <= 210)
      return true;
   else
      return false;
}
