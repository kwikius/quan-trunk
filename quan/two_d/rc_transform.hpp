#ifndef QUAN_TWO_D_RC_TRANSFORM_HPP_INCLUDED
#define QUAN_TWO_D_RC_TRANSFORM_HPP_INCLUDED
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
    various transforms designed to be combined in a list
    apply and apply inverse members return a rc_matrix
*/

#include <quan/angle.hpp>
#include <quan/two_d/vect.hpp>
#include <quan/two_d/rc_matrix_operations.hpp>

namespace quan{namespace two_d{

    template<typename T>
    struct rc_identity_matrix{  
            static const rc_matrix<T> value;
    };

//( needs to be moved to source file 
// or make rc_identity_matrix a function)
    template<typename T>
    const rc_matrix<T>  rc_identity_matrix<T>::value(
        1,0, 0/T(1),
        0,1, 0/T(1),
        T(0),T(0),1
    );
    // interface
    template<typename T>
    struct rc_transform{
        typedef T value_type;
        virtual rc_matrix<T> apply()const = 0;
        virtual rc_matrix<T> apply_inverse()const = 0;
        virtual ~rc_transform(){}
    };

    template<typename T,typename AngleType = quan::angle::rad>
    struct rc_rotation : rc_transform<T> {
        rc_rotation() : omega(0){}
        rc_rotation(AngleType const& in): omega (in){}
        AngleType omega;
        rc_matrix<T> apply()const
        {
            using quan::cos;
            using quan::sin;
            rc_matrix<T> ret(
                cos(omega),   sin(omega), 0 / T(1),
                -sin(omega),   cos(omega), 0 / T(1)
            );
            return ret;
        }
        rc_matrix<T> apply_inverse()const
        {
            using quan::cos;
            using quan::sin;
            rc_matrix<T> ret(
                cos(-omega),   sin(-omega), 0 / T(1),
                -sin(-omega),   cos(-omega), 0 / T(1)
            );
            return ret;
        }
    };

    template<typename T>
    struct rc_translation : rc_transform<T> {
        rc_translation () {}
        template <typename T1>
        rc_translation (T1 const & t1) : trans(t1){}
        vect<T> trans;
        template <typename T1>
        rc_translation (T1 const & x, T1 const & y) 
        : trans(x,y){}
        rc_matrix<T> apply()const
        {
            rc_matrix<T> const ret(
                    1,       0,      0 / T(1),
                    0,       1,      0 / T(1),
                    trans.x,       trans.y,      1
            );
            return ret;
        }
        rc_matrix<T> apply_inverse()const
        {
            rc_matrix<T> const ret(
                    1,       0,      0 / T(1),
                    0,       1,      0 / T(1),
                    -trans.x,       -trans.y,      1
            );
            return ret;
        }
    };

    template<typename T>
    struct rc_scaling : rc_transform<T> {
        typedef decltype(T() / T() ) value_type;
        vect<value_type> v;
        rc_scaling (): v(value_type(1),value_type(1)) {}
        //rc_scaling (const rc_scaling& in) : v(in.v){}
         template <typename T1>
        rc_scaling (T1 const & t1 ) : v(t1){}
        template <typename T1, typename T2>
        rc_scaling (T1 const & t1,T2 const& t2 ) : v(vect<value_type>(t1,t2)){}
        
        rc_matrix<T> apply()const
        {
            rc_matrix<T> const ret(
                    v.x,       0,      0 / T(1),
                    0,       v.y,      0 / T(1)
            );
            return ret;
        }
        rc_matrix<T> apply_inverse()const
        {
            rc_matrix<T> const ret(
                    1/v.x,       0,      0 / T(1),
                    0,       1/v.y,      0 / T(1)
            );
            return ret;
        }
    };

}}//quan::two_d

#endif

