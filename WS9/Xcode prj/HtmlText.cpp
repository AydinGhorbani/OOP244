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
      (Text&)*this = src;

      
    if (src.m_title)
    {
        Ut.aloCpy(m_title, src.m_title);
    }
    else m_title = nullptr;
  }
  return *this;
}


void HtmlText::write(std::ostream &os) const {
    os << "<html><head><title>";
    os << (m_title ? m_title : "No title");
    os << "</title></head>\n<body>\n";

    if (m_title) {
        os << "<h1>" << m_title << "</h1>\n";
        bool MS = false;
        const char* content = Text::getContent();

        for (const char* ptr = content; *ptr; ptr++) {
            switch (*ptr) {
                case ' ':
                    os << (MS ? "&nbsp;" : " ");
                    MS = true;
                    break;

                case '<':
                    os << "&lt;";
                    MS = false;
                    break;

                case '>':
                    os << "&gt;";
                    MS = false;
                    break;

                case '\n':
                    os << "<br />\n";
                    MS = false;
                    break;

                default:
                    os << *ptr;
                    MS = false;
                    break;
            }
        }
    }
    os << "</body>\n</html>";
}


}
