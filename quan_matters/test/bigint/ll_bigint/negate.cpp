
#include <quan_matters/test/bigint/ll_bigint/ll_bigint_test_local.hpp>
#include <quan/meta/integer_limits.hpp>

using quan::detail::ll_bigint;

namespace quan{ namespace test{
   
  void ll_bigint_negate()
  {
    ll_bigint v = 1;
   
    v.negate();

    QUAN_CHECK(v.is_negative());

    v.negate();

    QUAN_CHECK(v.eq_one());

    v.from_string_base<10>("25543428464545");
    v.negate();
    QUAN_CHECK(v.to_string_base<10>() =="-25543428464545")
    v.from_string_base<16>("-25543428464545");
    v.negate();
    QUAN_CHECK(v.to_string_base<16>() =="25543428464545")
  }

}}

