#ifndef QUAN_DOM_ADD_ELEMENT_EXT_HPP_INCLUDED
#define QUAN_DOM_ADD_ELEMENT_EXT_HPP_INCLUDED

#include <quan/dom/leaf.hpp>
#include <quan/dom/alg/get_branch.hpp>
#include <quan/dom/alg/add_element.hpp>

namespace quan{ namespace dom{

    template <typename NodePtr, typename Path, typename ID1,typename T>
    inline
    typename data_node<
      typename NodePtr::pointed_type::identifier_type,
      typename storage_traits<T>::type
    >::ptr
    add_element_ext(NodePtr const & p,Path const & path, ID1 const & id_in,T const & t)
    {
       return add_element(get_branch(p,path),id_in,t);
    }

}}//quan::dom

#endif


