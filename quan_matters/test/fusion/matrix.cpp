
#include <quan_matters/test/test.hpp>
#include <quan/fun/matrix33.hpp>
#include <quan/fun/matrix_row.hpp>
#include <quan/fun/at.hpp>
#include <tuple>
namespace {

   template <int R, int C, typename Seq>
   typename quan::fun::matrix<R,C,Seq>
   make_matrix( Seq && seq)
   {
      return quan::fun::matrix<R,C,Seq>(seq);
   }

}


void matrix_test()
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

   // test std::tuple access
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