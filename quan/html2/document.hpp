#ifndef QUAN_HTML2_DOCUMENT_HPP_INCLUDED
#define QUAN_HTML2_DOCUMENT_HPP_INCLUDED

#include <quan/html2/tabber.hpp>
#include <string>
#include <map>

namespace quan{ namespace html2{

   struct head_tag;
   struct body_or_frameset;

   struct document : tabber {

      document(std::string * title_in, int version_number_in);
      
      ~document();
      std::ostream & output(std::ostream & os);

      void set_root(std::string * in){m_root= in;}
      void set_offset(std::string * in){m_offset = in;}
      void set_head(head_tag* head); 
      void set_body (body_or_frameset * body) ;
      std::string* get_root() const {return m_root;}
      std::string* get_offset() const {return m_offset;}
      std::string* get_title() const {return m_title;}
      body_or_frameset* get_body()const { return m_body;}
      head_tag * get_head() const {return m_head;}
      int get_version_number()const{return m_version_number;}
     
   private:
      head_tag*                           m_head;
      body_or_frameset*                   m_body;
      std::string*                        m_root;
      std::string*                        m_offset;

      std::string*                        m_title;
      std::map<std::string,std::string>   m_resources;
      int                                 m_version_number;
   };

}}//quan::html


#endif

