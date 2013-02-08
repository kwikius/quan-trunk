#include <quan/detail/ll_bigint.hpp>

using quan::detail::ll_bigint;

/*
  request_compact as far as can before losing twos_c info 
*/

bool ll_bigint::extend(ll_bigint::size_type to_size)
{
   difference_type size_diff = to_size - this->get_num_elements() ;
   if (size_diff <= 0 ){
      return false;
   }else{
      bool const sign = this->is_negative();
      uint32 const mask = (sign)?static_cast<uint32>(~0):0;
      for(difference_type i = 0; i < size_diff; ++i) {
         m_rep.push_back(mask);
      }
      return true;
   }
}