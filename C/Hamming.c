/*
   Programmer: Kristoffer Larson
   Date: March 7, 2014
   
   Description: Simulates the hamming process.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//declare global vars
//define Hamming code
char * hamming = NULL; //if length is a power of 2, the last bit can be removed because it's a parity bit and doesn't check anything to the left
int parity;

void option_one() {
   //declare local vars
   int max_length; //can be global if wanted. only used once
   
   //prompt for max length
   printf("\nEnter the maximum length: ");
   scanf("%d", &max_length);
   
   //prompt for parity
   printf("Enter the parity (0=even, 1=odd): ");
   scanf("%d", &parity);
   
   hamming = (char *)malloc(max_length * sizeof(char));
   
}//End option_one

void option_two() {
   //declare local vars
   int actual_length, total_parity_bits, parity_result;
   
   //prompt for Hamming code
   printf("\nEnter the Hamming code: ");
   scanf("%s", hamming);
   
   //calculate actual length of hamming code
   actual_length = strlen(hamming);
   
   //calculate total num of parity bits
   total_parity_bits = ceil(log(actual_length) / log(2));
   //k = log(m + k)/log(2);
   //k is num of parity bits
   //m is num of data bits
   //log2 is available with C99
   
   //check hamming code for error
   // for-loop: for each parity bit {
   int i, j, k, result = 0;
   for (i = 1; i < actual_length; i *= 2) {
      parity_result = parity; //Initialize with odd/even parity from option_one
      //for-loop: for each starting position {
      for (j = i; j <= actual_length; j += i * 2) {
         //for-loop: for each indexed to check {
         for (k = j; k <= (j + i - 1) && (actual_length); k++) {
            parity_result = parity_result ^ (hamming[actual_length - k] - '0');
         }//End k
      }//End j
      //Update result
      //printf("i");
      result = result + parity_result * i; //convert to decimal
   }//End i
   
   printf("The corrected Hamming code is: %s\n", hamming);
   //Correct Hamming code
   if (result != 0) {
      //if pos. in error contains 0, change to 1, else change it to 1
      //hamming[actual_length - result] = '1' - hamming[actual_length - result];
      if (hamming[actual_length - result] == '0')
         hamming[actual_length - result] = '1';
      else
         hamming[actual_length - result] = '0';
      
      printf("There is an error in bit: %d\n", result);   
      printf("The corrected Hamming code is: %s\n", hamming);
   } else {
      printf("There is no bit error\n");
   }//End if
   
   
}//End option_two

int main() {
   int choice;
   
   while(1) {
      printf("\n\nHamming Code Checker:\n");
      printf("---------------------\n");
      printf("1) Enter parameters\n");
      printf("2) Check Hamming code\n");
      printf("3) Quit\n\n");
      
      printf("Enter selection: ");
      scanf("%d", &choice);
      
      switch(choice) {
         case 1: option_one(); break;
         case 2: option_two(); break;
         case 3: exit(0); break;
         default: printf("");
      }//End switch
   }//End while

   return 0;
}//End main
