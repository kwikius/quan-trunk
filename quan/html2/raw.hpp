#ifndef QUAN_HTML2_RAW_HPP_INCLUDED
#define QUAN_HTML2_RAW_HPP_INCLUDED

#include <quan/html2/body_content.hpp>

/*
   output raw html stuff with no processing
*/

#include <string>

namespace quan{ namespace html2{
   
   struct raw : body_content{

      raw(std::string * in) : m_pstr(in){}
      ~raw(){delete m_pstr;}

      std::ostream & output(std::ostream & os)const
      {
         os << *m_pstr ;
         return os;
      }
      bool is_inline_element()const {return true;}
      
   private:
      std::string*  m_pstr;
   };


}}//quan::html2


#endif

