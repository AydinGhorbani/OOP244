/*
 ****************************************
 Full Name  : Aydin Ghorbani
 Student ID#: 124170226
 Email      : aghorbani8@myseneca.ca
 
 completion date (updated) : 9/june/23
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#include <fstream>
#include "Text.h"
#include "cstring.h"

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
        if (T.m_filename){
            Ut.aloCpy(m_filename, T.m_filename);
            read();
        }
        else setEmpty();
        return *this;
    }

    Text::Text(const char* filename){
           if(filename){
            Ut.aloCpy(m_filename, filename);
            read();
        }
    }
    void Text::read() {
        // https://stackoverflow.com/questions/195323/what-is-the-most-elegant-way-to-read-a-text-file-with-c
        // code use in this part is copied. (source above)
        // its used to make the function more efficient and signeficantely faster.
        // alternative way to male function defiation is
        // ifstream _read(m_filename);
        // and a temp variable in the scope of function is needed.
        // Read the file and store it in a string
        
        std::ifstream file(m_filename, std::ios::binary);
        if (m_content) delete[] m_content;
        if (file.is_open()) {
            file.seekg(0, std::ios::end);
            std::streamsize size = file.tellg();
            m_content = new char[size + 1];
            file.seekg(0, std::ios::beg);
            file.read(m_content, size);
            m_content[size] = '\0';
            file.close();
            
        } else {
            m_content = nullptr;
        }
    }
    
    void Text::write(std::ostream &os) const {
      if (m_content) os << m_content;
    }
    
    std::ostream &operator<<(std::ostream &os, const Text& src) {
      src.write(os);
      return os;
    }

    const char &Text::operator[](int index) const {
      if (index >= 0 || index < getFileLength())
        return m_content[index];
      else
        return m_content[getFileLength()];
    }

    void Text::setEmpty(){
        
        m_filename = nullptr;
        m_content = nullptr;
        
    }

        Text::~Text(){
       if (m_filename) delete [] m_filename;
       if (m_content) delete [] m_content;
        }

    const char* Text::getContent() const {
        return m_content;
    }
    }
