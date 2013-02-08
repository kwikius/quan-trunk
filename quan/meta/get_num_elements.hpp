#ifndef QUAN_META_GET_NUM_ELEMENTS_HPP_INCLUDED
#define QUAN_META_GET_NUM_ELEMENTS_HPP_INCLUDED

#include <quan/meta/strip_cr.hpp>
#include <quan/archetypes/scalar.hpp>
#include <quan/is_model_of.hpp>
#include <quan/meta/int32.hpp>

namespace quan{ namespace meta{

    namespace impl{

       template <typename T, typename Where = void>
       struct get_num_elements_impl {};
        
       template <
         typename T
       >
       struct get_num_elements_impl<T, 
         typename quan::where_<
            quan::is_model_of<quan::Scalar,T>
         >::type
       > : quan::meta::int32<1>{};
       
    }

    template <typename T> struct get_num_elements : 
    quan::meta::impl::get_num_elements_impl<typename strip_cr<T>::type>{};

}}


#endif // QUAN_META_GET_NUM_ELEMENTS_HPP_INCLUDED
