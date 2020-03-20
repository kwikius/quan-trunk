#ifndef QUAN_THREE_D_QUAT_HPP_INCLUDED
#define QUAN_THREE_D_QUAT_HPP_INCLUDED
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
    quaternion definition + operations
*/

#include <quan/meta/binary_op.hpp>
#include <quan/three_d/quat_def.hpp>
#include <quan/where.hpp>

#include <quan/three_d/vect.hpp>

namespace quan{namespace three_d{


    template <typename TL, typename TR>
    inline
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
        typedef quan::three_d::quat<
            typename quan::meta::binary_op< 
                TL,
                quan::meta::plus,
                TR
            >::type
        > result_type;
        result_type result = lhs;
        result += rhs;
        return result;
    }

    template <typename TL, typename TR>
    inline
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
        typedef quan::three_d::quat<
            typename quan::meta::binary_op< 
                TL,
                quan::meta::minus,
                TR
            >::type
        > result_type;
        result_type result = lhs;
        result -= rhs;
        return result;
    }

// multiplication by scalar
    template <typename TL, typename TR>
    inline
// can be constrained but quan::meta::is_scalar is not in previous release
 //   typename quan::where_<
 //       quan::meta::is_scalar<TR>,
        quan::three_d::quat<
            typename quan::meta::binary_op< 
                TL,
                quan::meta::times,
                TR
            >::type
        >
  //  >::type
    operator *( 
        quan::three_d::quat<TL> const & lhs, 
        TR const & rhs
    ) 
    {
        typedef typename quan::meta::binary_op< 
            TL,
            quan::meta::times,
            TR
        >::type value_type;
        quan::three_d::quat<value_type> result(
            lhs.w * rhs,lhs.x * rhs,lhs.y * rhs, lhs.z * rhs 
        ); 
        return result;
    }

 // multiplication by scalar, reversed order
    template <typename TL, typename TR>
    inline
//    typename quan::where_<
//        quan::meta::is_scalar<TL>,
        quan::three_d::quat<
            typename quan::meta::binary_op< 
                TL,
                quan::meta::times,
                TR
            >::type
        >
 //   >::type
    operator  *( 
        TL const & lhs, 
        quan::three_d::quat<TR> const & rhs
    )
    {
         quan::three_d::quat<
            typename quan::meta::binary_op< 
                TL,
                quan::meta::times,
                TR
            >::type
        > result(lhs *rhs.w, lhs *rhs.x, lhs * rhs.y,lhs * rhs.z); 
       // question: why the implentation differs?
       // Answer: No reason. I should format them all for best legibility
        return result;
    }

 template <typename TL, typename TR>
    inline
    quan::three_d::quat<
        typename quan::meta::binary_op< 
            TL,
            quan::meta::divides,
            TR
        >::type
    > 
    operator  /( quan::three_d::quat<TL> const & lhs, TR const & rhs)
    {
        quan::three_d::quat<
            typename quan::meta::binary_op< 
                TL,
                quan::meta::divides,
                TR
            >::type
        > result(lhs.w / rhs, lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
        return result;
    }

    // might be best to decide if norm is a more appropriate name?
    template <typename ValueType>
    inline
    typename quan::meta::binary_op<
        ValueType,
        quan::meta::times,
        ValueType
    >::type
    squared_magnitude( quan::three_d::quat<ValueType> const & v) 
    {
        typedef typename quan::meta::binary_op<
            ValueType,
            quan::meta::times,
            ValueType
        >::type result_type;
       // result_type result(v.w * v.w + v.x * v.x + v.y * v.y + v.z * v.z);
        result_type result = quan::pow<2>(v.w);
        result += quan::pow<2>(v.x);
        result += quan::pow<2>(v.y);
        result += quan::pow<2>(v.z);
        return result;
    }

    template <typename ValueType>
    inline
    ValueType
    magnitude( quan::three_d::quat<ValueType> const & v)
    {
        ValueType result = sqrt(squared_magnitude(v));
        return result;
    }

    template <typename T1,typename T2>
    inline 
    typename quan::meta::binary_op< 
        T1,
        quan::meta::times,
        T2
    >::type
    dot_product( 
        quan::three_d::quat<T1> const & lhs,
        quan::three_d::quat<T2> const & rhs
    ){
//        typedef typename quan::meta::binary_op< 
//            T1,
//            quan::meta::times,
//            T2
//        >::type result_type;
       //result_type result 
        return  lhs.w * rhs.w + lhs.x * rhs.x + lhs.y * rhs.y  + lhs.z * rhs.z;
//        result_type result = lhs.w * rhs.w;
//        result += lhs.x * rhs.x;
//        result += lhs.y * rhs.y;
//        result += lhs.z * rhs.z;
//        return result;
    }

    // multiplication of quaternion by vector

    // I rearranged the calculation so that the division by norm_carre is only done 3 times
    // using a quan::three_d::rc_matrix to return the result isnt efficient IMO.
  
    template <typename TL, typename TR>
    inline
    // The ValueType of the result (TR) could be
    // promoted to float-type here, which would be useful if TR is an integer
    quan::three_d::vect<TR>
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

//#################################################################

}}//quan::three_d

#endif
