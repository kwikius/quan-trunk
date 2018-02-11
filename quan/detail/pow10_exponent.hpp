#ifndef QUAN_DETAIL_POW10_EXPONENT_HPP_INCLUDED
#define QUAN_DETAIL_POW10_EXPONENT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif


#include <quan/config.hpp>
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

// pow10_integer_exponent
// See QUAN_ROOT/quan_matters/index.html for documentation.

namespace quan{ namespace detail{

  template < typename ResultType,int64_t N> struct pow10_integer_exponent;

  template <>
  struct pow10_integer_exponent<float,0 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e0);}
  };

  template <>
  struct pow10_integer_exponent<float,1 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e1);}
  };

  template <>
  struct pow10_integer_exponent<float,2 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e2);}
  };

  template <>
  struct pow10_integer_exponent<float,3 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e3);}
  };

  template <>
  struct pow10_integer_exponent<float,4 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e4);}
  };

  template <>
  struct pow10_integer_exponent<float,5 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e5);}
  };

  template <>
  struct pow10_integer_exponent<float,6 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e6);}
  };

  template <>
  struct pow10_integer_exponent<float,7 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e7);}
  };

  template <>
  struct pow10_integer_exponent<float,8 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e8);}
  };

  template <>
  struct pow10_integer_exponent<float,9 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e9);}
  };

  template <>
  struct pow10_integer_exponent<float,10 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e10);}
  };

  template <>
  struct pow10_integer_exponent<float,11 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e11);}
  };

  template <>
  struct pow10_integer_exponent<float,12 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e12);}
  };

  template <>
  struct pow10_integer_exponent<float,13 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e13);}
  };

  template <>
  struct pow10_integer_exponent<float,14 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e14);}
  };

  template <>
  struct pow10_integer_exponent<float,15 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e15);}
  };

  template <>
  struct pow10_integer_exponent<float,16 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e16);}
  };

  template <>
  struct pow10_integer_exponent<float,17 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e17);}
  };

  template <>
  struct pow10_integer_exponent<float,18 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e18);}
  };

  template <>
  struct pow10_integer_exponent<float,19 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e19);}
  };

  template <>
  struct pow10_integer_exponent<float,20 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e20);}
  };

  template <>
  struct pow10_integer_exponent<float,21 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e21);}
  };

  template <>
  struct pow10_integer_exponent<float,22 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e22);}
  };

  template <>
  struct pow10_integer_exponent<float,23 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e23);}
  };

  template <>
  struct pow10_integer_exponent<float,24 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e24);}
  };

  template <>
  struct pow10_integer_exponent<float,25 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e25);}
  };

  template <>
  struct pow10_integer_exponent<float,26 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e26);}
  };

  template <>
  struct pow10_integer_exponent<float,27 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e27);}
  };

  template <>
  struct pow10_integer_exponent<float,28 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e28);}
  };

  template <>
  struct pow10_integer_exponent<float,29 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e29);}
  };

  template <>
  struct pow10_integer_exponent<float,30 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e30);}
  };

  template <>
  struct pow10_integer_exponent<float,31 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e31);}
  };

  template <>
  struct pow10_integer_exponent<float,32 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e32);}
  };

  template <>
  struct pow10_integer_exponent<float,33 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e33);}
  };

  template <>
  struct pow10_integer_exponent<float,34 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e34);}
  };

  template <>
  struct pow10_integer_exponent<float,35 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e35);}
  };

  template <>
  struct pow10_integer_exponent<float,36 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e36);}
  };

  template <>
  struct pow10_integer_exponent<float,37 > {
     QUAN_CONSTEXPR float operator()()const {return static_cast<float>(1.e37);}
  };

   template <>
  struct pow10_integer_exponent<double,0 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e0);}
  };

  template <>
  struct pow10_integer_exponent<double,1 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e1);}
  };

  template <>
  struct pow10_integer_exponent<double,2 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e2);}
  };

  template <>
  struct pow10_integer_exponent<double,3 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e3);}
  };

  template <>
  struct pow10_integer_exponent<double,4 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e4);}
  };

  template <>
  struct pow10_integer_exponent<double,5 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e5);}
  };

  template <>
  struct pow10_integer_exponent<double,6 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e6);}
  };

  template <>
  struct pow10_integer_exponent<double,7 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e7);}
  };

  template <>
  struct pow10_integer_exponent<double,8 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e8);}
  };

  template <>
  struct pow10_integer_exponent<double,9 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e9);}
  };

  template <>
  struct pow10_integer_exponent<double,10 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e10);}
  };

  template <>
  struct pow10_integer_exponent<double,11 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e11);}
  };

  template <>
  struct pow10_integer_exponent<double,12 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e12);}
  };

  template <>
  struct pow10_integer_exponent<double,13 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e13);}
  };

  template <>
  struct pow10_integer_exponent<double,14 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e14);}
  };

  template <>
  struct pow10_integer_exponent<double,15 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e15);}
  };

  template <>
  struct pow10_integer_exponent<double,16 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e16);}
  };

  template <>
  struct pow10_integer_exponent<double,17 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e17);}
  };

  template <>
  struct pow10_integer_exponent<double,18 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e18);}
  };

  template <>
  struct pow10_integer_exponent<double,19 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e19);}
  };

  template <>
  struct pow10_integer_exponent<double,20 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e20);}
  };

  template <>
  struct pow10_integer_exponent<double,21 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e21);}
  };

  template <>
  struct pow10_integer_exponent<double,22 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e22);}
  };

  template <>
  struct pow10_integer_exponent<double,23 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e23);}
  };

  template <>
  struct pow10_integer_exponent<double,24 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e24);}
  };

  template <>
  struct pow10_integer_exponent<double,25 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e25);}
  };

  template <>
  struct pow10_integer_exponent<double,26 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e26);}
  };

  template <>
  struct pow10_integer_exponent<double,27 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e27);}
  };

  template <>
  struct pow10_integer_exponent<double,28 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e28);}
  };

  template <>
  struct pow10_integer_exponent<double,29 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e29);}
  };

  template <>
  struct pow10_integer_exponent<double,30 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e30);}
  };

  template <>
  struct pow10_integer_exponent<double,31 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e31);}
  };

  template <>
  struct pow10_integer_exponent<double,32 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e32);}
  };

  template <>
  struct pow10_integer_exponent<double,33 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e33);}
  };

  template <>
  struct pow10_integer_exponent<double,34 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e34);}
  };

  template <>
  struct pow10_integer_exponent<double,35 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e35);}
  };

  template <>
  struct pow10_integer_exponent<double,36 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e36);}
  };

  template <>
  struct pow10_integer_exponent<double,37 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e37);}
  };

  template <>
  struct pow10_integer_exponent<double,38 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e38);}
  };

#if !((defined __AVR__ ) || (defined QUAN_USE_SINGLE_PRECISION_CONSTANTS) )
  template <>
  struct pow10_integer_exponent<double,39 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e39);}
  };

  template <>
  struct pow10_integer_exponent<double,40 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e40);}
  };

  template <>
  struct pow10_integer_exponent<double,41 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e41);}
  };

  template <>
  struct pow10_integer_exponent<double,42 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e42);}
  };

  template <>
  struct pow10_integer_exponent<double,43 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e43);}
  };

  template <>
  struct pow10_integer_exponent<double,44 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e44);}
  };

  template <>
  struct pow10_integer_exponent<double,45 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e45);}
  };

  template <>
  struct pow10_integer_exponent<double,46 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e46);}
  };

  template <>
  struct pow10_integer_exponent<double,47 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e47);}
  };

  template <>
  struct pow10_integer_exponent<double,48 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e48);}
  };

  template <>
  struct pow10_integer_exponent<double,49 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e49);}
  };

  template <>
  struct pow10_integer_exponent<double,50 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e50);}
  };

  template <>
  struct pow10_integer_exponent<double,51 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e51);}
  };

  template <>
  struct pow10_integer_exponent<double,52 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e52);}
  };

  template <>
  struct pow10_integer_exponent<double,53 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e53);}
  };

  template <>
  struct pow10_integer_exponent<double,54 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e54);}
  };

  template <>
  struct pow10_integer_exponent<double,55 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e55);}
  };

  template <>
  struct pow10_integer_exponent<double,56 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e56);}
  };

  template <>
  struct pow10_integer_exponent<double,57 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e57);}
  };

  template <>
  struct pow10_integer_exponent<double,58 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e58);}
  };

  template <>
  struct pow10_integer_exponent<double,59 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e59);}
  };

  template <>
  struct pow10_integer_exponent<double,60 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e60);}
  };

  template <>
  struct pow10_integer_exponent<double,61 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e61);}
  };

  template <>
  struct pow10_integer_exponent<double,62 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e62);}
  };

  template <>
  struct pow10_integer_exponent<double,63 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e63);}
  };

  template <>
  struct pow10_integer_exponent<double,64 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e64);}
  };

  template <>
  struct pow10_integer_exponent<double,65 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e65);}
  };

  template <>
  struct pow10_integer_exponent<double,66 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e66);}
  };

  template <>
  struct pow10_integer_exponent<double,67 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e67);}
  };

  template <>
  struct pow10_integer_exponent<double,68 > {
     QUAN_CONSTEXPR double operator()()const {return static_cast<double>(1.e68);}
  };

  template <>
  struct pow10_integer_exponent<long double,10 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e10);}
  };

  template <>
  struct pow10_integer_exponent<long double,11 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e11);}
  };

  template <>
  struct pow10_integer_exponent<long double,12 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e12);}
  };

  template <>
  struct pow10_integer_exponent<long double,13 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e13);}
  };

  template <>
  struct pow10_integer_exponent<long double,14 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e14);}
  };

  template <>
  struct pow10_integer_exponent<long double,15 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e15);}
  };

  template <>
  struct pow10_integer_exponent<long double,16 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e16);}
  };

  template <>
  struct pow10_integer_exponent<long double,17 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e17);}
  };

  template <>
  struct pow10_integer_exponent<long double,18 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e18);}
  };

  template <>
  struct pow10_integer_exponent<long double,19 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e19);}
  };

  template <>
  struct pow10_integer_exponent<long double,20 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e20);}
  };

  template <>
  struct pow10_integer_exponent<long double,21 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e21);}
  };

  template <>
  struct pow10_integer_exponent<long double,22 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e22);}
  };

  template <>
  struct pow10_integer_exponent<long double,23 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e23);}
  };

  template <>
  struct pow10_integer_exponent<long double,24 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e24);}
  };

  template <>
  struct pow10_integer_exponent<long double,25 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e25);}
  };

  template <>
  struct pow10_integer_exponent<long double,26 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e26);}
  };

  template <>
  struct pow10_integer_exponent<long double,27 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e27);}
  };

  template <>
  struct pow10_integer_exponent<long double,28 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e28);}
  };

  template <>
  struct pow10_integer_exponent<long double,29 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e29);}
  };

  template <>
  struct pow10_integer_exponent<long double,30 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e30);}
  };

  template <>
  struct pow10_integer_exponent<long double,31 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e31);}
  };

  template <>
  struct pow10_integer_exponent<long double,32 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e32);}
  };

  template <>
  struct pow10_integer_exponent<long double,33 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e33);}
  };

  template <>
  struct pow10_integer_exponent<long double,34 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e34);}
  };

  template <>
  struct pow10_integer_exponent<long double,35 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e35);}
  };

  template <>
  struct pow10_integer_exponent<long double,36 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e36);}
  };

  template <>
  struct pow10_integer_exponent<long double,37 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e37);}
  };

  template <>
  struct pow10_integer_exponent<long double,38 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e38);}
  };

  template <>
  struct pow10_integer_exponent<long double,39 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e39);}
  };

  template <>
  struct pow10_integer_exponent<long double,40 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e40);}
  };

  template <>
  struct pow10_integer_exponent<long double,41 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e41);}
  };

  template <>
  struct pow10_integer_exponent<long double,42 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e42);}
  };

  template <>
  struct pow10_integer_exponent<long double,43 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e43);}
  };

  template <>
  struct pow10_integer_exponent<long double,44 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e44);}
  };

  template <>
  struct pow10_integer_exponent<long double,45 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e45);}
  };

  template <>
  struct pow10_integer_exponent<long double,46 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e46);}
  };

  template <>
  struct pow10_integer_exponent<long double,47 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e47);}
  };

  template <>
  struct pow10_integer_exponent<long double,48 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e48);}
  };

  template <>
  struct pow10_integer_exponent<long double,49 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e49);}
  };

  template <>
  struct pow10_integer_exponent<long double,50 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e50);}
  };

  template <>
  struct pow10_integer_exponent<long double,51 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e51);}
  };

  template <>
  struct pow10_integer_exponent<long double,52 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e52);}
  };

  template <>
  struct pow10_integer_exponent<long double,53 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e53);}
  };

  template <>
  struct pow10_integer_exponent<long double,54 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e54);}
  };

  template <>
  struct pow10_integer_exponent<long double,55 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e55);}
  };

  template <>
  struct pow10_integer_exponent<long double,56 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e56);}
  };

  template <>
  struct pow10_integer_exponent<long double,57 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e57);}
  };

  template <>
  struct pow10_integer_exponent<long double,58 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e58);}
  };

  template <>
  struct pow10_integer_exponent<long double,59 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e59);}
  };

  template <>
  struct pow10_integer_exponent<long double,60 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e60);}
  };

  template <>
  struct pow10_integer_exponent<long double,61 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e61);}
  };

  template <>
  struct pow10_integer_exponent<long double,62 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e62);}
  };

  template <>
  struct pow10_integer_exponent<long double,63 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e63);}
  };

  template <>
  struct pow10_integer_exponent<long double,64 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e64);}
  };

  template <>
  struct pow10_integer_exponent<long double,65 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e65);}
  };

  template <>
  struct pow10_integer_exponent<long double,66 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e66);}
  };

  template <>
  struct pow10_integer_exponent<long double,67 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e67);}
  };

  template <>
  struct pow10_integer_exponent<long double,68 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e68);}
  };

  template <>
  struct pow10_integer_exponent<long double,69 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e69);}
  };

  template <>
  struct pow10_integer_exponent<long double,70 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e70);}
  };

  template <>
  struct pow10_integer_exponent<long double,71 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e71);}
  };

  template <>
  struct pow10_integer_exponent<long double,72 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e72);}
  };

  template <>
  struct pow10_integer_exponent<long double,73 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e73);}
  };

  template <>
  struct pow10_integer_exponent<long double,74 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e74);}
  };

  template <>
  struct pow10_integer_exponent<long double,75 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e75);}
  };

  template <>
  struct pow10_integer_exponent<long double,76 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e76);}
  };

  template <>
  struct pow10_integer_exponent<long double,77 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e77);}
  };

  template <>
  struct pow10_integer_exponent<long double,78 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e78);}
  };

  template <>
  struct pow10_integer_exponent<long double,79 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e79);}
  };

  template <>
  struct pow10_integer_exponent<long double,80 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e80);}
  };

  template <>
  struct pow10_integer_exponent<long double,81 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e81);}
  };

  template <>
  struct pow10_integer_exponent<long double,82 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e82);}
  };

  template <>
  struct pow10_integer_exponent<long double,83 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e83);}
  };

  template <>
  struct pow10_integer_exponent<long double,84 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e84);}
  };

  template <>
  struct pow10_integer_exponent<long double,85 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e85);}
  };

  template <>
  struct pow10_integer_exponent<long double,86 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e86);}
  };

  template <>
  struct pow10_integer_exponent<long double,87 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e87);}
  };

  template <>
  struct pow10_integer_exponent<long double,88 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e88);}
  };

  template <>
  struct pow10_integer_exponent<long double,89 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e89);}
  };

  template <>
  struct pow10_integer_exponent<long double,90 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e90);}
  };

  template <>
  struct pow10_integer_exponent<long double,91 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e91);}
  };

  template <>
  struct pow10_integer_exponent<long double,92 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e92);}
  };

  template <>
  struct pow10_integer_exponent<long double,93 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e93);}
  };

  template <>
  struct pow10_integer_exponent<long double,94 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e94);}
  };

  template <>
  struct pow10_integer_exponent<long double,95 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e95);}
  };

  template <>
  struct pow10_integer_exponent<long double,96 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e96);}
  };

  template <>
  struct pow10_integer_exponent<long double,97 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e97);}
  };

  template <>
  struct pow10_integer_exponent<long double,98 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e98);}
  };

  template <>
  struct pow10_integer_exponent<long double,99 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e99);}
  };

  template <>
  struct pow10_integer_exponent<long double,100 > {
     QUAN_CONSTEXPR long double operator()()const {return static_cast<long double>(1.e100);}
  };
#endif // #defined QUAN_AVR_NO_CPP_STDLIB single precision constants

}}//quan::detail

#endif

