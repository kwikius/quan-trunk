#ifndef QUAN_THREE_D_VECT_HPP_INCLUDED1
#define QUAN_THREE_D_VECT_HPP_INCLUDED1
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005

/*
    3d vect definition + operations
*/
#include <quan/meta/binary_op.hpp>
#include <quan/three_d/vect_def.hpp>
#include <quan/where.hpp>
#include <type_traits>
#include <quan/fixed_quantity/operations/power_root.hpp>
#include <quan/meta/is_scalar.hpp>

#include <quan/meta/is_vector.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/meta/get_num_elements.hpp>
#include <quan/meta/int32.hpp>
#include <cmath>

namespace quan{ namespace meta{

    template <typename T1>
    struct is_vector<quan::three_d::vect<T1> > : quan::meta::true_{}; 

    namespace impl{
        template <typename T1>
        struct get_num_elements_impl<quan::three_d::vect<T1> > : quan::meta::int32<3>{};
    }

}}

namespace quan{namespace three_d{

   template <typename TL, typename TR>
   inline 
   bool operator ==( 
      quan::three_d::vect<TL> const & lhs, 
      quan::three_d::vect<TR> const & rhs
   )
   {
      return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z);
   }
   template <typename TL, typename TR>
   inline 
   bool operator !=( 
      quan::three_d::vect<TL> const & lhs, 
      quan::three_d::vect<TR> const & rhs
   )
   {
      return (lhs.x != rhs.x) || (lhs.y != rhs.y) || (lhs.z != rhs.z);
   }
    
    template <typename TL, typename TR>
    inline
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
        quan::three_d::vect<
            typename quan::meta::binary_op< 
                TL,
                quan::meta::plus,
                TR
            >::type
        > result = lhs;
        return (result+= rhs);
    }

    template <typename TL, typename TR>
    inline
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
         quan::three_d::vect<
            typename quan::meta::binary_op< 
                TL,
                quan::meta::minus,
                TR
            >::type
        > result = lhs;
        return (result -= rhs);
    }

    template <typename TL, typename TR>
    inline
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
        return result_type(lhs.x * rhs,lhs.y * rhs,lhs.z * rhs);
    }

   template <typename TL, typename TR>
   inline
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
        return result_type(lhs *rhs.x, lhs * rhs.y,lhs * rhs.z);
    }

    template <typename TL, typename TR>
    inline
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
        return result_type(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);

    }

    template <typename Value_type>
    inline
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
    inline
    Value_type
    magnitude( quan::three_d::vect<Value_type> const & v)
    {
        return quan::pow<1,2>(quan::three_d::norm(v));
    }

    template <typename T1,typename T2>
    inline 
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
    inline
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
   inline
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
   inline
   vect<T>
   perp_vector_axis_x(vect<T> const & in)
   {
      return vect<T>(T(0), -in.z, in.y );
   }

   template <typename T>
   inline
   vect<T>
   perp_vector_axis_y(vect<T> const & in)
   {
      return vect<T>(in.z,T(0),- in.x);
   }

   template <typename T>
   inline
   vect<T>
   perp_vector_axis_z(vect<T> const & in)
   {
      return vect<T>(- in.y, in.x , T(0));
   }

   template <typename T>
   inline
   T
   magnitude_axis_z(vect<T> const & in)
   {
      return sqrt(quan::pow<2>(in.x) + quan::pow<2>(in.y));
   }

   template <typename T>
   inline
   T
   magnitude_axis_x(vect<T> const & in)
   {
      return sqrt(quan::pow<2>(in.y) + quan::pow<2>(in.z));
   }

   template <typename T>
   inline
   T
   magnitude_axis_y(vect<T> const & in)
   {
      return sqrt(quan::pow<2>(in.x) + quan::pow<2>(in.z));
   }

}}//quan::three_d


#endif
