/*
   Programmer: Kristoffer Larson
   Date: March 6, 2014
   
   Description: Using a deque, it checks if an integer 
      is a palindrome. Works with both positive and 
      negative numbers.

*/

#include <iostream>
#include <deque>

std::deque<int> deq;

int read() {
   int num;
   std::cout << "Enter a number to test: ";
   std::cin >> num;
   
   return num;
}//End read

void store(int a) {
   int b;
   while (a != 0) {
      b = a % 10;
      a /= 10;
      
      deq.push_front(b);
   }//End while
}//End store

bool palindrome(int a) {
   int one, two;
   store(a);
   if (deq.size() > 0) {
      while (deq.size() > 1) {
         one = deq.front();
         two = deq.back();
         
         if (one != two) return false;
         
         deq.pop_front();
         deq.pop_back();
      }//End while
   }//End if
   return true;
}//End palindrome

int main() {
   
   if (palindrome(read()))
      std::cout << "It's a palindrome" << std::endl;
   else
      std::cout << "It's not a palindrome" << std::endl;
   
   return 0;
}//End main
