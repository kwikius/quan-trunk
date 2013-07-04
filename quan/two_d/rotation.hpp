#ifndef QUAN_TWO_D_ROTATION_HPP_INCLUDED
#define QUAN_TWO_D_ROTATION_HPP_INCLUDED
/*
 Copyright (c) 2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/

/*
   use a class to creat a rotation to apply to a vect. saves some cycles on rotating several points the same angle
*/

#include <quan/angle.hpp>
#include <quan/two_d/vect.hpp>


namespace quan{ namespace two_d{

   struct rotation{
      rotation( quan::angle::rad const & in) : m_cos_theta{quan::cos(in)}, m_sin_theta{quan::sin(in)}{}

      template <typename T>
        typename quan::meta::binary_op<quan::two_d::vect<T>, quan::meta::times, double>::type
         operator() (quan::two_d::vect<T> const & in) const
         {
            return  in * m_cos_theta + perp_vector(in) * m_sin_theta;
         }
      private:

         double const m_cos_theta;
         double const m_sin_theta;
      
   };
}}

#endif // QUAN_TWO_D_ROTATION_HPP_INCLUDED
