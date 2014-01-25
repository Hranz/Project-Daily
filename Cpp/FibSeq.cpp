/*
   Programmers: Kris Larson
   Date: January 24, 2014
   
   Description: Playing with vectors and recursion.
   
*/

#include <iostream>
#include <vector>
using namespace std;

int fibSequence(int n);

int fibSequence(int n) {
   if (n == 0) {
      return 0;
   } else if (n == 1) {
      return 1;
   } else
      return fibSequence(n - 1) + fibSequence(n - 2);
}

int main() {
   int num;

   cout << "How many values of the Fibonacci Sequence do you want? ";
   cin >> num;
   vector<int> fibVector(num);
   
   for (int i = 0; i < num; i++) {
      fibVector[i] = fibSequence(i);
   }
   
   for (int i = 0; i < fibVector.size(); i++) {
      cout << fibVector[i] << endl;
   }
   
   return 0;
}
