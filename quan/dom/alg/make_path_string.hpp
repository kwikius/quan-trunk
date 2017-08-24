#ifndef QUAN_DOM_MAKE_PATH_STRING_HPP_INCLUDED
#define QUAN_DOM_MAKE_PATH_STRING_HPP_INCLUDED

#include <list>
#include <string>
#include <quan/atomicstring.hpp>

namespace quan{ namespace dom{

    template <typename CharType>
    inline
    std::basic_string<CharType>
    make_path_string(std::list<atomicstring<CharType> > const & in, bool add_leading_dot = true)
    {
        std::basic_string<CharType> str;
        if (add_leading_dot){
            str += '.';
        }
        typedef typename std::list<atomicstring<CharType> >::const_iterator const_iterator;
        for(const_iterator iter = in.begin(),end = in.end();
                iter!= end;
                ++iter){
            std::basic_string<CharType> t = *iter;
            str+= t;
            const_iterator iter1 = iter;
            if((++iter1) != end){
                str += '.';
            }
        }
        return str;
    }

    template <typename CharType>
    inline
    std::basic_string<CharType>
    make_path_string(std::list<std::basic_string<CharType> > const & in, bool add_leading_dot = true)
    {
        std::basic_string<CharType> str;
        if (add_leading_dot){
            str += '.';
        }
        typedef typename std::list<std::basic_string<CharType> >::const_iterator const_iterator;
        for(const_iterator iter = in.begin(),end = in.end();
                iter!= end;
                ++iter){
            std::basic_string<CharType> t = *iter;
            str += t;
            const_iterator iter1 = iter;
            if((++iter1) != end){
                str += '.';
            }
        }
        return str;
    }

    template <typename CharType>
    inline
    std::basic_string<CharType>  make_path_string(const CharType* str_in)
    {
       return str_in;
    }

    template <typename CharType>
    inline
    std::basic_string<CharType> const & make_path_string(std::basic_string<CharType> const & str_in)
    {
       return str_in;
    }

}}//quan::dom

#endif

