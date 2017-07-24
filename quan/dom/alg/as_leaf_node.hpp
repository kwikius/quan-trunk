#ifndef QUAN_DOM_AS_LEAF_NODE_HPP_INCLUDED
#define QUAN_DOM_AS_LEAF_NODE_HPP_INCLUDED

#include <quan/dom/leaf.hpp>

namespace quan{ namespace dom{

 template <typename T, typename NodePtr >
    inline
    typename leaf<typename NodePtr::pointed_type::identifier_type,T>::ptr
    as_leaf_node(NodePtr const & p)
    {
        typedef typename NodePtr::pointed_type::identifier_type identifier_type;
        typedef leaf<identifier_type,T> leaf_type;
        typename leaf_type::ptr d = quan::smart::dyna_cast<leaf_type>(p);
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

