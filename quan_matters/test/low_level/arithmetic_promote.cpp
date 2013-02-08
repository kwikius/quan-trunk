// Copyright T. Zach Laine 2006

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    test arithmetic_promote functionality
*/

#include <quan_matters/test/test.hpp>
#include <quan/meta/rational.hpp>
#include <quan/meta/arithmetic_promote.hpp>
#include <type_traits>

#if 1
void test_arithmetic_promote();
int errors =0;
int main()
{
   test_arithmetic_promote();
   EPILOGUE
}
#endif

void test_arithmetic_promote()
{
    typedef int underlying_wchar_t;
    typedef quan::meta::arithmetic_promote<bool, bool>::type bool_bool_promotion;
    bool bool_bool_value = std::is_same<bool_bool_promotion, int>::value;
    QUAN_CHECK(bool_bool_value);

    typedef quan::meta::arithmetic_promote<bool, signed char>::type bool_signed_char_promotion;
    bool bool_signed_char_value = std::is_same<bool_signed_char_promotion, int>::value;
    QUAN_CHECK(bool_signed_char_value);

    typedef quan::meta::arithmetic_promote<bool, unsigned char>::type bool_unsigned_char_promotion;
    bool bool_unsigned_char_value = std::is_same<bool_unsigned_char_promotion, int>::value;
    QUAN_CHECK(bool_unsigned_char_value);

    typedef quan::meta::arithmetic_promote<bool, char>::type bool_char_promotion;
    bool bool_char_value = std::is_same<bool_char_promotion, int>::value;
    QUAN_CHECK(bool_char_value);


    typedef quan::meta::arithmetic_promote<bool, wchar_t>::type bool_wchar_t_promotion;
    bool bool_wchar_t_value = std::is_same<bool_wchar_t_promotion, underlying_wchar_t>::value;
    QUAN_CHECK(bool_wchar_t_value);


    typedef quan::meta::arithmetic_promote<bool, short>::type bool_short_promotion;
    bool bool_short_value = std::is_same<bool_short_promotion, int>::value;
    QUAN_CHECK(bool_short_value);

    typedef quan::meta::arithmetic_promote<bool, unsigned short>::type bool_unsigned_short_promotion;
    bool bool_unsigned_short_value = std::is_same<bool_unsigned_short_promotion, int>::value;
    QUAN_CHECK(bool_unsigned_short_value);

    typedef quan::meta::arithmetic_promote<bool, int>::type bool_int_promotion;
    bool bool_int_value = std::is_same<bool_int_promotion, int>::value;
    QUAN_CHECK(bool_int_value);

    typedef quan::meta::arithmetic_promote<bool, unsigned int>::type bool_unsigned_int_promotion;
    bool bool_unsigned_int_value = std::is_same<bool_unsigned_int_promotion, unsigned int>::value;
    QUAN_CHECK(bool_unsigned_int_value);

    typedef quan::meta::arithmetic_promote<bool, long>::type bool_long_promotion;
    bool bool_long_value = std::is_same<bool_long_promotion, long>::value;
    QUAN_CHECK(bool_long_value);

    typedef quan::meta::arithmetic_promote<bool, unsigned long>::type bool_unsigned_long_promotion;
    bool bool_unsigned_long_value = std::is_same<bool_unsigned_long_promotion, unsigned long>::value;
    QUAN_CHECK(bool_unsigned_long_value);

    typedef quan::meta::arithmetic_promote<bool, float>::type bool_float_promotion;
    bool bool_float_value = std::is_same<bool_float_promotion, float>::value;
    QUAN_CHECK(bool_float_value);

    typedef quan::meta::arithmetic_promote<bool, double>::type bool_double_promotion;
    bool bool_double_value = std::is_same<bool_double_promotion, double>::value;
    QUAN_CHECK(bool_double_value);

    typedef quan::meta::arithmetic_promote<bool, long double>::type bool_long_double_promotion;
    bool bool_long_double_value = std::is_same<bool_long_double_promotion, long double>::value;
    QUAN_CHECK(bool_long_double_value);

    typedef quan::meta::arithmetic_promote<signed char, bool>::type signed_char_bool_promotion;
    bool signed_char_bool_value = std::is_same<signed_char_bool_promotion, int>::value;
    QUAN_CHECK(signed_char_bool_value);

    typedef quan::meta::arithmetic_promote<signed char, signed char>::type signed_char_signed_char_promotion;
    bool signed_char_signed_char_value = std::is_same<signed_char_signed_char_promotion, int>::value;
    QUAN_CHECK(signed_char_signed_char_value);

    typedef quan::meta::arithmetic_promote<signed char, unsigned char>::type signed_char_unsigned_char_promotion;
    bool signed_char_unsigned_char_value = std::is_same<signed_char_unsigned_char_promotion, int>::value;
    QUAN_CHECK(signed_char_unsigned_char_value);

    typedef quan::meta::arithmetic_promote<signed char, char>::type signed_char_char_promotion;
    bool signed_char_char_value = std::is_same<signed_char_char_promotion, int>::value;
    QUAN_CHECK(signed_char_char_value);

#ifndef BOOST_NO_INTRINSIC_WCHAR_T
    typedef quan::meta::arithmetic_promote<signed char, wchar_t>::type signed_char_wchar_t_promotion;
    bool signed_char_wchar_t_value = std::is_same<signed_char_wchar_t_promotion, underlying_wchar_t>::value;
    QUAN_CHECK(signed_char_wchar_t_value);
#endif

    typedef quan::meta::arithmetic_promote<signed char, short>::type signed_char_short_promotion;
    bool signed_char_short_value = std::is_same<signed_char_short_promotion, int>::value;
    QUAN_CHECK(signed_char_short_value);

    typedef quan::meta::arithmetic_promote<signed char, unsigned short>::type signed_char_unsigned_short_promotion;
    bool signed_char_unsigned_short_value = std::is_same<signed_char_unsigned_short_promotion, int>::value;
    QUAN_CHECK(signed_char_unsigned_short_value);

    typedef quan::meta::arithmetic_promote<signed char, int>::type signed_char_int_promotion;
    bool signed_char_int_value = std::is_same<signed_char_int_promotion, int>::value;
    QUAN_CHECK(signed_char_int_value);

    typedef quan::meta::arithmetic_promote<signed char, unsigned int>::type signed_char_unsigned_int_promotion;
    bool signed_char_unsigned_int_value = std::is_same<signed_char_unsigned_int_promotion, unsigned int>::value;
    QUAN_CHECK(signed_char_unsigned_int_value);

    typedef quan::meta::arithmetic_promote<signed char, long>::type signed_char_long_promotion;
    bool signed_char_long_value = std::is_same<signed_char_long_promotion, long>::value;
    QUAN_CHECK(signed_char_long_value);

    typedef quan::meta::arithmetic_promote<signed char, unsigned long>::type signed_char_unsigned_long_promotion;
    bool signed_char_unsigned_long_value = std::is_same<signed_char_unsigned_long_promotion, unsigned long>::value;
    QUAN_CHECK(signed_char_unsigned_long_value);

    typedef quan::meta::arithmetic_promote<signed char, float>::type signed_char_float_promotion;
    bool signed_char_float_value = std::is_same<signed_char_float_promotion, float>::value;
    QUAN_CHECK(signed_char_float_value);

    typedef quan::meta::arithmetic_promote<signed char, double>::type signed_char_double_promotion;
    bool signed_char_double_value = std::is_same<signed_char_double_promotion, double>::value;
    QUAN_CHECK(signed_char_double_value);

    typedef quan::meta::arithmetic_promote<signed char, long double>::type signed_char_long_double_promotion;
    bool signed_char_long_double_value = std::is_same<signed_char_long_double_promotion, long double>::value;
    QUAN_CHECK(signed_char_long_double_value);

    typedef quan::meta::arithmetic_promote<unsigned char, bool>::type unsigned_char_bool_promotion;
    bool unsigned_char_bool_value = std::is_same<unsigned_char_bool_promotion, int>::value;
    QUAN_CHECK(unsigned_char_bool_value);

    typedef quan::meta::arithmetic_promote<unsigned char, signed char>::type unsigned_char_signed_char_promotion;
    bool unsigned_char_signed_char_value = std::is_same<unsigned_char_signed_char_promotion, int>::value;
    QUAN_CHECK(unsigned_char_signed_char_value);

    typedef quan::meta::arithmetic_promote<unsigned char, unsigned char>::type unsigned_char_unsigned_char_promotion;
    bool unsigned_char_unsigned_char_value = std::is_same<unsigned_char_unsigned_char_promotion, int>::value;
    QUAN_CHECK(unsigned_char_unsigned_char_value);

    typedef quan::meta::arithmetic_promote<unsigned char, char>::type unsigned_char_char_promotion;
    bool unsigned_char_char_value = std::is_same<unsigned_char_char_promotion, int>::value;
    QUAN_CHECK(unsigned_char_char_value);


    typedef quan::meta::arithmetic_promote<unsigned char, wchar_t>::type unsigned_char_wchar_t_promotion;
    bool unsigned_char_wchar_t_value = std::is_same<unsigned_char_wchar_t_promotion, underlying_wchar_t>::value;
    QUAN_CHECK(unsigned_char_wchar_t_value);


    typedef quan::meta::arithmetic_promote<unsigned char, short>::type unsigned_char_short_promotion;
    bool unsigned_char_short_value = std::is_same<unsigned_char_short_promotion, int>::value;
    QUAN_CHECK(unsigned_char_short_value);

    typedef quan::meta::arithmetic_promote<unsigned char, unsigned short>::type unsigned_char_unsigned_short_promotion;
    bool unsigned_char_unsigned_short_value = std::is_same<unsigned_char_unsigned_short_promotion, int>::value;
    QUAN_CHECK(unsigned_char_unsigned_short_value);

    typedef quan::meta::arithmetic_promote<unsigned char, int>::type unsigned_char_int_promotion;
    bool unsigned_char_int_value = std::is_same<unsigned_char_int_promotion, int>::value;
    QUAN_CHECK(unsigned_char_int_value);

    typedef quan::meta::arithmetic_promote<unsigned char, unsigned int>::type unsigned_char_unsigned_int_promotion;
    bool unsigned_char_unsigned_int_value = std::is_same<unsigned_char_unsigned_int_promotion, unsigned int>::value;
    QUAN_CHECK(unsigned_char_unsigned_int_value);

    typedef quan::meta::arithmetic_promote<unsigned char, long>::type unsigned_char_long_promotion;
    bool unsigned_char_long_value = std::is_same<unsigned_char_long_promotion, long>::value;
    QUAN_CHECK(unsigned_char_long_value);

    typedef quan::meta::arithmetic_promote<unsigned char, unsigned long>::type unsigned_char_unsigned_long_promotion;
    bool unsigned_char_unsigned_long_value = std::is_same<unsigned_char_unsigned_long_promotion, unsigned long>::value;
    QUAN_CHECK(unsigned_char_unsigned_long_value);

    typedef quan::meta::arithmetic_promote<unsigned char, float>::type unsigned_char_float_promotion;
    bool unsigned_char_float_value = std::is_same<unsigned_char_float_promotion, float>::value;
    QUAN_CHECK(unsigned_char_float_value);

    typedef quan::meta::arithmetic_promote<unsigned char, double>::type unsigned_char_double_promotion;
    bool unsigned_char_double_value = std::is_same<unsigned_char_double_promotion, double>::value;
    QUAN_CHECK(unsigned_char_double_value);

    typedef quan::meta::arithmetic_promote<unsigned char, long double>::type unsigned_char_long_double_promotion;
    bool unsigned_char_long_double_value = std::is_same<unsigned_char_long_double_promotion, long double>::value;
    QUAN_CHECK(unsigned_char_long_double_value);

    typedef quan::meta::arithmetic_promote<char, bool>::type char_bool_promotion;
    bool char_bool_value = std::is_same<char_bool_promotion, int>::value;
    QUAN_CHECK(char_bool_value);

    typedef quan::meta::arithmetic_promote<char, signed char>::type char_signed_char_promotion;
    bool char_signed_char_value = std::is_same<char_signed_char_promotion, int>::value;
    QUAN_CHECK(char_signed_char_value);

    typedef quan::meta::arithmetic_promote<char, unsigned char>::type char_unsigned_char_promotion;
    bool char_unsigned_char_value = std::is_same<char_unsigned_char_promotion, int>::value;
    QUAN_CHECK(char_unsigned_char_value);

    typedef quan::meta::arithmetic_promote<char, char>::type char_char_promotion;
    bool char_char_value = std::is_same<char_char_promotion, int>::value;
    QUAN_CHECK(char_char_value);

#ifndef BOOST_NO_INTRINSIC_WCHAR_T
    typedef quan::meta::arithmetic_promote<char, wchar_t>::type char_wchar_t_promotion;
    bool char_wchar_t_value = std::is_same<char_wchar_t_promotion, underlying_wchar_t>::value;
    QUAN_CHECK(char_wchar_t_value);
#endif

    typedef quan::meta::arithmetic_promote<char, short>::type char_short_promotion;
    bool char_short_value = std::is_same<char_short_promotion, int>::value;
    QUAN_CHECK(char_short_value);

    typedef quan::meta::arithmetic_promote<char, unsigned short>::type char_unsigned_short_promotion;
    bool char_unsigned_short_value = std::is_same<char_unsigned_short_promotion, int>::value;
    QUAN_CHECK(char_unsigned_short_value);

    typedef quan::meta::arithmetic_promote<char, int>::type char_int_promotion;
    bool char_int_value = std::is_same<char_int_promotion, int>::value;
    QUAN_CHECK(char_int_value);

    typedef quan::meta::arithmetic_promote<char, unsigned int>::type char_unsigned_int_promotion;
    bool char_unsigned_int_value = std::is_same<char_unsigned_int_promotion, unsigned int>::value;
    QUAN_CHECK(char_unsigned_int_value);

    typedef quan::meta::arithmetic_promote<char, long>::type char_long_promotion;
    bool char_long_value = std::is_same<char_long_promotion, long>::value;
    QUAN_CHECK(char_long_value);

    typedef quan::meta::arithmetic_promote<char, unsigned long>::type char_unsigned_long_promotion;
    bool char_unsigned_long_value = std::is_same<char_unsigned_long_promotion, unsigned long>::value;
    QUAN_CHECK(char_unsigned_long_value);

    typedef quan::meta::arithmetic_promote<char, float>::type char_float_promotion;
    bool char_float_value = std::is_same<char_float_promotion, float>::value;
    QUAN_CHECK(char_float_value);

    typedef quan::meta::arithmetic_promote<char, double>::type char_double_promotion;
    bool char_double_value = std::is_same<char_double_promotion, double>::value;
    QUAN_CHECK(char_double_value);

    typedef quan::meta::arithmetic_promote<char, long double>::type char_long_double_promotion;
    bool char_long_double_value = std::is_same<char_long_double_promotion, long double>::value;
    QUAN_CHECK(char_long_double_value);


    typedef quan::meta::arithmetic_promote<wchar_t, bool>::type wchar_t_bool_promotion;
    bool wchar_t_bool_value = std::is_same<wchar_t_bool_promotion, underlying_wchar_t>::value;
    QUAN_CHECK(wchar_t_bool_value);

    typedef quan::meta::arithmetic_promote<wchar_t, signed char>::type wchar_t_signed_char_promotion;
    bool wchar_t_signed_char_value = std::is_same<wchar_t_signed_char_promotion, underlying_wchar_t>::value;
    QUAN_CHECK(wchar_t_signed_char_value);

    typedef quan::meta::arithmetic_promote<wchar_t, unsigned char>::type wchar_t_unsigned_char_promotion;
    bool wchar_t_unsigned_char_value = std::is_same<wchar_t_unsigned_char_promotion,underlying_wchar_t>::value;
    QUAN_CHECK(wchar_t_unsigned_char_value);

    typedef quan::meta::arithmetic_promote<wchar_t, char>::type wchar_t_char_promotion;
    bool wchar_t_char_value = std::is_same<wchar_t_char_promotion,underlying_wchar_t>::value;
    QUAN_CHECK(wchar_t_char_value);

    typedef quan::meta::arithmetic_promote<wchar_t, wchar_t>::type wchar_t_wchar_t_promotion;
    bool wchar_t_wchar_t_value = std::is_same<wchar_t_wchar_t_promotion, underlying_wchar_t>::value;
    QUAN_CHECK(wchar_t_wchar_t_value);

    typedef quan::meta::arithmetic_promote<wchar_t, short>::type wchar_t_short_promotion;
    bool wchar_t_short_value = std::is_same<wchar_t_short_promotion,underlying_wchar_t>::value;
    QUAN_CHECK(wchar_t_short_value);

    typedef quan::meta::arithmetic_promote<wchar_t, unsigned short>::type wchar_t_unsigned_short_promotion;
    bool wchar_t_unsigned_short_value = std::is_same<wchar_t_unsigned_short_promotion, underlying_wchar_t>::value;
    QUAN_CHECK(wchar_t_unsigned_short_value);

    typedef quan::meta::arithmetic_promote<wchar_t, int>::type wchar_t_int_promotion;
    bool wchar_t_int_value = std::is_same<wchar_t_int_promotion, underlying_wchar_t>::value;
    QUAN_CHECK(wchar_t_int_value);

// will fail if wchar_t is a long and long not sizeof uint
    typedef quan::meta::arithmetic_promote<wchar_t, unsigned int>::type wchar_t_unsigned_int_promotion;
    bool wchar_t_unsigned_int_value = std::is_same<wchar_t_unsigned_int_promotion, unsigned int>::value;
    QUAN_CHECK(wchar_t_unsigned_int_value);

    typedef quan::meta::arithmetic_promote<wchar_t, long>::type wchar_t_long_promotion;
    bool wchar_t_long_value = std::is_same<wchar_t_long_promotion, unsigned long>::value;
    QUAN_CHECK(wchar_t_long_value);

    typedef quan::meta::arithmetic_promote<wchar_t, unsigned long>::type wchar_t_unsigned_long_promotion;
    bool wchar_t_unsigned_long_value = std::is_same<wchar_t_unsigned_long_promotion, unsigned long>::value;
    QUAN_CHECK(wchar_t_unsigned_long_value);

    typedef quan::meta::arithmetic_promote<wchar_t, float>::type wchar_t_float_promotion;
    bool wchar_t_float_value = std::is_same<wchar_t_float_promotion, float>::value;
    QUAN_CHECK(wchar_t_float_value);

    typedef quan::meta::arithmetic_promote<wchar_t, double>::type wchar_t_double_promotion;
    bool wchar_t_double_value = std::is_same<wchar_t_double_promotion, double>::value;
    QUAN_CHECK(wchar_t_double_value);

    typedef quan::meta::arithmetic_promote<wchar_t, long double>::type wchar_t_long_double_promotion;
    bool wchar_t_long_double_value = std::is_same<wchar_t_long_double_promotion, long double>::value;
    QUAN_CHECK(wchar_t_long_double_value);

    typedef quan::meta::arithmetic_promote<short, bool>::type short_bool_promotion;
    bool short_bool_value = std::is_same<short_bool_promotion, int>::value;
    QUAN_CHECK(short_bool_value);

    typedef quan::meta::arithmetic_promote<short, signed char>::type short_signed_char_promotion;
    bool short_signed_char_value = std::is_same<short_signed_char_promotion, int>::value;
    QUAN_CHECK(short_signed_char_value);

    typedef quan::meta::arithmetic_promote<short, unsigned char>::type short_unsigned_char_promotion;
    bool short_unsigned_char_value = std::is_same<short_unsigned_char_promotion, int>::value;
    QUAN_CHECK(short_unsigned_char_value);

    typedef quan::meta::arithmetic_promote<short, char>::type short_char_promotion;
    bool short_char_value = std::is_same<short_char_promotion, int>::value;
    QUAN_CHECK(short_char_value);

    typedef quan::meta::arithmetic_promote<short, wchar_t>::type short_wchar_t_promotion;
    bool short_wchar_t_value = std::is_same<short_wchar_t_promotion, underlying_wchar_t>::value;
    QUAN_CHECK(short_wchar_t_value);

    typedef quan::meta::arithmetic_promote<short, short>::type short_short_promotion;
    bool short_short_value = std::is_same<short_short_promotion, int>::value;
    QUAN_CHECK(short_short_value);

    typedef quan::meta::arithmetic_promote<short, unsigned short>::type short_unsigned_short_promotion;
    bool short_unsigned_short_value = std::is_same<short_unsigned_short_promotion, int>::value;
    QUAN_CHECK(short_unsigned_short_value);

    typedef quan::meta::arithmetic_promote<short, int>::type short_int_promotion;
    bool short_int_value = std::is_same<short_int_promotion, int>::value;
    QUAN_CHECK(short_int_value);

    typedef quan::meta::arithmetic_promote<short, unsigned int>::type short_unsigned_int_promotion;
    bool short_unsigned_int_value = std::is_same<short_unsigned_int_promotion, unsigned int>::value;
    QUAN_CHECK(short_unsigned_int_value);

    typedef quan::meta::arithmetic_promote<short, long>::type short_long_promotion;
    bool short_long_value = std::is_same<short_long_promotion, long>::value;
    QUAN_CHECK(short_long_value);

    typedef quan::meta::arithmetic_promote<short, unsigned long>::type short_unsigned_long_promotion;
    bool short_unsigned_long_value = std::is_same<short_unsigned_long_promotion, unsigned long>::value;
    QUAN_CHECK(short_unsigned_long_value);

    typedef quan::meta::arithmetic_promote<short, float>::type short_float_promotion;
    bool short_float_value = std::is_same<short_float_promotion, float>::value;
    QUAN_CHECK(short_float_value);

    typedef quan::meta::arithmetic_promote<short, double>::type short_double_promotion;
    bool short_double_value = std::is_same<short_double_promotion, double>::value;
    QUAN_CHECK(short_double_value);

    typedef quan::meta::arithmetic_promote<short, long double>::type short_long_double_promotion;
    bool short_long_double_value = std::is_same<short_long_double_promotion, long double>::value;
    QUAN_CHECK(short_long_double_value);

    typedef quan::meta::arithmetic_promote<unsigned short, bool>::type unsigned_short_bool_promotion;
    bool unsigned_short_bool_value = std::is_same<unsigned_short_bool_promotion, int>::value;
    QUAN_CHECK(unsigned_short_bool_value);

    typedef quan::meta::arithmetic_promote<unsigned short, signed char>::type unsigned_short_signed_char_promotion;
    bool unsigned_short_signed_char_value = std::is_same<unsigned_short_signed_char_promotion, int>::value;
    QUAN_CHECK(unsigned_short_signed_char_value);

    typedef quan::meta::arithmetic_promote<unsigned short, unsigned char>::type unsigned_short_unsigned_char_promotion;
    bool unsigned_short_unsigned_char_value = std::is_same<unsigned_short_unsigned_char_promotion, int>::value;
    QUAN_CHECK(unsigned_short_unsigned_char_value);

    typedef quan::meta::arithmetic_promote<unsigned short, char>::type unsigned_short_char_promotion;
    bool unsigned_short_char_value = std::is_same<unsigned_short_char_promotion, int>::value;
    QUAN_CHECK(unsigned_short_char_value);

    typedef quan::meta::arithmetic_promote<unsigned short, wchar_t>::type unsigned_short_wchar_t_promotion;
    bool unsigned_short_wchar_t_value = std::is_same<unsigned_short_wchar_t_promotion, underlying_wchar_t>::value;
    QUAN_CHECK(unsigned_short_wchar_t_value);

    typedef quan::meta::arithmetic_promote<unsigned short, short>::type unsigned_short_short_promotion;
    bool unsigned_short_short_value = std::is_same<unsigned_short_short_promotion, int>::value;
    QUAN_CHECK(unsigned_short_short_value);

    typedef quan::meta::arithmetic_promote<unsigned short, unsigned short>::type unsigned_short_unsigned_short_promotion;
    bool unsigned_short_unsigned_short_value = std::is_same<unsigned_short_unsigned_short_promotion, int>::value;
    QUAN_CHECK(unsigned_short_unsigned_short_value);

    typedef quan::meta::arithmetic_promote<unsigned short, int>::type unsigned_short_int_promotion;
    bool unsigned_short_int_value = std::is_same<unsigned_short_int_promotion, int>::value;
    QUAN_CHECK(unsigned_short_int_value);

    typedef quan::meta::arithmetic_promote<unsigned short, unsigned int>::type unsigned_short_unsigned_int_promotion;
    bool unsigned_short_unsigned_int_value = std::is_same<unsigned_short_unsigned_int_promotion, unsigned>::value;
    QUAN_CHECK(unsigned_short_unsigned_int_value);

    typedef quan::meta::arithmetic_promote<unsigned short, long>::type unsigned_short_long_promotion;
    bool unsigned_short_long_value = std::is_same<unsigned_short_long_promotion, long>::value;
    QUAN_CHECK(unsigned_short_long_value);

    typedef quan::meta::arithmetic_promote<unsigned short, unsigned long>::type unsigned_short_unsigned_long_promotion;
    bool unsigned_short_unsigned_long_value = std::is_same<unsigned_short_unsigned_long_promotion, unsigned long>::value;
    QUAN_CHECK(unsigned_short_unsigned_long_value);

    typedef quan::meta::arithmetic_promote<unsigned short, float>::type unsigned_short_float_promotion;
    bool unsigned_short_float_value = std::is_same<unsigned_short_float_promotion, float>::value;
    QUAN_CHECK(unsigned_short_float_value);

    typedef quan::meta::arithmetic_promote<unsigned short, double>::type unsigned_short_double_promotion;
    bool unsigned_short_double_value = std::is_same<unsigned_short_double_promotion, double>::value;
    QUAN_CHECK(unsigned_short_double_value);

    typedef quan::meta::arithmetic_promote<unsigned short, long double>::type unsigned_short_long_double_promotion;
    bool unsigned_short_long_double_value = std::is_same<unsigned_short_long_double_promotion, long double>::value;
    QUAN_CHECK(unsigned_short_long_double_value);

    typedef quan::meta::arithmetic_promote<int, bool>::type int_bool_promotion;
    bool int_bool_value = std::is_same<int_bool_promotion, int>::value;
    QUAN_CHECK(int_bool_value);

    typedef quan::meta::arithmetic_promote<int, signed char>::type int_signed_char_promotion;
    bool int_signed_char_value = std::is_same<int_signed_char_promotion, int>::value;
    QUAN_CHECK(int_signed_char_value);

    typedef quan::meta::arithmetic_promote<int, unsigned char>::type int_unsigned_char_promotion;
    bool int_unsigned_char_value = std::is_same<int_unsigned_char_promotion, int>::value;
    QUAN_CHECK(int_unsigned_char_value);

    typedef quan::meta::arithmetic_promote<int, char>::type int_char_promotion;
    bool int_char_value = std::is_same<int_char_promotion, int>::value;
    QUAN_CHECK(int_char_value);

    typedef quan::meta::arithmetic_promote<int, wchar_t>::type int_wchar_t_promotion;
    bool int_wchar_t_value = std::is_same<int_wchar_t_promotion, underlying_wchar_t>::value;
    QUAN_CHECK(int_wchar_t_value);

    typedef quan::meta::arithmetic_promote<int, short>::type int_short_promotion;
    bool int_short_value = std::is_same<int_short_promotion, int>::value;
    QUAN_CHECK(int_short_value);

    typedef quan::meta::arithmetic_promote<int, unsigned short>::type int_unsigned_short_promotion;
    bool int_unsigned_short_value = std::is_same<int_unsigned_short_promotion, int>::value;
    QUAN_CHECK(int_unsigned_short_value);

    typedef quan::meta::arithmetic_promote<int, int>::type int_int_promotion;
    bool int_int_value = std::is_same<int_int_promotion, int>::value;
    QUAN_CHECK(int_int_value);

    typedef quan::meta::arithmetic_promote<int, unsigned int>::type int_unsigned_int_promotion;
    bool int_unsigned_int_value = std::is_same<int_unsigned_int_promotion, unsigned int>::value;
    QUAN_CHECK(int_unsigned_int_value);

    typedef quan::meta::arithmetic_promote<int, long>::type int_long_promotion;
    bool int_long_value = std::is_same<int_long_promotion, long>::value;
    QUAN_CHECK(int_long_value);

    typedef quan::meta::arithmetic_promote<int, unsigned long>::type int_unsigned_long_promotion;
    bool int_unsigned_long_value = std::is_same<int_unsigned_long_promotion, unsigned long>::value;
    QUAN_CHECK(int_unsigned_long_value);

    typedef quan::meta::arithmetic_promote<int, float>::type int_float_promotion;
    bool int_float_value = std::is_same<int_float_promotion, float>::value;
    QUAN_CHECK(int_float_value);

    typedef quan::meta::arithmetic_promote<int, double>::type int_double_promotion;
    bool int_double_value = std::is_same<int_double_promotion, double>::value;
    QUAN_CHECK(int_double_value);

    typedef quan::meta::arithmetic_promote<int, long double>::type int_long_double_promotion;
    bool int_long_double_value = std::is_same<int_long_double_promotion, long double>::value;
    QUAN_CHECK(int_long_double_value);

    typedef quan::meta::arithmetic_promote<unsigned int, bool>::type unsigned_int_bool_promotion;
    bool unsigned_int_bool_value = std::is_same<unsigned_int_bool_promotion, unsigned int>::value;
    QUAN_CHECK(unsigned_int_bool_value);

    typedef quan::meta::arithmetic_promote<unsigned int, signed char>::type unsigned_int_signed_char_promotion;
    bool unsigned_int_signed_char_value = std::is_same<unsigned_int_signed_char_promotion, unsigned int>::value;
    QUAN_CHECK(unsigned_int_signed_char_value);

    typedef quan::meta::arithmetic_promote<unsigned int, unsigned char>::type unsigned_int_unsigned_char_promotion;
    bool unsigned_int_unsigned_char_value = std::is_same<unsigned_int_unsigned_char_promotion, unsigned int>::value;
    QUAN_CHECK(unsigned_int_unsigned_char_value);

    typedef quan::meta::arithmetic_promote<unsigned int, char>::type unsigned_int_char_promotion;
    bool unsigned_int_char_value = std::is_same<unsigned_int_char_promotion, unsigned int>::value;
    QUAN_CHECK(unsigned_int_char_value);

    typedef quan::meta::arithmetic_promote<unsigned int, wchar_t>::type unsigned_int_wchar_t_promotion;
    bool unsigned_int_wchar_t_value = std::is_same<unsigned_int_wchar_t_promotion, unsigned int>::value;
    QUAN_CHECK(unsigned_int_wchar_t_value);

// may fail
    typedef quan::meta::arithmetic_promote<unsigned int, short>::type unsigned_int_short_promotion;
    bool unsigned_int_short_value = std::is_same<unsigned_int_short_promotion, unsigned int>::value;
    QUAN_CHECK(unsigned_int_short_value);

    typedef quan::meta::arithmetic_promote<unsigned int, unsigned short>::type unsigned_int_unsigned_short_promotion;
    bool unsigned_int_unsigned_short_value = std::is_same<unsigned_int_unsigned_short_promotion, unsigned int>::value;
    QUAN_CHECK(unsigned_int_unsigned_short_value);

    typedef quan::meta::arithmetic_promote<unsigned int, int>::type unsigned_int_int_promotion;
    bool unsigned_int_int_value = std::is_same<unsigned_int_int_promotion, unsigned int>::value;
    QUAN_CHECK(unsigned_int_int_value);

    typedef quan::meta::arithmetic_promote<unsigned int, unsigned int>::type unsigned_int_unsigned_int_promotion;
    bool unsigned_int_unsigned_int_value = std::is_same<unsigned_int_unsigned_int_promotion, unsigned int>::value;
    QUAN_CHECK(unsigned_int_unsigned_int_value);

    typedef quan::meta::arithmetic_promote<unsigned int, long>::type unsigned_int_long_promotion;
    bool unsigned_int_long_value = std::is_same<unsigned_int_long_promotion, unsigned long>::value;
    QUAN_CHECK(unsigned_int_long_value);

    typedef quan::meta::arithmetic_promote<unsigned int, unsigned long>::type unsigned_int_unsigned_long_promotion;
    bool unsigned_int_unsigned_long_value = std::is_same<unsigned_int_unsigned_long_promotion, unsigned long>::value;
    QUAN_CHECK(unsigned_int_unsigned_long_value);

    typedef quan::meta::arithmetic_promote<unsigned int, float>::type unsigned_int_float_promotion;
    bool unsigned_int_float_value = std::is_same<unsigned_int_float_promotion, float>::value;
    QUAN_CHECK(unsigned_int_float_value);

    typedef quan::meta::arithmetic_promote<unsigned int, double>::type unsigned_int_double_promotion;
    bool unsigned_int_double_value = std::is_same<unsigned_int_double_promotion, double>::value;
    QUAN_CHECK(unsigned_int_double_value);

    typedef quan::meta::arithmetic_promote<unsigned int, long double>::type unsigned_int_long_double_promotion;
    bool unsigned_int_long_double_value = std::is_same<unsigned_int_long_double_promotion, long double>::value;
    QUAN_CHECK(unsigned_int_long_double_value);

    typedef quan::meta::arithmetic_promote<long, bool>::type long_bool_promotion;
    bool long_bool_value = std::is_same<long_bool_promotion, long>::value;
    QUAN_CHECK(long_bool_value);

    typedef quan::meta::arithmetic_promote<long, signed char>::type long_signed_char_promotion;
    bool long_signed_char_value = std::is_same<long_signed_char_promotion, long>::value;
    QUAN_CHECK(long_signed_char_value);

    typedef quan::meta::arithmetic_promote<long, unsigned char>::type long_unsigned_char_promotion;
    bool long_unsigned_char_value = std::is_same<long_unsigned_char_promotion, long>::value;
    QUAN_CHECK(long_unsigned_char_value);

    typedef quan::meta::arithmetic_promote<long, char>::type long_char_promotion;
    bool long_char_value = std::is_same<long_char_promotion, long>::value;
    QUAN_CHECK(long_char_value);

    typedef quan::meta::arithmetic_promote<long, wchar_t>::type long_wchar_t_promotion;
    bool long_wchar_t_value = std::is_same<long_wchar_t_promotion, unsigned long>::value;
    QUAN_CHECK(long_wchar_t_value);

    typedef quan::meta::arithmetic_promote<long, short>::type long_short_promotion;
    bool long_short_value = std::is_same<long_short_promotion, long>::value;
    QUAN_CHECK(long_short_value);

    typedef quan::meta::arithmetic_promote<long, unsigned short>::type long_unsigned_short_promotion;
    bool long_unsigned_short_value = std::is_same<long_unsigned_short_promotion, long>::value;
    QUAN_CHECK(long_unsigned_short_value);

    typedef quan::meta::arithmetic_promote<long, int>::type long_int_promotion;
    bool long_int_value = std::is_same<long_int_promotion, long>::value;
    QUAN_CHECK(long_int_value);

    typedef quan::meta::arithmetic_promote<long, unsigned int>::type long_unsigned_int_promotion;
    bool long_unsigned_int_value = std::is_same<long_unsigned_int_promotion, unsigned long>::value;
    QUAN_CHECK(long_unsigned_int_value);

    typedef quan::meta::arithmetic_promote<long, long>::type long_long_promotion;
    bool long_long_value = std::is_same<long_long_promotion, long>::value;
    QUAN_CHECK(long_long_value);

    typedef quan::meta::arithmetic_promote<long, unsigned long>::type long_unsigned_long_promotion;
    bool long_unsigned_long_value = std::is_same<long_unsigned_long_promotion, unsigned long>::value;
    QUAN_CHECK(long_unsigned_long_value);

    typedef quan::meta::arithmetic_promote<long, float>::type long_float_promotion;
    bool long_float_value = std::is_same<long_float_promotion, float>::value;
    QUAN_CHECK(long_float_value);

    typedef quan::meta::arithmetic_promote<long, double>::type long_double_promotion;
    bool long_double_value = std::is_same<long_double_promotion, double>::value;
    QUAN_CHECK(long_double_value);

    typedef quan::meta::arithmetic_promote<long, long double>::type long_long_double_promotion;
    bool long_long_double_value = std::is_same<long_long_double_promotion, long double>::value;
    QUAN_CHECK(long_long_double_value);

    typedef quan::meta::arithmetic_promote<unsigned long, bool>::type unsigned_long_bool_promotion;
    bool unsigned_long_bool_value = std::is_same<unsigned_long_bool_promotion, unsigned long>::value;
    QUAN_CHECK(unsigned_long_bool_value);

    typedef quan::meta::arithmetic_promote<unsigned long, signed char>::type unsigned_long_signed_char_promotion;
    bool unsigned_long_signed_char_value = std::is_same<unsigned_long_signed_char_promotion, unsigned long>::value;
    QUAN_CHECK(unsigned_long_signed_char_value);

    typedef quan::meta::arithmetic_promote<unsigned long, unsigned char>::type unsigned_long_unsigned_char_promotion;
    bool unsigned_long_unsigned_char_value = std::is_same<unsigned_long_unsigned_char_promotion, unsigned long>::value;
    QUAN_CHECK(unsigned_long_unsigned_char_value);

    typedef quan::meta::arithmetic_promote<unsigned long, char>::type unsigned_long_char_promotion;
    bool unsigned_long_char_value = std::is_same<unsigned_long_char_promotion, unsigned long>::value;
    QUAN_CHECK(unsigned_long_char_value);

    typedef quan::meta::arithmetic_promote<unsigned long, wchar_t>::type unsigned_long_wchar_t_promotion;
    bool unsigned_long_wchar_t_value = std::is_same<unsigned_long_wchar_t_promotion, unsigned long>::value;
    QUAN_CHECK(unsigned_long_wchar_t_value);

    typedef quan::meta::arithmetic_promote<unsigned long, short>::type unsigned_long_short_promotion;
    bool unsigned_long_short_value = std::is_same<unsigned_long_short_promotion, unsigned long>::value;
    QUAN_CHECK(unsigned_long_short_value);

    typedef quan::meta::arithmetic_promote<unsigned long, unsigned short>::type unsigned_long_unsigned_short_promotion;
    bool unsigned_long_unsigned_short_value = std::is_same<unsigned_long_unsigned_short_promotion, unsigned long>::value;
    QUAN_CHECK(unsigned_long_unsigned_short_value);

    typedef quan::meta::arithmetic_promote<unsigned long, int>::type unsigned_long_int_promotion;
    bool unsigned_long_int_value = std::is_same<unsigned_long_int_promotion, unsigned long>::value;
    QUAN_CHECK(unsigned_long_int_value);

    typedef quan::meta::arithmetic_promote<unsigned long, unsigned int>::type unsigned_long_unsigned_int_promotion;
    bool unsigned_long_unsigned_int_value = std::is_same<unsigned_long_unsigned_int_promotion, unsigned long>::value;
    QUAN_CHECK(unsigned_long_unsigned_int_value);

    typedef quan::meta::arithmetic_promote<unsigned long, long>::type unsigned_long_long_promotion;
    bool unsigned_long_long_value = std::is_same<unsigned_long_long_promotion, unsigned long>::value;
    QUAN_CHECK(unsigned_long_long_value);

    typedef quan::meta::arithmetic_promote<unsigned long, unsigned long>::type unsigned_long_unsigned_long_promotion;
    bool unsigned_long_unsigned_long_value = std::is_same<unsigned_long_unsigned_long_promotion, unsigned long>::value;
    QUAN_CHECK(unsigned_long_unsigned_long_value);

    typedef quan::meta::arithmetic_promote<unsigned long, float>::type unsigned_long_float_promotion;
    bool unsigned_long_float_value = std::is_same<unsigned_long_float_promotion, float>::value;
    QUAN_CHECK(unsigned_long_float_value);

    typedef quan::meta::arithmetic_promote<unsigned long, double>::type unsigned_long_double_promotion;
    bool unsigned_long_double_value = std::is_same<unsigned_long_double_promotion, double>::value;
    QUAN_CHECK(unsigned_long_double_value);

    typedef quan::meta::arithmetic_promote<unsigned long, long double>::type unsigned_long_long_double_promotion;
    bool unsigned_long_long_double_value = std::is_same<unsigned_long_long_double_promotion, long double>::value;
    QUAN_CHECK(unsigned_long_long_double_value);

    typedef quan::meta::arithmetic_promote<float, bool>::type float_bool_promotion;
    bool float_bool_value = std::is_same<float_bool_promotion, float>::value;
    QUAN_CHECK(float_bool_value);

    typedef quan::meta::arithmetic_promote<float, signed char>::type float_signed_char_promotion;
    bool float_signed_char_value = std::is_same<float_signed_char_promotion, float>::value;
    QUAN_CHECK(float_signed_char_value);

    typedef quan::meta::arithmetic_promote<float, unsigned char>::type float_unsigned_char_promotion;
    bool float_unsigned_char_value = std::is_same<float_unsigned_char_promotion, float>::value;
    QUAN_CHECK(float_unsigned_char_value);

    typedef quan::meta::arithmetic_promote<float, char>::type float_char_promotion;
    bool float_char_value = std::is_same<float_char_promotion, float>::value;
    QUAN_CHECK(float_char_value);

    typedef quan::meta::arithmetic_promote<float, wchar_t>::type float_wchar_t_promotion;
    bool float_wchar_t_value = std::is_same<float_wchar_t_promotion, float>::value;
    QUAN_CHECK(float_wchar_t_value);

    typedef quan::meta::arithmetic_promote<float, short>::type float_short_promotion;
    bool float_short_value = std::is_same<float_short_promotion, float>::value;
    QUAN_CHECK(float_short_value);

    typedef quan::meta::arithmetic_promote<float, unsigned short>::type float_unsigned_short_promotion;
    bool float_unsigned_short_value = std::is_same<float_unsigned_short_promotion, float>::value;
    QUAN_CHECK(float_unsigned_short_value);

    typedef quan::meta::arithmetic_promote<float, int>::type float_int_promotion;
    bool float_int_value = std::is_same<float_int_promotion, float>::value;
    QUAN_CHECK(float_int_value);

    typedef quan::meta::arithmetic_promote<float, unsigned int>::type float_unsigned_int_promotion;
    bool float_unsigned_int_value = std::is_same<float_unsigned_int_promotion, float>::value;
    QUAN_CHECK(float_unsigned_int_value);

    typedef quan::meta::arithmetic_promote<float, long>::type float_long_promotion;
    bool float_long_value = std::is_same<float_long_promotion, float>::value;
    QUAN_CHECK(float_long_value);

    typedef quan::meta::arithmetic_promote<float, unsigned long>::type float_unsigned_long_promotion;
    bool float_unsigned_long_value = std::is_same<float_unsigned_long_promotion, float>::value;
    QUAN_CHECK(float_unsigned_long_value);

    typedef quan::meta::arithmetic_promote<float, float>::type float_float_promotion;
    bool float_float_value = std::is_same<float_float_promotion, float>::value;
    QUAN_CHECK(float_float_value);

    typedef quan::meta::arithmetic_promote<float, double>::type float_double_promotion;
    bool float_double_value = std::is_same<float_double_promotion, double>::value;
    QUAN_CHECK(float_double_value);

    typedef quan::meta::arithmetic_promote<float, long double>::type float_long_double_promotion;
    bool float_long_double_value = std::is_same<float_long_double_promotion, long double>::value;
    QUAN_CHECK(float_long_double_value);

    typedef quan::meta::arithmetic_promote<double, bool>::type double_bool_promotion;
    bool double_bool_value = std::is_same<double_bool_promotion, double>::value;
    QUAN_CHECK(double_bool_value);

    typedef quan::meta::arithmetic_promote<double, signed char>::type double_signed_char_promotion;
    bool double_signed_char_value = std::is_same<double_signed_char_promotion, double>::value;
    QUAN_CHECK(double_signed_char_value);

    typedef quan::meta::arithmetic_promote<double, unsigned char>::type double_unsigned_char_promotion;
    bool double_unsigned_char_value = std::is_same<double_unsigned_char_promotion, double>::value;
    QUAN_CHECK(double_unsigned_char_value);

    typedef quan::meta::arithmetic_promote<double, char>::type double_char_promotion;
    bool double_char_value = std::is_same<double_char_promotion, double>::value;
    QUAN_CHECK(double_char_value);

    typedef quan::meta::arithmetic_promote<double, wchar_t>::type double_wchar_t_promotion;
    bool double_wchar_t_value = std::is_same<double_wchar_t_promotion, double>::value;
    QUAN_CHECK(double_wchar_t_value);

    typedef quan::meta::arithmetic_promote<double, short>::type double_short_promotion;
    bool double_short_value = std::is_same<double_short_promotion, double>::value;
    QUAN_CHECK(double_short_value);

    typedef quan::meta::arithmetic_promote<double, unsigned short>::type double_unsigned_short_promotion;
    bool double_unsigned_short_value = std::is_same<double_unsigned_short_promotion, double>::value;
    QUAN_CHECK(double_unsigned_short_value);

    typedef quan::meta::arithmetic_promote<double, int>::type double_int_promotion;
    bool double_int_value = std::is_same<double_int_promotion, double>::value;
    QUAN_CHECK(double_int_value);

    typedef quan::meta::arithmetic_promote<double, unsigned int>::type double_unsigned_int_promotion;
    bool double_unsigned_int_value = std::is_same<double_unsigned_int_promotion, double>::value;
    QUAN_CHECK(double_unsigned_int_value);

    typedef quan::meta::arithmetic_promote<double, long>::type double_long_promotion;
    bool double_long_value = std::is_same<double_long_promotion, double>::value;
    QUAN_CHECK(double_long_value);

    typedef quan::meta::arithmetic_promote<double, unsigned long>::type double_unsigned_long_promotion;
    bool double_unsigned_long_value = std::is_same<double_unsigned_long_promotion, double>::value;
    QUAN_CHECK(double_unsigned_long_value);

    typedef quan::meta::arithmetic_promote<double, float>::type double_float_promotion;
    bool double_float_value = std::is_same<double_float_promotion, double>::value;
    QUAN_CHECK(double_float_value);

    typedef quan::meta::arithmetic_promote<double, double>::type double_double_promotion;
    bool double_double_value = std::is_same<double_double_promotion, double>::value;
    QUAN_CHECK(double_double_value);

    typedef quan::meta::arithmetic_promote<double, long double>::type double_long_double_promotion;
    bool double_long_double_value = std::is_same<double_long_double_promotion, long double>::value;
    QUAN_CHECK(double_long_double_value);

    typedef quan::meta::arithmetic_promote<long double, bool>::type long_double_bool_promotion;
    bool long_double_bool_value = std::is_same<long_double_bool_promotion, long double>::value;
    QUAN_CHECK(long_double_bool_value);

    typedef quan::meta::arithmetic_promote<long double, signed char>::type long_double_signed_char_promotion;
    bool long_double_signed_char_value = std::is_same<long_double_signed_char_promotion, long double>::value;
    QUAN_CHECK(long_double_signed_char_value);

    typedef quan::meta::arithmetic_promote<long double, unsigned char>::type long_double_unsigned_char_promotion;
    bool long_double_unsigned_char_value = std::is_same<long_double_unsigned_char_promotion, long double>::value;
    QUAN_CHECK(long_double_unsigned_char_value);

    typedef quan::meta::arithmetic_promote<long double, char>::type long_double_char_promotion;
    bool long_double_char_value = std::is_same<long_double_char_promotion, long double>::value;
    QUAN_CHECK(long_double_char_value);

    typedef quan::meta::arithmetic_promote<long double, wchar_t>::type long_double_wchar_t_promotion;
    bool long_double_wchar_t_value = std::is_same<long_double_wchar_t_promotion, long double>::value;
    QUAN_CHECK(long_double_wchar_t_value);


    typedef quan::meta::arithmetic_promote<long double, short>::type long_double_short_promotion;
    bool long_double_short_value = std::is_same<long_double_short_promotion, long double>::value;
    QUAN_CHECK(long_double_short_value);

    typedef quan::meta::arithmetic_promote<long double, unsigned short>::type long_double_unsigned_short_promotion;
    bool long_double_unsigned_short_value = std::is_same<long_double_unsigned_short_promotion, long double>::value;
    QUAN_CHECK(long_double_unsigned_short_value);

    typedef quan::meta::arithmetic_promote<long double, int>::type long_double_int_promotion;
    bool long_double_int_value = std::is_same<long_double_int_promotion, long double>::value;
    QUAN_CHECK(long_double_int_value);

    typedef quan::meta::arithmetic_promote<long double, unsigned int>::type long_double_unsigned_int_promotion;
    bool long_double_unsigned_int_value = std::is_same<long_double_unsigned_int_promotion, long double>::value;
    QUAN_CHECK(long_double_unsigned_int_value);

    typedef quan::meta::arithmetic_promote<long double, long>::type long_double_long_promotion;
    bool long_double_long_value = std::is_same<long_double_long_promotion, long double>::value;
    QUAN_CHECK(long_double_long_value);

    typedef quan::meta::arithmetic_promote<long double, unsigned long>::type long_double_unsigned_long_promotion;
    bool long_double_unsigned_long_value = std::is_same<long_double_unsigned_long_promotion, long double>::value;
    QUAN_CHECK(long_double_unsigned_long_value);

    typedef quan::meta::arithmetic_promote<long double, float>::type long_double_float_promotion;
    bool long_double_float_value = std::is_same<long_double_float_promotion, long double>::value;
    QUAN_CHECK(long_double_float_value);

    typedef quan::meta::arithmetic_promote<long double, double>::type long_double_double_promotion;
    bool long_double_double_value = std::is_same<long_double_double_promotion, long double>::value;
    QUAN_CHECK(long_double_double_value);

    typedef quan::meta::arithmetic_promote<long double, long double>::type long_double_long_double_promotion;
    bool long_double_long_double_value = std::is_same<long_double_long_double_promotion, long double>::value;
    QUAN_CHECK(long_double_long_double_value);

}


