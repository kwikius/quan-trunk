#include <quan_matters/test/test.hpp>

#include <quan/fun/access_modifiers.hpp>
#include <quan/length.hpp>
#include <string>
#include <type_traits>

void as_value_test()
{
    quan::fun::as_value f;

    int x = 1;
    auto xx = f(x) ;
    QUAN_CHECK( xx == x)
    QUAN_CHECK( &xx != &x)
    QUAN_CHECK ( (!std::is_const<decltype(xx)>::value))
    QUAN_CHECK ( (!std::is_reference<decltype(xx)>::value))

    auto const & xxx = f(x);
    QUAN_CHECK( &xxx != &x)

    QUAN_CHECK( (std::is_const<std::remove_reference<decltype(xxx)>::type>::value) )
    QUAN_CHECK ((std::is_reference<decltype(xxx)>::value))

    quan::length::mm x1{20};
    auto x2 = f(x1);
    QUAN_CHECK(&x1 != &x2)
    std::string str = "Hello";

    auto str1 = f(str);
    QUAN_CHECK(str1 == str)
    QUAN_CHECK( &str1 != &str)
    
}

void as_const_ref_test()
{
    quan::fun::as_const_ref f;
    int x = 1;
    auto & x1 = f(x);
    QUAN_CHECK (&x1 == &x)
    QUAN_CHECK ( (std::is_reference<decltype(x1)>::value))
    QUAN_CHECK ( (std::is_const<std::remove_reference<decltype(x1)>::type>::value))
}

void access_modifiers_test()
{
   as_value_test();
   as_const_ref_test();
/*
   TODO
*/

}


#if defined CODEBLOCKS_STANDALONE
int errors = 0;
int main()
{
   access_modifiers_test();
   QUAN_EPILOGUE
}
#endif

