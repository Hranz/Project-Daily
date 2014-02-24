/*
   Programmer: Kristoffer Larson
   Date: February 24, 2014
   
   Description: Read one thing from a file and writes it out
      to another file.

*/

#include <iostream>
#include <fstream>
using namespace std;

void read_file(char* data) {
   ifstream infile; 
   infile.open("afile.dat");  
   
   infile >> data; 
   infile.close();
}//End read_file

void write_file(char* data) {
   ofstream outfile;
   outfile.open("afile2.dat");

   outfile << data << endl;
   outfile.close();
}//End write_file

int main () {    
   char data[100];
   
   read_file(data);   
   cout << data << endl;
   write_file(data);
   
   return 0;
}//End main
