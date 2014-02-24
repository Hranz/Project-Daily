/*
   Programmer: Kristoffer Larson
   Date: February 23, 2014
   
   Description: A dictionary using a HashMap to have a key to value access,
      just like with a real dictionary. 
*/
import java.util.HashMap;
import java.util.Iterator;

public class Dictionary {
   
   HashMap<String, String> diction = new HashMap<String, String>();
   
   public Dictionary() {
      create(); 
      
      System.out.println(diction.get("Java")); //Gets the contents using key "Java" and prints them
      System.out.println(diction.get("Scheme")); //Gets the contents using key "Scheme" and prints them
      
      printAll();
   }//End Constructor
   
   public void create() { //Places values into the HashMap
      diction.put("Java", "Coffee");
      diction.put("C", "The third letter in the English alphabet");
      diction.put("C#", "A musical note, enharmonic to D-flat");
      diction.put("Python", "A large snake");
      diction.put("Ruby", "A precious gem, red in color");
      diction.put("Scheme", "Verb: To make plans in a devious way");
      diction.put("Assembly", "A group of people gathered together in one place for a common purpose");
      diction.put("Programmer", "A code monkey");
   }//End create
   
   public void printAll() { //Prints all the values of the HashMap as they were stored
      System.out.println();
      
      //Creates an iterator to step through the HashMap
      Iterator <String> it = diction.values().iterator();
      while (it.hasNext()){
         System.out.println(it.next());
      }//End while
   }//End printAll
   
   public static void main(String[] args) {
      Dictionary d = new Dictionary();
   }//End Main
}//End Class
