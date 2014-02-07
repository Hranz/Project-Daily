/*
   Programmer: Kristoffer Larson
   Date: February 6,2014
   
   Description: Tests the creation of threads in C++
      by creating threads and performing two different tasks
      depending on the number of the thread that was created.
*/

#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS     5

void *test1(void *threadid) {
   long tid;
   tid = (long)threadid;
   cout << "Even, Thread num: " << tid << endl;
   pthread_exit(NULL);
}//End test1

void *test2(void *threadid) {
   long tid;
   tid = (long)threadid;
   cout << "Odd, Thread num: " << tid << endl;
   pthread_exit(NULL);
}//End test2

int main () {
   pthread_t threads[NUM_THREADS];
   int rc;
   int i;
   for( i=0; i < NUM_THREADS; i++ ){
      cout << "Creating thread, " << i << endl;
               
      if (i % 2 == 0)
         rc = pthread_create(&threads[i], NULL, test1, (void *)i);
      else
         rc = pthread_create(&threads[i], NULL, test2, (void *)i);
         
      if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }//End if

   }//End for
   pthread_exit(NULL);
   return 0;
}//End main
