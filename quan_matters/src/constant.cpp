// Copyright Andrew Little 2005


#ifndef  QUAN_MATH_CONSTANT_LIB_SRC_CPP_INCLUDED
#define  QUAN_MATH_CONSTANT_LIB_SRC_CPP_INCLUDED

#include <quan/constants/constant.hpp>

#ifndef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
// static members
template<>
long double const   quan::constant_<long double>::pi
//=3.14159265358979323846L;
= 3.141592653589793238462643383279502884197L;
// = static_cast<long double>(M_PI);

template<>
double const  quan::constant_<double>::pi
//=3.14159265358979323846;   // dinkumware
= 3.141592653589793238462643383279502884197;
// = static_cast<double>(M_PI); // nonstandard
template<>
float const  quan::constant_<float>::pi
//=3.14159265358979323846F;
= 3.141592653589793238462643383279502884197F;
// = static_cast<float>(M_PI); //non standard
template<>
long double const   quan::constant_<long double>::e
= 0.5772156649015328606065120900824024310422L;

template<>
double const  quan::constant_<double>::e
= 0.5772156649015328606065120900824024310422;

template<>
float const  quan::constant_<float>::e
= 0.5772156649015328606065120900824024310422F;

template<>
long double const   quan::constant_<long double>::sqrt2
= 1.41421356237309504880168872420969807857L;

template<>
double const  quan::constant_<double>::sqrt2
= 1.41421356237309504880168872420969807857;

template<>
float const  quan::constant_<float>::sqrt2
= 1.41421356237309504880168872420969807857F;
#endif // #ifndef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS

#endif


