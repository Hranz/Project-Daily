/*

Programmers: Kris Larson

Description: Uses JFrame and Timer to create new buttons during 
  the run.
  
*/
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
import java.util.Timer;
import java.util.TimerTask;

public class GUIFun2 extends TimerTask {
	 
   private JFrame frame;
   private JPanel panel;
   private JButton button;
   private JButton button2;
   private static long interval = 1000;
   private int count = 0;
   private String str = "" + count;

   public GUIFun2(){
       frame = new JFrame();
       frame.setSize(500,500);
       frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
       panel = new JPanel();

       button = new JButton(str);
       button.addActionListener(new ActionListener(){

           public void actionPerformed(ActionEvent e){
               JOptionPane.showMessageDialog(null, "You clicked the JButton");
           }
       });
       

       panel.add(button);
       
       frame.add(panel);
       frame.setVisible(true);
       buttonCreation();
   }
   
   public void buttonCreation() {
      count++;
      str = "" + count;
      
      if (count > 100) {
         button2 = new JButton(str);
         button2.addActionListener(new ActionListener(){
         
             public void actionPerformed(ActionEvent e){
                 JOptionPane.showMessageDialog(null, "Wow! You're patient.");
             }
         });
      }
      else {
         button2 = new JButton(str);
         button2.addActionListener(new ActionListener(){
         
             public void actionPerformed(ActionEvent e){
                 JOptionPane.showMessageDialog(null, "Timer! Weeeeh!");
             }
         });
      }
      panel.add(button2);
   }
   
   public void run() {
      buttonCreation();
      frame.setSize(500,501);
      frame.setSize(500,500);
   }
   
   
   public static void main(String[] args) {
      Timer timer = new Timer("Printer");

      GUIFun2 t = new GUIFun2();
 
      timer.schedule(t, 0, interval);
   }
}
