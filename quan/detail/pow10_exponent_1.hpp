#ifndef QUAN_SI_LIBQ_DETAIL_POW10_EXPONENT_HPP_INCLUDED
#define QUAN_SI_LIBQ_DETAIL_POW10_EXPONENT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

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

// See QUAN_ROOT/quan_matters/index.html for documentation.

namespace quan{ namespace si{ namespace libq{ namespace detail{

  template < typename ResultType,int N> struct pow10_pos_integer_fp_exponent;

  template <>
  struct pow10_pos_integer_fp_exponent<float,10 > {
     float operator()()const {return static_cast<float>(1.e10);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,11 > {
     float operator()()const {return static_cast<float>(1.e11);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,12 > {
     float operator()()const {return static_cast<float>(1.e12);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,13 > {
     float operator()()const {return static_cast<float>(1.e13);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,14 > {
     float operator()()const {return static_cast<float>(1.e14);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,15 > {
     float operator()()const {return static_cast<float>(1.e15);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,16 > {
     float operator()()const {return static_cast<float>(1.e16);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,17 > {
     float operator()()const {return static_cast<float>(1.e17);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,18 > {
     float operator()()const {return static_cast<float>(1.e18);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,19 > {
     float operator()()const {return static_cast<float>(1.e19);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,20 > {
     float operator()()const {return static_cast<float>(1.e20);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,21 > {
     float operator()()const {return static_cast<float>(1.e21);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,22 > {
     float operator()()const {return static_cast<float>(1.e22);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,23 > {
     float operator()()const {return static_cast<float>(1.e23);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,24 > {
     float operator()()const {return static_cast<float>(1.e24);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,25 > {
     float operator()()const {return static_cast<float>(1.e25);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,26 > {
     float operator()()const {return static_cast<float>(1.e26);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,27 > {
     float operator()()const {return static_cast<float>(1.e27);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,28 > {
     float operator()()const {return static_cast<float>(1.e28);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,29 > {
     float operator()()const {return static_cast<float>(1.e29);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,30 > {
     float operator()()const {return static_cast<float>(1.e30);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,31 > {
     float operator()()const {return static_cast<float>(1.e31);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,32 > {
     float operator()()const {return static_cast<float>(1.e32);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,33 > {
     float operator()()const {return static_cast<float>(1.e33);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,34 > {
     float operator()()const {return static_cast<float>(1.e34);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,35 > {
     float operator()()const {return static_cast<float>(1.e35);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,36 > {
     float operator()()const {return static_cast<float>(1.e36);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<float,37 > {
     float operator()()const {return static_cast<float>(1.e37);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,10 > {
     double operator()()const {return static_cast<double>(1.e10);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,11 > {
     double operator()()const {return static_cast<double>(1.e11);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,12 > {
     double operator()()const {return static_cast<double>(1.e12);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,13 > {
     double operator()()const {return static_cast<double>(1.e13);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,14 > {
     double operator()()const {return static_cast<double>(1.e14);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,15 > {
     double operator()()const {return static_cast<double>(1.e15);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,16 > {
     double operator()()const {return static_cast<double>(1.e16);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,17 > {
     double operator()()const {return static_cast<double>(1.e17);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,18 > {
     double operator()()const {return static_cast<double>(1.e18);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,19 > {
     double operator()()const {return static_cast<double>(1.e19);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,20 > {
     double operator()()const {return static_cast<double>(1.e20);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,21 > {
     double operator()()const {return static_cast<double>(1.e21);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,22 > {
     double operator()()const {return static_cast<double>(1.e22);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,23 > {
     double operator()()const {return static_cast<double>(1.e23);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,24 > {
     double operator()()const {return static_cast<double>(1.e24);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,25 > {
     double operator()()const {return static_cast<double>(1.e25);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,26 > {
     double operator()()const {return static_cast<double>(1.e26);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,27 > {
     double operator()()const {return static_cast<double>(1.e27);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,28 > {
     double operator()()const {return static_cast<double>(1.e28);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,29 > {
     double operator()()const {return static_cast<double>(1.e29);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,30 > {
     double operator()()const {return static_cast<double>(1.e30);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,31 > {
     double operator()()const {return static_cast<double>(1.e31);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,32 > {
     double operator()()const {return static_cast<double>(1.e32);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,33 > {
     double operator()()const {return static_cast<double>(1.e33);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,34 > {
     double operator()()const {return static_cast<double>(1.e34);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,35 > {
     double operator()()const {return static_cast<double>(1.e35);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,36 > {
     double operator()()const {return static_cast<double>(1.e36);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,37 > {
     double operator()()const {return static_cast<double>(1.e37);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,38 > {
     double operator()()const {return static_cast<double>(1.e38);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,39 > {
     double operator()()const {return static_cast<double>(1.e39);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,40 > {
     double operator()()const {return static_cast<double>(1.e40);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,41 > {
     double operator()()const {return static_cast<double>(1.e41);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,42 > {
     double operator()()const {return static_cast<double>(1.e42);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,43 > {
     double operator()()const {return static_cast<double>(1.e43);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,44 > {
     double operator()()const {return static_cast<double>(1.e44);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,45 > {
     double operator()()const {return static_cast<double>(1.e45);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,46 > {
     double operator()()const {return static_cast<double>(1.e46);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,47 > {
     double operator()()const {return static_cast<double>(1.e47);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,48 > {
     double operator()()const {return static_cast<double>(1.e48);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,49 > {
     double operator()()const {return static_cast<double>(1.e49);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,50 > {
     double operator()()const {return static_cast<double>(1.e50);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,51 > {
     double operator()()const {return static_cast<double>(1.e51);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,52 > {
     double operator()()const {return static_cast<double>(1.e52);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,53 > {
     double operator()()const {return static_cast<double>(1.e53);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,54 > {
     double operator()()const {return static_cast<double>(1.e54);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,55 > {
     double operator()()const {return static_cast<double>(1.e55);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,56 > {
     double operator()()const {return static_cast<double>(1.e56);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,57 > {
     double operator()()const {return static_cast<double>(1.e57);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,58 > {
     double operator()()const {return static_cast<double>(1.e58);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,59 > {
     double operator()()const {return static_cast<double>(1.e59);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,60 > {
     double operator()()const {return static_cast<double>(1.e60);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,61 > {
     double operator()()const {return static_cast<double>(1.e61);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,62 > {
     double operator()()const {return static_cast<double>(1.e62);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,63 > {
     double operator()()const {return static_cast<double>(1.e63);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,64 > {
     double operator()()const {return static_cast<double>(1.e64);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,65 > {
     double operator()()const {return static_cast<double>(1.e65);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,66 > {
     double operator()()const {return static_cast<double>(1.e66);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,67 > {
     double operator()()const {return static_cast<double>(1.e67);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<double,68 > {
     double operator()()const {return static_cast<double>(1.e68);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,10 > {
     long double operator()()const {return static_cast<long double>(1.e10);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,11 > {
     long double operator()()const {return static_cast<long double>(1.e11);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,12 > {
     long double operator()()const {return static_cast<long double>(1.e12);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,13 > {
     long double operator()()const {return static_cast<long double>(1.e13);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,14 > {
     long double operator()()const {return static_cast<long double>(1.e14);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,15 > {
     long double operator()()const {return static_cast<long double>(1.e15);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,16 > {
     long double operator()()const {return static_cast<long double>(1.e16);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,17 > {
     long double operator()()const {return static_cast<long double>(1.e17);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,18 > {
     long double operator()()const {return static_cast<long double>(1.e18);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,19 > {
     long double operator()()const {return static_cast<long double>(1.e19);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,20 > {
     long double operator()()const {return static_cast<long double>(1.e20);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,21 > {
     long double operator()()const {return static_cast<long double>(1.e21);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,22 > {
     long double operator()()const {return static_cast<long double>(1.e22);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,23 > {
     long double operator()()const {return static_cast<long double>(1.e23);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,24 > {
     long double operator()()const {return static_cast<long double>(1.e24);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,25 > {
     long double operator()()const {return static_cast<long double>(1.e25);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,26 > {
     long double operator()()const {return static_cast<long double>(1.e26);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,27 > {
     long double operator()()const {return static_cast<long double>(1.e27);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,28 > {
     long double operator()()const {return static_cast<long double>(1.e28);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,29 > {
     long double operator()()const {return static_cast<long double>(1.e29);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,30 > {
     long double operator()()const {return static_cast<long double>(1.e30);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,31 > {
     long double operator()()const {return static_cast<long double>(1.e31);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,32 > {
     long double operator()()const {return static_cast<long double>(1.e32);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,33 > {
     long double operator()()const {return static_cast<long double>(1.e33);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,34 > {
     long double operator()()const {return static_cast<long double>(1.e34);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,35 > {
     long double operator()()const {return static_cast<long double>(1.e35);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,36 > {
     long double operator()()const {return static_cast<long double>(1.e36);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,37 > {
     long double operator()()const {return static_cast<long double>(1.e37);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,38 > {
     long double operator()()const {return static_cast<long double>(1.e38);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,39 > {
     long double operator()()const {return static_cast<long double>(1.e39);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,40 > {
     long double operator()()const {return static_cast<long double>(1.e40);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,41 > {
     long double operator()()const {return static_cast<long double>(1.e41);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,42 > {
     long double operator()()const {return static_cast<long double>(1.e42);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,43 > {
     long double operator()()const {return static_cast<long double>(1.e43);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,44 > {
     long double operator()()const {return static_cast<long double>(1.e44);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,45 > {
     long double operator()()const {return static_cast<long double>(1.e45);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,46 > {
     long double operator()()const {return static_cast<long double>(1.e46);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,47 > {
     long double operator()()const {return static_cast<long double>(1.e47);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,48 > {
     long double operator()()const {return static_cast<long double>(1.e48);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,49 > {
     long double operator()()const {return static_cast<long double>(1.e49);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,50 > {
     long double operator()()const {return static_cast<long double>(1.e50);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,51 > {
     long double operator()()const {return static_cast<long double>(1.e51);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,52 > {
     long double operator()()const {return static_cast<long double>(1.e52);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,53 > {
     long double operator()()const {return static_cast<long double>(1.e53);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,54 > {
     long double operator()()const {return static_cast<long double>(1.e54);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,55 > {
     long double operator()()const {return static_cast<long double>(1.e55);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,56 > {
     long double operator()()const {return static_cast<long double>(1.e56);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,57 > {
     long double operator()()const {return static_cast<long double>(1.e57);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,58 > {
     long double operator()()const {return static_cast<long double>(1.e58);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,59 > {
     long double operator()()const {return static_cast<long double>(1.e59);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,60 > {
     long double operator()()const {return static_cast<long double>(1.e60);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,61 > {
     long double operator()()const {return static_cast<long double>(1.e61);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,62 > {
     long double operator()()const {return static_cast<long double>(1.e62);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,63 > {
     long double operator()()const {return static_cast<long double>(1.e63);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,64 > {
     long double operator()()const {return static_cast<long double>(1.e64);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,65 > {
     long double operator()()const {return static_cast<long double>(1.e65);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,66 > {
     long double operator()()const {return static_cast<long double>(1.e66);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,67 > {
     long double operator()()const {return static_cast<long double>(1.e67);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,68 > {
     long double operator()()const {return static_cast<long double>(1.e68);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,69 > {
     long double operator()()const {return static_cast<long double>(1.e69);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,70 > {
     long double operator()()const {return static_cast<long double>(1.e70);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,71 > {
     long double operator()()const {return static_cast<long double>(1.e71);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,72 > {
     long double operator()()const {return static_cast<long double>(1.e72);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,73 > {
     long double operator()()const {return static_cast<long double>(1.e73);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,74 > {
     long double operator()()const {return static_cast<long double>(1.e74);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,75 > {
     long double operator()()const {return static_cast<long double>(1.e75);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,76 > {
     long double operator()()const {return static_cast<long double>(1.e76);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,77 > {
     long double operator()()const {return static_cast<long double>(1.e77);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,78 > {
     long double operator()()const {return static_cast<long double>(1.e78);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,79 > {
     long double operator()()const {return static_cast<long double>(1.e79);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,80 > {
     long double operator()()const {return static_cast<long double>(1.e80);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,81 > {
     long double operator()()const {return static_cast<long double>(1.e81);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,82 > {
     long double operator()()const {return static_cast<long double>(1.e82);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,83 > {
     long double operator()()const {return static_cast<long double>(1.e83);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,84 > {
     long double operator()()const {return static_cast<long double>(1.e84);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,85 > {
     long double operator()()const {return static_cast<long double>(1.e85);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,86 > {
     long double operator()()const {return static_cast<long double>(1.e86);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,87 > {
     long double operator()()const {return static_cast<long double>(1.e87);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,88 > {
     long double operator()()const {return static_cast<long double>(1.e88);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,89 > {
     long double operator()()const {return static_cast<long double>(1.e89);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,90 > {
     long double operator()()const {return static_cast<long double>(1.e90);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,91 > {
     long double operator()()const {return static_cast<long double>(1.e91);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,92 > {
     long double operator()()const {return static_cast<long double>(1.e92);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,93 > {
     long double operator()()const {return static_cast<long double>(1.e93);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,94 > {
     long double operator()()const {return static_cast<long double>(1.e94);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,95 > {
     long double operator()()const {return static_cast<long double>(1.e95);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,96 > {
     long double operator()()const {return static_cast<long double>(1.e96);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,97 > {
     long double operator()()const {return static_cast<long double>(1.e97);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,98 > {
     long double operator()()const {return static_cast<long double>(1.e98);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,99 > {
     long double operator()()const {return static_cast<long double>(1.e99);}
  };

  template <>
  struct pow10_pos_integer_fp_exponent<long double,100 > {
     long double operator()()const {return static_cast<long double>(1.e100);}
  };

}}}}//quan::si::libq::detail
#endif

