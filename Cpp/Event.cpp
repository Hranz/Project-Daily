/*
   Programmer: Kristoffer Larson
   Data: March 1, 2014
   
   Description: Creates pointers to objects and then creates an
      Event object for the created pointer. Creates events with
      a name and a mm/dd/yyyy they were/are on. This uses a 
      header file to create the object.
      
*/

#include "Event.hpp"

int main(int argc, const char * argv[]) {
   Event* event = new Event();
   event->print();
   
   Event* halloween = new Event();
      halloween->setName("Halloween");
      halloween->setTime(10, 31, 2022);
   halloween->print();
   
   Event* christmas = new Event("Christmas", 12, 25, 2014);
   christmas->print();
   
   delete event, halloween, christmas;

   return 0;
}//End main

