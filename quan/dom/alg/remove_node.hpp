#ifndef QUAN_DOM_REMOVE_NODE_HPP_INCLUDED
#define QUAN_DOM_REMOVE_NODE_HPP_INCLUDED

#include <quan/dom/alg/as_branch_node.hpp>
#include <quan/dom/alg/normalise_id.hpp>
#include <quan/dom/alg/get_full_path_string.hpp>

namespace quan{ namespace dom{

    template <typename ID,typename ChildID>
    inline
    void remove_node(node<ID>* n, ChildID const & child_id)
    {
        if (!n){
            std::string str = "remove_node: bad node";
            throw bad_node(str);
        }
        
        auto id = normalise_id(child_id);
        auto br = as_branch_node(n);
        if (! br->remove_child(id)){
            std::string str = "id not found in remove_node";
            str += "where node path is ";
            str += get_full_path_string(n);
            throw bad_id(str);
        }
    }

}}//quan::dom

#endif

