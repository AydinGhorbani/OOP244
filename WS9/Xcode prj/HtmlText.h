/*
 ****************************************
 Full Name  : Aydin Ghorbani
 Student ID#: 124170226
 Email      : aghorbani8@myseneca.ca
 
 completion date (updated) : 9/june/23
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
#include "cstring.h"
namespace sdds {
   class HtmlText :  public Text {
       char* m_title{};
   public:
       HtmlText(const char* filename=nullptr, const char* title = nullptr);
       HtmlText(const HtmlText& src);
       HtmlText &operator=(const HtmlText& src);
       virtual ~HtmlText();
       void write(std::ostream &ostr) const;
   };
}
#endif // !SDDS_HTMLTEXT_H__
