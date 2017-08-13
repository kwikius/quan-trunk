#ifndef QUAN_DOM_AS_LEAF_NODE_HPP_INCLUDED
#define QUAN_DOM_AS_LEAF_NODE_HPP_INCLUDED

#include <quan/dom/leaf.hpp>

namespace quan{ namespace dom{

    /*
      return the node in as a leaf node
      else if p is not a valid leaf then throw exception
    */
    template <typename T, typename ID >
    inline
    leaf<ID,T>*
    as_leaf_node(node<ID> * p)
    {
        auto d = dynamic_cast<leaf<ID,T>* >(p);
        if(!d){
            std::string str = "get_leaf_node: cannot convert node to leaf_node{";
            str += typeid(T).name();
            str += "}, where target is ";
            str += p->get_type_id();
            str += ", where node path is \"";
            str += get_full_path_string(p);
            str += "\"";
            throw invalid_leaf_node(str);
        }
        return d;
    }

}}//quan::dom

#endif

