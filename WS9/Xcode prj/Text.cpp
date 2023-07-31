#include <fstream>
#include "Text.h"
#include "Utils.h"
#include <iostream>
using namespace std;
namespace sdds {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

Text::Text(const Text& T){
    *this = T;
}
Text& Text::operator=(const Text& T){
    if (this != &T){
        Ut.reAloCpy(m_filename, T.m_filename);
        if (T.m_content){
            m_content = new char[T.getFileLength() + 1];
            Ut.strCpy(m_content, T.m_content);
        }
    }
    return *this;
}

Text::Text(const char* filename): m_content(nullptr), m_filename(nullptr) {
    
    std::ifstream file(m_filename);
    
    if (file) {
        os << "Error opening file: " << filename << endl;
        return;
    }
    
    m_content = new char (getFileLength() + 1);
    file.read(m_content ,getFileLength() );
    m_content[getFileLength()] = '\0';
    file.close();
}








    Text::~Text(){
        delete [] m_filename;
        delete [] m_content;
    }
}
