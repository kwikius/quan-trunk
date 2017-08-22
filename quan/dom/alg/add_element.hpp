#ifndef QUAN_DOM_NODE_ADD_ELEMENT_HPP_INCLUDED
#define QUAN_DOM_NODE_ADD_ELEMENT_HPP_INCLUDED

#include <quan/dom/alg/get_full_path_string.hpp>
#include <quan/dom/alg/as_branch_node.hpp>
#include <quan/dom/storage_traits.hpp>
#include <quan/dom/leaves/data_node.hpp>

namespace quan{ namespace dom{

   /*
      Add data element of type T with id element_id_in ,
      to a branch p 
      return the resulting data node
   */
   template <typename T, typename ID, typename ElementID>
   inline
   data_node< ID,typename storage_traits<T>::type>*
   add_element(node<ID>* p, ElementID const & element_id_in,T const & t)
   {
     if (!p){
         std::string str ="add_element: bad node";
         throw bad_branch_node(str);
     }

     auto element_id = normalise_id(element_id_in);
     auto br = as_branch_node(p);
     if(br->get_child(element_id)){
         std::string str = "add_element: id already_exists";
         throw element_id_already_exists(str);
     }
     typedef typename storage_traits<T>::type sT;
     sT s = t;
     auto element = new data_node<ID,sT>{element_id, s};
     br->add_child(element);
     return element;
   }

}}//quan::dom

#endif
 
