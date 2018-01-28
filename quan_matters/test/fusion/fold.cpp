
#include <tuple>
#include <typeinfo>
#include <quan/fusion/fold.hpp>

#include <quan_matters/test/test.hpp>
#include <quan/operators/binary_operator_functors.hpp>

#include <quan/fusion/make_vector.hpp>


namespace {

   // constexpr seq of rvalues in constexpr result
   void fold_test1()
   {
      auto constexpr seq = std::make_tuple(1,2,3,27.5,-3,-2,-1);

      QUAN_CHECK(quan::fun::is_fun_sequence<decltype(seq)>::value == true)

      auto constexpr r = quan::fusion::fold(seq,0,quan::operator_plus{});

      QUAN_CHECK( (std::is_same<decltype(r),const double>::value))

      QUAN_CHECK(r == 27.5);
   }

    void fold_test1a()
   {
      auto constexpr seq = quan::fusion::make_vector(1,2,3,27.5,-3,-2,-1);

      QUAN_CHECK(quan::fun::is_fun_sequence<decltype(seq)>::value == true)

      auto constexpr r = quan::fusion::fold(seq,0,quan::operator_plus{});

      QUAN_CHECK( (std::is_same<decltype(r),const double>::value))

      QUAN_CHECK(r == 27.5);
   }

   // constexpr seq in with constexpr lvalue. constexpr result
   void fold_test2()
   {
      constexpr auto v = 27.5;
      auto constexpr seq = std::make_tuple(1,2,3,v,-3,-2,-1);

      QUAN_CHECK(quan::fun::is_fun_sequence<decltype(seq)>::value == true)

      auto constexpr r = quan::fusion::fold(seq,0,quan::operator_plus{});

      QUAN_CHECK( (std::is_same<decltype(r),const double>::value))

      QUAN_CHECK(r == 27.5);
   }

   void fold_test2a()
   {
      constexpr auto v = 27.5;
      auto constexpr seq = quan::fusion::make_vector(1,2,3,v,-3,-2,-1);

      QUAN_CHECK(quan::fun::is_fun_sequence<decltype(seq)>::value == true)

      auto constexpr r = quan::fusion::fold(seq,0,quan::operator_plus{});

      QUAN_CHECK( (std::is_same<decltype(r),const double>::value))

      QUAN_CHECK(r == 27.5);
   }
   // const seq in with const lvalue, const result
    void fold_test3()
   {
      const auto v = 27.5;
      auto const seq = std::make_tuple(1,2,3,v,-3,-2,-1);

      QUAN_CHECK(quan::fun::is_fun_sequence<decltype(seq)>::value == true)

      auto const r = quan::fusion::fold(seq,0,quan::operator_plus{});

      QUAN_CHECK( (std::is_same<decltype(r),const double>::value))

      QUAN_CHECK(r == 27.5);
   }

   void fold_test3a()
   {
      const auto v = 27.5;
      auto const seq = quan::fusion::make_vector(1,2,3,v,-3,-2,-1);

      QUAN_CHECK(quan::fun::is_fun_sequence<decltype(seq)>::value == true)

      auto const r = quan::fusion::fold(seq,0,quan::operator_plus{});

      QUAN_CHECK( (std::is_same<decltype(r),const double>::value))

      QUAN_CHECK(r == 27.5);
   }

   // const seq in with non-const lvalue, const result
   void fold_test4()
   {
      auto v = 27.5;
      auto const seq = std::make_tuple(1,2,3,v,-3,-2,-1);

     // std::cout << typeid(seq).name()  <<'\n';

      QUAN_CHECK(quan::fun::is_fun_sequence<decltype(seq)>::value == true)

      auto const r = quan::fusion::fold(seq,0,quan::operator_plus{});

      QUAN_CHECK( (std::is_same<decltype(r),const double>::value))

      QUAN_CHECK(r == 27.5);
   }

   void fold_test4a()
   {
      auto v = 27.5;
      auto const seq = quan::fusion::make_vector(1,2,3,v,-3,-2,-1);
     
     // std::cout << typeid(seq).name()  <<'\n';

      QUAN_CHECK(quan::fun::is_fun_sequence<decltype(seq)>::value == true)

      auto r = quan::fusion::fold(seq,0,quan::operator_plus{});

      QUAN_CHECK( (std::is_same<decltype(r),double>::value))

      QUAN_CHECK(r == 27.5);
   }


  // r_value sequence
   void fold_test5()
   {
      auto v = 27.5;

      auto r = quan::fusion::fold(
         quan::fusion::make_vector(1,2,3,v,-3,-2,-1),0,quan::operator_plus{});

      QUAN_CHECK( (std::is_same<decltype(r),double>::value))

      QUAN_CHECK(r == 27.5);
   }

   

}

void fold_test()
{
   fold_test1();
   fold_test1a();
   fold_test2();
   fold_test2a();
   fold_test3();
   fold_test3a();
   fold_test4();
   fold_test4a();
   fold_test5();
}

  
