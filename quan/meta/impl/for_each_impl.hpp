#ifndef QUAN_META_IMPL_DETAIL_FOR_EACH_IMPL_HPP_INCLUDED
#define QUAN_META_IMPL_DETAIL_FOR_EACH_IMPL_HPP_INCLUDED

namespace quan{ namespace meta{ namespace impl{

      template <
         typename Sequence, 
         typename Fun, 
         typename Where = void   // // overload for each type of sequence and or function
      >
      struct for_each_impl;

}}}

#endif // QUAN_META_IMPL_DETAIL_FOR_EACH_IMPL_HPP_INCLUDED
