
#include <quan_matters/test/bigint/ll_bigint/ll_bigint_test_local.hpp>
#include <quan/meta/integer_limits.hpp>

using quan::detail::ll_bigint;

namespace quan{ namespace test{
   
   void ll_bigint_int_ctor()
   {
      ll_bigint v = 1;

      QUAN_CHECK(v.eq_one())
      QUAN_CHECK(!v.eq_zero())
      QUAN_CHECK(!v.is_negative())

      ll_bigint v1 = -1;
      QUAN_CHECK( v1.eq_one() == false)
      QUAN_CHECK( v1.is_negative())

      ll_bigint v2 = quan::meta::integer_max<int>::value;
      QUAN_CHECK( !v2.is_negative())

      ll_bigint v3 = quan::meta::integer_min<int>::value;
      QUAN_CHECK( v3.is_negative() )

      ll_bigint v4 = -0xFFFFFF;
      QUAN_CHECK(v4.is_negative());

   }

}}

