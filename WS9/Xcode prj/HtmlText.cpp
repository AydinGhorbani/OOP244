#include "HtmlText.h"
#include "cstring.h"
#include <iostream>
using namespace std;
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
    ostr << (m_title ? m_title : "No title");
    ostr << "</title></head>\n<body>\n";

    if (m_title) {
        ostr << "<h1>" << m_title << "</h1>\n";
        bool MS = false;
        const char* content = Text::getContent();

        for (ptr = content; *ptr; ptr++) {
            switch (*ptr) {
                case ' ':
                   ostr << (MS ? "&nbsp;" : " ");
                    MS = true;
                    break;

                case '<':
                    ostr << "&lt;";
                    MS = false;
                    break;

                case '>':
                    ostr << "&gt;";
                    MS = false;
                    break;

                case '\n':
                    ostr << "<br />\n";
                    MS = false;
                    break;

                default:
                    ostr << *ptr;
                    MS = false;
                    break;
            }
        }
    }
    ostr << "</body>\n</html>";
}


}
