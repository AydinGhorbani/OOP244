#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
#include "Utils.h"
namespace sdds {
   class HtmlText :  public Text {
      char* m_title;
   public:
       HtmlText(const char* filename=nullptr, const char* title = nullptr);
       HtmlText(const HtmlText& src);
       HtmlText &operator=(const HtmlText& src);
       virtual ~HtmlText();
       void write(std::ostream &os) const;
   };
}
#endif // !SDDS_HTMLTEXT_H__
