#ifndef QUAN_THREE_D_VECT_HPP_INCLUDED1
#define QUAN_THREE_D_VECT_HPP_INCLUDED1
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
    3d vect definition + operations
*/
#include <quan/meta/binary_op.hpp>
#include <quan/three_d/vect_def.hpp>
#include <quan/where.hpp>
//#include <type_traits>
#include <quan/fixed_quantity/operations/power_root.hpp>
#include <quan/meta/is_scalar.hpp>

#include <quan/meta/is_vector.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/meta/get_num_elements.hpp>
#include <quan/meta/int32.hpp>
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <cmath>
#else
#include <math.h>
#endif

namespace quan{ namespace meta{

   template <typename T1>
   struct is_vector<quan::three_d::vect<T1> > : quan::meta::true_{}; 

   namespace impl{

      template <typename T1>
      struct get_num_elements_impl<quan::three_d::vect<T1> > : quan::meta::int32<3>{};
 
      template <typename T1, typename T2>
      struct binary_op_impl<
        quan::three_d::vect<T1>,plus, quan::three_d::vect<T2>,
        typename quan::where_<
            is_valid_binary_op<T1,plus,T2>
        >::type
      >
      {
        typedef quan::three_d::vect<
            typename quan::meta::binary_op<
                T1,plus, T2
            >::type
        > type;
      };

      template <typename T1, typename T2>
      struct binary_op_impl<
        quan::three_d::vect<T1>, minus, quan::three_d::vect<T2>,
        typename quan::where_<
            is_valid_binary_op<T1,minus,T2>
        >::type
      >
      {
        typedef quan::three_d::vect<
            typename quan::meta::binary_op<
                T1,minus, T2
            >::type
        > type;
      };

      template <typename T1, typename T2>
      struct binary_op_impl<
        quan::three_d::vect<T1>, times, T2,
        typename quan::where_<
            quan::meta::and_<
               is_valid_binary_op<T1,times,T2>,
               is_scalar<T2>
            >
        >::type
      >
      {
        typedef quan::three_d::vect<
            typename quan::meta::binary_op<
                T1,times, T2
            >::type
        > type;
      };

      template <typename T1, typename T2>
      struct binary_op_impl<
        T1, times, quan::three_d::vect<T2>,
        typename quan::where_<
            quan::meta::and_<
               is_valid_binary_op<T1,times,T2>,
               is_scalar<T1>
            >
        >::type
      >
      {
        typedef quan::three_d::vect<
            typename quan::meta::binary_op<
                T1,times, T2
            >::type
        > type;
      };

      template <typename T1, typename T2>
      struct binary_op_impl<
        quan::three_d::vect<T1>, divides, T2,
        typename quan::where_<
            is_valid_binary_op<T1,divides,T2>
        >::type
      >
      {
        typedef quan::three_d::vect<
            typename quan::meta::binary_op<
                T1,divides, T2
            >::type
        > type;
      };

       template <typename T1, typename Op, typename T2>
       struct binary_op_impl<
         quan::three_d::vect<T1>, Op, quan::three_d::vect<T2>,
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

}}

namespace quan{namespace three_d{

   template <typename TL, typename TR>
   inline  constexpr
   bool operator ==( 
      quan::three_d::vect<TL> const & lhs, 
      quan::three_d::vect<TR> const & rhs
   )
   {
      return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z);
   }

   template <typename TL, typename TR>
   inline constexpr 
   bool operator !=( 
      quan::three_d::vect<TL> const & lhs, 
      quan::three_d::vect<TR> const & rhs
   )
   {
      return (lhs.x != rhs.x) || (lhs.y != rhs.y) || (lhs.z != rhs.z);
   }
    
    template <typename TL, typename TR>
    inline constexpr
    quan::three_d::vect<
        typename quan::meta::binary_op< 
            TL,
            quan::meta::plus,
            TR
        >::type
    >
    operator +( 
        quan::three_d::vect<TL> const & lhs, 
        quan::three_d::vect<TR> const & rhs
    )
    {
        typedef quan::three_d::vect<
            typename quan::meta::binary_op< 
                TL,
                quan::meta::plus,
                TR
            >::type
        > result_type;
        return result_type{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
    }

    template <typename TL, typename TR>
    inline constexpr
    quan::three_d::vect<
        typename quan::meta::binary_op< 
            TL,
            quan::meta::minus,
            TR
        >::type
    >
    operator -( 
        quan::three_d::vect<TL> const & lhs,
        quan::three_d::vect<TR> const & rhs
    )
    {
        typedef quan::three_d::vect<
            typename quan::meta::binary_op< 
                TL,
                quan::meta::minus,
                TR
            >::type
        > result_type;
        return result_type{lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
    }

    template <typename TL, typename TR>
    inline constexpr 
    typename quan::where_<
      quan::meta::is_scalar<TR>,
      quan::three_d::vect<
         typename quan::meta::binary_op< 
               TL,
               quan::meta::times,
               TR
         >::type
      >
    >::type
    operator *( quan::three_d::vect<TL> const & lhs, TR const & rhs)
    {
        typedef quan::three_d::vect<
            typename quan::meta::binary_op< 
               TL,
               quan::meta::times,
               TR
            >::type 
        > result_type;  
        return result_type{lhs.x * rhs,lhs.y * rhs,lhs.z * rhs};
    }

   template <typename TL, typename TR>
   inline constexpr
   typename quan::where_<
      quan::meta::is_scalar<TL>,
      quan::three_d::vect<
         typename quan::meta::binary_op< 
            TL,
            quan::meta::times,
            TR
         >::type
      >
      >::type
    operator *( TL const & lhs, quan::three_d::vect<TR> const & rhs)
    {
         typedef quan::three_d::vect<
            typename quan::meta::binary_op< 
                TL,
                quan::meta::times,
                TR
            >::type
        > result_type;
        return result_type{lhs * rhs.x, lhs * rhs.y,lhs * rhs.z};
    }

    template <typename TL, typename TR>
    inline constexpr
    quan::three_d::vect<
        typename quan::meta::binary_op< 
            TL,
            quan::meta::divides,
            TR
        >::type
    > 
    operator /( quan::three_d::vect<TL> const & lhs, TR const & rhs)
    {
        typedef quan::three_d::vect<
            typename quan::meta::binary_op< 
                TL,
                quan::meta::divides,
                TR
            >::type
        > result_type;
        return result_type{lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};

    }

    template <typename Value_type>
    inline constexpr
    typename quan::meta::binary_op<
        Value_type,
        quan::meta::times,
        Value_type
    >::type
    norm( quan::three_d::vect<Value_type> const & v)
    {
        return v.x * v.x + v.y * v.y + v.z * v.z;
    }

    template <typename Value_type>
    inline constexpr
    quan::three_d::vect<Value_type>
    abs( quan::three_d::vect<Value_type> const & v)
    {
        return{abs(v.x),abs(v.y),abs(v.z)};
    }

    template <typename Value_type>
    inline constexpr
    Value_type
    magnitude( quan::three_d::vect<Value_type> const & v)
    {
        return sqrt(quan::three_d::norm(v));
    }

    template <typename T1,typename T2>
    inline constexpr
    typename quan::meta::binary_op< 
        T1,
        quan::meta::times,
        T2
    >::type
    dot_product( 
        quan::three_d::vect<T1> const & lhs,
        quan::three_d::vect<T2> const & rhs
    ){
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    template<typename T1, typename T2>
    inline constexpr
    quan::three_d::vect<
        typename quan::meta::binary_op< 
            T1,
            quan::meta::times,
            T2
        >::type
    >
    cross_product(
        quan::three_d::vect<T1> const & lhs,
        quan::three_d::vect<T2> const & rhs
    ){
        typedef quan::three_d::vect<
            typename quan::meta::binary_op< 
                T1,
                quan::meta::times,
                T2
            >::type
        > result_type;
       return result_type (
            lhs.y * rhs.z - lhs.z * rhs.y,
            lhs.z * rhs.x - lhs.x * rhs.z, 
            lhs.x * rhs.y - lhs.y * rhs.x
        );
    }

   template <typename T>
   inline constexpr
   vect<
      typename quan::meta::binary_op<
         T,quan::meta::divides,T
      >::type
   >
   unit_vector(quan::three_d::vect<T> const & in)
   {
      return in / magnitude(in);
   }

   template <typename T>
   inline constexpr
   vect<T>
   perp_vector_axis_x(vect<T> const & in)
   {
      return vect<T>(T(0), -in.z, in.y );
   }

   template <typename T>
   inline constexpr
   vect<T>
   perp_vector_axis_y(vect<T> const & in)
   {
      return vect<T>(in.z,T(0),- in.x);
   }

   template <typename T>
   inline constexpr
   vect<T>
   perp_vector_axis_z(vect<T> const & in)
   {
      return vect<T>(- in.y, in.x , T(0));
   }

   template <typename T>
   inline  constexpr
   T
   magnitude_axis_z(vect<T> const & in)
   {
      return sqrt(quan::pow<2>(in.x) + quan::pow<2>(in.y));
   }

   template <typename T>
   inline  constexpr
   T
   magnitude_axis_x(vect<T> const & in)
   {
      return sqrt(quan::pow<2>(in.y) + quan::pow<2>(in.z));
   }

   template <typename T>
   inline  constexpr
   T
   magnitude_axis_y(vect<T> const & in)
   {
      return sqrt(quan::pow<2>(in.x) + quan::pow<2>(in.z));
   }

}}//quan::three_d


#endif
