#ifndef QUAN_DOM_GET_NODE_PATH_EXT_HPP_INCLUDED
#define QUAN_DOM_GET_NODE_PATH_EXT_HPP_INCLUDED

#include <quan/dom/alg/get_node.hpp>
#include <quan/dom/alg/get_node_path.hpp>

namespace quan{ namespace dom{

    template <typename NodePtr, typename Path>
    inline
    std::list<typename NodePtr::pointed_type::identifier_type> 
    get_node_path_ext( NodePtr const & p_in,Path const & path_in)
    {
        typedef typename NodePtr::pointed_type::identifier_type identifier_type;
        typename node<identifier_type>::ptr v = quan::dom::get_node(p_in,path_in);
        return quan::dom::get_node_path(v);
    }

}}//quan:;dom

#endif

