/*
   Programmer: Kristoffer Larson
   Date: March 10, 2014
   
   Description: Adds objects into a priority queue and prints
      them out in order based on the MetalComparator class.
      
*/

import java.util.PriorityQueue;
import java.awt.Color;

public class PQueue {
   public static void main(String[] args){
   
      Metal titanium = new Metal("Titanium", "A", 8, 10.2, Color.GRAY);
      Metal tin = new Metal("Tin", "G", 1, 4.8, Color.GRAY);
      Metal copper = new Metal("Copper", "F", 2, 3.1, new Color(165, 42, 42));
      Metal lead = new Metal("Lead", "H", 0, 10.2, Color.GRAY);
      Metal steel = new Metal("Steel", "B", 9, 6.0, Color.GRAY);
      Metal gold = new Metal("Gold", "C", 7, 20.5, Color.YELLOW);
   
      PriorityQueue<Metal> PQueue = new PriorityQueue(10, new MetalComparator());
   
      PQueue.add(titanium);
      PQueue.add(tin);
      PQueue.add(gold);
      PQueue.add(copper);
      PQueue.add(lead);
      PQueue.add(steel);
   
      int count = 1;
      while(!PQueue.isEmpty())
      {
         System.out.println("Dequeued " + count + " -->" + PQueue.remove());
         count++;
      }
      System.out.println();
   }//End main() method
}//End PQueue class