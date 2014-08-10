#ifndef QUAN_FUN_TOUPPER_HPP_INCLUDED
#define QUAN_FUN_TOUPPER_HPP_INCLUDED
#include <locale>

namespace quan{ namespace fun{ namespace detail{
   template <typename String>
   struct toupper{
      String & result;
      toupper(String & in) : result(in){}
      void operator()(typename String::value_type const & ch)const
      {
         result+= std::toupper(ch,std::locale());
      }
   };
}
   template <typename Str>
   inline
   detail::toupper<Str>
   toupper(Str & str)
   {
     return detail::toupper<Str>(str);
   }
}}
#endif
