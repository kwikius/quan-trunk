#ifndef QUAN_DOM_MAKE_PATH_STRING_WITH_SEP_HPP_INCLUDED
#define QUAN_DOM_MAKE_PATH_STRING_WITH_SEP_HPP_INCLUDED

#include <list>
#include <string>
#include <quan/dom/string_handle.hpp>
#include <quan/dom/alg/make_path.hpp>

namespace quan{ namespace dom{

    inline
    std::string 
    make_path_string_with_sep(std::list<string_handle> const & in, std::string const & sep)
    {
        std::string str;
       /* if (add_leading_dot){
            str += sep;
        }*/
        typedef std::list<string_handle>::const_iterator const_iterator;
        for(const_iterator iter = in.begin(),end = in.end();
                iter!= end;
                ++iter){
            std::string t = *iter;
            str+= t;
            const_iterator iter1 = iter;
            if((++iter1) != end){
                str += sep;
            }
        }
        return str;
    }
    
    inline
    std::string  make_path_string_with_sep(std::string const & str, std::string const & sep)
    {
        std::list<string_handle> path = make_path<string_handle>(str);
        return make_path_string_with_sep(path,sep);
    }

}}//quan::dom

#endif

