/*
   Programmers: Kris Larson
   Date: January 27, 2014
   
   Description: Using interfaces
   
*/

#include <iostream>
using namespace std;

class Stats {
   public:
      virtual int getAbility() = 0;
      void setHealth(int h) {
         health = h;
      }
      void setStrength(int s) {
         strength = s;
      }
      void setDefense(int d) {
         defense = d;
      }
      void setSpeed(int sp) {
         speed = sp;
      }
      int getStrength() {
         return strength;
      }
      int getHealth() {
         return health;
      }
   protected:
      int health;
      int strength;
      int defense;
      int speed;
};

class Player: public Stats {
   public:
      Player() {
         health = 100;
         strength = 10;
         defense = 8;
         speed = 8;
      }
      int getAbility() {
         return health * strength + defense + speed;
      }
};

class Monster: public Stats {
   public: 
      Monster() {
         health = 200;
         strength = 12;
         defense = 5;
         speed = 6;
      }
      int getAbility() {
      return health * (strength * defense + speed);
   }
};

int main() {
   Player hranz;
   Monster slime;
   bool run = true;
   
   while (run) { //Run until Hranz can beat the slime
      if (hranz.getAbility() < slime.getAbility()) {
         cout << "Oh no! Hranz got killed by the slime.\n He better power up.\n\n";
         hranz.setStrength(hranz.getStrength() + 5); //Power up the player
         hranz.setHealth(hranz.getHealth() + 10);
      } else {
         cout << "Hranz obliterates the slime!";
         run = false;  
      }
   }
   
   return 0;
}
