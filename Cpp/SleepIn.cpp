/*
   Programmer: Kristoffer Larson
   
   Description: Determines whether to sleep in
   	or not.

*/


#include <iostream>
using namespace std;

int main() {
   bool weekday = true;
   bool vacation = true;
   
   if (vacation || !weekday)
      cout << "Sleep in!";
   else
      cout << "Don't sleep in or you'll be late!";
	return 0;
}
