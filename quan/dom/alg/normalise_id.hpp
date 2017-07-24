#ifndef QUAN_DOM_NORMALISE_ID_HPP_INCLUDED
#define QUAN_DOM_NORMALISE_ID_HPP_INCLUDED

#include <quan/dom/string_handle.hpp>

namespace quan{ namespace dom{

    template <typename CharType>
    inline
    string_handle<CharType> normalise_id( std::basic_string<CharType> const & str)
    {
        std::basic_string<CharType>  result = str;
         
        if ( str.size() && str.at(0) == '.'){
            result = result.substr(1,std::string::npos);
        }
      
        return string_handle<CharType> (result);
    }

    template <typename CharType>
    inline
    string_handle<CharType> normalise_id( const CharType * p)
    {
        std::basic_string<CharType> result = p;
         
        if ( result.size() && result.at(0) == '.'){
            result = result.substr(1,std::string::npos);
        }
        return string_handle<CharType> (result);
    }

    template<typename CharType>
    inline
    string_handle<CharType> normalise_id( string_handle<CharType> const & in)
    {
        return in;
    }
   
}}//quan::dom

#endif

