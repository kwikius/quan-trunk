#ifndef QUAN_DOM_GET_ELEMENT_REF_HPP_INCLUDED
#define QUAN_DOM_GET_ELEMENT_REF_HPP_INCLUDED 

#include <quan/dom/leaf.hpp>
#include <quan/dom/alg/get_leaf_node.hpp>

namespace quan{ namespace dom{

    template <typename T, typename NodePtr, typename Path>
    inline
    T & get_element_ref(NodePtr const & p_in,Path const & path)
    {
        typedef typename NodePtr::pointed_type::identifier_type identifier_type;
        typename leaf<identifier_type,T>::ptr d = get_leaf_node<T>(p_in,path);
        return d->get_data_ref();
    }
    
}}//quan::dom

#endif

