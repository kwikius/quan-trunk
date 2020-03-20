#ifndef QUAN_DOM_ADD_BRANCH_HPP_INCLUDED
#define QUAN_DOM_ADD_BRANCH_HPP_INCLUDED

#include <quan/config.hpp>

#if defined QUAN_NO_EXCEPTIONS
#include <cassert>
#endif
#include <quan/dom/branch.hpp>
#include <quan/dom/alg/get_full_path_string.hpp>
#include <quan/dom/alg/normalise_id.hpp>
#include <quan/dom/alg/as_branch_node.hpp>
#include <quan/dom/storage_traits.hpp>
#include <quan/dom/except.hpp>

namespace quan{ namespace dom{

   /*
      Add a new child branch 
      identified by child_branch_id, 
      to the node p
      and return a pointer to it
      else if p is null throw an exception
      or if p is not a branch throw an exception
      or if there is already a branch of that name throw exception
   */

   template <
      typename ID, typename ChildID
   >
   inline
   branch<ID>*
   add_branch(node<ID> * p, ChildID const & child_branch_id)
   {
#if defined QUAN_NO_EXCEPTIONS
      assert( (p != nullptr) && "add_branch: bad branch_node");
#else
      if (!p){
         std::string str = "add_branch: bad branch_node";
         throw bad_branch_node(str);
      }
#endif

      auto br = as_branch_node(p);
      auto id = normalise_id(child_branch_id);

#if defined QUAN_NO_EXCEPTIONS
      assert( (br->get_child(id) == nullptr )  && "add_branch: id  already_exists");
#else
      if(br->get_child(id)){
         std::string str = "add_branch: id  already_exists";
         throw element_id_already_exists(str);
      }
#endif
      auto child_branch = new branch<ID>{id};
      br->add_child(child_branch);
      return child_branch;
   }

      /*
      Add a branch identified by id_in to the distant child of p identified by the path path
   */
   template < 
      typename ID, 
      typename Path, 
      typename ChildID
   >
   inline
   branch<ID>*
   add_branch(node<ID>* p, Path const & path, ChildID const & child_id)
   {
      return add_branch(get_branch(p,path),child_id);
   }

}}//quan::dom

#endif

