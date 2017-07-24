#ifndef QUAN_DOM_NODE_ADD_ELEMENT_HPP_INCLUDED
#define QUAN_DOM_NODE_ADD_ELEMENT_HPP_INCLUDED


#include <quan/dom/alg/get_full_path_string.hpp>
#include <quan/dom/alg/as_branch_node.hpp>
#include <quan/dom/storage_traits.hpp>
#include <quan/dom/leaves/data_node.hpp>


namespace quan{ namespace dom{

    template <typename NodePtr, typename ID1,typename T>
    inline
    typename data_node<
      typename NodePtr::pointed_type::identifier_type,
      typename storage_traits<T>::type
    >::ptr
    add_element(NodePtr const &  p, ID1 const & id_in,T const & t)
    {
        if (!p){
            std::string str ="add_element: bad node";
            throw bad_branch_node(str);
        }
        typedef typename NodePtr::pointed_type::identifier_type identifier_type;
        identifier_type id = normalise_id(id_in);
        typename branch<identifier_type>::ptr br = as_branch_node(p);
        if(br->get_child(id)){
            std::string str = "add_element: id already_exists";
            throw element_id_already_exists(str);
        }
        typedef typename storage_traits<T>::type sT;
        sT s = t;
        typename data_node<identifier_type,sT>::ptr d 
         = quan::smart::gc_alloc<data_node<identifier_type,sT> >(id, s);
         br->add_child(d);
         return d;
    }

}}//quan::dom

#endif
 
