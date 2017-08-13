#ifndef QUAN_DOM_GET_LEAF_NODE_HPP_INCLUDED
#define QUAN_DOM_GET_LEAF_NODE_HPP_INCLUDED
 
#include <quan/dom/alg/get_node.hpp>
#include <quan/dom/alg/as_leaf_node.hpp>

namespace quan{ namespace dom{

    template <typename T, typename ID ,typename Path>
    inline
    leaf<ID,T>*
    get_leaf_node(node<ID>* p_in,Path const & path)
    {
#if 1
        return as_leaf_node<T>(get_node(p_in,path));
#else
        auto p = get_node(p_in,path);
        auto d = as_leaf_node<T>(p);
        return d;
#endif
    }

}}//quan::dom

#endif
 
