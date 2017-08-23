#ifndef QUAN_DOM_GET_BRANCH_HPP_INCLUDED
#define QUAN_DOM_GET_BRANCH_HPP_INCLUDED

#include <quan/dom/branch.hpp>
#include <quan/dom/alg/make_path.hpp>
#include <quan/dom/alg/as_branch_node.hpp>
#include <quan/dom/alg/get_node.hpp>

namespace quan{ namespace dom{

    template <typename ID, typename Path>
    inline
    branch<ID>*
    get_branch(node<ID>* p_in,Path const & path_in)
    {
      return as_branch_node(get_node(p_in,make_path(path_in)));
    }

}}//quan::dom

#endif

