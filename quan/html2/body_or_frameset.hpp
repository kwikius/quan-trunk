#ifndef QUAN_HTML2_BODY_OR_FRAMESET_HPP_INCLUDED
#define QUAN_HTML2_BODY_OR_FRAMESET_HPP_INCLUDED

#include <quan/html2/tabber.hpp>

#include <iosfwd>

namespace quan{ namespace html2{

   struct document;

   struct body_or_frameset : tabber{
      virtual ~body_or_frameset(){}
      virtual std::ostream & output(std::ostream & os)const =0;
       document* get_document() const { return m_pdoc;}

      private :
        document* m_pdoc;
        friend class document;
        void set_document( document * pdoc){ 
         m_pdoc = pdoc;
        }
   };

}}//quan::html

#endif

