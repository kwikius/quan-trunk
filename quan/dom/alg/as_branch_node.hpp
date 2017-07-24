#ifndef QUAN_DOM_AS_BRANCH_NODE_HPP_INCLUDED
#define QUAN_DOM_AS_BRANCH_NODE_HPP_INCLUDED

#include <quan/dom/branch.hpp>
#include <quan/dom/alg/get_full_path_string.hpp>
#include <quan/dom/alg/normalise_id.hpp>

namespace quan{ namespace dom{

    template <typename NodePtr>
    inline
    typename branch<typename NodePtr::pointed_type::identifier_type>::ptr
    as_branch_node(NodePtr const & in)
    {
      if(!in){
         throw bad_node("empty node in as_branch_node");
      }
      typedef branch<typename NodePtr::pointed_type::identifier_type> branch_type;
      typename branch_type::ptr b = dynamic_cast<typename branch_type::ptr>(in);
      if(b){
         return b;
      }
      std::string str = "get_branch: cannot convert node to branch_node";
      str += " where target node path is ";
      str += get_full_path_string(in);
      throw not_a_branch_node(str);
      
    }

}}//quan::dom

#endif

