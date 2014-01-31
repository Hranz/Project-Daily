/*
   Programmer: Kristoffer Larson
   Date: January 31, 2014
   
   Description: Calculates the average CPI, total execution time, 
      and the MIPS of a sequence of instructions, given the number
      of instruction classes, the CPI and the total count of each 
      instruction type, and the clock rate (frequency) of a particular
      machine.
   
*/
#include<stdio.h>

int nic; //Number of instruction classes (types)
int cr; //Clock rate of machine (Mhz)
int totalInst; //Total count of each type of instruction (in millions)
int totalCycles; 

void insertParams() {
   totalInst = 0;
   totalCycles = 0;
   int i, cpiClass, instCount;
   
   printf("\nEnter number of instruction classes: ");
   scanf("%d", &nic);
   printf("Enter the frequency of the machine (MHz): ");
   scanf("%d", &cr);

   for (i = 0; i < nic; i++) {
      printf("Enter CPI of class %d: ", i + 1);
      scanf("%d", &cpiClass);
      printf("Enter instruction count of class %d (millions): ", i + 1);
      scanf("%d", &instCount);
      
      totalInst += instCount;
      totalCycles += cpiClass * instCount;
   } //end for
   
   return;
}

void calcCPI() {
   float avgCPI = totalCycles / ((float)totalInst);
   printf("The average CPI of the sequence is: %.2f\n", avgCPI);
   
   return;
}

void executionTime() {
   float t = (totalCycles / ((float)cr)) * 1000;
   printf("The total CPU time of the sequence is: %.2f msec\n", t);
   
   return;
}

void mips() {
   float mips = totalInst / (totalCycles / ((float)cr));
   printf("The total MIPS of the sequence is: %.2f\n", mips);
   
   return;
}

int main() {
   int choice;
   
   while (choice != 5) {
       printf("\nMenu of Options");
       printf("\n---------------");
       printf("\n1) Enter parameters");
       printf("\n2) Calculate average CPI of a sequence of instructions");
       printf("\n3) Calculate total execution time of a sequence of instructions");
       printf("\n4) Calculate MIPS of a sequence of instructions");
       printf("\n5) Quit\n\n");
       printf("Enter selection: ");
       scanf("%d", &choice);
      
      switch(choice) {
         case 1: insertParams(); break;
         case 2: calcCPI(); break;
         case 3: executionTime(); break;
         case 4: mips(); break;
         case 5: break;
         default: printf("\nPlease enter a valid input (1-5)");
      }
   }

   return 0;
}
