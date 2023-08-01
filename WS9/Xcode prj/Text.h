#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
namespace sdds {
   class Text {
      char* m_filename ;
      char* m_content ;
      int getFileLength()const;
   protected:
    const char& operator[](int index)const;
    Text& operator=(const Text& T);

   public:
    Text(const char* filename=nullptr);
    Text(const Text& T);
    Text() : m_filename(nullptr) , m_content(nullptr){};
      void setEmpty();
      void read();
      void write(std::ostream& os)const;
      virtual ~Text();
   };
    std::ostream &operator<< (std::ostream &os, const Text &src);
}
#endif // !SDDS_PERSON_H__

