#ifndef QUAN_DOM_GET_NODE_PATH_HPP_INCLUDED
#define QUAN_DOM_GET_NODE_PATH_HPP_INCLUDED


#include <quan/config.hpp>
#if defined QUAN_NO_EXCEPTIONS
#include <cassert>
#endif
#include <quan/dom/except.hpp>
#include <quan/dom/node.hpp>
#include <quan/dom/alg/get_node.hpp>
#include <quan/dom/alg/make_path_string.hpp>
#include <list>

namespace quan{ namespace dom{

   template <typename ID>
   inline
   std::list<ID>
   get_node_path(node<ID>* p, bool add_head=false)
   {
#if defined QUAN_NO_EXCEPTIONS
      assert(( p != nullptr ) && "get_node_path: bad branch_node");
#else
      if(!p){
         throw bad_branch_node("get_node_path: bad branch_node");
      }
#endif
      std::list<ID> result;
      auto p1 = p;
      while(! p1->is_head()){
         result.push_front(p1->get_id());
         p1 = p1->get_parent();
#if defined QUAN_NO_EXCEPTIONS
        assert ( (p1 != nullptr) && "get_node_path: orphaned node");
#else
         if (!p1){
            std::string str = "get_node_path: orphaned node where partial path is ";
            str += make_path_string(result);
            throw orphaned_node(str);
         }
#endif
      }
      if ( add_head){
         result.push_front(p1->get_id());
      }
      return result;
   }

    template <typename ID, typename Path>
    inline
    std::list<ID> 
    get_node_path( node<ID> * p_in,Path const & path_in)
    {
       return quan::dom::get_node_path(get_node(p_in,path_in));
    }


}}//quan::dom

#endif

