#include <quan/detail/ll_bigint.hpp>

using quan::detail::ll_bigint;

std::size_t ll_bigint::get_num_elements()const
{
  return this->m_rep.size();
}