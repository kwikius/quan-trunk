#ifndef QUAN_HTML2_BODY_CONTENT_LIST_HPP_INCLUDED
#define QUAN_HTML2_BODY_CONTENT_LIST_HPP_INCLUDED

#include <quan/html2/body_content.hpp>
#include <list>
#include <cassert>

namespace quan{ namespace html2{

   struct body_content_list : body_content{

      body_content_list(){}
      body_content_list& push_back( body_content * d_in)
      {
         assert(d_in != nullptr);
         d_in->set_parent(this);
         m_content.push_back(d_in);
         return *this;
      }

      std::list<body_content*> & get_list() {return m_content;}

//      virtual std::ostream & output(std::ostream & os)const
//      {
//         for  (auto elem : m_content) {elem->output(os);}
//         return os;
//      }

      ~body_content_list(){ for( auto p : m_content){delete p;} }
    protected:
      std::list<body_content*> m_content;
      
   };

}}//quan::html

#endif

