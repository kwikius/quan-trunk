
#include <quan_matters/test/bigint/ll_bigint/ll_bigint_test_local.hpp>
#include <quan/meta/integer_limits.hpp>

using quan::detail::ll_bigint;

namespace quan{ namespace test{
   
  void ll_bigint_bitand_eq()
  {
    ll_bigint v1 = int{0xFF7FFF};
    v1.from_string_base<16>("FF7FFF");
    ll_bigint v2 = 0xFFFF0;
    v1.bitand_eq(v2);

    QUAN_CHECK( v1.to_string_base<16>() == "F7FF0")

    v1.from_string_base<16>("FFFF0000888811110000FFFF000088881111");
    v2.from_string_base<16>( "FFF0000788811110000FFFF000000001101");
    v1.bitand_eq(v2);
    QUAN_CHECK( v1.to_string_base<16>()
         ==                  "FFF0000088811110000FFFF000000001101");
  }

}}

