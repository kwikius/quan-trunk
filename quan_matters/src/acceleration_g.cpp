// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#ifndef QUAN_FIXED_QUANTITY_ACCELERATION_G_CPP_INCLUDED
#define QUAN_FIXED_QUANTITY_ACCELERATION_G_CPP_INCLUDED

#include <quan/acceleration.hpp>


namespace quan{
// gravitational constant S.I units

   template<>
    acceleration_<float>::m_per_s2 const
   acceleration_<float>::g 
   = acceleration_<float>::m_per_s2(9.80665f);

   template<>
   acceleration_<double>::m_per_s2 const
   acceleration_<double>::g
   = acceleration_<double>::m_per_s2(9.80665);

   template<>
   acceleration_<int>::m_per_s2 const
   acceleration_<int>::g
   = acceleration_<int>::m_per_s2(10);

}


#endif

