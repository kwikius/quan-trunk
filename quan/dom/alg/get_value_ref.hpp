#ifndef QUAN_DOM_GET_VALUE_REF_HPP_INCLUDED
#define QUAN_DOM_GET_VALUE_REF_HPP_INCLUDED 

#include <quan/dom/leaf.hpp>
#include <quan/dom/alg/get_leaf_node.hpp>

namespace quan{ namespace dom{

    template <typename T, typename ID, typename Path>
    inline
    T & get_value_ref(node<ID>* p_in,Path const & path)
    {
       return get_leaf_node<T>(p_in,path)->get_data_ref();
    }
    
}}//quan::dom

#endif //QUAN_DOM_GET_VALUE_REF_HPP_INCLUDED

