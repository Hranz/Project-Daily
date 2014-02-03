/*
   Programmer: Kristoffer Larson
   Date: February 3,2014
   
   Description: Modifying the BoxLayoutDemo from the Oracle
      website, this allows the user to choose which button
      to display when the frame shows. This makes use of
      showInputDialog() and parses the value to an integer.
   
*/
     
import java.awt.*;
import javax.swing.*;

public class GUI_Input {
   public static void addComponentsToPane(Container pane) {
      
      pane.setLayout(new BoxLayout(pane, BoxLayout.Y_AXIS));
      
      String inputValue = JOptionPane.showInputDialog("Please input a value (1-8)");
      int choice = Integer.parseInt(inputValue);
      
      switch(choice) {
         case 1: addAButton("Button 1", pane); break;
         case 2: addAButton("Button 2", pane); break;
         case 3: addAButton("Button 3", pane); break;
         case 4: addAButton("Long-Named Button 4", pane); break;
         case 5: addAButton("5", pane); break;
      }
   }

   private static void addAButton(String text, Container container) {
      JButton button = new JButton(text);
      button.setAlignmentX(Component.CENTER_ALIGNMENT);
      container.add(button);
   }

   private static void createAndShowGUI() {
      //Create and set up the window.
      JFrame frame = new JFrame("Test");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
   
      //Set up the content pane.
      addComponentsToPane(frame.getContentPane());
   
      //Display the window.
      frame.pack();
      frame.setVisible(true);
   }

   public static void main(String[] args) {
      //Schedule a job for the event-dispatching thread:
      //creating and showing this application's GUI.
      javax.swing.SwingUtilities.invokeLater(
            new Runnable() {
               public void run() {
                  createAndShowGUI();
               }
            });
   }
}
