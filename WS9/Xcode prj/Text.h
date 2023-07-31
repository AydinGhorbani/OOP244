#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
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
       
      void read();
      virtual ~Text();
      virtual void write(std::ostream& os)const;
   };
}
#endif // !SDDS_PERSON_H__

