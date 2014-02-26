/*
   Programmer: Kristoffer Larson
   Date: February 26, 2014
   
   Description: Write to a file and read it out.

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void read_file(string sLine) {
   ifstream infile; 
   infile.open("afile3.dat");  
   
   cout << "The word is: " << endl;
   infile >> sLine; 
   cout << sLine << endl;
   
   cout << "The definition is: ";
   while (!infile.eof()) {
      getline(infile, sLine);
      cout << sLine << endl;
   }
   
   infile.close();
}//End read_file

void write_file(string sLine) {
   ofstream outfile;
   outfile.open("afile3.dat");
   string data;
   
   cout << "Enter a word: " << endl;
   getline (cin, sLine);
   //cin >> sLine;
   outfile << sLine << endl;
   
   cout << "Enter a definition: " << endl;
   getline (cin, sLine);
   outfile << sLine << endl;
   
   outfile.close();
}//End write_file

int main () {    
   string sLine;
   
   //write_file(sLine);
   read_file(sLine);   
   
   return 0;
}//End main
