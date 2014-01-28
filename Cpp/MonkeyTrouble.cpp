/*
   Programmer: Kris Larson
   Date: January 19, 2014
   
   Description: Two monkeys are making trouble
      and we need to know if there's a problem.
   
*/

#include <iostream>
using namespace std;

bool monkeyTrouble(bool smileOne, bool smileTwo);

int main() {
   bool smileOne = false; bool smileTwo = false;
   int one, two;
   cout << "Something's up with the monkeys. Tell me which, if any, are smiling.\n";
   cout << "Monkey one (1 for smiling, 2 for not): ";
   cin >> one;
   cin.clear();
   cout << "Monkey two (1 for smiling, 2 for not): ";
   cin >> two;
   if (one == 1) smileOne = true;
   if (two == 1) smileTwo = true;
   
   if (monkeyTrouble(smileOne, smileTwo))
      cout << ("\nUh oh we have a problem...");
   else
      cout << ("\nAhh good. No problems here!");
      
   return 0;
}

bool monkeyTrouble(bool smileOne, bool smileTwo) {
   if (smileOne == smileTwo)
      return true;
   else
      return false;
}
