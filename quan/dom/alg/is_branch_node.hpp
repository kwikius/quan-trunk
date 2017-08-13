#ifndef QUAN_DOM_IS_BRANCH_NODE_HPP_INCLUDED
#define QUAN_DOM_IS_BRANCH_NODE_HPP_INCLUDED

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
      if(in){
         return  dynamic_cast<branch<ID>*>(in);
      }else{
         return nullptr;
      }
   }

}}//quan::dom

#endif

