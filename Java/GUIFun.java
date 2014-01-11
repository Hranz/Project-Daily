/*

Programmers: Kris Larson

Description: Just fiddling around with JFrame and GUIs in java.

*/



import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
import java.util.ArrayList;

public class GUIFun {
	 
   private JFrame frame;
   private JPanel panel;
   private JButton button;
   private JButton button2;


   public GUIFun(){
       frame = new JFrame();
       frame.setSize(400,400);
       frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
       panel = new JPanel();

       button = new JButton("0");
       button.addActionListener(new ActionListener(){

           public void actionPerformed(ActionEvent e){
               JOptionPane.showMessageDialog(null, "You clicked the JButton");
           }
       });

       panel.add(button);
       otherButtons();
       buttonsCreate();
       
       frame.add(panel);
       frame.setVisible(true);
   }
   
   public void otherButtons() {
      button2 = new JButton("1");
      
      button2.addActionListener(new ActionListener(){

           public void actionPerformed(ActionEvent e){
               JOptionPane.showMessageDialog(null, "");
           }
       });
       
       panel.add(button2);
   }
   
   
   public void buttonsCreate() {
      String str;
            
      for (int count = 0; count < 16; count++) {
         str = "" + count;
         JButton test = new JButton(str);
         
         if (count == 10) {
            test.addActionListener(new ActionListener(){
   
              public void actionPerformed(ActionEvent e){
                  methodAction();
              }
            });
         }
         else {
            test.addActionListener(new ActionListener(){
   
              public void actionPerformed(ActionEvent e){
                  JOptionPane.showMessageDialog(null, "Eventually will be a dynamic message");
              }
            });
         }
         
         panel.add(test);
      } 
   }
   
   public void methodAction() {
      JOptionPane.showMessageDialog(null, "Wooh the method works!");
   }
   
   public static void main(String[] args) {
      GUIFun test = new GUIFun();
   }
}
