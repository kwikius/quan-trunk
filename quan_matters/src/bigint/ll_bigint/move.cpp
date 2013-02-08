#include <quan/detail/ll_bigint.hpp>

using quan::detail::ll_bigint;

void ll_bigint::move(ll_bigint & rhs)
{
  this->m_rep = rhs.m_rep;
  rhs.m_rep.clear();
}
