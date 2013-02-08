#ifndef QUAN_HTML2_HEAD_TAG_HPP_INCLUDED
#define QUAN_HTML2_HEAD_TAG_HPP_INCLUDED

#include <quan/html2/head_content.hpp>
#include <list>

namespace quan{ namespace html2{

   struct document;

   struct head_tag : tabber {

      std::list<head_content*> m_content;

      std::ostream & output(std::ostream & os)const{

         os << "<head>\n";
         for (auto p : m_content){
            p->output(os);
         }
         os <<  "</head>\n";
         return os;
      }
      head_tag & push_back( head_content * d_in)
      {
         m_content.push_back(d_in);
         return *this;
      }

      head_tag(): m_document{nullptr}{}
    

      document * get_document() const { return m_document;}

       ~head_tag()
      {
          for (auto p : m_content){
            delete p;
         }
       }
    private :
       document * m_document;
      friend class document;
      void set_document(document * doc) 
      {
         m_document = doc;
         for (auto p : m_content){
           p->set_document(doc);
         }
      }
   };

}}//quan::html

#endif

