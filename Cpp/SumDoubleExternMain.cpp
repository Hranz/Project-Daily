/*
   Programmers: Kris Larson
   Date: January 20, 2014
   
   Description: Testing the use of extern
   
*/

#include <iostream>
using namespace std;
 
int sum ;
extern int sumDouble_Extern(int one, int two);
 
int main() {
   int one, two;
   sum = 0;
   cout << "Enter two integers to be summed: ";
   cin >> one;
   cin.clear();
   cin >> two;
   
   cout << sumDouble_Extern(one, two);
   return 0;
}
