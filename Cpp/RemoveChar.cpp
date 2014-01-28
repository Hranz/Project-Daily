/*
   Programmer: Kris Larson
   Date: January 17, 2014
   
   Description: Removes chosen character in desired word, or 
      displays a certain number of characters in said word.
   
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

string removeChar(char word[], int n);
void displayWhat(char word[], int n);

int main() {
   char word[30];
   int n;
   cout << "Please enter a string followed by what character you wish to remove: ";
   cin >> word;
   cin.clear();
   cin >> n;
   
   string newWord = removeChar(word, n);
   cout << word << endl;
   displayWhat(word, n);
   return 0;
}

string removeChar(char word[], int n) {   
   for (int i = n; i < strlen(word); i++) {
      word[i] = word[i + 1];
   } 
   return word;
}

void displayWhat(char word[], int n) {
   word[n] = '\0';
   cout << word << endl;
}
