#ifndef QUAN_TWO_D_VECT_HPP_INCLUDED
#define QUAN_TWO_D_VECT_HPP_INCLUDED
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

/*
    2d vect fun definition and ops
*/
#include <quan/config.hpp>
#include <quan/two_d/vect_def.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/meta/is_valid_binary_op.hpp>
#include <quan/angle.hpp>
#include <quan/meta/is_scalar.hpp>
#include <quan/meta/is_vector.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/meta/get_num_elements.hpp>
#include <quan/meta/int32.hpp>
#include <cmath>

namespace quan{namespace meta{

    template <typename T1>
    struct is_vector<quan::two_d::vect<T1> > : quan::meta::true_{}; 

    namespace impl{

        template <typename T1>
        struct get_num_elements_impl<quan::two_d::vect<T1> > : quan::meta::int32<2>{};
    

       template <typename T1, typename T2>
       struct binary_op_impl<
           quan::two_d::vect<T1>,plus, quan::two_d::vect<T2>,
           typename quan::where_<
               is_valid_binary_op<T1,plus,T2>
           >::type
       >
       {
           typedef quan::two_d::vect<
               typename quan::meta::binary_op<
                   T1,plus, T2
               >::type
           > type;
       };

       template <typename T1, typename T2>
       struct binary_op_impl<
           quan::two_d::vect<T1>, minus, quan::two_d::vect<T2>,
           typename quan::where_<
               is_valid_binary_op<T1,minus,T2>
           >::type
       >
       {
           typedef quan::two_d::vect<
               typename quan::meta::binary_op<
                   T1,minus, T2
               >::type
           > type;
       };

       template <typename T1, typename T2>
       struct binary_op_impl<
           quan::two_d::vect<T1>, times, T2,
           typename quan::where_<
               quan::meta::and_<
                  is_valid_binary_op<T1,times,T2>,
                  is_scalar<T2>
               >
           >::type
       >
       {
           typedef quan::two_d::vect<
               typename quan::meta::binary_op<
                   T1,times, T2
               >::type
           > type;
       };

       template <typename T1, typename T2>
       struct binary_op_impl<
           T1, times, quan::two_d::vect<T2>,
           typename quan::where_<
               quan::meta::and_<
                  is_valid_binary_op<T1,times,T2>,
                  is_scalar<T1>
               >
           >::type
       >
       {
           typedef quan::two_d::vect<
               typename quan::meta::binary_op<
                   T1,times, T2
               >::type
           > type;
       };

       template <typename T1, typename T2>
       struct binary_op_impl<
           quan::two_d::vect<T1>, divides, T2,
           typename quan::where_<
               is_valid_binary_op<T1,divides,T2>
           >::type
       >
       {
           typedef quan::two_d::vect<
               typename quan::meta::binary_op<
                   T1,divides, T2
               >::type
           > type;
       };

       template <typename T1, typename Op, typename T2>
       struct binary_op_impl<
         quan::two_d::vect<T1>, Op, quan::two_d::vect<T2>,
         typename quan::where_<
            quan::meta::and_<
               quan::meta::is_equality_operator<Op>
               ,quan::meta::is_valid_binary_op<T1,Op,T2>
            >
         >::type
       >
       {
          typedef bool type;
       };

   } //impl
}}//quan::meta


namespace quan{ namespace two_d{

   template <typename TL, typename TR>
   inline
   constexpr bool operator ==(
      quan::two_d::vect<TL> const & lhs,
      quan::two_d::vect<TR> const & rhs
   )
   {
      return (lhs.x == rhs.x) && (lhs.y == rhs.y) ;
   }

   template <typename TL, typename TR>
   inline
   constexpr bool operator !=(
      quan::two_d::vect<TL> const & lhs,
      quan::two_d::vect<TR> const & rhs
   )
   {
      return (lhs.x != rhs.x) || (lhs.y != rhs.y);
   }

    template <typename TL, typename TR>
    inline
    constexpr quan::two_d::vect <
        typename quan::meta::binary_op<
            TL,quan::meta::plus,TR
        >::type
    >
    operator +( quan::two_d::vect<TL> const & lhs, quan::two_d::vect<TR> const & rhs)
    {
        typedef typename quan::two_d::vect<
            typename quan::meta::binary_op<
                TL,quan::meta::plus,TR
            >::type
        > result_type;
        return result_type{lhs.x + rhs.x, lhs.y + rhs.y};
    }

    template <typename TL, typename TR>
    inline
    constexpr quan::two_d::vect <
         typename quan::meta::binary_op<
            TL,quan::meta::minus,TR
        >::type
    >
    operator -( quan::two_d::vect<TL> const & lhs, quan::two_d::vect<TR> const & rhs)
    {
        typedef typename quan::two_d::vect<
            typename quan::meta::binary_op<
                TL,quan::meta::minus,TR
            >::type
        > result_type;
      return result_type{lhs.x - rhs.x, lhs.y - rhs.y};
    }

    template <typename TL, typename TR>
    inline constexpr 
    typename quan::where_<
      quan::meta::is_scalar<TR>,
      quan::two_d::vect <
          typename quan::meta::binary_op<
               TL,quan::meta::times,TR
         >::type
      >
    >::type
    operator  *( quan::two_d::vect<TL> const & lhs, TR const & rhs)
    {
       return  typename quan::meta::binary_op<
            quan::two_d::vect<TL> ,
            quan::meta::times,
            TR
        >::type (lhs.x * rhs, lhs.y * rhs);
    }

    template <typename TL, typename TR>
    inline constexpr 
    typename quan::where_<
      quan::meta::is_scalar<TL>,
      quan::two_d::vect <
            typename quan::meta::binary_op<
               TL,quan::meta::times,TR
         >::type
      >
    >::type
    operator *( TL const & lhs, quan::two_d::vect<TR> const & rhs)
    {
        return typename quan::meta::binary_op<
            quan::two_d::vect<TL> ,
            quan::meta::times,
            TR
        >::type (lhs * rhs.x, lhs * rhs.y);
    }


    template <typename TL, typename TR>
    inline constexpr 
    quan::two_d::vect <
         typename quan::meta::binary_op<
            TL,quan::meta::divides,TR
        >::type
    >
    operator  /( quan::two_d::vect<TL> const & lhs, TR const & rhs)
    {
     
        return  typename quan::meta::binary_op<
            quan::two_d::vect<TL> ,
            quan::meta::divides,
            TR
        >::type (lhs.x / rhs, lhs.y / rhs);

    }

    template <typename Value_type>
    inline constexpr 
    quan::two_d::vect<Value_type>
    abs( quan::two_d::vect<Value_type> const & v)
    {
        return{abs(v.x),abs(v.y)};
    }

    template <typename Value_type>
    inline constexpr
    typename quan::meta::binary_op<
        Value_type,
        quan::meta::times,
        Value_type
    >::type
    norm( quan::two_d::vect<Value_type> const & v)
    {
       return v.x * v.x + v.y * v.y;
    }

   template <typename Value_type>
   inline constexpr
   Value_type
   magnitude( vect<Value_type> const & v)
   {
      return sqrt(norm(v));
   }

   template <typename TL, typename TR>
   inline constexpr
   typename quan::meta::binary_op<
      TL, quan::meta::times,TR
   >::type
   dot_product(
      vect<TL> const & lhs,
      vect<TR> const & rhs
   ){
      return lhs.x * rhs.x + lhs.y * rhs.y;
   }

   template <typename TL, typename TR>
   inline constexpr 
   typename quan::meta::binary_op<
      TL, quan::meta::times,TR
   >::type
   cross_product(
      vect<TL> const & lhs,
      vect<TR> const & rhs
   ){
      return lhs.x*rhs.y - lhs.y * rhs.x;
   }

   template <typename T>
   inline constexpr
   vect<T>
   perp_vector(vect<T> const & in)
   {
      return vect<T>(-in.y,in.x);
   }

   template <typename T>
   inline 
   vect<T> rotate( vect<T> const & in , quan::angle::rad const & theta)
   {
      return  in * cos(theta) + perp_vector(in) * sin(theta);
   }

   template <typename T>
   inline constexpr
   vect<
      typename quan::meta::binary_op<
         T,quan::meta::divides,T
      >::type
   >
   unit_vector(vect<T> const & in)
   {
      return in / magnitude(in);
   }

   inline 
   vect<double>
   unit_vector(quan::angle::rad angle_in)
   {
      return vect<double>(quan::cos(angle_in),quan::sin(angle_in));
   }

/*
    multiply x and y parts of each vector together independently
    equivalent to matrix multiply
    where lhs -> mM_lhs ->
         [ lhs.x, 0 |
         | 0, lhs.y ]
    rhs -> M_rhs ->
         [ rhs.x |
         | rhs.y ]

    so Mresult ->
          [  lhs.x * rhs.x |
          |  lhs.y * rhs.y]

    so result = [ lhs.x * rhs.x , lhs.y * rhs.y]
*/

   template < typename TL, typename TR>
   inline constexpr auto independent_product(
      quan::two_d::vect<TL> const & lhs, quan::two_d::vect<TR> const & rhs) 
   -> quan::two_d::vect<decltype(TL{} * TR{})>
   {
      return  { lhs.x * rhs.x,lhs.y * rhs.y};
   }

}}//quan::two_d

#endif
