#ifndef QUAN_DOM_ALG_FIND_BRANCH_HPP_INCLUDED
#define QUAN_DOM_ALG_FIND_BRANCH_HPP_INCLUDED

#include <quan/dom/alg/find_child.hpp>
#include <quan/dom/alg/is_branch_node.hpp>

namespace quan{ namespace dom{

   template <typename ID, typename Path>
   inline
   branch<ID>*
   find_branch(node<ID>* n, Path const & path_in)
   {
      return is_branch_node(find_child(n,path_in));
   }
   
}}

#endif // QUAN_DOM_ALG_FIND_BRANCH_HPP_INCLUDED
