/*
   Programmer: Kristoffer Larson
   Date: March 8, 2014
   
   Description: A menu for accessing statistics equations
      that will be built up over time.
*/

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class StatsCalc extends JPanel 
                       implements ActionListener {
                      
   public StatsCalc() {
      super(new BorderLayout());
    
      String[] str = { "Bernoulli Distribution", "Binomial Distribution", 
         "Negative Binomial Distribution", "Hypergeometric Distribution", 
         "Poisson Distribution", "More..." };
   
      JComboBox list = new JComboBox(str);
      list.setSelectedIndex(0);
      list.addActionListener(this);

      add(list, BorderLayout.PAGE_START);
      setBorder(BorderFactory.createEmptyBorder(20,20,20,20));
   }//End StatsCalc() constructor
  
  /** Listens to the combo box. */
   public void actionPerformed(ActionEvent e) {
      JComboBox cb = (JComboBox)e.getSource();
      String petName = (String)cb.getSelectedItem();
   }//End actionPerformed() method

   private static void createAndShowGUI() {
      JFrame frame = new JFrame("StatsCalc");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
   
      JComponent newContentPane = new StatsCalc();
      newContentPane.setOpaque(true); 
      frame.setContentPane(newContentPane);
   
      frame.pack();
      frame.setSize(400,100);
      frame.setVisible(true);
   }//End createAndShowGUI() method

   public static void main(String[] args) {
      javax.swing.SwingUtilities.invokeLater(
            new Runnable() {
               public void run() {
                  createAndShowGUI();
               }
            });
   }//End main() method

}//End StatsCalc class
