/*
   Programmer: Kristoffer Larson
   Date: March 11, 2014
   
   Description: A test of the static keyword for variables.
*/
#include <iostream>

int num() {
   static int count = 0;
   
   for (int i = 0; i < 10; i++) {
      count++;
   }
   std::cout << count << std::endl;
}

int main() {
   
   for (int i = 0; i < 5; i++) {
      num();
   }

   return 0;
}
