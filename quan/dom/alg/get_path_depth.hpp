#ifndef QUAN_DOM_GET_PATH_DEPTH_HPP_INCLUDED
#define QUAN_DOM_GET_PATH_DEPTH_HPP_INCLUDED

#include <quan/dom/node.hpp>
#include <cassert>

namespace quan{ namespace dom{

   template <typename NodePtr>
   inline
   int get_path_depth( NodePtr const & in)
   {
      assert(in);
      int depth=0;
      
      typename node<typename NodePtr::pointed_type::identifier_type>::lazy_ptr n =in->get_parent();
      while (n){
         ++depth;
         n = n->get_parent();
      }
      return depth;
   }

}}//quan::dom

#endif

