
#include <quan_matters/test/test.hpp>
#include <quan/fusion/static_value/static_value.hpp>
#include <quan/fusion/static_value/out/static_value.hpp>
#include <quan/meta/rational.hpp>
#include <quan/out/length.hpp>
#include <quan/out/time.hpp>
#include <quan/fixed_quantity/literal.hpp>
#include <quan/out/velocity.hpp>
#include <type_traits>
#include <utility>
#include <typeinfo>

namespace {

   template <int64_t N, int64_t D>
   using static_mm = quan::fusion::static_value<quan::length::mm,quan::meta::rational<N,D> >;

   template <int64_t N, int64_t D>
   using static_m_per_s = quan::fusion::static_value<quan::velocity::m_per_s,quan::meta::rational<N,D> >;

   template <int64_t N, int64_t D>
   using static_s = quan::fusion::static_value<quan::time::s,quan::meta::rational<N,D> >;

   template <int64_t N, int64_t D>
   using static_float = quan::fusion::static_value< double,quan::meta::rational<N,D> >;

   QUAN_QUANTITY_LITERAL(length,mm)
   QUAN_QUANTITY_LITERAL(velocity,m_per_s)
   QUAN_QUANTITY_LITERAL(time,s)

}
#if defined __cpp_concepts
bool check_static_value(quan::fusion::StaticValue v)
{
    return true;
}

template <typename T> 
requires ! quan::fusion::StaticValue<T>
bool check_static_value(T v)
{
   return false;
}
#else

template <typename T>
typename quan::where_<quan::fusion::is_static_value<T>,bool >::type
check_static_value(T v)
{
  return true;
}

template <typename T>
typename quan::where_not<quan::fusion::is_static_value<T>,bool > ::type
check_static_value(T v)
{
   return false;
}

#endif

int errors;
using quan::fusion::to_runtime;
int main()
{
   QUAN_CHECK(quan::meta::is_scalar<quan::length::mm>::value)
   constexpr auto v1 = static_mm<11,3>{};
   QUAN_CHECK(check_static_value(v1) == true);
  
   QUAN_CHECK((quan::meta::is_scalar<decltype(v1)>::value))
   QUAN_CHECK((quan::meta::is_runtime_type<decltype(v1)>::value == false))
   QUAN_CHECK(to_runtime{}(v1) == 11_mm / 3.0);

   constexpr auto b1 = v1 == v1;
   QUAN_CHECK(check_static_value(b1)== true);
   QUAN_CHECK(to_runtime{}(b1) == true);

   auto constexpr v2 = v1 + v1;
   QUAN_CHECK(check_static_value(v2)== true);
   QUAN_CHECK(to_runtime{}(v2) == 22_mm / 3.0);

   constexpr auto b2 = v1 == v2;
   QUAN_CHECK(check_static_value(b2) == true);
   QUAN_CHECK(to_runtime{}(b2) == false);

   constexpr auto v1a = static_s<2,3>{};

   constexpr auto v1b = v1 / v1a;

   QUAN_CHECK(check_static_value(v1b)== true);
   QUAN_CHECK(to_runtime{}(v1b) == 11.0_mm / 2_s) ;

   constexpr auto two = static_float<2,1>{};
   QUAN_CHECK(check_static_value(two)== true);
   QUAN_CHECK(to_runtime{}(two) == 2.0);

   constexpr auto v1c = v1b / (two * v1b);
   QUAN_CHECK(check_static_value(v1c)== true);
   QUAN_CHECK(to_runtime{}(v1c) == 1.0 / 2.0);
  
   auto constexpr v3 = v1 * two; 
   QUAN_CHECK(check_static_value(v3) == true);
   QUAN_CHECK(to_runtime{}(v2 == v3) == true);

   auto constexpr zero = static_float<0,1>{};
   QUAN_CHECK(check_static_value(zero) == true);
   QUAN_CHECK(to_runtime{}(zero) == 0.0);

   auto constexpr v5 = zero * 2.f;

   QUAN_CHECK(check_static_value(v5) == true);
   QUAN_CHECK(to_runtime{}(v5) == 0.0);

   auto constexpr one = static_float<1,1>{};
   QUAN_CHECK(check_static_value(one)== true);
   QUAN_CHECK(to_runtime{}(one) == 1.0);

   auto constexpr v6 = one * two;
   QUAN_CHECK(check_static_value(v6)== true);
   QUAN_CHECK(to_runtime{}(v6) == 2.0);

   auto constexpr v7 = one * 2;
   QUAN_CHECK(check_static_value(v7)== false);
   QUAN_CHECK(to_runtime{}(v6) == v6);

   QUAN_EPILOGUE;

}
