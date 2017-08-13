#ifndef QUAN_DOM_GET_NODE_PATH_HPP_INCLUDED
#define QUAN_DOM_GET_NODE_PATH_HPP_INCLUDED

#include <quan/dom/except.hpp>
#include <quan/dom/node.hpp>
#include <quan/dom/alg/make_path_string.hpp>
#include <list>

namespace quan{ namespace dom{

   template <typename IDType>
   inline
   std::list<IDType>
   get_node_path(node<IDType>* p, bool add_head=false)
   {
      if(!p){
         throw bad_branch_node("get_node_path: bad branch_node");
      }
      typedef IDType identifier_type;
      std::list<identifier_type> result;
      auto p1 = p;
      while(! p1->is_head()){
         result.push_front(p1->get_id());
         p1 = p1->get_parent();
         if (!p1){
            std::string str = "get_node_path: orphaned node where partial path is ";
            str += make_path_string(result);
            throw orphaned_node(str);
         }
      }
      if ( add_head){
         result.push_front(p1->get_id());
      }
      return result;
   }


}}//quan::dom

#endif

