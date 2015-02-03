#ifndef QUAN_TWO_D_ARC_HPP_INCLUDED
#define QUAN_TWO_D_ARC_HPP_INCLUDED

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
 
 
 

#include <quan/two_d/vect.hpp>
#include <quan/angle.hpp>
#include <cmath>

namespace quan{namespace two_d{

   template <typename T>
   struct arc{
      arc(
         vect<T> const & center_in,
         quan::angle::rad const & start_angle_in,
         quan::angle::rad const & end_angle_in,
         T const& radius_in        
      )
      :m_center(center_in),
      m_start_angle(start_angle_in),
      m_end_angle(end_angle_in),
      m_radius(radius_in){} 
   
      vect<T> m_center;
      quan::angle::rad m_start_angle;
      quan::angle::rad m_end_angle;
      T m_radius; 
      template <typename List>
      void get_point_list(List & list, T const & granularity)
      {
         T arc_length = this->m_radius * (this->m_end_angle - this->m_start_angle);
         typedef quan::meta::binary_op<T,quan::meta::divides,T> ::type numeric_type;
         //granularity of the points on arc should be > pixel_size If drawing on display
         typename List::size_type n_segs = std::abs(static_cast<int>( arc_length / granularity));
         //check for n_segs < 1
         ////vect<T> last_pt;
         //for ( int i = 0; i <= n_segs; ++i){
         //   quan::angle::rad angle_n = this->m_start_angle 
         //      + ((this->m_end_angle - this->m_start_angle) * i )/n_segs;
         //   vect<numeric_type> unit_v(quan::cos(angle_n),quan::sin(angle_n));
         //   vect<T> pt = this->m_center + unit_v * this->m_radius ;
         //   list.push_back(pt);    
         //}
          get_point_list_n(list, n_segs);
      }

      template <typename List>
      void get_point_list_n(List & list, typename List::size_type n_segs)
      {
         typedef quan::meta::binary_op<T,quan::meta::divides,T> ::type numeric_type;
         for ( typename List::size_type i = 0; i <= n_segs; ++i){
            quan::angle::rad angle_n = this->m_start_angle 
               + ((this->m_end_angle - this->m_start_angle) * i )/n_segs;
            vect<numeric_type> unit_v(quan::cos(angle_n),quan::sin(angle_n));
            vect<T> pt = this->m_center + unit_v * this->m_radius ;
            list.push_back(pt);    
         }
      }
   };
   
}}//quan::two_d

#endif
