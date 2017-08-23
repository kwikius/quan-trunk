#ifndef QUAN_DOM_SET_VALUE_HPP_INCLUDED
#define QUAN_DOM_SET_VALUE_HPP_INCLUDED

#include <quan/dom/alg/get_leaf_node.hpp>

namespace quan{ namespace dom{

 template <typename T, typename ID, typename Path>
    inline
    T& set_value(node<ID>* p_in,Path const & path, T const & in)
    {
        auto d = get_leaf_node<T>(p_in,path);
        return d->get_data_ref() = in;
    }

}}//quan::dom

#endif //QUAN_DOM_SET_VALUE_HPP_INCLUDED


