#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
namespace sdds {
   class Text {
       char* m_filename{} ;
       char* m_content{};
      int getFileLength()const;
   protected:
    const char& operator[](int index)const;

    const char* getContent() const;
   public:
    Text(const char* filename=nullptr);
    Text(const Text& T);
    Text& operator=(const Text& T);
      void setEmpty();
      void read();
      virtual void write(std::ostream& os)const;
      virtual ~Text();
   };
    std::ostream &operator<< (std::ostream &os, const Text &src);
}
#endif // !SDDS_PERSON_H__

