/*
   Programmer: Kristoffer Larson
   Date: February 14, 2014
   
   Description: Creates a structure and stores information
      in it, then prints it out.

*/
#include <string.h>
#include <stdio.h>

typedef struct Boxes {
   int size;
   char content[50];
} Box;

int main() {
   Box stuff;
   
   stuff.size = 42;
   strcpy(stuff.content, "Many things.");
   
   printf("Size of box: %i\n", stuff.size);
   printf("Contents of box: %s", stuff.content);
   
   return 0;
} //End Main
