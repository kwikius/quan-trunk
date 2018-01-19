
#include <quan_matters/test/test.hpp>
#include <quan/fusion/static_value/static_value.hpp>
#include <quan/fusion/static_value/out/static_value.hpp>
#include <quan/meta/rational.hpp>
#include <quan/out/length.hpp>
#include <quan/out/area.hpp>
#include <quan/out/time.hpp>
#include <quan/fixed_quantity/literal.hpp>
#include <quan/out/velocity.hpp>
#include <type_traits>
#include <utility>
#include <typeinfo>

namespace {

   template <int64_t N, int64_t D = 1>
   using static_mm = quan::fusion::static_value<quan::length::mm,quan::meta::rational<N,D> >;

   template <int64_t N, int64_t D= 1>
   using static_m = quan::fusion::static_value<quan::length::m,quan::meta::rational<N,D> >;

   template <int64_t N, int64_t D= 1>
   using static_mm2 = quan::fusion::static_value<quan::area::mm2,quan::meta::rational<N,D> >;

   template <int64_t N, int64_t D= 1>
   using static_m_per_s = quan::fusion::static_value<quan::velocity::m_per_s,quan::meta::rational<N,D> >;

   template <int64_t N, int64_t D= 1>
   using static_s = quan::fusion::static_value<quan::time::s,quan::meta::rational<N,D> >;

   template <int64_t N, int64_t D= 1>
   using static_float = quan::fusion::static_value< double,quan::meta::rational<N,D> >;

   QUAN_QUANTITY_LITERAL(length,mm)
   QUAN_QUANTITY_LITERAL(length,m)
   QUAN_QUANTITY_LITERAL(area,mm2)
   QUAN_QUANTITY_LITERAL(area,m2)
   
   QUAN_QUANTITY_LITERAL(velocity,m_per_s)
   QUAN_QUANTITY_LITERAL(time,s)

   auto constexpr zero = static_float<0,1>{};
   auto constexpr zero_mm = static_mm<0,1>{};
   auto constexpr zero_m = static_m<0,1>{};
    
   auto constexpr zero_mm2 = static_mm2<0,1>{};

   auto constexpr one = static_float<1,1>{};
   auto constexpr one_mm = static_mm<1,1>{};
   auto constexpr one_m = static_m<1,1>{};
}

#if defined __cpp_concepts
bool is_static_value(quan::fusion::StaticValue v)
{
    return true;
}

template <typename T> 
requires ! quan::fusion::StaticValue<T>
bool is_static_value(T v)
{
   return false;
}
#else

template <typename T>
typename quan::where_<quan::fusion::is_static_value<T>,bool >::type
is_static_value(T v)
{
  return true;
}

template <typename T>
typename quan::where_not<quan::fusion::is_static_value<T>,bool > ::type
is_static_value(T v)
{
   return false;
}

#endif

using quan::fusion::to_runtime;

void static_value_concepts_test()
{
   constexpr auto v1 = static_mm<3,11>{};
   QUAN_CHECK(is_static_value(v1) == true);
   QUAN_CHECK(to_runtime{}(v1) == 3_mm / 11.0);
  
   QUAN_CHECK((quan::meta::is_scalar<decltype(v1)>::value))
   QUAN_CHECK((quan::meta::is_runtime_type<decltype(v1)>::value == false))
   
}

// n.b missing unary_plus and unary_minus atm
void static_value_op_plus_test()
{
   constexpr auto v1 = static_mm<11,3>{};
   QUAN_CHECK(to_runtime{}(v1) == 11_mm / 3.0)

   constexpr auto v1a = +v1;
   QUAN_CHECK( to_runtime{}(v1a == v1) )
  
   auto constexpr v2 = v1 + v1;
   QUAN_CHECK(is_static_value(v2)== true)
   QUAN_CHECK(to_runtime{}(v2) == 22_mm / 3.0)

   QUAN_CHECK(to_runtime{}((v1 + zero_mm ) == v1))

   auto constexpr v3 = v1 + 20_m;
   QUAN_CHECK(is_static_value(v3)== false)
   auto constexpr rtv3 = to_runtime{}(v3);
   auto constexpr calc_rtv3 = (11_mm / 3.0) + 20_m;
   QUAN_CHECK(rtv3 == calc_rtv3 )

   auto constexpr v4 = 20_m + v1;
   QUAN_CHECK(is_static_value(v4)== false);
   auto constexpr rtv4 = to_runtime{}(v4);
   auto constexpr calc_rtv4 = 20_m + (11_mm / 3.0);
   QUAN_CHECK(rtv4 == calc_rtv4 )

   auto constexpr v5 = 2_mm + zero_mm;
   QUAN_CHECK(is_static_value(v5)== false);
   QUAN_CHECK( v5 == 2_mm)

   auto constexpr v6 = zero_mm + 2_mm ;
   QUAN_CHECK(is_static_value(v6)== false);
   QUAN_CHECK( v6 == 2_mm)

   
/*  //TODO compile fail tests
   auto constexpr v7 = zero_mm + one; // ! same dimension
   auto constexpr v8 = zero_mm + 2 ;  // ! same dimension
   auto constexpr v9 = 2 + zero_mm ;  // ! same dimension

*/
}

void static_value_op_minus_test()
{
    constexpr auto v1 = static_mm<11,3>{};
    
    QUAN_CHECK(to_runtime{}( (v1 - v1) == zero_mm))
    constexpr auto v1a = -static_mm<11,3>{};
    QUAN_CHECK(is_static_value(v1a)== true)
    QUAN_CHECK(to_runtime{}(v1a) == (- 11_mm / 3.0) )

    constexpr auto v2 = v1 - v1a;
    QUAN_CHECK(is_static_value(v2)== true)
    QUAN_CHECK(to_runtime{}(v2) == 22_mm / 3.0)

    constexpr auto v3 = v1 - 1_mm;
    QUAN_CHECK(is_static_value(v3)== false)
    QUAN_CHECK(v3 == (11_mm / 3.0) - 1_mm)

    constexpr auto v4 = 1_mm - v1;
    QUAN_CHECK(is_static_value(v4)== false)
    QUAN_CHECK(v4 == 1_mm - (11_mm / 3.0))

    constexpr auto v5 = zero_mm - v1;
    QUAN_CHECK(is_static_value(v5))
    QUAN_CHECK(to_runtime{}(v5 == -v1))
}


extern float extern_float;
// check for runtime values
void to_runtime_test()
{
    QUAN_CHECK(to_runtime{}(1U) == 1U)

    QUAN_CHECK(to_runtime{}(-1234) == -1234)

    QUAN_CHECK(to_runtime{}(true) == true)

    QUAN_CHECK(to_runtime{}(extern_float) == extern_float)

    quan::length::in q1;
    QUAN_CHECK(to_runtime{}(q1) == q1)
}

float extern_float = -1234567.98765;
int errors =0;

void static_value_op_multiply_test()
{
    constexpr auto v1 = static_mm<11,3>{};
    constexpr auto v2 = v1 * v1;
    constexpr auto rtv2 = to_runtime{}(v2);
    constexpr auto alt_rtv2 = quan::pow<2>(to_runtime{}(v1));

   // std :: cout << "rtv2 = " << rtv2 << '\n';
   // std :: cout << "alt_rtv2 = " << alt_rtv2 << '\n';
    // probably lose accuracy here in floating point calc compared to the compile time rational
    QUAN_CHECK_CLOSE(rtv2,alt_rtv2,1.e-6_mm2)

    constexpr auto v3 = v1 * 2;
    QUAN_CHECK(is_static_value(v3) == false);
    QUAN_CHECK(v3 == 22_mm/3.0);

    constexpr auto v4 = 2 * v1;
    QUAN_CHECK(is_static_value(v4) == false);
    QUAN_CHECK(v4 == 22_mm/3.0);

    constexpr auto v5 = 2 * zero;
    QUAN_CHECK(is_static_value(v5) == true);
    QUAN_CHECK(to_runtime{}(v5 == zero));

    constexpr auto v6 = zero * 2_mm;
    QUAN_CHECK(is_static_value(v6) == true);
    QUAN_CHECK(to_runtime{}(v6 == zero_mm));

    constexpr auto v7 = zero_mm * 2_mm;
    QUAN_CHECK(is_static_value(v7) == true);
    QUAN_CHECK(to_runtime{}(v7 == zero_mm2));

    constexpr auto v8 = 2 * -v1;
    QUAN_CHECK(is_static_value(v8) == false);
    QUAN_CHECK(v8 == -22_mm/3.0);
    
}

//divide compare

void static_value_op_divide_test()
{
   constexpr auto v1 = static_mm<11,3>{};

   constexpr auto v1a = static_s<2,3>{};

   constexpr auto v1b = v1 / v1a;

   QUAN_CHECK(is_static_value(v1b)== true);
   QUAN_CHECK(to_runtime{}(v1b) == 11.0_mm / 2_s) ;

   constexpr auto two = static_float<2,1>{};
   QUAN_CHECK(is_static_value(two)== true);
   QUAN_CHECK(to_runtime{}(two) == 2.0);

   constexpr auto v1c = v1b / (two * v1b);
   QUAN_CHECK(is_static_value(v1c)== true);
   QUAN_CHECK(to_runtime{}(v1c) == 1.0 / 2.0);

   constexpr auto  v2 = one / v1;
   QUAN_CHECK(is_static_value(v2)== true);
   QUAN_CHECK(to_runtime{}(v2) == 3.0 / 11_mm);

   constexpr auto  v3 = 1.0 / v1;
   QUAN_CHECK(is_static_value(v3)== false);
   //QUAN_CHECK(v3 == 3.0 / 11_mm)
 //  std::cout << "v3 = " << v3 <<'\n';
 //  std::cout << "3.0 / 11_mm = " << (3.0 / 11_mm) <<'\n';
   QUAN_CHECK_CLOSE(v3 , 3.0 / 11_mm, 1/1.e6_mm)

   constexpr auto v4 = v1 / one;
   QUAN_CHECK(is_static_value(v4)== true);
   QUAN_CHECK(to_runtime{}(v4 == v1));

   constexpr auto v5 = v1 / one_mm;
   QUAN_CHECK(is_static_value(v5)== true);
   QUAN_CHECK(to_runtime{}(v5) == 11.0/3);

   constexpr auto v6 = zero_mm / 2;
   QUAN_CHECK(is_static_value(v6)== true);
   QUAN_CHECK(to_runtime{}(v6) == 0_mm);

  /*
   test compile fail division by zero
   constexpr auto v7 = 2 / zero;
   QUAN_CHECK(is_static_value(v7)== true);
   QUAN_CHECK(to_runtime{}(v7) == 2/0.f);
   */

}

void static_value_op_compare_test()
{
   //todo though some comparse done above
    constexpr auto v1 = static_mm<11,3>{};

    constexpr auto v2 = static_mm<22,6>{};
    QUAN_CHECK(to_runtime{}(v2 == v1) )

    QUAN_CHECK( to_runtime{}(v2 != one_mm) )

    QUAN_CHECK( one_mm == 1_mm)

    QUAN_CHECK( 25_mm == static_mm<25>{})

/*
    To do other comparison ops
    QUAN_CHECK( to_runtime{}(v1 < v1) == false)
    QUAN_CHECK( to_runtime{}(v1 < v2))
    QUAN_CHECK( to_runtime{}(v2 < v1) == false)
    QUAN_CHECK( to_runtime{}(v1 > v2) == false)
    QUAN_CHECK( to_runtime{}(v1 <= v2))
    QUAN_CHECK( to_runtime{}(v1 >= v1))
    QUAN_CHECK( to_runtime{}(v1 > v1) == false)
*/
   
}


int main()
{
   to_runtime_test();
   static_value_concepts_test();
   static_value_op_plus_test();
   static_value_op_minus_test();

   static_value_op_multiply_test();

   static_value_op_divide_test();
   static_value_op_compare_test();

   QUAN_EPILOGUE;
}
