#include <quan/detail/ll_bigint.hpp>

using quan::detail::ll_bigint;

void ll_bigint::div_eq(ll_bigint const & rhs)
{
  ll_bigint temp;
  div_mod(*this,rhs,*this,temp);
}
