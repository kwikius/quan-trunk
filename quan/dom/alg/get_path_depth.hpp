#ifndef QUAN_DOM_GET_PATH_DEPTH_HPP_INCLUDED
#define QUAN_DOM_GET_PATH_DEPTH_HPP_INCLUDED

#include <quan/dom/node.hpp>
#include <cassert>

namespace quan{ namespace dom{

   template <typename ID>
   inline
   int get_path_depth(node<ID> const* in)
   {
      if (!in){
         std::string str = "get_path_depth: bad node";
         throw bad_branch_node(str);
      }
      int depth=0;
      auto n =in->get_parent();
      while (n){
         ++depth;
         n = n->get_parent();
      }
      return depth;
   }

}}//quan::dom

#endif

