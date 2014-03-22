/*
   Programmer: Kristoffer Larson
   Date: March 22, 2014
   
   Description: Creating threads by extending the Thread
      class. This prevents extending any other class since
      Java only supports single extention in inheritance.
      
*/

public class ThreadingTwo extends Thread {
   
   private int[] array = new int[12];
   private int i = 0;
   private int j;
   
   public ThreadingTwo(int j) { //Used to run an instance of the thread in this class
      this.j = j;
      
   }//End constructor
   
   public void run() {
      while (i < 10) {
            add();
            subtract();
         
         if (i < -10) {
            System.exit(-1);
         }
      }//End while
      
      for (int k = 0; k < array.length; k++) {
         System.out.println(array[k]);
      }//End for
   }//End run() method
   
   public void add() {
      array[i] = i;
      i += 2;
   }//End add() method
   
   public void subtract() {
      array[i] = j;
      i--;
   }
   
   public static void main(String[] args) {
      ThreadingTwo thread = new ThreadingTwo(0);
      ThreadingTwo threadTwo = new ThreadingTwo(1);
      thread.run();
      threadTwo.run();
   }//End main() method

}//End ThreadingTwo class
