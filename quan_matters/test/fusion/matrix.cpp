
#include <quan_matters/test/test.hpp>
#include <quan/fun/matrix.hpp>
//#include <quan/fun/matrix33.hpp>

#include <quan/concepts/fusion/sequence.hpp>
#include <quan/fun/matrix_row.hpp>
#include <quan/fun/matrix_col.hpp>
#include <quan/fun/at.hpp>
#include <tuple>

#include <quan/length.hpp>
#include <quan/time.hpp>
#include <quan/area.hpp>
#include <quan/velocity.hpp>
#include <quan/reciprocal_length.hpp>
#include <quan/fusion/static_value.hpp>
#include <quan/fixed_quantity/literal.hpp>
#include <quan/fun/vector9.hpp>
#include <quan/undefined.hpp>



namespace {

#if defined __cpp_concepts
   template <int R, int C, quan::fusion::Sequence Seq>
     requires quan::fusion::num_elements<Seq> == R * C
   constexpr 
   quan::fun::matrix<R,C,Seq>
   make_matrix( Seq && seq)
   {
      return quan::fun::matrix<R,C,Seq>(seq);
   }

   template<int R, int C, typename... Elements>
     requires sizeof ...(Elements)  == R * C
   constexpr quan::fun::matrix<R,C,std::tuple<Elements...> >
   make_matrix(Elements&&... args)
   {
      return make_matrix<R,C>(std::forward_as_tuple(args...));
   }

#else
   template <int R, int C, typename Seq>
   constexpr 
   typename quan::where_<
      quan::meta::and_<
         quan::is_model_of<quan::fusion::Sequence_,Seq>
         ,quan::meta::bool_< ( quan::fusion::num_elements<Seq> == R * C ) >
      >,
      quan::fun::matrix<R,C,Seq>
   >::type
   make_matrix( Seq && seq)
   {
      return quan::fun::matrix<R,C,Seq>(seq);
   }

   template<int R, int C, typename... Elements>
   constexpr 
   typename quan::where_c<
      ( sizeof ...(Elements) == R * C)
     ,quan::fun::matrix<R,C,std::tuple<Elements...> >
   >::type
   make_matrix(Elements&&... args)
   {
      return make_matrix<R,C>(std::forward_as_tuple(args...));
   }

#endif

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

         auto id2 = make_matrix<2,2> (
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

         auto id2a = make_matrix<2,2> (
           // std::make_tuple(
                one {}, zero{}
               ,zero{}, one {}
            //)
         );
         QUAN_CHECK( ( static_cast<bool>(id2a.at<0,0>() == one{}) ) );
         QUAN_CHECK( ( id2a.at<0,0>() == 1.0 ) );
         QUAN_CHECK( ( static_cast<bool>(id2a.at<0,1>() == zero{}) ) ); 
         QUAN_CHECK( ( id2a.at<0,1>() == 0.0 ) );
      }
   }

   void matrix_row_test()
   {
      quan::fun::vector9<
         int,int,int,
         int,int,int,
         int,int,int
      > sequence { 
         11,12,13, 
         21,22,23, 
         31,32,33
      };

      auto v = make_matrix<3,3>(sequence);

      QUAN_CHECK( (v.at<0,0>() == 11));
      QUAN_CHECK( (v.at<2,2>() == 33));

      // test assignment of element
      v.at<0,0>() = 3;
      QUAN_CHECK( (v.at<0,0>() == 3));

      typedef decltype(v) matrix_type;

   //--- matrix row
      typedef  quan::fun::matrix_row<0,matrix_type> row0_type;

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

   void basic_matrix_test()
   {
      quan::fun::vector9<
         int,int,int,
         int,int,int,
         int,int,int
      > sequence { 
         11,12,13, 
         21,22,23, 
         31,32,33
      };

      auto v = make_matrix<3,3>(sequence);

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
      auto v1 = make_matrix<3,3> (
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
}

void matrix_test()
{
   basic_matrix_test();
   matrix_row_test();
   static_value_matrix_test();
}