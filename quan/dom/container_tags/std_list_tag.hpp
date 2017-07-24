#ifndef QUAN_DOM_STD_LIST_TAG_HPP_INCLUDED
#define QUAN_DOM_STD_LIST_TAG_HPP_INCLUDED

#include <quan/dom/container_node.hpp>
#include <quan/dom/container_tags/std_sequence_tag.hpp>
#include <quan/dom/alg/add_branch.hpp>
#include <list>

namespace quan{ namespace dom{

   template <typename IdentifierType>
   struct std_list_tag : 
      std_sequence_tag<IdentifierType,std::list<node<IdentifierType>*> >
   {
      static std::string get_type_id()
       {
            return "std::list";
       }
   };

   template <
      typename ID, typename Alias
   >
   inline
   container_node<std_list_tag<ID> >*
   add_list_branch(node<ID>* p, Alias const & id_in)
   {
      return add_branch<std_list_tag<ID> >(p,id_in);
   }

   template < 
   typename ID, typename Alias, typename T
   >
   inline
   container_data<std_list_tag<ID>,T >*
   add_list_branch(node<ID>*  p, Alias const & id_in,T const & t)
   {
      return add_branch<std_list_tag<ID> >(p,id_in,t);
   }

}}//quan::dom

#endif

