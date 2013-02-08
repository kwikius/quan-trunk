
#include <quan_matters/test/bigint/ll_bigint/ll_bigint_test_local.hpp>


using quan::detail::ll_bigint;

namespace quan{ namespace test{
   
  void ll_bigint_from_string_base10()
  {
    ll_bigint v;
    v.from_string_base<10>              ("655341234567893635426");
    QUAN_CHECK(v.to_string_base<10>() == "655341234567893635426")

    v.from_string_base<16>              ("FF0F7654321FFFFFFFFFFFFFFFFFFFFF");
    QUAN_CHECK(v.to_string_base<16>() == "FF0F7654321FFFFFFFFFFFFFFFFFFFFF");

    v.from_string_base<2>("11110001");
    QUAN_CHECK(v.to_string_base<16>() == "F1")
    
    v.from_string_base<16>("FFABCDEF1234567897FCAFCA");
    QUAN_CHECK(v.to_string_base<10>() == "79126376314809684474963210186")
  }

}}

