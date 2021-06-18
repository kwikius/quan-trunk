#ifndef QUAN_THREE_D_QUAT_HPP_INCLUDED
#define QUAN_THREE_D_QUAT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

/*
  Copyright (c) 2003-2021 Andy Little.
  Copyright Janek Kozicki 2006

  Copyright (C) David Calkin
  https://sourceforge.net/p/flightgear/flightgear/ci/next/tree/examples/netfdm/

  Copyright (C) 2006-2009  Mathias Froehlich - Mathias.Froehlich@web.de
  simgear https://github.com/FlightGear/simgear/math/SGQuat.hxx

  Copyright (C) Jens Wilhelm Wulf
  crrcsim https://sourceforge.net/projects/crrcsim

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
    quaternion definition + operations
*/
#include <quan/where.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/meta/is_scalar.hpp>
#include <quan/three_d/vect.hpp>
#include <quan/three_d/make_vect.hpp>
#include <quan/three_d/quat_def.hpp>
#include <quan/angle.hpp>
#include <cmath>

namespace quan{namespace three_d{

   template <typename TL, typename TR>
   inline constexpr
   quan::three_d::quat<
      typename quan::meta::binary_op< 
         TL,
         quan::meta::plus,
         TR
      >::type
   >
   operator +( 
      quan::three_d::quat<TL> const & lhs, 
      quan::three_d::quat<TR> const & rhs
   )
   {
      return { lhs.w + rhs.w,lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
   }

   template <typename TL, typename TR>
   inline constexpr
   quan::three_d::quat<
      typename quan::meta::binary_op< 
         TL,
         quan::meta::minus,
         TR
      >::type
   >
   operator -( 
      quan::three_d::quat<TL> const & lhs,
      quan::three_d::quat<TR> const & rhs)
   {
      return { lhs.w - rhs.w,lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
   }

   // multiplication by scalar
   template <typename TL, typename TR>
   inline constexpr
   typename quan::where_<
      quan::meta::is_scalar<TR>,
      quan::three_d::quat<
         typename quan::meta::binary_op< 
            TL,
            quan::meta::times,
            TR
         >::type
      >
   >::type
   operator *( 
   quan::three_d::quat<TL> const & lhs, 
   TR const & rhs
   ) 
   {
      return {lhs.w * rhs,lhs.x * rhs,lhs.y * rhs, lhs.z * rhs};
   }

   // multiplication by scalar, reversed order
   template <typename TL, typename TR>
   inline constexpr 
   typename quan::where_<
      quan::meta::is_scalar<TL>,
      quan::three_d::quat<
         typename quan::meta::binary_op< 
            TL,
            quan::meta::times,
            TR
         >::type
      >
   >::type
   operator  *( 
      TL const & lhs, 
      quan::three_d::quat<TR> const & rhs
   )
   {
      return {lhs * rhs.w, lhs * rhs.x, lhs * rhs.y,lhs * rhs.z};
   }

   template <typename TL, typename TR>
   inline constexpr 
   typename quan::where_<
      quan::meta::is_scalar<TR>,
      quan::three_d::quat<
         typename quan::meta::binary_op< 
            TL,
            quan::meta::divides,
            TR
         >::type
      >
   >::type
   operator /( quan::three_d::quat<TL> const & lhs, TR const & rhs)
   {
      return {lhs.w / rhs, lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
   }

   template <typename TL, typename TR>
   inline constexpr 
   bool operator == (quan::three_d::quat<TL> const & lhs, quan::three_d::quat<TR> const & rhs)
   {
      return (lhs.w == rhs.w) &&
            ( lhs.x == rhs.x) &&
            ( lhs.y == rhs.y) &&
            ( lhs.z == rhs.z);
   }

   template <typename TL, typename TR>
   inline constexpr 
   bool operator != (quan::three_d::quat<TL> const & lhs, quan::three_d::quat<TR> const & rhs)
   {
      return (lhs.w != rhs.w) ||
            ( lhs.x != rhs.x) ||
            ( lhs.y != rhs.y) ||
            ( lhs.z != rhs.z);
   }

   template <typename TL, typename TR>
   inline constexpr 
   typename quan::meta::binary_op<
      TL,
      quan::meta::times,
      TR
   >::type
   dot_product(
      quan::three_d::quat<TL> const & lhs, 
      quan::three_d::quat<TR> const & rhs
   )
   {
      return lhs.w * rhs.w + lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
   }

    // might be best to decide if norm is a more appropriate name?
   template <typename ValueType>
   inline constexpr
   typename quan::meta::binary_op<
     ValueType,
     quan::meta::times,
     ValueType
   >::type
   squared_magnitude( quan::three_d::quat<ValueType> const & v) 
   {
      return dot_product(v,v);
   }

   template <typename ValueType>
   inline constexpr 
   ValueType
   magnitude( quan::three_d::quat<ValueType> const & v)
   {
      return sqrt(squared_magnitude(v));
   }

   template <typename T>
   inline constexpr
   quat<
      typename quan::meta::binary_op<
         T,
         quan::meta::divides,
         T
      >::type
   > unit_quat(quat<T> const & q)
   {
      return q / magnitude(q);
   }

   template <typename TL, typename TR>
   inline constexpr
   quat<
      typename quan::meta::binary_op<
         TL,quan::meta::times,TR
      >::type
   >  
   hamilton_product(quat<TL> const & lhs, quat<TR> const & rhs)
   {
      return {
         lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z,
         lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y,
         lhs.w * rhs.y - lhs.x * rhs.z + lhs.y * rhs.w + lhs.z * rhs.x,
         lhs.w * rhs.z + lhs.x * rhs.y - lhs.y * rhs.x + lhs.z * rhs.w
      };
   }

   template <typename T>
   quat<T>  
   inline
   conjugate(quat<T> const & q)
   {
      return { q.w, -q.x,-q.y,-q.z};
   }

   namespace detail{

      template <typename T, typename Float>
      constexpr inline 
      quat<
         typename quan::meta::binary_op<
            T,
            quan::meta::times, 
            Float
         >::type
      >
      ll_quatFrom(quan::three_d::vect<T> const & axis, Float const &sin__angle_div_2, Float const & cos__angle_div_2)
      {
         return {cos__angle_div_2,axis.x * sin__angle_div_2,axis.y * sin__angle_div_2,axis.z * sin__angle_div_2};
      }
      
   } // detail

   template <typename T>
   inline quan::three_d::quat<T> exp(quan::three_d::quat<T> const & q)
   {
      auto const vm = magnitude(quan::three_d::vect<T>{q.x,q.y,q.z});
      if ( vm > 0.0){
         auto const s = sin(vm)/ vm;
         return exp(q.w) * quan::three_d::quat<T>{ cos(vm), s* q.x, s * q.y,s * q.z};
      }else{
         return {exp(q.w),0.0,0.0,0.0};
      }
   }

   /**
      N.B that axis is not made into a unit_vector inside the function
   */
   template <typename T, typename Angle>
   constexpr inline 
     typename quan::where_<
      quan::meta::or_<
         quan::meta::is_angle<Angle>,
         std::is_floating_point<Angle>
      >,
      quat<
         typename quan::meta::binary_op<
            T,
            quan::meta::times, 
            QUAN_FLOAT_TYPE
         >::type
       >
   >::type quatFrom(quan::three_d::vect<T> const & axis, Angle const & angle)
   {
      using std::sin;
      using std::cos;
      return detail::ll_quatFrom<QUAN_FLOAT_TYPE>(axis,sin(angle/static_cast<QUAN_FLOAT_TYPE>(2)),cos(angle/static_cast<QUAN_FLOAT_TYPE>(2)));
   }

    // multiplication of quaternion by vector

    // I rearranged the calculation so that the division by norm_carre is only done 3 times
    // using a quan::three_d::rc_matrix to return the result isnt efficient IMO.
  
    template <typename TL, typename TR>
    inline
    typename quan::where_<
         quan::meta::and_<
            quan::meta::is_scalar<TL>,
            quan::meta::is_scalar<TR>
        >,
       // The ValueType of the result (TR) could be
       // promoted to float-type here, which would be useful if TR is an integer
       quan::three_d::vect<quan::meta::binary_op_t<TL,quan::meta::times,TR> >
    >::type
    operator *( 
        quan::three_d::quat<TL> const & lhs, 
        quan::three_d::vect<TR> const & rhs
    ) 
    {
        typedef typename quan::meta::binary_op< 
            TL,
            quan::meta::times,
            TL
        >::type quat_squared_type;

        // I'm not sure if this actually speeds things up...

        // FWIW I sometimes use a const ref (as below) to make the intent clear
        // but I dont know if that affects things  for good or bad either.
        // My guess is that all three ways produce the same result
        // under most optimisers
	    TL const&   a = lhs.w; 
	    TL const&   b = lhs.x;
	    TL const&   c = lhs.y;
	    TL const&   d = lhs.z;

     //   TL   a = lhs.w; 
	    //TL   b = lhs.x;
	    //TL   c = lhs.y;
	    //TL   d = lhs.z;
    	
	     quat_squared_type    aa = a*a;
        quat_squared_type    bb = b*b;
        quat_squared_type    cc = c*c;
        quat_squared_type    dd = d*d;
        quat_squared_type    norme_carre = aa+bb+cc+dd;

        // throwing here is a good idea
 // to_arithmetic is available in pqs_3_1_0 but isnt included by default
 // so will ignore this for the moment
      /*  quan::meta::to_arithmetic<quat_squared_type> size_check;
        using    ::std::numeric_limits;
        if    (size_check(norme_carre) <= numeric_limits<QUAN_REAL_TYPE>::epsilon()){
            throw ::std::underflow_error("Argument to quat * vect is too small!"); 
        }*/

	    quat_squared_type    ab = a*b;
	    quat_squared_type    ac = a*c;
	    quat_squared_type    ad = a*d;
	    quat_squared_type    bc = b*c;
	    quat_squared_type    bd = b*d;
	    quat_squared_type    cd = c*d;

        typedef  quan::three_d::vect<quat_squared_type> squared_vect;
        squared_vect svx(aa+bb-cc-dd,2*(-ad+bc),2*(ac+bd));
        squared_vect svy(2*(ad+bc),(aa-bb+cc-dd),2*(-ab+cd));
        squared_vect svz(2*(-ac+bd),2*(ab+cd),(aa-bb-cc+dd));

        quan::three_d::vect<TR> result(
            dot_product(svx,rhs)/norme_carre,
            dot_product(svy,rhs)/norme_carre,
            dot_product(svz,rhs)/norme_carre
        );
        return result;

     // Alternatively make a 3x3 matrix from vects.
     //   typedef  quan::three_d::vect<quat_squared_type> squared_vect;
     //   typedef  quan::three_d::vect<squared_vect> matrix;
     //   matrix m (
     //       squared_vect(aa+bb-cc-dd,2*(-ad+bc),2*(ac+bd)),
     //       squared_vect(2*(ad+bc),(aa-bb+cc-dd),2*(-ab+cd)),
     //       squared_vect(2*(-ac+bd),2*(ab+cd),(aa-bb-cc+dd))
     //   );
     //   quan::three_d::vect<TR> result(
     //       dot_product(m.x,rhs)/norme_carre,
     //       dot_product(m.y,rhs)/norme_carre,
     //       dot_product(m.z,rhs)/norme_carre
     //   );
     //   return result;

    }

// Included here is the previous version of quat * vect
// renamed as multiply for comparison of results
//#############################################################

    template <typename TL, typename TR>
    inline
// Note: I changed the result type!!
    quan::three_d::vect<TR>

    multiply( quan::three_d::quat<TL> const & lhs, quan::three_d::vect<TR> const & rhs) 
   // multiplication of quaternion by vector
    {
        typedef typename quan::meta::binary_op< 
            TL,
            quan::meta::times,
            TL
        >::type quat_squared_type;

    
	TL    a = lhs.w; // I'm not sure if this actually speeds things up...
	TL    b = lhs.x;
	TL    c = lhs.y;
	TL    d = lhs.z;
	
	quat_squared_type    aa = a*a;
	quat_squared_type    ab = a*b;
	quat_squared_type    ac = a*c;
	quat_squared_type    ad = a*d;
	quat_squared_type    bb = b*b;
	quat_squared_type    bc = b*c;
	quat_squared_type    bd = b*d;
	quat_squared_type    cc = c*c;
	quat_squared_type    cd = c*d;
	quat_squared_type    dd = d*d;
	quat_squared_type    norme_carre = aa+bb+cc+dd;
	   
   
/* throwing here is a good idea, but perhaps it should be replaced with 
PQS's own mechanism of throwing
 *
        using    ::std::numeric_limits;
        if    (norme_carre <= numeric_limits<TYPE_FLOAT>::epsilon())
        {
            ::std::string            error_reporting("Argument to quaternion_to_R3_rotation is too small!");
            ::std::underflow_error   bad_argument(error_reporting);
            
            throw(bad_argument); 
        }
*/  
   typedef typename quan::meta::binary_op<
            quat_squared_type,
            quan::meta::divides,
            quat_squared_type
    >::type dimless_type;
            
	// NOTE: if quaternion has magnitude=1.0, then following equations can be simplified, which could result in faster calculation
        dimless_type at11 = (aa+bb-cc-dd)/norme_carre; // all dimensios delete themselves here....
        dimless_type at12 = 2*(-ad+bc)/norme_carre;
        dimless_type at13 = 2*(ac+bd)/norme_carre;
        dimless_type at21 = 2*(ad+bc)/norme_carre;
        dimless_type at22 = (aa-bb+cc-dd)/norme_carre;
        dimless_type at23 = 2*(-ab+cd)/norme_carre;
        dimless_type at31 = 2*(-ac+bd)/norme_carre;
        dimless_type at32 = 2*(ab+cd)/norme_carre;
        dimless_type at33 = (aa-bb-cc+dd)/norme_carre;

        /*typedef typename quan::meta::binary_op< 
            TL,
            quan::meta::times,
            TR
        >::type value_type;*/

        //value_type 
        TR
		  x = rhs.x*at11 + rhs.y*at12 + rhs.z*at13 
		, y = rhs.x*at21 + rhs.y*at22 + rhs.z*at23
		, z = rhs.x*at31 + rhs.y*at32 + rhs.z*at33 ;

        quan::three_d::vect<TR> result(x,y,z);
        return result;
    }

   template <typename Tout, typename Angle>
    typename quan::where_<
      quan::meta::and_<
         std::is_arithmetic<Tout>,
         quan::meta::or_<
            quan::meta::is_angle<Angle>,
            std::is_floating_point<Angle>
         >
      >,
      quan::three_d::quat<Tout>
   >::type
   quat_from_euler(quan::three_d::vect<Angle> const & pose)
   {
        /*
            x = roll, y = pitch, z = yaw
        */
      auto const v = 0.5 * pose;
      auto const s = make_vect( sin(v.x),sin(v.y),sin(v.z));
      auto const c = make_vect( cos(v.x),cos(v.y),cos(v.z));

      Tout const cXcZ = c.x * c.z;
      Tout const cXsZ = c.x * s.z;
      Tout const sXsZ = s.x * s.z;
      Tout const sXcZ = s.x * c.z;

      return { 
         cXcZ * c.y + sXsZ * s.y,
         sXcZ * c.y - cXsZ * s.y,
         cXcZ * s.y + sXsZ * c.y,
         cXsZ * c.y - sXcZ * s.y
      };
   }

   template <typename T>
   typename quan::where_<
      std::is_floating_point<T>,
      quan::three_d::vect<quan::angle::rad> 
   >::type
   euler_from_quat(quan::three_d::quat<T> const & q)
   {
      quan::three_d::quat<T> q2 {q.w*q.w,q.x*q.x,q.y * q.y, q.z * q.z};

      T constexpr lim = std::numeric_limits<T>::min();
      quan::three_d::vect<quan::angle::rad> result;
      {
         T const numx = 2.0 * ( q.y * q.z + q.w * q.x);
         T const denx = q2.w - q2.x - q2.y + q2.z;
         if ( (std::abs(denx) <= lim) && (std::abs(numx) <= lim) ){
           result.x = 0.0;
         }else{
           result.x = atan2(numx,denx);
         }
      }
      {
         T const tmp = 2.0 * (q.x * q.z - q.w * q.y);
         if ( tmp <= -1.0 ){
            result.y = quan::constant::pi/2.0;
         }else {
            if ( tmp >= 1.0 ){
               result.y = -quan::constant::pi/2.0;
            }else{
               result.y = -asin(tmp);
            }
         }
      }
      {
         T const numz = 2.0 * (q.x * q.y + q.w * q.z);
         T const denz = q2.w + q2.x - q2.y - q2.z;
         if( (std::abs(denz) <= lim) && (std::abs(numz) <= lim) ){
            result.z = 0;
         }else{
            T psi = atan2(numz, denz);
            if (psi < 0){
               psi += 2.0*quan::constant::pi;
            }
            result.z = psi;
         }
      }
      return result;
   }

//#################################################################

}}//quan::three_d

#endif
