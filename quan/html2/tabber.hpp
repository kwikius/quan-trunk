#ifndef QUAN_HTML2_TABBER_HPP_INCLUDED
#define QUAN_HTML2_TABBER_HPP_INCLUDED

#include <quan/html2/tabs.hpp>

namespace quan{ namespace html2{

   struct tabber{
      virtual ~tabber(){}
      static wordproc::tab_object<2> tabs;
   };

}}//quan::html2

#endif

