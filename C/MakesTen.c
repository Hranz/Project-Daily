/*
   Programmer: Kristoffer Larson
   Date: February 5, 2014
   
   Description: Capitalizing on the similarities between C++ and C,
      this makes use of 1s and 0s instead of boolean values true and
      false that are so standard in Java. Given 2 ints, a and b, 
      return 'true' if one if them is 10 or if their sum is 10. 
   
*/

#include <stdio.h>

int makesTen(int a, int b) {
   if (a == 10 || b == 10 || (a + b) == 10)
      return 1;
   else
      return 0;
}

int main() {
   int i, j;
   printf("Given two numbers, is one of them 10 or is there sum 10?\n");
   printf("Enter two numbers : ");
   scanf("%d%d", &i, &j);
   
   if (makesTen(i,j))
      printf("True");
   else
      printf("False");
}
