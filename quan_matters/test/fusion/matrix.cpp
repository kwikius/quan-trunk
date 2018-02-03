
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
/*
 todo 

https://www.geeksforgeeks.org/determinant-of-a-matrix/

adjoint, 
 hence inverse
https://www.geeksforgeeks.org/adjoint-inverse-matrix/
*/

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
   
   void static_value_matrix_test()
   {
      {
         // identity matrix l_values
         constexpr static_float<0> zero;
         constexpr static_float<1> one;

         auto id2 = quan::fusion::make_matrix<2,2> (
              one , zero
            ,zero ,  one 
         );

         QUAN_CHECK( ( static_cast<bool>(id2.at<0,0>() == one) ) );
         QUAN_CHECK( ( id2.at<0,0>() == 1.0 ) );
         QUAN_CHECK( ( static_cast<bool>(id2.at<0,1>() == zero) ) ); 
         QUAN_CHECK( ( id2.at<0,1>() == 0.0 ) );
      }

      {
         // identity matrix temporaries
         typedef static_float<0> zero;
         typedef static_float<1> one;

         auto constexpr id2a 
         = quan::fusion::make_matrix<2,2> 
         (
              one{}, zero{}
            ,zero{},  one{}
         );

         QUAN_CHECK( (quan::fun::is_fun_matrix<decltype(id2a)>::value == true) )
         QUAN_CHECK( (quan::fun::matrix_row_size<decltype(id2a)>::value == 2) )
         QUAN_CHECK( (quan::fun::matrix_col_size<decltype(id2a)>::value == 2) )

         QUAN_CHECK( ( static_cast<bool>(id2a.at<0,0>() == one{}) ) )
         QUAN_CHECK( ( id2a.at<0,0>() == 1.0 ) )
         QUAN_CHECK( ( static_cast<bool>(id2a.at<0,1>() == zero{}) ) );
         QUAN_CHECK( ( id2a.at<0,1>() == 0.0 ) )
      }

      {
         // identity matrix temporaries non square matrix
         typedef static_float<0> zero;
         typedef static_float<1> one;

         float v00 = 2345.0;
         float two = 2.0;
         auto id2a 
         = quan::fusion::make_matrix<2,3> 
         (
             v00,          one{},                     zero{}
            ,  2,static_mm<20>{}, std::string{"Hello World"}
         );

         QUAN_CHECK( (quan::fun::is_fun_matrix<decltype(id2a)>::value == true) )
         QUAN_CHECK( (quan::fun::matrix_row_size<decltype(id2a)>::value == 2) )
         QUAN_CHECK( (quan::fun::matrix_col_size<decltype(id2a)>::value == 3) )
         // row 0
         QUAN_CHECK( ( id2a.at<0,0>() == v00) )

         QUAN_CHECK( ( static_cast<bool>(id2a.at<0,1>() == one{})) )

         QUAN_CHECK( ( static_cast<bool>(id2a.at<0,2>() == zero{}) ) ) 

         // row 1
         QUAN_CHECK( ( id2a.at<1,0>() == 2 ) )
         QUAN_CHECK( ( id2a.at<1,0>() == two ) )

         QUAN_CHECK( ( id2a.at<1,1>() == quan::length::mm{20} ) )
         QUAN_CHECK( ( static_cast<bool>(id2a.at<1,1>() == static_mm<20>{}) ) )

         QUAN_CHECK( ( id2a.at<1,2>() == "Hello World")  )
      }

      // so a 2d coord would be a matrix<1,2> 
      // 3d matrix<1,3> 
      // quat a matrix 1,4
      // note to adapt a quan two d vect etc to a matrix should be quite easy too
   }

   void matrix_row_test()
   {
      quan::fun::vector<
         int,int,int,
         int,int,int,
         int,int,int
      > sequence { 
         11,12,13, 
         21,22,23, 
         31,32,33
      };

      auto v = quan::fusion::make_matrix<3,3>(sequence);

      QUAN_CHECK( (v.at<0,0>() == 11));
      QUAN_CHECK( (v.at<1,2>() == 23));
      QUAN_CHECK( (v.at<2,2>() == 33));

      // test assignment of element
      v.at<0,0>() = 3;
      QUAN_CHECK( (v.at<0,0>() == 3));

      typedef decltype(v) matrix_type;

   //--- matrix row
      typedef  quan::fun::matrix_row<0,matrix_type> row0_type;

      #if defined __cpp_concepts
      QUAN_CHECK((quan::fusion::Sequence<row0_type> == true))
      #endif
      QUAN_CHECK((quan::fun::is_fun_sequence<row0_type>::value == true))
      QUAN_CHECK((quan::is_model_of<quan::fusion::Sequence_,row0_type>::value == true))

      QUAN_CHECK((quan::fusion::num_elements<row0_type> == 3))

      row0_type row0{v};

      // check read via row
      QUAN_CHECK((quan::fun::at_seq<0,row0_type>{}(row0) == 3));

      // check write via row
      quan::fun::at_seq<0,row0_type,quan::fun::as_ref>{}(row0) = 8;

      QUAN_CHECK((quan::fun::at_seq<0,row0_type>{}(row0) == 8));
    
      // check read via row with at
      QUAN_CHECK((quan::fun::at<0>(row0) == 8) );

      QUAN_CHECK((v.at<0,0>() == 8));

      // check assignment via matrix_row with at
      quan::fun::at<0>(row0) = 10;
      
      QUAN_CHECK( (v.at<0,0>() == 10));

      QUAN_CHECK( (quan::fun::at<0>(row0) == 10));
   }

   void matrix_column_test()
   {
      auto constexpr m = quan::fusion::make_matrix<3,2> (
          0.0,0.1
         ,1.0,1.1
         ,2.0,2.1
      );
      {
         typedef quan::fun::matrix_col<0,decltype(m)> col0_type;
        #if defined __cpp_concepts
          QUAN_CHECK((quan::fusion::Sequence<col0_type> == true))
        #endif
         QUAN_CHECK((quan::fun::is_fun_sequence<col0_type>::value == true))
         QUAN_CHECK((quan::is_model_of<quan::fusion::Sequence_,col0_type>::value == true))

         QUAN_CHECK((quan::fusion::num_elements<col0_type> == 3))

         col0_type const col0{m};

         QUAN_CHECK((quan::fun::at_seq<0,col0_type>{}(col0) == 0.0));
         QUAN_CHECK((quan::fun::at_seq<1,col0_type>{}(col0) == 1.0));
         QUAN_CHECK((quan::fun::at_seq<2,col0_type>{}(col0) == 2.0));

      }
      {
         typedef quan::fun::matrix_col<1,decltype(m)> col1_type;

        #if defined __cpp_concepts
         QUAN_CHECK((quan::fusion::Sequence<col1_type> == true))
        #endif
         QUAN_CHECK((quan::fun::is_fun_sequence<col1_type>::value == true))
         QUAN_CHECK((quan::is_model_of<quan::fusion::Sequence_,col1_type>::value == true))

         QUAN_CHECK((quan::fusion::num_elements<col1_type> == 3))

         col1_type col1{m};

         QUAN_CHECK((quan::fun::at_seq<0,col1_type>{}(col1) == 0.1));
         QUAN_CHECK((quan::fun::at_seq<1,col1_type>{}(col1) == 1.1));
         QUAN_CHECK((quan::fun::at_seq<2,col1_type>{}(col1) == 2.1));

      }
   }

   void basic_matrix_test()
   {
      quan::fun::vector<
         int,int,int,
         int,int,int,
         int,int,int
      > sequence { 
         11,12,13, 
         21,22,23, 
         31,32,33
      };

      auto v = quan::fusion::make_matrix<3,3>(sequence);

      QUAN_CHECK( (quan::fun::is_fun_matrix<decltype(v)>::value == true) )
      QUAN_CHECK( (quan::fun::matrix_row_size<decltype(v)>::value == 3) )
      QUAN_CHECK( (quan::fun::matrix_col_size<decltype(v)>::value == 3) )

      QUAN_CHECK( (v.at<0,0>() == 11));
      QUAN_CHECK( (v.at<0,1>() == 12));
      QUAN_CHECK( (v.at<0,2>() == 13));

      QUAN_CHECK( (v.at<1,0>() == 21));
      QUAN_CHECK( (v.at<1,1>() == 22));
      QUAN_CHECK( (v.at<1,2>() == 23));

      QUAN_CHECK( (v.at<2,0>() == 31));
      QUAN_CHECK( (v.at<2,1>() == 32));
      QUAN_CHECK( (v.at<2,2>() == 33));

      // test assignment of element
      v.at<0,0>() = 3;
      QUAN_CHECK( (v.at<0,0>() == 3));

      // test std::tuple elements
      auto v1 = quan::fusion::make_matrix<3,3> (
           std::make_tuple(
               110,120,130,
               210,220,230,
               310,320,330
            ) );
      QUAN_CHECK( (!std::is_const<decltype(v1)::elements_type>::value))
      QUAN_CHECK( (v1.at<0,0>() == 110));
      QUAN_CHECK( (v1.at<1,2>() == 230));
      QUAN_CHECK( (v1.at<2,2>() == 330));

      QUAN_CHECK( (v1.at<1,1>() == 220) );
      v1.at<1,1>() = 20;
      QUAN_CHECK( (v1.at<1,1>() == 20) );
   }

   void matrix_1x1_test()
   {
     auto constexpr m = quan::fusion::make_matrix<1>(1.23456);
     QUAN_CHECK(sizeof(m) == sizeof(double))
     QUAN_CHECK((m.at<0,0>() == 1.23456))
   }

   void fusion_submatrix_test()
   {
      auto constexpr m = quan::fusion::make_matrix<2>
      (
         1.f, 2.f
        ,3.f , 4.f
      );

      auto const s00 = quan::fusion::make_sub_matrix_view<0,0>(m);
      QUAN_CHECK((s00.at<0,0>() == 4))

      auto const s01 = quan::fusion::make_sub_matrix_view<0,1>(m);
      QUAN_CHECK((s01.at<0,0>() == 3))

      auto const s10 = quan::fusion::make_sub_matrix_view<1,0>(m);
      QUAN_CHECK((s10.at<0,0>() == 2))

      auto const s11 = quan::fusion::make_sub_matrix_view<1,1>(m);
      QUAN_CHECK((s11.at<0,0>() == 1))
   }

   void fusion_determinant_test()
   {
      auto constexpr m1 = quan::fusion::make_matrix<1>
      (
         99.f
      );

      auto constexpr res1 = quan::fusion::determinant(m1);
      QUAN_CHECK(res1 == 99.f)

      auto constexpr m2 = quan::fusion::make_matrix<2>
      (
         1.f, 2.f
         ,3.f , 4.f
      );

      auto constexpr res2 = quan::fusion::determinant(m2);
      QUAN_CHECK ( res2 == -2.f)  // 1 * 4 - 2 * 3

      auto constexpr m3 = quan::fusion::make_matrix<3>
      (
         56.f,  90.f,  72.f,
         2.f,   4.f,   7.f,
         -3.f,   1.f,   5.f
      );

      auto constexpr res3 = quan::fusion::determinant(m3);
      QUAN_CHECK ( res3 == -1054.f)

      auto constexpr m4 = quan::fusion::make_matrix<4>
      (                       
           56,  90,   72,    65, 
            2,   4,    7,  - 20, 
           -3,   1,    5,     6, 
          125,  50,   97, -1000 
      );

      auto constexpr res4 = quan::fusion::determinant(m4);
      QUAN_CHECK ( res4 == -328293)

   }
}

void matrix_mux_result_test();
void transpose_matrix_test();
void test_sub_matrix_of_m3();
void qty_matrix_test();

void matrix_test()
{
   basic_matrix_test();
   matrix_row_test();
   matrix_column_test();
   static_value_matrix_test();
   matrix_mux_result_test();
  
   matrix_1x1_test();
   fusion_submatrix_test();
   fusion_determinant_test();
   test_sub_matrix_of_m3();

   qty_matrix_test();
}