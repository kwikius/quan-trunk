#ifndef QUAN_DOM_GET_FULL_PATH_STRING_HPP_INCLUDED
#define QUAN_DOM_GET_FULL_PATH_STRING_HPP_INCLUDED

#include <quan/dom/alg/make_path_string.hpp>
#include <quan/dom/alg/get_node_path.hpp>
#include <string>

namespace quan{ namespace dom{

   template <typename IDType>
   inline
   std::string
   get_full_path_string(node<IDType>* p, bool add_leading_dot=false)
   {
      return  make_path_string(get_node_path(p,true),add_leading_dot);
   }

}}//quan::dom

#endif

