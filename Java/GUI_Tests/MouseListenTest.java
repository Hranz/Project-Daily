/*
   Programmer: Kristoffer Larson
   Date: January 30, 2014
   
   Description: Loads in an image saved in the same folder
      and places it in the panel, to be displayed. 
      First creates the button and then places the image
      icon. Modified from GUI_Frame.
*/

import java.awt.GridLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.*;

public class MouseListenTest extends JPanel implements MouseListener{

   int red = 0;
   int yellow = 0;
   int blue = 0;

   private static void createAndShowGUI() {
       //Create and set up the window.
      JFrame frame = new JFrame("Mouse");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
       //Create and set up the content pane.
      JComponent newContentPane = new MouseListenTest();
      newContentPane.setOpaque(true); //content panes must be opaque
      frame.setContentPane(newContentPane);
        
       //Display the window.
      frame.pack();
      frame.setVisible(true);
   }
   
   public MouseListenTest() {
      super(new GridLayout(0,1));
      JLabel area = new JLabel();
      setBackground(Color.YELLOW);
      setOpaque(true);
   
      area.addMouseListener(this);
      addMouseListener(this);
      setPreferredSize(new Dimension(450, 450));
      setBorder(BorderFactory.createEmptyBorder(20,20,20,20));
   }
   
   public void mousePressed(MouseEvent e) {
      setBackground(Color.GRAY);
   }
     
   public void mouseReleased(MouseEvent e) {
      setBackground(Color.MAGENTA);
   }
     
   public void mouseEntered(MouseEvent e) {
      setBackground(Color.GREEN);
   }
     
   public void mouseExited(MouseEvent e) {
      setBackground(Color.YELLOW);
      red = 0;
   }
     
   public void mouseClicked(MouseEvent e) {
      if (red > 245) red = 0;
      red += 5;
      setBackground(new Color(red, 0, 0));
   }
   
   public static void main(String[] args) {
      javax.swing.SwingUtilities.invokeLater(
            new Runnable() {
               public void run() {
                  createAndShowGUI();
               }
            });
   }
}