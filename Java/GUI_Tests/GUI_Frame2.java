/*
   Programmer: Kristoffer Larson
   Date: January 30, 2014
   
   Description: Loads in an image saved in the same folder
      and places it in the panel, to be displayed. 
      First creates the button and then places the image
      icon. Modified from GUI_Frame.
*/

import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.*;

public class GUI_Frame2 extends JPanel {

   private JFrame frame;
   private JPanel panel;
   private JButton button;
   private BufferedImage img;
   private final String IMAGE = "spaceship-space-city-future-clouds.jpg"; //Image file name

   public GUI_Frame2(){
      frame = new JFrame();
      frame.setSize(400,400);
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
      loadImage();
      panel = new JPanel();  
       
      JLabel picLabel = new JLabel(new ImageIcon(img));
      
       
      button = new JButton("Press Me");
      button.addActionListener(
            new ActionListener(){
            
               public void actionPerformed(ActionEvent e){
                  JOptionPane.showMessageDialog(null, "You died! Try again");
                  System.exit(-1);
               }
            });
   
      panel.add(button); 
      panel.add(picLabel);
      frame.add(panel);
      frame.setVisible(true);
   }
   
   public GUI_Frame2(BufferedImage img) {
      this.img = img;
   }
   
   @Override
   protected void paintComponent(Graphics g) { //Paint the image on the frame
      super.paintComponent(g);
      if (img != null) {
         g.drawImage(img, 100, 100, this);
      }
   }
   
   public void loadImage() { //Load image file in
      try {
         img = ImageIO.read(new File(IMAGE));
      } 
      catch (IOException e) {
         e.printStackTrace();
         System.exit(-1);
      }
   }
   
   public static void main(String[] args) {
      GUI_Frame2 test = new GUI_Frame2();
   }
}
