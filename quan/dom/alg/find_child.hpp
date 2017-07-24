#ifndef QUAN_DOM_FIND_CHILD_HPP_INCLUDED
#define QUAN_DOM_FIND_CHILD_HPP_INCLUDED

#include <quan/dom/alg/normalise_id.hpp>
#include <quan/dom/alg/as_branch_node.hpp>

namespace quan{ namespace dom{

#if 0
   template <typename NodePtr,typename ID>
   inline
   typename node<typename NodePtr::pointed_type::identifier_type>::ptr
   find_child(NodePtr const & n, ID const & id_in)
   {
      typedef typename NodePtr::pointed_type::identifier_type identifier_type;
      identifier_type id = normalise_id(id_in);
      typename branch<identifier_type>::ptr p = dynamic_cast<branch<identifier_type>* >(n);
      if(p) {
           return p->get_child(id);
      }
      else{
        return typename node<identifier_type>::ptr();
      }
   }
#else
   template <typename ID, typename Alias>
   inline
   node<ID>*
   find_child(node<ID>* n, Alias const & id_in)
   {
      ID id = normalise_id(id_in);
      branch<ID>* p = dynamic_cast<branch<ID>* >(n);
      if(p) {
           return p->get_child(id);
      }
      else{
        return nullptr;
      }
   }
#endif

   template <typename NodePtr, typename Path>
   inline
   typename node<typename NodePtr::pointed_type::identifier_type>::ptr
   find_child_ext(NodePtr const & n, Path const & path_in)
   {
      typedef typename NodePtr::pointed_type::identifier_type identifier_type;
      typedef std::list<identifier_type> list;
      list path = make_path(path_in);
      typename list::const_iterator iter = path.begin();
      typename node<identifier_type>::ptr p = n;
      typename list::const_iterator path_end = path.end();
      while (p && (iter !=path_end )){
         p = find_child(p,*iter);
         ++iter;
      }
      return p;
   }

}}//quan::dom

#endif


