

#include <quan/fusion/inner_product.hpp>
#include <quan/operators/binary_operator_functors.hpp>
#include <quan/fun/vector16.hpp>

#include <quan_matters/test/test.hpp>

#if ( __cplusplus < 201402L )
#error requires C++14 or greater
#endif

void inner_product_test()
{
   auto seqL = quan::fun::vector16<
         int,int,int,int,
         int,int,int,int,
         int,int,int,int,
         int,int,int,int >{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

   auto seqR = quan::fun::vector16<
         int,int,int,int,
         int,int,int,int,
         int,int,int,int,
         int,int,int,double >{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

   typedef quan::fun::inner_product_seq::result<
         decltype(seqL),decltype(seqR),quan::operator_plus,quan::operator_times
   >::type
   result_type;
#if defined __cpp_concepts 
   QUAN_CHECK(quan::fusion::Sequence<decltype(seqL)>);
   QUAN_CHECK(quan::fusion::Sequence<decltype(seqR)>);
 #else
   QUAN_CHECK(quan::fun::is_fun_sequence<decltype(seqL)>::value);
   QUAN_CHECK(quan::fun::is_fun_sequence<decltype(seqR)>::value);
#endif

   QUAN_CHECK(quan::fusion::num_elements<decltype(seqL)> == 16);
   QUAN_CHECK(quan::fusion::num_elements<decltype(seqR)> == 16);

   QUAN_CHECK( ( std::is_same<quan::fusion::type_at<0,decltype(seqL)>,int>::value ) );
   QUAN_CHECK( ( std::is_same<quan::fusion::type_at<15,decltype(seqL)>,int>::value ) );

   auto r = quan::fusion::inner_product(seqL,seqR,quan::operator_plus{},quan::operator_times{});

   QUAN_CHECK( (std::is_same<decltype(r),double>::value) )
   QUAN_CHECK( (std::is_same<result_type,double>::value) )

   int sum = 0;
   // equivalent calc
   for ( unsigned int i = 1U ; i <= quan::fusion::num_elements<decltype(seqL)> ;++i){
     sum += i * i;
   }

   QUAN_CHECK(r == sum);
}

