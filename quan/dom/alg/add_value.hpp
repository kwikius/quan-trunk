#ifndef QUAN_DOM_NODE_ADD_VALUE_HPP_INCLUDED
#define QUAN_DOM_NODE_ADD_VALUE_HPP_INCLUDED

#include <quan/config.hpp>
#if defined QUAN_NO_EXCEPTIONS
#include <cassert>
#endif

#include <quan/dom/alg/get_full_path_string.hpp>
#include <quan/dom/alg/as_branch_node.hpp>
#include <quan/dom/storage_traits.hpp>
#include <quan/dom/leaves/data_node.hpp>

namespace quan{ namespace dom{

   /*
      Add value of type T with id value_id_in ,
      to a branch p 
      return the resulting data node
   */
   template <typename T, typename ID, typename ValueID>
   inline
   data_node<ID,typename storage_traits<T>::type>*
   add_value(node<ID>* p, ValueID const & value_id_in,T const & t)
   {
#if defined QUAN_NO_EXCEPTIONS
      assert ( (p != nullptr) && "nullptr in add_value");
#else
      if (!p){
         std::string str ="add_value: bad node";
         throw bad_branch_node(str);
      }
#endif
      auto value_id = normalise_id(value_id_in);
      auto br = as_branch_node(p);
#if defined QUAN_NO_EXCEPTIONS
      assert ((br->get_child(value_id) == nullptr) && "add_value: id already_exists");
#else
      if(br->get_child(value_id)){
         std::string str = "add_value: id already_exists";
         throw element_id_already_exists(str);
      }
#endif
      typedef typename storage_traits<T>::type sT;
      sT s = t;
      auto n = new data_node<ID,sT>{value_id, s};
      br->add_child(n);
      return n;
   }

   
    /*
      add element of type T with id id_in to a distant sub-branch(referenced by Path path) of branch p
    */
    template <typename T, typename ID, typename Path, typename ID1>
    inline
    data_node<ID,typename storage_traits<T>::type>*
    add_value(node<ID>*  p,Path const & path, ID1 const & id_in,T const & t)
    {
       return add_value(get_branch(p,path),id_in,t);
    }

}}//quan::dom

#endif
 
