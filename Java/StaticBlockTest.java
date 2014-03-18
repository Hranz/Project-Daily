/*
   Programmer: Kristoffer Larson
   Date: March 18, 2014
   
   Description: Runs a java program through a static block
      instead of the main method. 
*/

public class StaticBlockTest {

   
   static { //Static initializer block
      System.out.println("Hello static");
   }
   
   public static void main(String[] args) {
      //Required to be here by the JVM
   }
}
