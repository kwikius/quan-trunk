#ifndef QUAN_THREE_D_RC_TRANSFORM_HPP_INCLUDED
#define QUAN_THREE_D_RC_TRANSFORM_HPP_INCLUDED
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
//
 
 
 

/*
    various 3d transform functors designed to be combined in a list
*/

#include <quan/angle/angle.hpp>
#include <quan/three_d/vect.hpp>
#include <quan/three_d/rc_matrix_operations.hpp>

namespace quan{namespace three_d{

    template<typename T>
    struct rc_identity_matrix{  
            static const rc_matrix<T> value;
    };

    template<typename T>
    const rc_matrix<T>  rc_identity_matrix<T>::value(
        1,0,0, 0/T(1),
        0,1,0, 0/T(1),
        0,0,1 ,0/T(1),
        T(0),T(0),T(0),1
    );

    template<typename T>
    struct rc_transform{
        typedef T value_type;
        virtual rc_matrix<T> apply()const = 0;
        virtual rc_matrix<T> apply_inverse()const = 0;
        virtual ~rc_transform(){}
    };

    template<typename T,typename AngleType = quan::angle::rad>
    struct rc_x_rotation : rc_transform<T> {
        //rc_x_rotation() : theta(0){}
        rc_x_rotation(AngleType const& in): theta (in){}
        AngleType theta;
        rc_matrix<T> apply()const
        {
            using quan::math::cos;
            using quan::math::sin;
            rc_matrix<T> ret(
             1,             0,              0,          0 / T(1),
             0,     cos(theta),   sin(theta),           0 / T(1),
             0,    -sin(theta),   cos(theta),           0 / T(1),
             T(0),        T(0),         T(0),                  1
            );
            return ret;
        }
        rc_matrix<T> apply_inverse()const
        {
            using quan::math::cos;
            using quan::math::sin;
            rc_matrix<T> ret(
             1,             0,             0,          0 / T(1),
             0,   cos(-theta),   sin(-theta),          0 / T(1),
             0,  -sin(-theta),   cos(-theta),          0 / T(1),
             T(0),       T(0),          T(0),                 1
            );
            return ret;
        }
    };

    template<typename T,typename AngleType = quan::angle::rad>
    struct rc_y_rotation : rc_transform<T> {
        //rc_y_rotation() : theta(0){}
        rc_y_rotation(AngleType const& in): theta (in){}
        AngleType theta;
        rc_matrix<T> apply()const
        {
            using quan::math::cos;
            using quan::math::sin;
            rc_matrix<T> ret(
    
             cos(theta),     0,  sin(theta),        0 / T(1),
             0,              1,           0,        0 / T(1),
             -sin(theta),    0,   cos(theta),       0 / T(1),
             T(0),        T(0),         T(0),               1
            );
            return ret;
        }
        rc_matrix<T> apply_inverse()const
        {
            using quan::math::cos;
            using quan::math::sin;
            rc_matrix<T> ret(
             cos(-theta),     0,  -sin(-theta),        0 / T(1),
             0,               1,             0,        0 / T(1),
             sin(-theta),     0,    cos(-theta),       0 / T(1),
             T(0),        T(0),         T(0),                1
            );
            return ret;
        }
    };

    template<typename T,typename AngleType = quan::angle::rad>
    struct rc_z_rotation : rc_transform<T> {
        //rc_y_rotation() : theta(0){}
        rc_z_rotation(AngleType const& in): theta (in){}
        AngleType theta;
        rc_matrix<T> apply()const
        {
            using quan::math::cos;
            using quan::math::sin;
            rc_matrix<T> ret(
              cos(theta),  sin(theta),     0,     0 / T(1),
             -sin(theta),  cos(theta),     0,     0 / T(1),
                       0,           0,     0,     0 / T(1),
                    T(0),        T(0),  T(0),            1
            );
            return ret;
        }
        rc_matrix<T> apply_inverse()const
        {
            using quan::math::cos;
            using quan::math::sin;
            rc_matrix<T> ret(
              cos(-theta), sin(-theta),    0,     0 / T(1),
             -sin(-theta), cos(-theta),    0,     0 / T(1),
                        0,           0,    0,     0 / T(1),
                     T(0),        T(0), T(0),            1
            );
            return ret;
        }
    };

    template<
        typename T,
        typename AngleType = quan::angle::rad
    >
    struct rc_rotation : rc_transform<T> {
        typedef decltype(T()/T()) value_type;
        //rc_y_rotation() : theta(0){}
        rc_rotation(
            AngleType alpa,
            vect<T> const& direction_in
        ): direction(direction_in),alpha(alph_in){}
            //normalise direction to 1;
              /* direction_cosines =
                    direction_in / magnitude(direction_in)*/
               /*     direction_in
                / quan::sqrt(
                    quan::pow<2>(direction.x) 
                    + quan::pow<2>(direction.y) 
                    + quan::pow<2>(direction.z)
                ); */
        //}
       // vect<value_type> direction_cosines;
        AngleType alpha;
        rc_matrix<T> apply()const
        {
            // rotate xangle around  x axis to y - z plane
            // rotate yangle around  y axis to z axis
            // rotate alpa
            // rotate -yangle around y
            // rotate -xangle around x
           //typedef T value_type;
            value_type cos_beta = quan::sqrt( 
                quan::pow<2>(direction.y) 
                + quan::pow<2>(direction.z)
            );
            value_type cos_alpha = direction.z / cos_beta;
            value_type sin_alpha = direction.y / cos_beta;
            value_type sin_beta  = direction.x;
            rc_matrix<T> Rx(
                1,           0,          0,      0,
                0,    cos_alpa,  sin_alpha,      0,
                0,  -sin_alpha,  cos_alpha,      0,
                0,           0,          0,      1
            );
            rc_matrix<T> Ry(
                cos_beta,     0,  sin_beta,      0,
                       0,     1,         0,      0,
                -sin_beta,    0,  cos_alpha,     0,
                        0,    0,         0,      1
            );
            
            rc_matrix<T> delta = rc_z_rotation(alpha)::apply();
            rc_matrix<T> result = Rx * Ry * delta * inverse_of(Ry) * inverse_of(Rx);
            return result;
        }
       
        rc_matrix<T> apply_inverse()const ;
    };
    
    

    template<typename T>
    struct rc_translation : rc_transform<T> {
        rc_translation () {}
        template <typename T1>
        rc_translation (vect<T1> const & t1) : trans(t1){}
       
        rc_matrix<T> apply()const
        {
            rc_matrix<T> const ret(
                    1,       0,       0,   0 / T(1),
                    0,       1,       0,   0 / T(1),
                    0,       0,       1,   0 / T(1),
              trans.x, trans.y, trans.z,          1
            );
            return ret;
        }
        rc_matrix<T> apply_inverse()const
        {
             rc_matrix<T> const ret(
                    1,         0,        0,   0 / T(1),
                    0,         1,        0,   0 / T(1),
                    0,         0,        1,   0 / T(1),
             -trans.x,  -trans.y, -trans.z,          1
            );
            return ret;
        }
        vect<T> trans;
    };

    template<typename T, typename Value_type = double>
    struct rc_scaling : rc_transform<T> {
       
        template <typename T1>
        rc_scaling (T1 const & t1 ) : v(t1){}       
        rc_matrix<T> apply()const
        {
            rc_matrix<T> const ret(
                    v.x,       0,     0,  0 / T(1),
                    0,       v.y,     0,  0 / T(1),
                    0,         0,     v.z,  0/T(1),
                    T(0),   T(0),     T(0),     1
            );
            return ret;
        }
        rc_matrix<T> apply_inverse()const
        {
           
            rc_matrix<T> const ret(
                    1/v.x,       0,     0,    0 / T(1),
                    0,       1/v.y,     0,     0 / T(1),
                    0,         0,     1/v.z,   0 / T(1),
                    T(0),   T(0),     T(0),       1
            );
            return ret;
        }
        vect<Value_type> v;
    };

}}//quan::three_d

#endif
