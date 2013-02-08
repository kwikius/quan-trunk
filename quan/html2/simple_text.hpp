#ifndef QUAN_HTML2_SIMPLE_TEXT_HPP_INCLUDED
#define QUAN_HTML2_SIMPLE_TEXT_HPP_INCLUDED

#include <quan/html2/body_content.hpp>
#include <quan/html2/tag_identifier.hpp>
#include <quan/html2/tag_id.hpp>

#include <string>

namespace quan{ namespace html2{
   
   struct simple_text : body_content{

      simple_text( std::string * in) :m_content(in){ assert(m_content !=0);}
      ~simple_text(){ delete m_content;}

      static std::string format( std::string const & in)
      {
         std::string str;
         for( std::string::const_iterator i = in.begin(); i !=in.end(); ++i){
            char ch = *i;
            switch (ch){
               case '<':
                  str += "&lt;";
                  break;
               case '>':
                  str+= "&gt;";
                  break;
               default :
                  str += ch;
                  break;
            }
         }
         return str;
      }

      std::ostream & output(std::ostream & os)const
      {
         os << tabs ;
         if ( m_tag_identifier){
            os << "<font";
            this->m_tag_identifier->output(os);
            os << ">";
         }
         os << format(*m_content);
         if (m_tag_identifier){
            os << "</font>";
         }

         return os;
      }
      bool is_inline_element()const {return true;}
      std::string * get_text(){return m_content;}
   private:
      std::string * m_content;
   };


}}//quan::html


#endif

