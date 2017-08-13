#ifndef QUAN_DOM_ADD_BRANCH_HPP_INCLUDED
#define QUAN_DOM_ADD_BRANCH_HPP_INCLUDED


#include <quan/dom/container_data.hpp>
#include <quan/dom/alg/get_full_path_string.hpp>
#include <quan/dom/alg/normalise_id.hpp>
#include <quan/dom/alg/as_branch_node.hpp>
#include <quan/dom/storage_traits.hpp>
#include <quan/dom/except.hpp>

namespace quan{ namespace dom{

   /*
      Add a new child branch of style ContainerTag, 
      identified by child_branch_id, 
      to the node p
      and return a pointer to it
      else if p is null throw an exception
      or if p is not a branch throw an exception
      or if there is already a branch of that name throw exception
   */

   template <
      typename ContainerTag, typename ID, typename ChildID
   >
   inline
   container_node<ContainerTag>*
   add_branch(node<ID> * p, ChildID const & child_branch_id)
   {
      if (!p){
         std::string str = "add_branch: bad branch_node";
         throw bad_branch_node(str);
      }

      auto br = as_branch_node(p);
      auto id = normalise_id(child_branch_id);
      if(br->get_child(id)){
         std::string str = "add_branch: id  already_exists";
         throw element_id_already_exists(str);
      }
      typedef container_node<ContainerTag> child_container_type; // type of the branch to be added
      auto child_branch = new child_container_type{id};
      br->add_child(child_branch);
      return child_branch;
   }

   /*
      Add a new child branch of style ContainerTag, 
      identified by child_branch_id, 
      to the node p, initialised with the element t
   */
   template <
      typename T,
      typename ContainerTag,typename ID, typename ChildID 
   >
   inline
   container_data<ContainerTag,T>*
   add_branch(node<ID> * p, ChildID const & child_branch_id,T const & t)
   {
      if (!p){
         std::string str ="add_element: bad node";
         throw bad_branch_node(str);
      }
      //typedef typename ContainerTag::identifier_type id_type;
      auto br = as_branch_node(p);
      auto id = normalise_id(child_branch_id);
      
      if(br->get_child(id)){
         std::string str = "add_element: id already_exists";
         throw element_id_already_exists(str);
      }
      typedef typename storage_traits<T>::type sT;
      sT s = t;
      typedef container_data<ContainerTag,T> child_container_type;
      auto child_branch = new child_container_type{id,s};
      br->add_child(child_branch);
      
      return child_branch;
   }

}}//quan::dom

#endif

