/*
   Programmer: Kristoffer Larson
   Date: February 12, 2014
   
   Description: Sets up RadioButtons and prints their name
      when selected. Also uses setMnemonic to give access to
      keyboard commands in choosing a button.

*/
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
 
public class RadioButtons extends JPanel implements ActionListener {
   static String one = "asdf";
   static String two = "qwerty";
   static String three = "erdfy";
   static String four = "jkli";
   static String five = "rorxo";

   public RadioButtons() {
      super(new BorderLayout());
   
      //Create the radio buttons.
      JRadioButton aButton = new JRadioButton(one);
      aButton.setMnemonic(KeyEvent.VK_A);
      aButton.setActionCommand(one);
      aButton.setSelected(true);
   
      JRadioButton bButton = new JRadioButton(two);
      bButton.setMnemonic(KeyEvent.VK_Q);
      bButton.setActionCommand(two);
   
      JRadioButton cButton = new JRadioButton(three);
      cButton.setMnemonic(KeyEvent.VK_E);
      cButton.setActionCommand(three);
   
      JRadioButton dButton = new JRadioButton(four);
      dButton.setMnemonic(KeyEvent.VK_J);
      dButton.setActionCommand(four);
   
      JRadioButton eButton = new JRadioButton(five);
      eButton.setMnemonic(KeyEvent.VK_R);
      eButton.setActionCommand(five);
   
      //Group the radio buttons. Only one can be selected at a time.
      ButtonGroup group = new ButtonGroup();
      group.add(aButton);
      group.add(bButton);
      group.add(cButton);
      group.add(dButton);
      group.add(eButton);
    
      //Register a listener for the radio buttons.
      aButton.addActionListener(this);
      bButton.addActionListener(this);
      cButton.addActionListener(this);
      dButton.addActionListener(this);
      eButton.addActionListener(this); 
   
      //Put the radio buttons in a column in a panel.
      JPanel radioPanel = new JPanel(new GridLayout(0, 1));
      radioPanel.add(aButton);
      radioPanel.add(bButton);
      radioPanel.add(cButton);
      radioPanel.add(dButton);
      radioPanel.add(eButton);
   
      add(radioPanel, BorderLayout.LINE_START);
      setBorder(BorderFactory.createEmptyBorder(20,20,20,20));
   }//End Constructor

   /** Listens to the radio buttons. */
   public void actionPerformed(ActionEvent e) {
      System.out.printf("%s\n", e.getActionCommand());
   }//End actionPerformed

   private static void createAndShowGUI() {
      //Create and set up the window.
      JFrame frame = new JFrame("RadioButtons");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
   
      //Create and set up the content pane.
      JComponent newContentPane = new RadioButtons();
      newContentPane.setOpaque(true); //content panes must be opaque
      frame.setContentPane(newContentPane);
   
      //Display the window.
      frame.pack();
      frame.setVisible(true);
   }//End createAndShowGUI

   public static void main(String[] args) {
      //Schedule a job for the event-dispatching thread:
      //creating and showing this application's GUI.
      javax.swing.SwingUtilities.invokeLater(
            new Runnable() {
               public void run() {
                  createAndShowGUI(); 
               }//End run
            });//End Thread
   }//End Main
}//End Class
