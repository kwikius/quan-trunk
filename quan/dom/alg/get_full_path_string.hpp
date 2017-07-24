#ifndef QUAN_DOM_GET_FULL_PATH_STRING_HPP_INCLUDED
#define QUAN_DOM_GET_FULL_PATH_STRING_HPP_INCLUDED

#include <quan/dom/alg/make_path_string.hpp>
#include <quan/dom/alg/get_node_path.hpp>

namespace quan{ namespace dom{

   template <typename NodePtr>
   inline
   std::basic_string<typename NodePtr::pointed_type::identifier_type::char_type>
   get_full_path_string(NodePtr const & p, bool add_leading_dot=false)
   {
      return  make_path_string(get_node_path(p,true),add_leading_dot);
   }

}}//quan::dom

#endif

