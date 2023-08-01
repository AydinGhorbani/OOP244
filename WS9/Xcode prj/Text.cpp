#include <fstream>
#include "Text.h"
#include "Utils.h"

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
        if (this != &T && m_filename)
        {
            delete[] m_filename;
        }
        if (T.m_filename){
            Ut.reAloCpy(m_filename, T.m_filename);
            read();
        }
        setEmpty();
        return *this;
    }

    Text::Text(const char* filename): m_filename(nullptr) {
        
        std::ifstream file(m_filename);
        
        if (file) {
            // this line is just coded for code readability
            // has no effect on submitter. maybe dose not have any effect on
            // the readablity at all but it helped me :)
            cout << "Error opening file: " << filename << endl;
            return;
        }
        //the only codes needed for copy constructor are lines 45 to 47.
        if(filename){
            Ut.aloCpy(m_filename, filename);
            read();
        }
    }

    void Text::write(std::ostream &os) const {
      if (m_content) os << m_content;
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
