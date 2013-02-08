#include <quan/detail/ll_bigint.hpp>

using quan::detail::ll_bigint;

ll_bigint ll_bigint::gcd(ll_bigint const & nume, ll_bigint const & denom)
{
     if ( denom.eq_zero()){
       return nume;
     }
     else {
       ll_bigint temp = nume;
       temp.mod_eq(denom);
       return gcd( denom , temp);
     }
}