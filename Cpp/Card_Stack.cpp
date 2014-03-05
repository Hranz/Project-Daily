/*
   Programmer: Kristoffer Larson
   Date: March 4, 2014
   
   Description: Create a user specified number of 
      Num_Card objects, store them in a stack, find
      the max, and print it.

*/

#include <stdlib.h>
#include <iostream>
#include <stack>
#include <ctime>

class Num_Card {
   private:
      int value;
      
   public:
      Num_Card() {
         value = -1;
      }//End default constructor
      
      Num_Card(int v) {
         value = v;
      }//End constructor
      
      void setValue(int v) {
         value = v;
      }//End setValue
      
      //static so that it can be called without reference to an object      
      static int getValue(Num_Card * v) {
         return v->value;
      }//End getValue
      
      //static so that it can be called without reference to an object
      static int compare(Num_Card * c2, Num_Card * c) {
         int num = c2->value - c->value;
         if (num == 0) return 0;
         else if (num > 0) return 1;
         else return -1;
      }//End compare
};//End class

std::stack<Num_Card *> box;//create stack

//I could prototype to make the order nicer, but this is fine too.
void print(Num_Card * m) {
   std::cout << Num_Card::getValue(m);
}//End print

void create(int n) {
   int i = 0, num;
   srand(time(0));//initialize a seed for rand based off the system clock
   
   while (i < n) {
      num = rand() % 100 + 1;
      Num_Card * card = new Num_Card(num);
      box.push(card);
      
      i++;
   }//End while
}//End create

void max() {
   Num_Card * temp = new Num_Card();
   Num_Card * one = new Num_Card();
   Num_Card * two = new Num_Card();
   
   if (box.size() >= 2) {
      one = box.top();
         box.pop();
      two = box.top();
         box.pop();
      if (Num_Card::compare(one, two) > 0) temp = one;
      else temp = two;
   }//End if
   
   while (!box.empty()) {
      one = box.top();
         box.pop();

      if (Num_Card::compare(one, temp) > 0) temp = one;
   }//End while
   print(temp);
}//End max

int main() {
   int n;
   std::cout << "How many cards? ";
   std::cin >> n;
      
   create(n);
   max();
   
   return 0;
}//End main
