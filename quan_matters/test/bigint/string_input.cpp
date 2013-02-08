#include "ll_bigint_test.hpp"

#if (0)
void quan::test::ll_bigint_string_input_test1()
{
   using quan::detail::ll_bigint;
   typedef ll_bigint::uint32 uint32;

   std::string str = "123456789123456789123456789";
   ll_bigint num = str;
   num.assign_from_string(str);
   QUAN_CHECK(( num.to_string() == str))
}
#endif
