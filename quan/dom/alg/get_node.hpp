#ifndef QUAN_DOM_GET_NODE_HPP_INCLUDED
#define QUAN_DOM_GET_NODE_HPP_INCLUDED

#include <quan/config.hpp>
#if defined QUAN_NO_EXCEPTIONS
#include <cassert>
#endif

#include <quan/dom/node.hpp>
#include <quan/dom/alg/make_path.hpp>
#include <quan/dom/alg/get_full_path_string.hpp>
#include <quan/dom/alg/make_path_string.hpp>
#include <quan/dom/alg/as_branch_node.hpp>

namespace quan{ namespace dom{

   template <typename ID, typename Path>
   inline
   node<ID>*
   get_node( node<ID>* p_in,Path const & path_in)
   {
      auto p = p_in;
#if defined QUAN_NO_EXCEPTIONS
      assert( (p_in != nullptr ) && "bad node in get_node");
#else
      if (!p){
          throw bad_node("bad node in get_node");
      }
#endif
      auto path = make_path(path_in);
    //  for (std::list<identifier_type>::const_iterator iter = path.begin(),end = path.end();
    for (auto iter = path.begin(),end = path.end();
               iter !=end; ++iter){
         auto old_p = p;
         auto br = as_branch_node(p);
         p = br->get_child(*iter);
  #if defined QUAN_NO_EXCEPTIONS
         assert( (p != nullptr ) && "null child in get_node");
  #else
         if ( p == nullptr ){
            //std::string str0 = *iter;
            std::string child = *iter;
            std::string super_path = get_full_path_string(p_in);
            std::string cur_parent_path = get_full_path_string(old_p);
            std::string path_string = make_path_string(path_in);
            std::string str = "In quan::dom::get_node("
               "\"" + super_path + "\",\""
               + path_string + "\"). Child-node \""
               + cur_parent_path + '.' + child + "\" doesnt exist.";
            throw bad_path_string(str);
         }
   #endif
      }
      return p;
   }

}}//quan::dom

#endif

