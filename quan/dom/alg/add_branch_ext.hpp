#ifndef QUAN_DOM_ADD_BRANCH_EXT_HPP_INCLUDED
#define QUAN_DOM_ADD_BRANCH_EXT_HPP_INCLUDED

#include <quan/dom/alg/get_branch.hpp>
#include <quan/dom/alg/add_branch.hpp>
//#include <quan/dom/container_node.hpp>

namespace quan{ namespace dom{

   template <
     typename ContainerTag,
     typename NodePtr, typename Path, typename ID1>
    inline
    typename container_node<ContainerTag>::ptr
    add_branch_ext(NodePtr const & p, Path const & path, ID1 const & id_in)
    {
      return add_branch<ContainerTag>(get_branch(p,path),id_in);
    }

}}//quan::dom

#endif

