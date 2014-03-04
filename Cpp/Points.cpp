/*
   Programmer: Kristoffer Larson
   Date: March 3, 2014
   
   Description: Recreating Java's Point2D and Point classes
      in C++ to the best of my ability.

*/

#include <math.h>

class Point2D {
   protected:
      int x, y; //Java's Point2D doesn't have field variables
      Point2D() { }
      
   public:
      virtual double getX() = 0;
      
      virtual double getY() = 0;
      
      virtual void setLocation(double x, double y) = 0;
      
      void setLocation(Point2D &p) {
         this->x = p.x;
         this->y = p.y;
      }
      
      double distanceSq(double x1, double y1, double x2, double y2) {
         return pow((y2 - y1), 2) + pow((x2 - x1), 2);
      }
      
      double distance(double x1, double y1, double x2, double y2) {
         return pow(pow((y2 - y1), 2) + pow((x2 - x1), 2), 0.5);
      }
      
      double distanceSq(double px, double py) {
         return pow((this->y - py), 2) + pow((this->x - px), 2);
      }
      
      double distance(double px, double py) {
         return pow(pow((this->y - py), 2) + pow((this->x - px), 2), 0.5);
      }
      
      double distanceSq(Point2D *pt) {
         return pow((this->y - pt->y), 2) + pow((this->x - pt->x), 2);
      }
      
      double distance(Point2D *pt) {
         return pow(pow((this->y - pt->y), 2) + pow((this->x - pt->x), 2), 0.5);
      }
      
      //clone() and hashCode() are beyond me.
      
      bool equals(Point2D *obj) { //Java's Point2D has it as Object obj
         if ((this->x == obj->x) && (this->y == obj->y)) return true;
         else return false;
      }
};

class Point:Point2D {
   
   public:
      int x, y;
      
      Point() {
         x = 0;
         y = 0;
      }
      
      Point(const Point &p) {
         x = p.x;
         y = p.y;
      }
      
      Point(int x_, int y_) {
         x = x_;
         y = y_;
      }
      
      double getX() { return x; }
      
      double getY() { return y; }
      
      Point getLocation() { return Point(x, y); }
      
      void setLocation(const Point &p) {
         x = p.x;
         y = p.y;
      }
      
      void setLocation(int x_, int y_) {
         x = x_;
         y = y_;
      }
      
      void setLocation(double x_, double y_) {
         x = (int)x_;
         y = (int)y_;
      }
      
      void move(int x_, int y_) {
         x = x_;
         y = y_;
      }
      
      void translate(int dx, int dy) {
         x += dx;
         y += dy;
      }
      
      bool equals(const Point &p) {
         if ((p.x == x) && (p.y == y)) return true;
         else return false;
      }
      
      
};
