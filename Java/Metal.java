/*
   Programmer: Kristoffer Larson
   Date: March 10, 2014
   
   Description: An object with simple qualities of a metal
      including: name, rank, quality, mass, and color.
      
*/

import java.awt.Color;

public class Metal {
   
   private String name, rank;
   private int quality;
   private double mass;
   private Color color;
   
   public Metal(String name, String rank, int quality, double mass, Color color) {
      this.name = name;
      this.rank = rank;
      this.quality = quality;
      this.mass = mass;
      this.color = color;
   }//End Metal() constructor
   
   public String getName() {
      return name;
   }//End getName() method
   
   public String getRank() {
      return rank;
   }//End getRank() method
   
   public int getQuality() {
      return quality;
   }//End getQuality() method
   
   public double getMass() {
      return mass;
   }//End getMass() method
   
   public Color getColor() {
      return color;
   }//End getColor() method

      
   public String toString(){
      return "Name: " + name + ", Rank: " + rank + 
         ", Quality: " + quality + ", Mass: " + mass
         + ", Color: " + color;
   }
}