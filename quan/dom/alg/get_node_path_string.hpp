#ifndef QUAN_DOM_GET_NODE_PATH_STRING_HPP_INCLUDED
#define QUAN_DOM_GET_NODE_PATH_STRING_HPP_INCLUDED

#include <quan/dom/alg/make_path_string.hpp>
#include <quan/dom/alg/get_node_path.hpp>

namespace quan{ namespace dom{

    
    template <typename ID>
    inline
    std::basic_string<typename ID::char_type> 
    get_node_path_string(node<ID>* p, bool add_leading_dot=true)
    { 
       return  make_path_string(get_node_path(p,false),add_leading_dot);
    }


}}//quan::dom

#endif

