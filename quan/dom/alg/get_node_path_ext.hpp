#ifndef QUAN_DOM_GET_NODE_PATH_EXT_HPP_INCLUDED
#define QUAN_DOM_GET_NODE_PATH_EXT_HPP_INCLUDED

#include <quan/dom/alg/get_node.hpp>
#include <quan/dom/alg/get_node_path.hpp>

namespace quan{ namespace dom{

    template <typename ID, typename Path>
    inline
    std::list<ID> 
    get_node_path_ext( node<ID> * p_in,Path const & path_in)
    {
       return quan::dom::get_node_path(get_node(p_in,path_in));
    }

}}//quan:;dom

#endif

