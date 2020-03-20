#ifndef QUAN_DOM_IS_BRANCH_NODE_HPP_INCLUDED
#define QUAN_DOM_IS_BRANCH_NODE_HPP_INCLUDED

#include <quan/config.hpp>
#if defined QUAN_NO_EXCEPTIONS
#endif
#if defined QUAN_NO_RTTI
#error requires rtti
#endif
#include <quan/dom/branch.hpp>

namespace quan{ namespace dom{

    /*
      return the node in as a branch node
      if valid else nullptr
    */
   template <typename ID>
   inline
   branch<ID>*
   is_branch_node(node<ID> * in)
   {
      return  dynamic_cast<branch<ID>*>(in);
   }

}}//quan::dom

#endif

