#include <quan_matters/test/test.hpp>

#include <quan/fusion/make_matrix.hpp>
#include <quan/fun/matrix_row.hpp>
#include <quan/fun/matrix_col.hpp>
#include <quan/fusion/make_sub_matrix_view.hpp>
#include <quan/fusion/determinant.hpp>
#include <quan/fun/at.hpp>
#include <quan/length.hpp>
#include <quan/time.hpp>
#include <quan/area.hpp>
#include <quan/velocity.hpp>
#include <quan/reciprocal_length.hpp>
#include <quan/fusion/static_value.hpp>
#include <quan/fixed_quantity/literal.hpp>
#include <quan/fusion/static_value/out/static_value.hpp>

namespace {

   template <int64_t N, int64_t D = 1>
   using static_mm = quan::fusion::static_value<quan::length::mm,quan::meta::rational<N,D> >;

   template <int64_t N, int64_t D= 1>
   using static_m = quan::fusion::static_value<quan::length::m,quan::meta::rational<N,D> >;

   template <int64_t N, int64_t D = 1>
   using static_per_mm = quan::fusion::static_value<quan::reciprocal_length::per_mm,quan::meta::rational<N,D> >;

   template <int64_t N, int64_t D= 1>
   using static_per_m = quan::fusion::static_value<quan::reciprocal_length::per_m,quan::meta::rational<N,D> >;

   template <int64_t N, int64_t D= 1>
   using static_mm2 = quan::fusion::static_value<quan::area::mm2,quan::meta::rational<N,D> >;

   template <int64_t N, int64_t D= 1>
   using static_m_per_s = quan::fusion::static_value<quan::velocity::m_per_s,quan::meta::rational<N,D> >;

   template <int64_t N, int64_t D= 1>
   using static_s = quan::fusion::static_value<quan::time::s,quan::meta::rational<N,D> >;

   template <int64_t N, int64_t D= 1>
   using static_float = quan::fusion::static_value< double,quan::meta::rational<N,D> >;

   template <typename T>
   constexpr bool is_static_value = quan::fusion::is_static_value<T>::value;

} // namespace

 void qty_matrix_test()
 {

      auto constexpr m = quan::fusion::make_matrix<4>
      (
         static_float<1>{}, static_float<2>{}, static_float<3>{}, static_float<0>{},
         static_float<2>{}, static_float<2>{}, static_float<3>{}, static_float<0>{},
         static_float<1>{}, static_float<1>{}, static_float<1>{}, static_float<0>{},
         static_float<1>{}, static_float<2>{}, static_float<1>{}, static_float<1>{}
      );

      constexpr auto v = quan::fusion::determinant(m);

      QUAN_CHECK(is_static_value<decltype(v)>)
      QUAN_CHECK(quan::fusion::to_runtime{}(v) == 1)

      auto constexpr m1 = quan::fusion::make_matrix<2>
      (  
          static_per_mm<2>{}, static_mm<0>{},
          static_per_mm<0>{}, static_mm<2>{}
      );

      constexpr auto v1 = quan::fusion::determinant(m1);
      QUAN_CHECK(is_static_value<decltype(v1)>)
      QUAN_CHECK(quan::fusion::to_runtime{}(v1) == 4.f)
 }

 void test_sub_matrix_of_m3()
 {
      auto constexpr m = quan::fusion::make_matrix<3>
      ( 
         static_float<56>{},  static_float<90>{},  static_float<72>{},
         static_float<2>{},   static_float<4>{},   static_float<7>{},
         static_float<-3>{},   static_float<1>{},   static_float<5>{}
      );

      constexpr auto v = quan::fusion::determinant(m);

      QUAN_CHECK(is_static_value<decltype(v)>)
      QUAN_CHECK(quan::fusion::to_runtime{}(v) == -1054)

   // s00
      auto const s00 = quan::fusion::make_sub_matrix_view<0,0>(m);

      QUAN_CHECK((s00.at<0,0>() == 4))
      QUAN_CHECK((s00.at<0,1>() == 7))

      QUAN_CHECK((s00.at<1,0>() == 1))
      QUAN_CHECK((s00.at<1,1>() == 5))

      QUAN_CHECK((s00.at<1,0>() == 1))
      QUAN_CHECK((s00.at<1,1>() == 5))
    
   // s01

      auto const s01 =quan::fusion::make_sub_matrix_view<0,1> (m);


      QUAN_CHECK((s01.at<0,0>() == 2))
      QUAN_CHECK((s01.at<0,1>() == 7))

      QUAN_CHECK((s01.at<1,0>() == -3))
      QUAN_CHECK((s01.at<1,1>() == 5))

   // s02
      auto const s02 = quan::fusion::make_sub_matrix_view<0,2>(m);

      QUAN_CHECK((s02.at<0,0>() == 2))
      QUAN_CHECK((s02.at<0,1>() == 4))

      QUAN_CHECK((s02.at<1,0>() == -3))
      QUAN_CHECK((s02.at<1,1>() == 1))

   // s10
      auto const s10 = quan::fusion::make_sub_matrix_view<1,0>(m);

      QUAN_CHECK((s10.at<0,0>() == 90))
      QUAN_CHECK((s10.at<0,1>() == 72))

      QUAN_CHECK((s10.at<1,0>() == 1))
      QUAN_CHECK((s10.at<1,1>() == 5))

    // s11
      auto const s11 = quan::fusion::make_sub_matrix_view<1,1>(m);

      QUAN_CHECK((s11.at<0,0>() == 56))
      QUAN_CHECK((s11.at<0,1>() == 72))

      QUAN_CHECK((s11.at<1,0>() == -3))
      QUAN_CHECK((s11.at<1,1>() == 5))

    // s12
      auto const s12 = quan::fusion::make_sub_matrix_view<1,2>(m);

      QUAN_CHECK((s12.at<0,0>() == 56))
      QUAN_CHECK((s12.at<0,1>() == 90))

      QUAN_CHECK((s12.at<1,0>() == -3))
      QUAN_CHECK((s12.at<1,1>() == 1))

    // s20
      auto const s20 = quan::fusion::make_sub_matrix_view<2,0>(m);

      QUAN_CHECK((s20.at<0,0>() == 90))
      QUAN_CHECK((s20.at<0,1>() == 72))

      QUAN_CHECK((s20.at<1,0>() == 4))
      QUAN_CHECK((s20.at<1,1>() == 7))

   //s21
      auto const s21 = quan::fusion::make_sub_matrix_view<2,1>(m);

      QUAN_CHECK((s21.at<0,0>() == 56))
      QUAN_CHECK((s21.at<0,1>() == 72))

      QUAN_CHECK((s21.at<1,0>() == 2))
      QUAN_CHECK((s21.at<1,1>() == 7))

   //s22
      auto const s22 = quan::fusion::make_sub_matrix_view<2,2>(m);

      QUAN_CHECK((s22.at<0,0>() == 56))
      QUAN_CHECK((s22.at<0,1>() == 90))


      QUAN_CHECK((s22.at<1,0>() == 2))
      QUAN_CHECK((s22.at<1,1>() == 4))

   }


