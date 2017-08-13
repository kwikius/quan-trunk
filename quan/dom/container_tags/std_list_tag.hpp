#ifndef QUAN_DOM_STD_LIST_TAG_HPP_INCLUDED
#define QUAN_DOM_STD_LIST_TAG_HPP_INCLUDED

#include <quan/dom/container_node.hpp>
#include <quan/dom/container_tags/std_sequence_tag.hpp>
#include <quan/dom/alg/add_branch.hpp>
#include <list>

namespace quan{ namespace dom{

   template <typename IDType>
   struct std_list_tag : 
      std_sequence_tag<IDType,std::list<node<IDType>*> >
   {
   };

   template <
      typename IDType, typename Alias
   >
   inline
   container_node<std_list_tag<IDType> >*
   add_list_branch(node<IDType>* p, Alias const & id_in)
   {
      return add_branch<std_list_tag<IDType> >(p,id_in);
   }

   template < 
   typename IDType, typename Alias, typename T
   >
   inline
   container_data<std_list_tag<IDType>,T >*
   add_list_branch(node<IDType>*  p, Alias const & id_in,T const & t)
   {
      return add_branch<std_list_tag<IDType> >(p,id_in,t);
   }

}}//quan::dom

#endif

