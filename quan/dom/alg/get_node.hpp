#ifndef QUAN_DOM_GET_NODE_HPP_INCLUDED
#define QUAN_DOM_GET_NODE_HPP_INCLUDED

#include <quan/dom/node.hpp>
#include <quan/dom/alg/make_path.hpp>
#include <quan/dom/alg/get_full_path_string.hpp>
#include <quan/dom/alg/make_path_string.hpp>
#include <quan/dom/alg/as_branch_node.hpp>

namespace quan{ namespace dom{

   template <typename NodePtr, typename NodePath>
   inline
   typename node<typename NodePtr::pointed_type::identifier_type>::ptr
   get_node( NodePtr const & p_in,NodePath const & path_in)
   {
      typedef typename NodePtr::pointed_type::identifier_type identifier_type;
     /* if (!p_in){
          throw bad_node("empty node in get_node");
      }
      typename node<identifier_type>::ptr p = quan::smart::dyna_cast<node<identifier_type> >(p_in); */
      typename node<identifier_type>::ptr p = p_in;
      if (!p){
          throw bad_node("bad node in get_node");
      }
      std::list<identifier_type> path = make_path(path_in);
    //  for (std::list<identifier_type>::const_iterator iter = path.begin(),end = path.end();
    for (auto iter = path.begin(),end = path.end();
               iter !=end; ++iter){
         typename node<identifier_type>::ptr old_p = p;
         typename branch<identifier_type>::ptr br = as_branch_node(p);
         if (! (p= br->get_child(*iter)) ){
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
      }
      return p;
   }

}}//quan::dom

#endif

