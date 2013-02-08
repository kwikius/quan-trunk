#include <quan/detail/ll_bigint.hpp>

using quan::detail::ll_bigint;

void ll_bigint::negate()
{
   this->invert();
   this->plus_eq1(); 
}

