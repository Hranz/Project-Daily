/*
	Programmers: Kristoffer Larson
  	Date: January 21, 2014

	Description: 
		Checks if two words are anagrams
		of each other, or not.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isAnagram(string s1, string s2);

bool isAnagram(string s1, string s2) {
	for (int i = 0; i < s1.size(); i++) {
		tolower(s1[i]);
	}
	for (int i = 0; i < s2.size(); i++) {
		tolower(s2[i]);
	}
	
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	
	int result = s1.compare(s2);
	
	if (result == 0)
		return true;
	else
		return false;
}

int main() {
	string s1, s2;
	cout << "Enter the two words you want to compare: ";
	cin >> s1;
	cin.clear();
	cin >> s2;
	
	if (isAnagram(s1, s2))
		cout << "\nThey are anagrams of each other.";
	else
		cout << "\nThey are not anagrams of each other.";
	
	return 0;
}
