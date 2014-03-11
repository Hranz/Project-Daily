/*
   Programmer: Kristoffer Larson
   Date: March 10, 2014
   
   Description: A comparator class for Metal objects.
      
*/

import java.util.Comparator;

public class MetalComparator implements Comparator<Metal> {
   
   public int compare(Metal one, Metal two) {
      double mOne = one.getQuality() * one.getMass();
      double mTwo = two.getQuality() * two.getMass();
      if (mOne == mTwo) return 0;
      else if (mOne > mTwo) return 1;
      else return -1;
   }//End compare() method
   
}//End MetalComparator class