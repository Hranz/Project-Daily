/*
   Programmer: Kristoffer Larson
   Date: February 28, 2014
   
   Description: Simulates cache and main memory, when reading and
      writing values.

*/


#include <stdio.h>
#include <stdlib.h>

//declare global variables

//define main mem as dynamic array
int *main_mem = NULL; //total size of accessible main memory (in words)
int main_mem_size;
int cache_size;
int block_size;
int num_cache_rows;

//define cache as dyanamic array of lines
struct Cache_node { //total size of the cache(in words)
   int tag;
   int *block;
} *cache = NULL; //cache dynamic array
typedef struct Cache_node node; 

void option_one() {
   printf("\nEnter main memory size (words): ");
      scanf("%d", &main_mem_size);
   printf("Enter cache size (words): ");
      scanf("%d", &cache_size);
   printf("Enter block size (words/block): ");
      scanf("%d", &block_size);
   
   main_mem = (int *)malloc(main_mem_size * sizeof(int));
   num_cache_rows = cache_size / block_size;
   int i;
   for (i = 0; i < main_mem_size; i++) {
      main_mem[i] = main_mem_size - i;
   }
   cache = (node *)malloc(num_cache_rows * sizeof(node));
   for (i = 0; i < num_cache_rows; i++) {
      cache[i].block = NULL;
      cache[i].tag = -1;
   }
   
}//End option_one

void option_two() {
   int rw, addr, value, t, s, w, base;
   
   printf("Select read (0) or write (1): ");
      scanf("%d", &rw);
   
   //Won't work if input is something other than 1 or 0
   if (rw == 1) {
      printf("\nEnter main memory address to write to: ");
         scanf("%d", &addr);
      printf("Enter value to write: ");
         scanf("%d", &value);
   } else if (rw == 0) {
      printf("\nEnter main memory address to read from: ");
         scanf("%d", &addr);
   }//End if
   
   //translate mm_addr for cache.
      t = addr / cache_size;
      s = (addr % cache_size) / block_size;
      w = addr % block_size;
      base = w * block_size; //start of a block, uses integer division
      
   if (cache[s].tag == -1) {
      //allocate appropriate block in cache
      cache[s].block = (int *)malloc(block_size * sizeof(int));
   }
   if (cache[s].tag != t) {
      if (rw == 1) {
         main_mem[addr] = value;
      }
      //replace/overwrite appropriate block in cache form main mem
      int i;
      for (i = 0; i < block_size; i++) {
         cache[s].block[i] = main_mem[base + i];
      }
      //update tag value to calculated tag value
      cache[s].tag = t;
      //print msg: read/write miss
      if (rw == 1) {
         printf("Write miss!\n");
      } else if (rw == 0) {
         printf("Read miss!\n");
      }
   } else {
      //if read, transfer appropriate word from cache to local var
      if (rw == 0) {
         w = cache[s].block[w];
         value = main_mem[addr];
      } else if (rw == 1) {   
      //write, transfer local var (value to write) to appropriate word in cache
         cache[s].block[w] = w;
         //update mm
         main_mem[addr] = value;
      }//End if

      if (rw == 1) {
         printf("Write hit!\n");
      } else if (rw == 0) {
         printf("Read hit!\n");
      }//End if
   }//End case 3
   printf("Word %d of block %d with tag %d contains value %d\n", w, s, t, value);
   //update cache
   cache[s].block[w] = w;
}//End option_two
   
void quit() {
   exit(0);
}//End quit

int main() {
   int choice;
   
   while(1) {
      printf("\nCache memory allocation and mapping:\n");
      printf("-------------------------------------\n");
      printf("1) Enter parameters\n");
      printf("2) Access cache for reading/writing and transfer data\n");
      printf("3) Quit\n\n");
      
      printf("Enter selection: ");
      scanf("%d", &choice);
      
      switch(choice) {
         case 1: option_one(); break;
         case 2: option_two(); break;
         case 3: quit(); break;
         default: printf("");
      }//End switch
   }//End while

   return 0;
}
