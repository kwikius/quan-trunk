
#include <cstdlib>
#include <quan_matters/test/test.hpp>

#include <iostream>
#include <string>

namespace {
   
   struct compile_info_t{
      std::string compiler;
      std::string flags;
      std::string includes;
      std::string log_file;
   };
}

//bool compile_fail_test(std::string const & filename, std::string const & cmd_head_in = cmd_head, std::string const & log_file_in = log_file)
bool compile_fail_test(std::string const & filename, compile_info_t const & compile_info)
{
   std::string header = "echo '#### compile fail test on " + filename + " ####\n'";//  >> " + compile_info.log_file;
   system(header.c_str());
   std::string cmd_head = compile_info.compiler + " " + compile_info.flags + " " + compile_info.includes;
   std::string cmd = cmd_head + " " + filename + " >> " + compile_info.log_file + " 2>&1" ;
   int result = system(cmd.c_str());
   if ( result == 0){
      std::string tail =  "echo '#### UNEXPECTED : compilation of " + filename + " succeeded: TEST FAILED \n'";//  >> " + compile_info.log_file;
      system (tail.c_str());
   }else{
      std::string tail =  "echo 'TEST SUCCESSFUL : ( compilation of " + filename + " failed as expected)\n'";// >> " + compile_info.log_file;
      system (tail.c_str());
   }
   return result != 0;
}

int main()
{
   compile_info_t compile_info;

   compile_info.compiler   = "g++-7";
   compile_info.flags      = "-std=c++11 -fmax-errors=1";
   compile_info.includes   = "-I../../../";
   compile_info.log_file   = "compile_fail_log.txt";
   
   std::string header = "echo '########## starting compile fail test suite ##########\n'" ;//  > " + compile_info.log_file;
   system (header.c_str());

   QUAN_CHECK( compile_fail_test("t1_quantity/addeq_not_dimen_equiv_test1.cpp",compile_info) )

   QUAN_CHECK( compile_fail_test("t1_quantity/addeq_not_dimen_equiv_test.cpp",compile_info) )
   QUAN_CHECK( compile_fail_test("t1_quantity/add_not_dimen_equiv_test.cpp",compile_info) )
   QUAN_CHECK( compile_fail_test("t1_quantity/compare_fail.cpp",compile_info) )
   QUAN_CHECK( compile_fail_test("t1_quantity/da_wrong_assign.cpp",compile_info) )
   QUAN_CHECK( compile_fail_test("t1_quantity/da_wrong_div_eq.cpp",compile_info) )
   QUAN_CHECK( compile_fail_test("t1_quantity/da_wrong_init.cpp",compile_info) )
   QUAN_CHECK( compile_fail_test("t1_quantity/da_wrong_minus_eq.cpp",compile_info) )
   QUAN_CHECK( compile_fail_test("t1_quantity/da_wrong_plus_eq.cpp",compile_info) )
   QUAN_CHECK( compile_fail_test("t1_quantity/da_wrong_times_eq.cpp",compile_info) )
   QUAN_CHECK( compile_fail_test("t1_quantity/dif_dim_init.cpp",compile_info) )
   QUAN_CHECK( compile_fail_test("t1_quantity/dimensionally_wrong_calc.cpp",compile_info) )
   QUAN_CHECK( compile_fail_test("t1_quantity/divide_equal.cpp",compile_info) )
   QUAN_CHECK( compile_fail_test("t1_quantity/implicit_value_initialise.cpp",compile_info) )
   QUAN_CHECK( compile_fail_test("t1_quantity/less_equal_fail.cpp",compile_info) )
   QUAN_CHECK( compile_fail_test("t1_quantity/less_fail.cpp",compile_info) )
   QUAN_CHECK( compile_fail_test("t1_quantity/not_convert_value_type.cpp",compile_info) )
   QUAN_CHECK( compile_fail_test("t1_quantity/prevent_unit_conv_test.cpp",compile_info) )
   QUAN_CHECK( compile_fail_test("t1_quantity/subeq_not_dimen_equiv_test1.cpp",compile_info) )
   QUAN_CHECK( compile_fail_test("t1_quantity/subeq_not_dimen_equiv_test.cpp",compile_info) )
   QUAN_CHECK( compile_fail_test("t1_quantity/sub_not_dimen_equiv_test.cpp",compile_info) )
   QUAN_CHECK( compile_fail_test("t1_quantity/times_equal.cpp",compile_info) )

   std::string tail =  "echo '########## compile fail tests completed ##########\n'";// >> " + compile_info.log_file;
   system (tail.c_str());

   QUAN_EPILOGUE
}

int errors = 0;


