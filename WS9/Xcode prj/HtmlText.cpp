/*
 ****************************************
 Full Name  : Aydin Ghorbani
 Student ID#: 124170226
 Email      : aghorbani8@myseneca.ca
 
 
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 ****************************************
 */
#include "HtmlText.h"
#include "cstring.h"


namespace sdds {


HtmlText::HtmlText(const HtmlText& src){
  *this = src;
}

HtmlText:: HtmlText(const char *filename, const char *title) : Text(filename) {
  if (title) Ut.aloCpy(m_title, title);
}



HtmlText::~HtmlText() {
  if (m_title) delete[] m_title;
}


HtmlText &HtmlText::operator=(const HtmlText& src) {
  if (this != &src)
  {
      Text::operator=(src);
      if (m_title)delete[] m_title;
      
    if (src.m_title)
    {
        Ut.aloCpy(m_title, src.m_title);
    }
    else m_title = nullptr;
  }
  return *this;
}


void HtmlText::write(std::ostream &ostr) const {
    const char* ptr{};
    ostr << "<html><head><title>";
    if (m_title) {
        ostr << m_title;
    } else {
        ostr << "No title";
    }
    ostr << "</title></head>\n<body>\n";

    if (m_title) {
        //casting all the file in a static pointer is much more efficient then
        // going though the loop and calling and allocationg memory for insertion
        // operator.
        ostr << "<h1>" << m_title << "</h1>\n";
        bool MS = false;
        
        const char* content = Text::getContent();

        for (ptr = content; *ptr; ptr++) {
            if (*ptr == ' ') {
                ostr << (MS ? "&nbsp;" : " ");
                MS = true;
            } else if (*ptr == '<') {
                ostr << "&lt;";
                MS = false;
            } else if (*ptr == '>') {
                ostr << "&gt;";
                MS = false;
            } else if (*ptr == '\n') {
                ostr << "<br />\n";
                MS = false;
            } else {
                ostr << *ptr;
                MS = false;
            }
        }
    }

    ostr << "</body>\n</html>";
}



}
