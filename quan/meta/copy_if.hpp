#ifndef QUAN_META_COPY_IF_HPP_INCLUDED
#define QUAN_META_COPY_IF_HPP_INCLUDED

#include <quan/meta/type_sequence.hpp>
#include <quan/meta/eval_if.hpp>

namespace quan{ namespace meta{

    namespace detail{

       template <typename SrcList, typename TargetList, typename Pred> struct copy_if_i {
        
          typedef typename quan::meta::front<SrcList>::type src_element;

         // should be Pred::apply<src_element_type>::type is true or false
          typedef typename quan::meta::eval_if<
               typename Pred::template apply<src_element>,
               quan::meta::push_back<TargetList,src_element>,
               TargetList
           >::type target_list;

          typedef typename quan::meta::pop_front<SrcList>::type list_in_next;

          typedef typename quan::meta::eval_if_c<
            (quan::meta::get_num_elements<list_in_next>::value > 0),
            quan::meta::detail::copy_if_i<list_in_next,target_list,Pred>,
            target_list
          >::type type; 
       };
    }

    template <typename SrcList, typename F> 
    struct copy_if{
        typedef typename quan::meta::eval_if_c<
            (quan::meta::get_num_elements<SrcList>::value  == 0),
            quan::meta::type_sequence<>,
            quan::meta::detail::copy_if_i<SrcList,quan::meta::type_sequence<>,F>
         >::type type;
    };

}}// quan::meta

#endif // QUAN_META_COPY_IF_HPP_INCLUDED
