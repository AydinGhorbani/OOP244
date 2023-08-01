/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 9
// Version 1.0
// Description
// tester program
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <fstream>
#include "HtmlText.h"
#include "Text.h"
using namespace std;
using namespace sdds;
void show(Text T)  {
   cout << "*" << T << "*" << endl;
}
void saveHtml(HtmlText H) {
   ofstream("dcwr.html")<<H;
}
void displayFile(const char* filename) {
   cout << "File: " << filename << endl;
   cout << "==================================================" << endl;
   ifstream fin(filename);
   char ch = 0;
   while (fin.get(ch)) {
      cout << ch;
   }
   cout << endl << "==================================================" << endl;
}
int main() {
   Text T("/Users/aydinghorbani/Desktop/OOP245/github/OOP244/WS9/Xcode prj/test.txt");
   Text Y("/Users/aydinghorbani/Desktop/OOP245/github/OOP244/WS9/Xcode prj/dcwr.txt");
   Text Z;
   Y = T;
   Z = Y;
   show(Y);
   HtmlText H1("/Users/aydinghorbani/Desktop/OOP245/github/OOP244/WS9/Xcode prj/dcwr.txt", "Derived Classes and Resources");
   HtmlText H2("/Users/aydinghorbani/Desktop/OOP245/github/OOP244/WS9/Xcode prj/dcwr.txt");
   HtmlText H3;
   H2 = H1;
   H3 = H2;
   saveHtml(H3);
   displayFile("/Users/aydinghorbani/Desktop/OOP245/github/OOP244/WS9/Xcode prj/dcwr.txt");
   return 0;
}
