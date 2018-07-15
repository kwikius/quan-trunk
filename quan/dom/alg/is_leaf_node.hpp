#ifndef QUAN_DOM_IS_LEAF_NODE_HPP_INCLUDED
#define QUAN_DOM_IS_LEAF_NODE_HPP_INCLUDED

#include <quan/dom/leaf.hpp>

namespace quan{ namespace dom{

    /*
      return the node in as a leaf node
      else if p is not a valid return null
    */
    template <typename T, typename ID >
    inline
    leaf<ID,T>*
    is_leaf_node(node<ID> * p)
    {
       return dynamic_cast<leaf<ID,T>* >(p);
    }

}}//quan::dom

#endif

