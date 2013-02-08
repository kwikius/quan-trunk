
#include <quan_matters/test/bigint/ll_bigint/ll_bigint_test_local.hpp>
#include <quan/meta/integer_limits.hpp>

using quan::detail::ll_bigint;

namespace quan{ namespace test{
   
  void ll_bigint_bitxor_eq()
  {
    ll_bigint v1 = 0xFF0F;
    ll_bigint v2 = 0x7F00;
   // v1.dump_rep();
    v1.bitxor_eq(v2);
   // v1.dump_rep();
   QUAN_CHECK(v1.to_string_base<10>() == "32783")

  }

}}

