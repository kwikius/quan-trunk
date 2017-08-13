#ifndef QUAN_DOM_FIND_CHILD_HPP_INCLUDED
#define QUAN_DOM_FIND_CHILD_HPP_INCLUDED

#include <quan/dom/alg/normalise_id.hpp>
#include <quan/dom/alg/is_branch_node.hpp>
#include <quan/dom/alg/make_path.hpp>

namespace quan{ namespace dom{

   /*
     return the child node identified by the alias if it exists
     else nullptr
   */
   template <typename ID, typename Alias>
   inline
   node<ID>*
   find_child(node<ID>* n, Alias const & id_in)
   {
      auto p = is_branch_node(n);
      if(p != nullptr) {
          return p->get_child(normalise_id(id_in));
      }
      else{
        return nullptr;
      }
   }

   /*
     return the distant child node identified by the path if it exists
     else nullptr
   */
   template <typename ID, typename Path>
   inline
   node<ID>*
   find_child_ext(node<ID>* n, Path const & path_in)
   {
      auto const path = make_path(path_in);
      
      auto iter = path.begin();
      auto* p = n;
      auto const path_end = path.end();
      while (p && (iter !=path_end )){
         p = find_child(p,*iter);
         ++iter;
      }
      return p;
   }

}}//quan::dom

#endif


