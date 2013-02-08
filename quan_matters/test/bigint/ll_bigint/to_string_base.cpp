
#include <quan_matters/test/bigint/ll_bigint/ll_bigint_test_local.hpp>
#include <quan/meta/integer_limits.hpp>

using quan::detail::ll_bigint;

namespace quan{ namespace test{
   
  void ll_bigint_to_string_base10()
  {
    ll_bigint v;
    v.from_string_base<10>("1234567890");
    QUAN_CHECK( v.to_string_base<10>() == "1234567890")
   
  }

}}

