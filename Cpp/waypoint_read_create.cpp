/*
   Programmer: Kristoffer Larson
   Date: February 27, 2014
   
   Description: Read from a file and create a collection of objects.

*/
#include <iostream>
#include <fstream>
using namespace std;

class WayPoint {
   private:
      int x, y, h, cV, g;
      bool visted;
      
   public: 
      //would typically also have all the mutators and accessors
      WayPoint(int x_, int y_, int h_) { //regular waypoints
         x = x_;
         y = y_;
         h = h_;
         visted = false;
      }
      WayPoint(int x_, int y_, int h_, int cV_, int g_){ //gold, city waypoints
         x = x_;
         y = y_;
         h = h_;
         cV = cV_;
         g = g_;
         visted = false;
      }
      int getX() {
         return x;
      }
};

void read_file() {
   ifstream infile; 

   try {
      infile.open("waypoint.txt", ios::in);
      int a, b, c, d, e, f, g, h, count = 0;
      
      while (!infile.eof()) {
         
         infile >> a >> b >> c >> d >> e >> f >> g >> h;
         
         if (d > 0 || e > 0) {
            WayPoint a_wp(a, b, c, d, e);
            cout << a_wp.getX() << endl;
            count++;
         } else {
            WayPoint a_wp(a, b, c);
            cout << a_wp.getX() << endl;
            count++;
         }
      }
      cout << "The number of WayPoints made is: " << count << endl;
      infile.close();
   } catch (ifstream::failure e) {
      cerr << "Exception opening/reading/closing file" << endl;
   }
     
}//End read_file

int main() {
   read_file();
   
   return 0;
}
