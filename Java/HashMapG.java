/*
   Programmer: Kristoffer Larson
   Date: April 1, 2014
   
   Description: Testing a generic HashMap.

*/
import java.util.HashMap;

public class HashMapG {
   
   public static void main(String[] args) {
      HashMap hm;
      hm = new HashMap();
      
      hm.put(10, 'd');
      hm.put("pie", 67);
      
      System.out.println(hm.get("pie"));
      System.out.println(hm.get(10));
   }// end main
   
   
}// end HashMapG class
