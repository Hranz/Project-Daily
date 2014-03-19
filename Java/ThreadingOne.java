/*
   Programmer: Kristoffer Larson
   Date: March 19, 2014
   
   Description: Creates a thread, starts it, updates j
      and puts the thread to sleep for 1 ms. If the thread
      isn't put to sleep j updates faster than a thread can
      be created and run.
*/



public class ThreadingOne implements Runnable {
   
   static int j = 0;
   
   public static int num() {
      return j = j + 1;
   }
   
   public void run() {
      System.out.println("Hello from a thread!" + j);
      
   }

   public static void main(String args[]) throws InterruptedException {
      for (int i = 0; i < 10; i++) {
         (new Thread(new ThreadingOne())).start();
         j = num();
         //Thread.sleep(1); //Having a thread sleep slows it down enough to print a new int
      }
      System.out.println(java.lang.Thread.activeCount());
   }
   
}
