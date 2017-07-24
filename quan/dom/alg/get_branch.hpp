#ifndef QUAN_DOM_GET_BRANCH_HPP_INCLUDED
#define QUAN_DOM_GET_BRANCH_HPP_INCLUDED

#include <quan/dom/branch.hpp>
#include <quan/dom/alg/make_path.hpp>
#include <quan/dom/alg/as_branch_node.hpp>
#include <quan/dom/alg/get_node.hpp>

namespace quan{ namespace dom{

    template <typename NodePtr, typename Path>
    inline
    typename branch<typename NodePtr::pointed_type::identifier_type>::ptr
    get_branch(NodePtr const & p_in,Path const & path_in)
    {
      typedef typename NodePtr::pointed_type::identifier_type identifier_type;
      std::list<identifier_type> path = make_path(path_in);
      typename node<identifier_type>::ptr p = get_node(p_in,path);
      typename branch<identifier_type>::ptr b = as_branch_node(p);
      return b;
    }

}}//quan::dom

#endif

