/*
   Programmer: Kristoffer Larson
   Data: March 1, 2014
   
   Description: The header file that creates Event objects.
      Also contains methods to return or mutate objects.
      
*/

#include <iostream>
#include <string>

class Event {
   private:
      std::string name;
      int month;
      int day;
      int year;
   
   public:
      Event() {
         name = "Eventful Event";
         month = 1;
         day = 2;
         year = 3456;
      }//End default constructor
      Event(std::string n, int m, int d, int y) {
         name = n;
         month = m;
         day = d;
         year = y;
      }//End constructor
      void setName(std::string n) { name = n; }
      void setTime(int m, int d, int y) {
         month = m;
         day = d;
         year = y;
      }
      std::string getName() { return name; }
      int getMonth() { return month; }
      int getDay() { return day; }
      int getYear() { return year; }
      void print() {
         std::cout << name << " is/was on " << month << ", " << day << ", " << year << std::endl;
      }

};//End Event class
