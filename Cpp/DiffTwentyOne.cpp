/*
   Programmer: Kristoffer Larson
   
   Description: Finds the absolute difference
   	between 21 and some input value.
*/

#include <stdio.h>
#include <stdlib.h>
using namespace std;

int diffTwentyOne(int n);

int main() {
   int n = 22;
	int num = diffTwentyOne(n);
   printf("The abs difference between 21 and %d is %d", n, num);
	return 0;
}

int diffTwentyOne(int n) {
   return abs(21 - n);
}
