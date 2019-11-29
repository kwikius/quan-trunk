#ifndef QUAN_THREE_D_ROTATION_HPP_INCLUDED
#define QUAN_THREE_D_ROTATION_HPP_INCLUDED

#include <quan/angle.hpp>
#include <quan/atan2.hpp>
#include <quan/three_d/vect.hpp>
#include <quan/two_d/vect.hpp>
#include <quan/two_d/rotation.hpp>

#include <cassert>

namespace quan { namespace three_d{

   // rotation around x axis
   struct x_rotation{
      // for simplicity just reuse 2d rotation
      x_rotation( quan::angle::rad const & in) : m_rot2{in}{}

         template <typename T>
         typename quan::meta::binary_op<quan::three_d::vect<T>, quan::meta::times, QUAN_FLOAT_TYPE>::type
         operator() (quan::three_d::vect<T> const & in) const
         {
            quan::two_d::vect<T> const v2_in{in.y,in.z};
            auto const v2_out = m_rot2(v2_in);
            typedef typename quan::meta::binary_op<quan::three_d::vect<T>, quan::meta::times, QUAN_FLOAT_TYPE>::type result_type;
            return result_type{in.x,v2_out.x,v2_out.y}; 
         }

   private:

     quan::two_d::rotation m_rot2;
   };

      // rotation around y axis
   struct y_rotation{
      // for simplicity just reuse 2d rotation
      y_rotation( quan::angle::rad const & in) : m_rot2{in}{}

         template <typename T>
         typename quan::meta::binary_op<quan::three_d::vect<T>, quan::meta::times, QUAN_FLOAT_TYPE>::type
         operator() (quan::three_d::vect<T> const & in) const
         {
            quan::two_d::vect<T> const v2_in{in.x,in.z};
            auto const v2_out = m_rot2(v2_in);
            typedef typename quan::meta::binary_op<quan::three_d::vect<T>, quan::meta::times, QUAN_FLOAT_TYPE>::type result_type;
            return result_type{v2_out.x,in.y,v2_out.y}; 
         }

   private:

     quan::two_d::rotation m_rot2;
   };

         // rotation around y axis
   struct z_rotation{
      // for simplicity just reuse 2d rotation
      z_rotation( quan::angle::rad const & in) : m_rot2{in}{}

         template <typename T>
         typename quan::meta::binary_op<quan::three_d::vect<T>, quan::meta::times, QUAN_FLOAT_TYPE>::type
         operator() (quan::three_d::vect<T> const & in) const
         {
            quan::two_d::vect<T> const v2_in{in.x,in.y};
            auto const v2_out = m_rot2(v2_in);
            typedef typename quan::meta::binary_op<quan::three_d::vect<T>, quan::meta::times, QUAN_FLOAT_TYPE>::type result_type;
            return result_type{v2_out.x,v2_out.y,in.z}; 
         }

   private:

     quan::two_d::rotation m_rot2;
   };
      
}}

#endif // QUAN_THREE_D_ROTATION_HPP_INCLUDED
