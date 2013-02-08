
#include <quan_matters/test/bigint/ll_bigint/ll_bigint_test_local.hpp>
#include <quan/meta/integer_limits.hpp>

using quan::detail::ll_bigint;

namespace quan{ namespace test{
   
  void ll_bigint_shr_eq()
  {
    ll_bigint v = 0xff000000LL;
    v.logical_shr_eq(24);
    QUAN_CHECK(v.to_string_base<16>() == "FF")

    ll_bigint v1 = 0xff000000LL;
    v1.logical_shr_eq(23); 
    QUAN_CHECK(v1.to_string_base<16>() == "1FE")

    ll_bigint v2 = 0xff000000LL;
    v2.logical_shr_eq(22); 
    QUAN_CHECK(v2.to_string_base<16>() == "3FC")

    ll_bigint v3 = 0xff000000LL;
    v3.logical_shr_eq(21); 
    QUAN_CHECK(v3.to_string_base<16>() == "7F8")
    
  
  }

}}

