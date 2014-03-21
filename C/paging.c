/*
   Programmer: Kristoffer Larson
   Date: March 21, 2014
   
   Description: Simulates the paging process with virtual
      and physical addresses.
*/

#include <stdio.h>
#include <stdlib.h>

//VM addr -> MM addr
//PT(malloc)

//declare some global vars
int mm_size, page_size, rp, entries;

//define page table
struct node {
   int vp; //virtual page
   int pf; //page frame
} * page_table = NULL;
typedef struct node row;


void option_one() {

   printf("\nEnter main memory size (words): ");
   scanf("%d", &mm_size);
   
   printf("Enter page size (words/page): ");
   scanf("%d", &page_size);
   
   printf("Enter replacement policy (0=LRU, 1=FIFO): ");
   scanf("%d", &rp);
   
   //calculate # entries in page table
   entries = mm_size / page_size;  
   //allocate space for page table
   page_table = (row *)malloc(entries * sizeof(row));
   
   //initialize vp field of each entry in the page table to -1
   int i;
   for (i = 0; i < entries; i++) {
      page_table[i].vp = -1;
      page_table[i].pf = i;
   }//End for
   
}//End option_one

void option_two() {
   //maps virtual address
   //declare local vars
   int vm_addr, virtual_page, offset, j, temp_pf, phys_addr;
   
   printf("Enter virtual memory address to access: ");
   scanf("%d", &vm_addr);
   
   //translate into virtual page & offset
   virtual_page = vm_addr / page_size;
   offset = vm_addr % page_size;
   
   //check for the virtual_page entry in page table
   int i = 0; //(i < entries) must be first
   while ((i < entries) && (page_table[i].vp != -1) && (page_table[i].vp != virtual_page)) { 
      i++;
   }//End while
   
   //case 1: i == # of entries
   //replace LRU (least recently used) or FIFO
   if (i == entries) {
      temp_pf = page_table[0].pf;
      
      for (j = 0; j < entries - 1; j++) {
         //page_table[j].vp = page_table[j + 1].vp;
         //page_table[j].pf = page_table[j + 1].pf;
         page_table[j] = page_table[j + 1];
      }//End for
      page_table[entries - 1].vp = virtual_page;
      page_table[entries - 1].pf = temp_pf;
      printf("Page fault!"); //full table
   } else if (page_table[i].vp == -1) { //case 2
      page_table[i].vp = virtual_page;
      page_table[i].pf = i;
      printf("Page fault!"); //unused entry
   } else { //case 3: there's a hit in the table at page_table[i].vp
      //on a hit put at the end of queue (rearrange table)
      //on hit if table isn't full, goes to the end of filled spots
      
      temp_pf = page_table[i].pf;
      if (rp == 0) { //Least recently used
         for (j = i; j < entries - 1; j++) { //from i to (including) entries - 2
            if (page_table[j + 1].vp == -1) break; //exit loop when a -1 is found
            page_table[j] = page_table[j + 1]; //push values up the table
         }//End for
         
         page_table[i + 1].vp = virtual_page; //i or i + 1
         page_table[i + 1].pf = temp_pf; //i or i + 1
      }//End if 
      //push the table up?
      phys_addr = temp_pf * page_size + offset;
      //print msg VA ____ maps to PA ____
      printf("Virtual address %d maps to physical address %d", vm_addr, phys_addr);
   }//End if
   
   
   
}//End option_two

void option_three() { //print page table

   int i;
   for (i = 0; i < entries; i++) {
      if (page_table[i].vp == -1) break;
      printf("VP %d --> PF %d\n", page_table[i].vp, page_table[i].pf);
   }//End for
   
}//End option_three

int main() {
   int choice;
   
   while(1) {
      printf("\n\nVirtual address mapping:\n");
      printf("----------------------------\n");
      printf("1) Enter parameters\n");
      printf("2) Map virtual address\n");
      printf("3) Print page table\n");
      printf("4) Quit\n\n");
      
      printf("Enter selection: ");
      scanf("%d", &choice);
      
      switch(choice) {
         case 1: option_one(); break;
         case 2: option_two(); break;
         case 3: option_three(); break;
         case 4: exit(0); break;
         default: printf("");
      }//End switch
   }//End while

   return 0;
}//End main
