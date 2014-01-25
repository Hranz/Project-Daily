/*
   Programmers: Kris Larson
   Date: January 25, 2014
   
   Description: Playing with stacks and pointers.
   
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
   stack <string> cards;
   string *c = new string;
   cards.push("Ace of Spades");
   c = &cards.top(); 
   cards.push("King of Hearts");
   
   string s = cards.top();
   cout << s << endl;
   cards.pop();
   s = cards.top();
   cout << s << endl;
   cards.pop();
   cards.push("One of Clubs");
   cards.push("Ten of Diamonds");
   s = cards.top();
   cout << s << endl;
   cout << *c << endl; //Print the value that c is pointing at
   
   c += 1; //Incrementing through the stack
   
   cout << *c << endl;
   
   delete c;
}
