#ifndef QUAN_DOM_AS_BRANCH_NODE_HPP_INCLUDED
#define QUAN_DOM_AS_BRANCH_NODE_HPP_INCLUDED

#include <quan/config.hpp>
#if defined QUAN_NO_EXCEPTIONS
#include <cassert>
#endif
#if defined QUAN_NO_RTTI
#error requires rtti
#endif

#include <quan/dom/branch.hpp>
#include <quan/dom/alg/get_full_path_string.hpp>
#include <quan/dom/alg/normalise_id.hpp>

namespace quan{ namespace dom{

    /*
      return the node in as a branch node
      else if in is not a valid branch node then throw exception
    */
    template <typename ID>
    inline
    branch<ID>*
    as_branch_node(node<ID> * in)
    {
#if defined QUAN_NO_EXCEPTIONS
      assert( (in != nullptr) && "empty node in as_branch_node");
#else
      if(!in){
         throw bad_node("empty node in as_branch_node");
      }
#endif

      auto * b = dynamic_cast<branch<ID>*>(in);

#if defined QUAN_NO_EXCEPTIONS
      assert( (b!= nullptr ) && "get_branch: cannot convert node to branch_node");
#else
      if ( b== nullptr){
         std::string str = "get_branch: cannot convert node to branch_node";
         str += " where target node path is ";
         str += get_full_path_string(in);
         throw not_a_branch_node(str);
      }
#endif
      return b;
    }

}}//quan::dom

#endif

