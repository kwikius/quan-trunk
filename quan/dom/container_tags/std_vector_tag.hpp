#ifndef QUAN_DOM_STD_VECTOR_TAG_HPP_INCLUDED
#define QUAN_DOM_STD_VECTOR_TAG_HPP_INCLUDED

#include <quan/dom/container_node.hpp>
#include <quan/dom/container_tags/std_sequence_tag.hpp>
#include <quan/dom/alg/add_branch.hpp>
#include <quan/dom/alg/as_leaf_node.hpp>
#include <vector>

namespace quan{ namespace dom{

   template <typename IDType>
   struct std_vector_tag : 
      std_sequence_tag<IDType,std::vector<node<IDType>*> >
   {
   };

   template <
      typename IDType, typename Alias
   >
   inline
   container_node<std_vector_tag<IDType> >*
   add_vector_branch(node<IDType>* p, Alias const & id_in)
   {
      return add_branch<std_vector_tag<IDType> >(p,id_in);
   }

   template < 
   typename IDType, typename Alias, typename T
   >
   inline
   container_data<std_vector_tag<IDType>,T >*
   add_vector_branch(node<IDType>*  p, Alias const & id_in,T const & t)
   {
      return add_branch<std_vector_tag<IDType> >(p,id_in,t);
   }

   template <typename IDType>
   inline
   void push_back(node<IDType>*  vector, node<IDType>* element)
   {
      auto * vect = dynamic_cast<container_node<std_vector_tag<IDType> >*>(vector);
      if ( vect) {
         vect->get_container().push_back(element);
      }else{
          throw bad_node("no vector");
      }
   }

   template <typename IDType>
   inline
   node<IDType>*
   get_node_at(node<IDType>*  vector_node, unsigned i)
   {
      auto * vect = dynamic_cast<container_node<std_vector_tag<IDType> >*>(vector_node);
      if ( vect) {
         return vect->get_container().at(i);
      }else{
         throw bad_node("no vector");
      }
   }

   template <typename T, typename IDType>
   inline
   T
   get_element_at(node<IDType>*  vector_node, unsigned i)
   {
      return as_leaf_node<T>(get_node_at(vector_node,i))->get_data(); // may throw
   }

}}//quan::dom

#endif

