/*
   Programmer: Kristoffer Larson
   Date: February 4,2014
   
   Description: Making use of the Oracle sample GUI
      layouts, this program calls the appropriate class
      for the desired layout to be shown. Each main method
      of the demo classes has been turned into a constructor
      for ease of calling from this class.
   
*/

public class LayoutChoice {
  
   public static void main(String[] args) {
      
      String inputValue = JOptionPane.showInputDialog("Please input a value (1-7)");
      int choice = Integer.parseInt(inputValue);
      
      switch(choice) {
         case 1: BorderLayoutDemo.main(args);
            break;
         case 2: BoxLayoutDemo.main(args);
            break;
         case 3: CardLayoutDemo.main(args);
            break;
         case 4: FlowLayoutDemo.main(args);
            break;
         case 5: GridBagLayoutDemo.main(args);
            break;
         case 6: GridLayoutDemo.main(args);
            break;
         case 7: SpringDemo1.main(args);
            break;
         default: System.exit(-1);   
      }//switch
   }//main
}//class
