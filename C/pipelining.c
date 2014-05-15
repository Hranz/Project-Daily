/*
   Programmer: Kristoffer Larson
   Date: May 14, 2014
   
   Description: The program calculates the performance of a set of arithmetic 
      register assignment statements and prints out the aligned instructions 
      based on choosing from a menu.

*/


#include <stdio.h>
#include <stdlib.h>

//declare global variables
void print_chart(void);
int total_num_instr;

struct node {
   int dest;
   int src1, src2;
   int delay;
} *set = NULL;
typedef struct node instr;

void option_one() {
   int i;
   char instr_str[10];

   printf("\nEnter total number of instructions: ");
   scanf("%d", &total_num_instr);
   printf("\n");
   
   set = (instr*)malloc((total_num_instr + 1)*sizeof(instr));
   set[0].dest = -1;
   
   for (i = 1; i <= total_num_instr; i++) {
      printf("%d) ", i);
      scanf("%s", instr_str);
      set[i].dest = instr_str[1];
      set[i].src1 = instr_str[4];
      set[i].src2 = instr_str[7];
   }//End for loop
}//End option_one

void option_two() {
   int i, delay, overlap = 0, total_delay;
   
   set[1].delay = 0;
   for (i = 2; i <= total_num_instr; i++) {
      delay = 0;
      if ((set[i - 2].dest == set[i].src1) || (set[i - 2].dest == set[i].src2)) {
      //if RAW
         if (overlap == 0) {
            delay = 1;
            overlap = 1;
         } 
         else {
            delay = 0;
            overlap = 0;
         }
      } 
      else {
      //no RAW
         overlap = 0;
      }
      
      if ((set[i - 1].dest == set[i].src1) || (set[i - 1].dest == set[i].src2)) {
         delay = 2;
         overlap = 1;
      }
      set[i].delay = delay + set[i - 1].delay + 1;
   }//End for loop
   
   total_delay = set[total_num_instr].delay + 6;
   
   printf("\nTotal number of cycles: %i\n\n", total_delay);
   print_chart();
}//End option_two
   
void option_three() {
   int i, delay, pipe_delay = 1, overlap1 = 0, overlap2 = 0, overlap3 = 0, overlap4 = 0, overlap5 = 0, total_delay;
   
   /*
   dependency delay: 2 if i) -> i+1)
                     2 if i) -> i+2) & not coupled w/previous
                     1 if i) -> i+2) & supposed to be coupled w/previous
                     1 if i) -> i+3)
                     1 if i) -> i+4) & not coupled w/previous
                     0 otherwise
   */
   
   
   set[1].delay = 0;
   for (i = 2; i <= total_num_instr; i++) {
      delay = 0;
      pipe_delay = 1 - pipe_delay;
      if (i >= 5) {
         //check for RAW dep between instr's i-5) and i)
         if ((set[i - 5].dest == set[i].src1) || (set[i - 5].dest == set[i].src2)) {
         //check for overriding overlapping delay
            if (overlap1 == 0 && overlap2 == 0 && overlap3 == 0 && overlap4 == 0) {
               overlap5 = 1;
               if (pipe_delay == 1)
                  delay = 0;
               else
                  delay = 0;
               pipe_delay = 1; //force de-coupling from prev. instr
            } 
            else {
               delay = 0;
               overlap5 = 0;
            }
         } 
         else {
         //no RAW
            overlap5 = 0;
         }
      } // i >= 5
      if (i >= 4) {
         //check for RAW dep between instr's i-4) and i)
         if ((set[i - 4].dest == set[i].src1) || (set[i - 4].dest == set[i].src2)) {
         //check for overriding overlapping delay
            if (overlap1 == 0 && overlap2 == 0 && overlap3 == 0) {
               overlap4 = 1;
               if (pipe_delay == 1)
                  delay = 1;
               else
                  delay = 0;
               pipe_delay = 1; //force de-coupling from prev. instr
            } 
            else {
               delay = 0;
               overlap4 = 0;
            }
         } 
         else {
         //no RAW
            overlap4 = 0;
         }
      } // i >= 4
      if (i >= 3) {
         //check for RAW dep between instr's i-3) and i)
         if ((set[i - 3].dest == set[i].src1) || (set[i - 3].dest == set[i].src2)) {
         //check for overriding overlapping delay
            if (overlap1 == 0 && overlap2 == 0) {
               overlap3 = 1;
               if (pipe_delay == 1)
                  delay = 1;
               else
                  delay = 1;
               pipe_delay = 1; //force de-coupling from prev. instr
            } 
            else {
               delay = 0;
               overlap3 = 0;
            }
         } 
         else {
         //no RAW
            overlap3 = 0;
         }
      } // i >= 3
      if (i >= 2) {
         //check for RAW dep between instr's i-2) and i)
         if ((set[i - 2].dest == set[i].src1) || (set[i - 2].dest == set[i].src2)) {
         //check for overriding overlapping delay
            if (overlap1 == 0) {
               overlap2 = 1;
               if (pipe_delay == 1)
                  delay = 0;
               else
                  delay = 0;
               pipe_delay = 1; //force de-coupling from prev. instr
            } 
            else {
               delay = 0;
               overlap2 = 0;
            }
         } 
         else {
         //no RAW
            overlap2 = 0;
         }
      } // i >= 2
      if (i >= 1) {
         //check for RAW dep between instr's i-1) and i)
         if ((set[i - 1].dest == set[i].src1) || (set[i - 1].dest == set[i].src2)) {
               overlap1 = 1;
               delay = 2;
               pipe_delay = 1; //force de-coupling from prev. instr
         } 
         else {
         //no RAW
            overlap1 = 0;
         }
      } // i >= 1
      
      
      set[i].delay = delay + set[i - 1].delay + pipe_delay;
      
   }//End for loop
   
   total_delay = set[total_num_instr].delay + 6;
   
   printf("\nTotal number of cycles: %i\n\n", total_delay);
   print_chart();
}//End option_three

void print_chart() {
   int i,j;
   printf("1)");
   for (i = 1; i <= total_num_instr; i++) {
      //printf("");
      for (j = 0; j < set[i].delay; j++) {
         printf("\t");
      }//delay before
      printf("FI\tDI\tCO\tFO\tEI\tWO\n");
      if (i < total_num_instr) printf("%i)", i + 1);
   }
   printf("\n");
}//End print_chart

int main() {
   int choice;
   
   while(1) {
      printf("\nPipelined/Superscalar instruction performance:\n");
      printf("-----------------------------------------------\n");
      printf("1) Enter instructions\n");
      printf("2) Calculate/chart total cycles on a 6-stage piplined architecture\n");
      printf("3) Calculate/chart total cycles on a 6-stage superscalar architecture\n");
      printf("4) Quit\n\n");
      
      printf("Enter selection: ");
      scanf("%d", &choice);
      
      switch(choice) {
         case 1: option_one(); 
            break;
         case 2: option_two(); 
            break;
         case 3: option_three(); 
            break;
         case 4: exit(0); 
            break;
         default: printf("");
      }//End switch
   }//End while

   return 0;
}//End main
