#ifndef QUAN_DOM_REMOVE_NODE_HPP_INCLUDED
#define QUAN_DOM_REMOVE_NODE_HPP_INCLUDED

#include <quan/config.hpp>
#if defined QUAN_NO_EXCEPTIONS
#include <cassert>
#endif
#include <quan/dom/alg/as_branch_node.hpp>
#include <quan/dom/alg/normalise_id.hpp>
#include <quan/dom/alg/get_full_path_string.hpp>

namespace quan{ namespace dom{

    template <typename ID,typename ChildID>
    inline
    void remove_node(node<ID>* n, ChildID const & child_id)
    {
#if defined QUAN_NO_EXCEPTIONS
        assert ( (n != nullptr) && "remove_node: bad node");
#else
        if (!n){
            std::string str = "remove_node: bad node";
            throw bad_node(str);
        }
#endif        
        auto id = normalise_id(child_id);
        auto br = as_branch_node(n);
#if defined QUAN_NO_EXCEPTIONS
        assert( ( br->remove_child(id) ) && "id not found in remove_node");
#else
        if (! br->remove_child(id)){
            std::string str = "id not found in remove_node";
            str += "where node path is ";
            str += get_full_path_string(n);
            throw bad_id(str);
        }
#endif
    }

}}//quan::dom

#endif

