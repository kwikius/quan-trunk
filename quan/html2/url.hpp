#ifndef QUAN_HTML2_URL_HPP_INCLUDED
#define QUAN_HTML2_URL_HPP_INCLUDED

#include <iosfwd>
#include <string>

namespace quan{namespace html2{

   struct url  {
     
      virtual std::ostream & output(std::ostream & os)const =0;     
      void set_document( document * doc) { m_document = doc;}
      document * get_document() const { return m_document;}
      virtual std::string get_string() const {assert(m_pstr);return *m_pstr;}
    
      virtual ~url(){ delete m_pstr;}
   protected:
      url (std::string * in) : m_pstr(in){}
   private:
      document * m_document;
      std::string * m_pstr;
      
   };

}}//quan::html2

#endif

