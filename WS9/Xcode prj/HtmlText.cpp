#include "HtmlText.h"
#include "Utils.h"

namespace sdds {

HtmlText::HtmlText(const HtmlText& src): Text(src){
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
    *this = src;

    if (m_title) delete[] m_title;
      
    if (src.m_title)
    {
        Ut.aloCpy(m_title, src.m_title);
    }
    else m_title = nullptr;
  }
  return *this;
}


void HtmlText::write(std::ostream &os) const {
    bool multipleSpaces = false;

    // Convert the text file to a simple HTML file
    os << "<html><head><title>";
    if (m_title != nullptr) {
        os << m_title;
    } else {
        os << "No title";
    }
    os << "</title></head>\n<body>\n";

    if (m_title) {
        os << "<h1>" << m_title << "</h1>\n";

        int index = 0;
        char currentChar;

        while ((currentChar = Text::operator[](index)) != '\0') {
            if (currentChar == ' ') {
                if (multipleSpaces) {
                    os << "&nbsp;";
                } else {
                    os << currentChar;
                    multipleSpaces = true;
                }
            } else if (currentChar == '<') {
                os << "&lt;";
                multipleSpaces = false;
            } else if (currentChar == '>') {
                os << "&gt;";
                multipleSpaces = false;
            } else if (currentChar == '\n') {
                os << "<br />\n";
                multipleSpaces = false;
            } else {
                os << currentChar;
                multipleSpaces = false;
            }

            index++;
        }
    }

    os << "</body>\n</html>";
}


}
