
#include <quan_matters/test/test.hpp>

#include <quan/meta/binary_op.hpp>
#include <quan/meta/binary_op_seq.hpp>
#include <quan/length.hpp>

using quan::meta::plus;
using quan::meta::minus;
using quan::meta::times;
using quan::meta::divides;

//TODO check all inbuilt are correct
void binary_op_builtin_plus_test1()
{
   QUAN_CHECK( (std::is_same<quan::meta::binary_op<int,plus,int>::type,int>::value) )
   QUAN_CHECK( (std::is_same<quan::meta::binary_op<char,plus,char>::type,int>::value) )
   QUAN_CHECK( (std::is_same<quan::meta::binary_op<char,plus,unsigned char>::type,int>::value) )
   QUAN_CHECK( (std::is_same<quan::meta::binary_op<unsigned char,plus,char>::type,int>::value) )
   QUAN_CHECK( (std::is_same<quan::meta::binary_op<unsigned char,plus,unsigned char>::type,int>::value) )

   QUAN_CHECK( (std::is_same<quan::meta::binary_op<char,plus,short>::type,int>::value) )
   
   QUAN_CHECK( (std::is_same<quan::meta::binary_op<char,plus,unsigned char>::type,int>::value) )
   QUAN_CHECK( (std::is_same<quan::meta::binary_op<char,plus,unsigned short>::type,int>::value) )


   QUAN_CHECK( (std::is_same<quan::meta::binary_op<char,plus,int>::type,int>::value) )
}

void binary_op_seq_test()
{
   typedef quan::meta::binary_op_seq<char,plus,int,float,char,quan::length::m>::type res;

   QUAN_CHECK( ( std::is_same<res,quan::undefined>::value))

   typedef quan::meta::binary_op_seq<char,plus,int,float,char,bool>::type res1;

   QUAN_CHECK( ( std::is_same<res1,float>::value))

   typedef quan::meta::binary_op_seq<float,plus,double>::type res2;

   QUAN_CHECK( ( std::is_same<res2,double>::value))

}

int errors = 0;
int main()
{
   binary_op_builtin_plus_test1();
   binary_op_seq_test();

   QUAN_EPILOGUE
}



