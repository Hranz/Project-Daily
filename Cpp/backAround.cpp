/*
   Programmers: Kris Larson
   Date: January 18, 2014
   
   Description: Takes the last char in a string
      and concatenates it to the front and back.
   
*/

#include <iostream>
#include <string>
using namespace std;

string backAround(string word);

int main() {
   string word;
   cout << "Please enter a string: ";
   cin >> word;
   cout << backAround(word);
   return 0;
}

string backAround(string word) {
   string lett;
   lett = word[word.length() - 1];
   word = lett + word + lett;
   
   return word;
}
