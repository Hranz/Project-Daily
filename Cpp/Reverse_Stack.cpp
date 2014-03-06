/*
   Programmer: Kristoffer Larson
   Date: March 5, 2014
   
   Description: Place values in a stack and have 
      them come out the order they went in.
   
*/
#include <iostream>
#include <stack>

std::stack<int> container_one;
std::stack<int> container_two;

void store(int value) {
   container_one.push(value);
}//End store

void flip() {
   while (!container_one.empty()) {
      container_two.push(container_one.top());
      container_one.pop();
   }//End while
}//End flip

void print() {
   while(!container_two.empty()) {
      std::cout << container_two.top() << std::endl;
      container_two.pop();
   }//End while
}//End print

int main() {
   int num;
   while (num != -1) {
      std::cout << "Enter in numbers. Terminate list with -1. ";
      std::cin >> num;
      if (num != -1)
         store(num);
   }//End while
   
   flip();
   print();
   return 0;
}//End main
