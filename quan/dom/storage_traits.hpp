#ifndef QUAN_DOM_STORAGE_TRAITS_HPP_INCLUDED
#define QUAN_DOM_STORAGE_TRAITS_HPP_INCLUDED

#include <string>

namespace quan{ namespace dom{

    template <typename T>
    struct storage_traits{
        typedef T type;
    };
    template <>
    struct storage_traits<const char*>
    {
        typedef std::string type;
    };
    
    template <>
    struct storage_traits<char*>
    {
        typedef std::string type;
    };
    
    template <>
    struct storage_traits<char* const>
    {
        typedef std::string type;
    };
    
    template <>
    struct storage_traits<const char* const>
    {
        typedef std::string type;
    };
    
    template <int N>
    struct storage_traits< char [N]>
    {
        typedef std::string type;
    };
    
    template <int N>
    struct storage_traits< const char [N]>
    {
        typedef std::string type;
    };

}}//quan::dom

#endif

