#ifndef QUAN_DOM_ADD_BRANCH_EXT_HPP_INCLUDED
#define QUAN_DOM_ADD_BRANCH_EXT_HPP_INCLUDED

#include <quan/dom/alg/get_branch.hpp>
#include <quan/dom/alg/add_branch.hpp>
//#include <quan/dom/container_node.hpp>

namespace quan{ namespace dom{

   /*
      Add a branch identified by id_in to the distant child of p identified by the path path
   */
   template <
      typename ContainerTag, 
      typename ID, 
      typename Path, 
      typename ChildID
   >
   inline
   container_node<ContainerTag>*
   add_branch_ext(node<ID>* p, Path const & path, ChildID const & child_id)
   {
      return add_branch<ContainerTag>(get_branch(p,path),child_id);
   }

}}//quan::dom

#endif

