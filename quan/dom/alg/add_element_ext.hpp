#ifndef QUAN_DOM_ADD_ELEMENT_EXT_HPP_INCLUDED
#define QUAN_DOM_ADD_ELEMENT_EXT_HPP_INCLUDED

#include <quan/dom/leaf.hpp>
#include <quan/dom/alg/get_branch.hpp>
#include <quan/dom/alg/add_element.hpp>

namespace quan{ namespace dom{

    /*
      add element of type T with id id_in to a distant sub-branch(referenced by Path path) of branch p
    */
    template <typename T, typename ID, typename Path, typename ID1>
    inline
    data_node<ID,typename storage_traits<T>::type>*
    add_element_ext(node<ID>*  p,Path const & path, ID1 const & id_in,T const & t)
    {
       return add_element(get_branch(p,path),id_in,t);
    }

}}//quan::dom

#endif


