
#include <typeinfo>

#include <quan_matters/test/test.hpp>

#include <quan/fusion/matrix.hpp>
#include <quan/fusion/static_value.hpp>

#include <quan/length.hpp>
#include <quan/time.hpp>
#include <quan/area.hpp>
#include <quan/velocity.hpp>
#include <quan/reciprocal_length.hpp>

#include <quan/fixed_quantity/literal.hpp>

namespace {

   

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

   void multiply_view_test()
   {
      auto constexpr m1 = quan::fusion::make_matrix<4>
      (
         1.0 ,2.0 ,3.0 ,4.0 ,
         1.0 ,2.0 ,3.0 ,4.0 ,
         1.0 ,2.0 ,3.0 ,4.0 ,
         1.0 ,2.0 ,3.0 ,4.0
      );

      auto constexpr m2 = quan::fusion::make_matrix<4>
      (
         1,0,0,0,
         0,1,0,0,
         0,0,1,0,
         0,0,0,2
      );

      auto constexpr result = m1 * m2;
      display(result,"m1 * m2 : ");

      typedef quan::meta::strip_cr<decltype(result)>::type result_type;

      auto const res_view = quan::fusion::make_multiplies_view(m1,m2);
      typedef quan::meta::strip_cr<decltype(res_view)>::type res_view_type;
      typedef quan::fun::as_value_matrix<res_view_type>::type mux_val_type;
      auto const mux_val = mux_val_type{quan::fusion::as_sequence(res_view)};

      display(mux_val,"The synthesised  mux of m1 , m2: ");

      QUAN_CHECK((res_view.at<0,0>() == result.at<0,0>() ))

      typedef quan::fun::as_value_matrix<res_view_type>::type alt_result_type;
#if ! defined QUAN_NO_RTTI
      QUAN_CHECK( ( typeid(alt_result_type).name() == typeid(result_type).name() ) );
#endif
      QUAN_CHECK( (std::is_same<result_type,alt_result_type>::value));

      typedef quan::fun::matrix_as_sequence<res_view_type> mat_as_seq1;

      mat_as_seq1 s1{res_view};

      typedef quan::fun::matrix_as_sequence<result_type> mat_as_seq2;
      mat_as_seq2 s2{result};

      

      // TODO no at in as_seq
      //QUAN_CHECK( (s1.at<0>() == s2.at<0,0>() ) )
  
   }

   void matrix_mux_result_test1()
   {

       auto constexpr m1 = quan::fusion::make_matrix<3,3>(
           1.0, 0.0 , 0.0
          ,0.0, 1.0 , 0.0
          ,0.0, 0.0 , 1.0
       );

       auto constexpr m2 = quan::fusion::make_matrix<3,3>(
           2.0, 0.0 , 0.0
          ,0.0, 2.0 , 0.0
          ,0.0, 0.0 , 2.0
       );

       auto constexpr result = m1 * m2;

       QUAN_CHECK( (result.at<0,0>() == 2.0))
       QUAN_CHECK( (result.at<0,1>() == 0.0))
       QUAN_CHECK( (result.at<0,2>() == 0.0))

       QUAN_CHECK( (result.at<1,0>() == 0.0))
       QUAN_CHECK( (result.at<1,1>() == 2.0))
       QUAN_CHECK( (result.at<1,2>() == 0.0))

       QUAN_CHECK( (result.at<2,0>() == 0.0))
       QUAN_CHECK( (result.at<2,1>() == 0.0))
       QUAN_CHECK( (result.at<2,2>() == 2.0))

       QUAN_CHECK(sizeof (result) == 9 * sizeof(double));
   }

   template <int64_t N, int64_t D= 1>
   using static_float = quan::fusion::static_value< double,quan::meta::rational<N,D> >;

   typedef static_float<0> zero;
   typedef static_float<1> one;
   typedef static_float<2> two;

   void matrix_mux_result_test2()
   {

      auto constexpr m1 = quan::fusion::make_matrix<3,3>(
        one{}, zero{} , zero{}
       ,zero{}, one{} , zero{}
       ,zero{}, zero{}, one{}
      );

      auto constexpr m2 = quan::fusion::make_matrix<3,3>(
        two{}, zero{} , zero{}
       ,zero{}, two{} , zero{}
       ,zero{}, zero{}, two{}
      );

      auto constexpr result = m1 * m2;

      QUAN_CHECK( is_static_value(result.at<0,0>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<0,0>() == two{})))
      QUAN_CHECK( (result.at<0,0>() == 2))

      QUAN_CHECK( is_static_value(result.at<0,1>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<0,1>() == zero{})))
      QUAN_CHECK( (result.at<0,1>() == 0))

      QUAN_CHECK( is_static_value(result.at<0,2>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<0,2>() == zero{})))
      QUAN_CHECK( (result.at<0,2>() == 0))

      QUAN_CHECK( is_static_value(result.at<1,0>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<1,0>() == zero{})))
      QUAN_CHECK( (result.at<1,0>() == 0))

      QUAN_CHECK( is_static_value(result.at<1,1>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<1,1>() == two{})))
      QUAN_CHECK( (result.at<1,1>() == 2))

      QUAN_CHECK( is_static_value(result.at<1,2>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<1,2>() == zero{})))
      QUAN_CHECK( (result.at<1,2>() == 0))

      QUAN_CHECK( is_static_value(result.at<2,0>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<2,0>() == zero{})))
      QUAN_CHECK( (result.at<2,0>() == 0))

      QUAN_CHECK( is_static_value(result.at<2,1>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<2,1>() == zero{})))
      QUAN_CHECK( (result.at<2,1>() == 0))

      QUAN_CHECK( is_static_value(result.at<2,2>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<2,2>() == two{})))
      QUAN_CHECK( (result.at<2,2>() == 2))
   }

   void matrix_mux_result_test3()
   {
      auto constexpr m1 = quan::fusion::make_matrix<3,3>(
        one{}, zero{} , zero{}
       ,zero{}, one{} , zero{}
       ,zero{}, zero{}, one{}
      );

      auto constexpr m2 = quan::fusion::make_matrix<3,3>(
        2, zero{} , zero{}
       ,zero{}, 2 , zero{}
       ,zero{}, zero{}, 2
      );

      auto constexpr result = m1 * m2;

      auto constexpr r00 = result.at<0,0>();

      QUAN_CHECK( !is_static_value(r00) )
      QUAN_CHECK( (r00 == two{}))
      QUAN_CHECK( (r00 == 2))

      QUAN_CHECK( !is_static_value(result.at<0,0>()) )
      QUAN_CHECK( (result.at<0,0>() == two{}))
      QUAN_CHECK( (result.at<0,0>() == 2))

      auto constexpr r01 = result.at<0,1>();
      QUAN_CHECK( is_static_value(r01) )
      QUAN_CHECK( (static_cast<bool>(r01 == zero{})))
      QUAN_CHECK( (r01 == 0))

      QUAN_CHECK( is_static_value(result.at<0,1>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<0,1>() == zero{})))
      QUAN_CHECK( (result.at<0,1>() == 0))

      auto constexpr r02 = result.at<0,2>();
      QUAN_CHECK( (static_cast<bool>(r02 == zero{})))
      QUAN_CHECK( is_static_value(result.at<0,2>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<0,2>() == zero{})))
      QUAN_CHECK( (result.at<0,2>() == 0))

      auto constexpr r10 = result.at<1,0>();
      QUAN_CHECK( (r10 == 0));
      QUAN_CHECK( is_static_value(result.at<1,0>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<1,0>() == zero{})))
      QUAN_CHECK( (result.at<1,0>() == 0))

      auto constexpr r11 = result.at<1,1>();
      QUAN_CHECK( (r11 == 2));
      QUAN_CHECK( !is_static_value(result.at<1,1>()) )
      QUAN_CHECK( (result.at<1,1>() == two{}))
      QUAN_CHECK( (result.at<1,1>() == 2))

      auto constexpr r12 = result.at<1,2>();
      QUAN_CHECK( (r12 == 0));
      QUAN_CHECK( is_static_value(result.at<1,2>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<1,2>() == zero{})))
      QUAN_CHECK( (result.at<1,2>() == 0))

      auto constexpr r20 = result.at<2,0>();
      QUAN_CHECK( (r20 == 0));
      QUAN_CHECK( is_static_value(result.at<2,0>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<2,0>() == zero{})))
      QUAN_CHECK( (result.at<2,0>() == 0))

      auto constexpr r21 = result.at<2,1>();
      QUAN_CHECK( (r21 == 0));
      QUAN_CHECK( is_static_value(result.at<2,1>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<2,1>() == zero{})))
      QUAN_CHECK( (result.at<2,1>() == 0))

      auto constexpr r22 = result.at<2,2>();
      QUAN_CHECK( (r22 == 2));
      QUAN_CHECK(! is_static_value(result.at<2,2>()) )
      QUAN_CHECK( (result.at<2,2>() == two{}))
      QUAN_CHECK( (result.at<2,2>() == 2))
   }

    // check mux of temporaries
    void matrix_mux_result_test4()
    {
       auto constexpr result = quan::fusion::make_matrix<3,3>(
        one{}, zero{} , zero{}
       ,zero{}, one{} , zero{}
       ,zero{}, zero{}, one{}
      ) 
       * 
      quan::fusion::make_matrix<3,3>(
        2, zero{} , zero{}
       ,zero{}, 2 , zero{}
       ,zero{}, zero{}, 2
      );

      auto constexpr r00 = result.at<0,0>();

      QUAN_CHECK( !is_static_value(r00) )
      QUAN_CHECK( (r00 == two{}))
      QUAN_CHECK( (r00 == 2))

      QUAN_CHECK( !is_static_value(result.at<0,0>()) )
      QUAN_CHECK( (result.at<0,0>() == two{}))
      QUAN_CHECK( (result.at<0,0>() == 2))

      auto constexpr r01 = result.at<0,1>();
      QUAN_CHECK( is_static_value(r01) )
      QUAN_CHECK( (static_cast<bool>(r01 == zero{})))
      QUAN_CHECK( (r01 == 0))

      QUAN_CHECK( is_static_value(result.at<0,1>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<0,1>() == zero{})))
      QUAN_CHECK( (result.at<0,1>() == 0))

      auto constexpr r02 = result.at<0,2>();
      QUAN_CHECK( (static_cast<bool>(r02 == zero{})))
      QUAN_CHECK( is_static_value(result.at<0,2>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<0,2>() == zero{})))
      QUAN_CHECK( (result.at<0,2>() == 0))

      auto constexpr r10 = result.at<1,0>();
      QUAN_CHECK( (r10 == 0));
      QUAN_CHECK( is_static_value(result.at<1,0>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<1,0>() == zero{})))
      QUAN_CHECK( (result.at<1,0>() == 0))

      auto constexpr r11 = result.at<1,1>();
      QUAN_CHECK( (r11 == 2));
      QUAN_CHECK( !is_static_value(result.at<1,1>()) )
      QUAN_CHECK( (result.at<1,1>() == two{}))
      QUAN_CHECK( (result.at<1,1>() == 2))

      auto constexpr r12 = result.at<1,2>();
      QUAN_CHECK( (r12 == 0));
      QUAN_CHECK( is_static_value(result.at<1,2>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<1,2>() == zero{})))
      QUAN_CHECK( (result.at<1,2>() == 0))

      auto constexpr r20 = result.at<2,0>();
      QUAN_CHECK( (r20 == 0));
      QUAN_CHECK( is_static_value(result.at<2,0>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<2,0>() == zero{})))
      QUAN_CHECK( (result.at<2,0>() == 0))

      auto constexpr r21 = result.at<2,1>();
      QUAN_CHECK( (r21 == 0));
      QUAN_CHECK( is_static_value(result.at<2,1>()) )
      QUAN_CHECK( (static_cast<bool>(result.at<2,1>() == zero{})))
      QUAN_CHECK( (result.at<2,1>() == 0))

      auto constexpr r22 = result.at<2,2>();
      QUAN_CHECK( (r22 == 2));
      QUAN_CHECK(! is_static_value(result.at<2,2>()) )
      QUAN_CHECK( (result.at<2,2>() == two{}))
      QUAN_CHECK( (result.at<2,2>() == 2))

    }

}

void matrix_mux_result_test()
{
   matrix_mux_result_test1();
   matrix_mux_result_test2();
   matrix_mux_result_test3();

   matrix_mux_result_test4();

   multiply_view_test();
}

