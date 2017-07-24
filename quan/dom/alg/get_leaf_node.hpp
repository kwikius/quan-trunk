#ifndef QUAN_DOM_GET_LEAF_NODE_HPP_INCLUDED
#define QUAN_DOM_GET_LEAF_NODE_HPP_INCLUDED
 
#include <quan/dom/alg/get_node.hpp>
#include <quan/dom/alg/as_leaf_node.hpp>

namespace quan{ namespace dom{

    template <typename T, typename NodePtr ,typename Path>
    inline
    typename leaf<typename NodePtr::pointed_type::identifier_type,T>::ptr
    get_leaf_node(NodePtr const & p_in,Path const & path)
    {
        typedef typename NodePtr::pointed_type::identifier_type identifier_type;
        typename node<identifier_type>::ptr p = get_node(p_in,path);
        typename leaf<identifier_type,T>::ptr d  = as_leaf_node<T>(p);
        return d;
    }

}}//quan::dom

#endif
 
