
#include <quan_matters/test/bigint/ll_bigint/ll_bigint_test_local.hpp>
#include <quan/meta/integer_limits.hpp>

using quan::detail::ll_bigint;

namespace quan{ namespace test{
   
  void ll_bigint_bitor_eq()
  {
    ll_bigint v1 = 0x00FF;
    ll_bigint v2 = 0xF707;
   // v1.dump_rep();
    v1.bitor_eq(v2);
    QUAN_CHECK(v1.to_string_base<16>() == "F7FF")
    ll_bigint v3;
    v3.from_string_base<16>("F1234DABFFFFFFFFF000000");
    v2.plus_eq(v3);
    v1.bitor_eq(v2);
    QUAN_CHECK( v1.to_string_base<16>() == "F1234DABFFFFFFFFF00F7FF")
  //  v1.dump_rep();

  }

}}

