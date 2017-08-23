#ifndef QUAN_DOM_GET_ELEMENT_HPP_INCLUDED
#define QUAN_DOM_GET_ELEMENT_HPP_INCLUDED 

#include <quan/dom/leaf.hpp>
#include <quan/dom/alg/get_leaf_node.hpp>

/*
 todo rename to get_value
   get_value<T>(node,path);
*/

namespace quan{ namespace dom{

    template <typename T, typename ID, typename Path>
    inline
    T get_element(node<ID>* p_in,Path const & path)
    { 
       return get_leaf_node<T>(p_in,path)->get_data();
    }
    
}}//quan::dom

#endif

