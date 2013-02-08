#include <quan/detail/ll_bigint.hpp>
#include <quan/asm/get_msb.hpp>

using quan::detail::ll_bigint;

/*
  request_compact ..
   will go as far as can before losing twos_c info 
*/

ll_bigint::size_type ll_bigint::request_compact(ll_bigint::size_type to_size)
{
  size_type const size = (to_size==0)?0:to_size -1;
  bool const sign = this->is_negative();
  uint32 const mask = (sign)?static_cast<uint32>(~0):0;
  int remove_count = 0;
  for(size_type i = this->get_num_elements()-1; i > size; --i) {
      if ( ( m_rep.at(i) != mask ) ||
      ( quan::asm_::get_msb(this->m_rep.at(i-1)) != sign ) 
      ){
         break;
      }
      else{
          ++ remove_count;
      }
  }

  for (int i = remove_count; i > 0; --i){
    m_rep.pop_back();
  }

  return this->get_num_elements();
}

ll_bigint::size_type ll_bigint::force_compact(ll_bigint::size_type to_size)
{
  
  difference_type const remove_count 
         = static_cast<difference_type>(this->get_num_elements())
             - static_cast<difference_type>(to_size);
  for(difference_type i = 0; i < remove_count; ++i) {
    m_rep.pop_back();
  }
  return this->get_num_elements();
}
