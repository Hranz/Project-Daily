/*
   Programmers: Kris Larson
   Date: January 23, 2014
   
   Description: Testing creation of a class, constructors,
      and a destructor.
   
*/

#include <iostream>
using namespace std;

void outOfScope();

class Player {
   public: 
      void setName(string n);
      string getName();
      //would typically also have all the mutators and accessors
      Player(); //constructor
      Player(string n, int h, int m, int a, int d, int s); //overloaded constructor
      ~Player(); //destructor

   private:
      string name;
      int health;
      int mana;
      int attack;
      int defense;
      int speed;
};

Player::Player() {
   name = "Name";
   health = 100;
   mana = 50;
   attack = 10;
   defense = 8;
   speed = 8;
   cout << "Player made\n";
}

Player::Player(string n, int h, int m, int a, int d, int s) {
   name = n;
   health = h;
   mana = m;
   attack = a;
   defense = d;
   speed = s;
   cout << "Super player made\n";
}

Player::~Player() {
   cout << "Player deleted\n\n";
}

void Player::setName(string n) {
   name = n;
}

string Player::getName() {
   return name;
}

void outOfScope() {
   Player hranz;
   hranz.setName("Hranz");
   
   cout << "Player's name is: " << hranz.getName() << endl;
}

int main() {
   outOfScope();
   
   Player ralph("Ralph", 500, 300, 100, 250, 80);
   cout << "Player's name is: " << ralph.getName() << endl;
   
   return 0;
}




// string FirstReverse(string str) { 
//   char temp;
//   int i = 0;
//   int j = str.size() - 1;
//   while (i < j) {
//     temp = str[i];
//     str[i] = str[j];
//     str[j] = temp;
//     i++;
//     j--;
//   }
//   // code goes here   
//   return str; 
//             
// }
// 
// int main() { 
//   string str;
//   cout << "Enter a string to be reversed: ";
//   cin >> str;
//   cout << FirstReverse(str);
//   return 0;    
// } 
// 
// 
