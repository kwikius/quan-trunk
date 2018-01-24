
#include <quan_matters/test/test.hpp>
#include <quan/fun/matrix33.hpp>
#include <quan/fun/matrix_row.hpp>
#include <quan/fun/at.hpp>
#include <tuple>
namespace {

   template <int R, int C, typename Seq>
   typename quan::fun::matrix<R,C,Seq>
   make_matrix( Seq const & seq)
   {
      return quan::fun::matrix<R,C,Seq>(seq);
   }

}
/*
 sequenc num_elements == R * C;

  make matrix<R, Seq>(seq const & s)
  {
      size_seq = num_elements<Seq>::value;
      cols = size_seq / R;
      assert( size_seq % r ==0);

      return make_matrix<R,cols>(s);

  }

*/
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

   v.at<0,0>() = 3;

   typedef decltype(v) matrix_type;

   typedef  quan::fun::matrix_row<0,matrix_type> row0_type;

   row0_type row0{v};

   std::cout << "mat < < " << quan::fun::at_seq<0,row0_type>{}(row0) << '\n';
   std::cout << "mat < < " << v.at<0,0>() <<'\n';

   QUAN_CHECK(  (quan::fun::at_seq<0,row0_type>{}(row0) == 3));

   QUAN_CHECK( (v.at<0,0>() == 3));

   quan::fun::at_seq<0,row0_type>{}(row0) = 8;

   QUAN_CHECK(  (quan::fun::at_seq<0,row0_type>{}(row0) == 8));
 
   QUAN_CHECK( (quan::fun::at<0>(row0) == 8) );

   QUAN_CHECK( (v.at<0,0>() == 8));

  // auto & r = quan::fun::at<0>(row0);

  // r= 10;

   QUAN_CHECK( (v.at<0,0>() == 10));

   std::cout << "mat < < " << quan::fun::at_seq<0,row0_type>{}(row0) << '\n';
   std::cout << "mat < < " << v.at<0,0>() <<'\n';

   // v1 is const afaics
   auto v1 = make_matrix<3,3> (std::make_tuple(
            110,120,130,
            210,220,230,
            310,320,330
         ) );

   QUAN_CHECK( (v1.at<0,0>() == 110));
   QUAN_CHECK( (v1.at<1,2>() == 230));
   QUAN_CHECK( (v1.at<2,2>() == 330));

         
}