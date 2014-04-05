/*
   Programmer: Kristoffer Larson
   Date: April 4, 2014
   
   Description: Tests with arrays and pointers.

*/

#include <iostream>
#include <stdlib.h>

int main(void) {
   char array_1[10];
   char array_2[5];
   char* array_3[5];
   
   for (int i = 0; i < sizeof(array_2); i++) {
      array_2[i] = i;
   }
   
   array_3[0] = array_2;
   char* point = array_3[0];
   
   while (point > 0) {
      std::cout << *point << std::endl;
      *(point + 1);
   }
   
   

   int a = 3002500;
   int b = a / 256;
   int c = a % 255;
   array_1[0] = a;
   array_1[1] = b;
   int d = (int)(unsigned char)array_1[0];
   int e = (int)(unsigned char)array_1[1];
   int f = b / 256;
   std::cout << d << " & " << e << std::endl;
   //std::cout << b  << std::endl;
   std::cout << (f * 256 * 256) + (e * 256) + (d) << std::endl;
   
   
   int *pointer;
   pointer = (int *)((void *) &array_1[0]);
   //pointer = (int*) malloc(1 * sizeof(int));
   (void *) pointer;
   *(pointer+3) = 99; 
   
   std::cout << *(pointer+3) << std::endl;
   
   for (int i = 0; i < sizeof(array_2); i++) {
      //pointer = &array_2[i];
      //array_1[i] = *pointer;
   
   }
   
   for (int i = 0; i < sizeof(array_2); i++) {
      array_2[i] = i + 62;
   
   }
   
   for (int i = 0; i < sizeof(array_2); i++) {
      std::cout << array_1[i] << std::endl;
      std::cout << array_2[i] << std::endl;
   
   }
   
}// end main
