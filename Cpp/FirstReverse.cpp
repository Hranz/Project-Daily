/*
   Programmers: Kris Larson
   Date: January 22, 2014
   
   Description: Reverse a string
   
*/

#include <iostream>
using namespace std;

string FirstReverse(string str) { 
  char temp;
  int i = 0;
  int j = str.size() - 1;
  while (i < j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
  // code goes here   
  return str; 
            
}

int main() { 
  string str;
  cout << "Enter a string to be reversed: ";
  cin >> str;
  cout << FirstReverse(str);
  return 0;    
} 

