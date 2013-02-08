#ifndef QUAN_STRING_CONVERT_HPP
#define  QUAN_STRING_CONVERT_HPP

#include <string>
#include <iostream>
#include <type_traits>
#include <locale>
#include <quan/where.hpp>
#include <quan/meta/bool.hpp>

namespace quan{

     template <typename CharTo, typename CharFrom>
     inline
     typename quan::where_<
        quan::meta::bool_< (sizeof(CharTo) > sizeof(CharFrom))>,
        std::basic_string<CharTo>
     >::type
      convert(std::basic_string<CharFrom> const & in)
     {
        typedef std::ctype<CharTo> ct;
        auto & facet = std::use_facet<ct>(std::locale());
        std::basic_string<CharTo> result;
        for ( auto i = 0U ; i < in.length();++i){
          result += facet.widen(in[i]);
        }
        return result;
     }

     template <typename CharTo, typename CharFrom>
     inline
     typename quan::where_<
         quan::meta::bool_< (sizeof(CharTo) == sizeof(CharFrom))>,
         std::basic_string<CharFrom> const &
     >::type
      convert(std::basic_string<CharFrom> const & in)
     {
        return in;
     }

     template <typename CharTo, typename CharFrom>
     inline
     typename quan::where_<
         quan::meta::bool_< (sizeof(CharTo) < sizeof(CharFrom))>,
         std::basic_string<CharTo>
     >::type
      convert(std::basic_string<CharFrom> const & in)
     {
        typedef std::ctype<CharFrom> ct;
        auto & facet = std::use_facet<ct>(std::locale());
        std::basic_string<CharTo> result;
        for ( auto i = 0U ; i < in.length();++i){
          result += facet.narrow(in[i],'#');
        }
        return result;
     }


}

#endif
