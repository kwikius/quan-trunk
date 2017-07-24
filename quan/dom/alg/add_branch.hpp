#ifndef QUAN_DOM_ADD_BRANCH_HPP_INCLUDED
#define QUAN_DOM_ADD_BRANCH_HPP_INCLUDED


#include <quan/dom/container_data.hpp>
#include <quan/dom/alg/get_full_path_string.hpp>
#include <quan/dom/alg/normalise_id.hpp>
#include <quan/dom/alg/as_branch_node.hpp>
#include <quan/dom/storage_traits.hpp>
#include <quan/dom/except.hpp>

namespace quan{ namespace dom{

   template <
      typename ContainerTag,
      typename NodePtr, typename ID1
   >
   inline
   typename container_node<ContainerTag>::ptr
   add_branch(NodePtr const & p, ID1 const & id_in)
   {
      if (!p){
         std::string str = "add_branch: bad branch_node";
         throw bad_branch_node(str);
      }
      
      typedef typename ContainerTag::identifier_type id_type;
      typename branch<id_type>::ptr br = as_branch_node(p);
      id_type id = normalise_id(id_in);
      if(br->get_child(id)){
         std::string str = "add_branch: id  already_exists";
         throw element_id_already_exists(str);
      }
      typedef container_node<ContainerTag> container_node_type;;
      typename container_node_type::ptr child_branch 
      = new container_node_type{id};
      br->add_child(child_branch);
      return child_branch;
   }

   template <
   typename ContainerTag, 
   typename NodePtr, typename ID1, typename T
   >
   inline
   typename container_data<ContainerTag,T>::ptr
   add_branch(NodePtr const &  p, ID1 const & id_in,T const & t)
   {
      if (!p){
         std::string str ="add_element: bad node";
         throw bad_branch_node(str);
      }
      typedef typename ContainerTag::identifier_type id_type;
      typename branch<id_type>::ptr br = as_branch_node(p);
      id_type id = normalise_id(id_in);
      
      if(br->get_child(id)){
         std::string str = "add_element: id already_exists";
         throw element_id_already_exists(str);
      }
      typedef typename storage_traits<T>::type sT;
      sT s = t;

      typedef container_data<ContainerTag,T> cont_data_node;
      
      typename cont_data_node::ptr d = new cont_data_node{id,s};

      br->add_child(d);
      
      return d;
   }

}}//quan::dom

#endif

