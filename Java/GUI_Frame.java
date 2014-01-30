/*
	Programmer: Kristoffer Larson
	Date: January 29, 2014

	Description: Loads in an image saved in the same folder
      and places it in the background of the frame, to be 
      displayed. I tested this with a picture of a young
      Morgan Freeman.
*/

import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class GUI_Frame extends JPanel {
	 
   private JFrame frame;
   private JPanel panel;
   private BufferedImage img;
   private final String IMAGE = "MorganFreeman.jpg"; //Image file name

   public GUI_Frame(){
       frame = new JFrame();
       frame.setSize(400,400);
       frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
       loadImage();
       frame.getContentPane().add(new GUI_Frame(img));
       frame.setVisible(true);
   }
   
   public GUI_Frame(BufferedImage img) {
      this.img = img;
   }
   
   @Override
   protected void paintComponent(Graphics g) { //Paint the image on the frame
      super.paintComponent(g);
      if (img != null) {
         g.drawImage(img, 0, 0, this);
      }
   }
   
   public void loadImage() { //Load image file in
      try {
         img = ImageIO.read(new File(IMAGE));
      } catch (IOException e) {
         e.printStackTrace();
         System.exit(-1);
      } 
   }
   
   public static void main(String[] args) {
      GUI_Frame test = new GUI_Frame();
   }
}
