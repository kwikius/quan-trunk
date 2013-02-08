#include <quan/detail/ll_bigint.hpp>
#include <quan/asm/get_msb.hpp>

using quan::detail::ll_bigint;

/*
 rep is twos complement where the msb of the highest word represents the sign
*/

bool ll_bigint::is_negative()const
{
 // assert(this->get_num_elements());
  return quan::asm_::get_msb(this->m_rep.back());
}
