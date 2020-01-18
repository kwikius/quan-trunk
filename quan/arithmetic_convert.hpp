#ifndef QUAN_ARITHMETIC_CONVERT_HPP_INCLUDED
#define QUAN_ARITHMETIC_CONVERT_HPP_INCLUDED

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
#include <quan/config.hpp>
#include <quan/limits.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/signed_unsigned.hpp>
#include <quan/meta/not.hpp>
#include <quan/meta/or.hpp>
#include <quan/implicit_cast.hpp>
#include <quan/meta/identity.hpp>
#include <quan/meta/is_angle.hpp>

#if defined QUAN_AVR_NO_CPP_STDLIB
#include <math.h>
#include <quan/std/tr1/is_unsigned.hpp>
#include <quan/std/tr1/is_arithmetic.hpp>
#include <quan/std/tr1/is_float.hpp>
#include <quan/std/tr1/is_same.hpp>
#include <quan/avr/numeric_limits.hpp>
#undef max
#else
#include <type_traits>
#include <cmath>
#endif
#if defined abs
//#error "abs is a macro"
#undef abs
#endif
#include <quan/meta/max.hpp>

#if !defined QUAN_NO_EXCEPTIONS
#include <stdexcept>
#endif

namespace quan {namespace impl_detail {

   template <typename Target, typename Source, typename Where = void>
   struct range_check_impl;

   template <typename Target, typename Source>
   struct range_check_impl<
      Target,Source,
      typename quan::where_< quan::meta::not_<std::is_unsigned<Source> > >::type
   > {

      QUAN_CONSTEXPR bool operator ()(Source const & s)const
      {
        typedef quan::impl_detail::lowest<Target> lowest_target_type;
        typedef quan::impl_detail::highest<Target> highest_target_type;
        // get promoted type of both
        // 
        return (lowest_target_type{}() <= s ) && (highest_target_type{}() >= s);
      }
   };
 
   template <typename Target, typename Source>
   struct range_check_impl<
      Target,Source,
      typename quan::where_<std::is_unsigned<Source> >::type
   > {

      QUAN_CONSTEXPR bool operator ()(Source const & s)const
      {
         typedef typename quan::meta::eval_if<
            //quan::is_model_of<quan::Signed_,Target>,
            std::is_signed<Target>,
            quan::meta::signed_to_unsigned<Target>,
            quan::meta::identity<Target>
         >::type unsigned_or_float_type;

        // return( static_cast<unsigned_or_float_type>(std::numeric_limits<Target>:: max ()) >= s);
         return  static_cast<unsigned_or_float_type>(quan::meta::max_<Target>::value) >= s;
      }
   };
 
   template <typename Target, typename Source,typename Where =void>
   struct arithmetic_convert_impl;
// not narrowing
 
   template <typename Target, typename Source>
   struct arithmetic_convert_impl<
      Target, Source,
      typename quan::where_<
         quan::meta::and_<
           std::is_arithmetic<Source>,
           std::is_arithmetic<Target>,
           quan::meta::not_<is_narrowing_conversion<Target, Source> >
         >
      >::type
   > {
       QUAN_CONSTEXPR Target operator()(Source const & s) const
       {
           return s;
       }
   };
 
   template <typename Target, typename Source>
   struct arithmetic_convert_impl<
      Target, Source,
      typename quan::where_<
         quan::meta::and_<
            is_narrowing_conversion<Target, Source>,
            quan::meta::and_<
               std::is_floating_point<Source>,
               std::is_integral<Target>
            >
         >
      >::type
   > {   
    Target operator()(Source const & s) const
    {

        if (range_check_impl<Target,Source>{}(s)) {
         int sign_s = ( s >= Source{0} ) ? 1 : -1;
         Source abs_s = (sign_s ==1)?s:-s;
         Source abs_intpart =0;
#ifndef QUAN_AVR_NO_CPP_STDLIB
         Source abs_fract = std::modf(abs_s,&abs_intpart);
#else
         Source abs_fract = ::modf(abs_s,&abs_intpart);
#endif
         if (abs_fract < (Source{1}/2)){
            return static_cast<Target>(s);
         }else {
            if (abs_fract > (Source{1}/2)){
                return static_cast<Target>(s) + sign_s;
            }else{//fraction is 0.5;
                Target abs_res = static_cast<Target>(abs_intpart);
                if( (abs_res & 1 ) == 0) {// even
                   return static_cast<Target>(s);
                }else{
                   return static_cast<Target>(s)  + sign_s;
                }
            }
         }
       }
   
      else {
#ifndef QUAN_NO_EXCEPTIONS
            throw std::out_of_range("conversion out of range");
#else
            typedef quan::impl_detail::lowest<Target> lowest_type;
            typedef quan::impl_detail::highest<Target> highest_type;
            return (s > 0) ? highest_type{}() : lowest_type{}();
#endif
        }
      }
    };
 
    template <typename Target, typename Source>
    struct arithmetic_convert_impl<
            Target, Source,
            typename quan::where_<
            quan::meta::and_<
            is_narrowing_conversion<Target, Source>,
            quan::meta::and_<
            std::is_floating_point<Source>,
            std::is_floating_point<Target>
            >
            >
            >::type
            > {
#ifdef QUAN_NO_EXCEPTIONS
        constexpr
#endif
          Target operator()(Source const & s) const
        {
#ifndef QUAN_NO_EXCEPTIONS
            if (range_check_impl<Target,Source>()(s))
                return static_cast<Target>(s);

            throw std::out_of_range("conversion out of range");
#else
            // saturate
            typedef quan::impl_detail::lowest<Target> lowest_type;
            typedef quan::impl_detail::highest<Target> highest_type;

            return (range_check_impl<Target,Source>()(s))
            ? static_cast<Target>(s)
            : (s > 0.f) ? highest_type{}() : lowest_type{}();
#endif
 
        }
    };
 
    template <typename Target, typename Source>
    struct arithmetic_convert_impl<
            Target, Source,
            typename quan::where_<
            quan::meta::and_<
            is_narrowing_conversion<Target, Source>,
            quan::meta::and_<
            std::is_integral<Source>,
            std::is_integral<Target>
            >
            >
            >::type
            > {
#ifdef QUAN_NO_EXCEPTIONS
        constexpr
#endif
        Target operator()(Source const & s) const
        {

#ifndef QUAN_NO_EXCEPTIONS
            if (range_check_impl<Target,Source>()(s))
                return static_cast<Target>(s);
            throw std::out_of_range("conversion out of range");
#else
            typedef quan::impl_detail::lowest<Target> lowest_type;
            typedef quan::impl_detail::highest<Target> highest_type;

            return (range_check_impl<Target,Source>()(s))
            ?static_cast<Target>(s)
            : (s > 0) ? highest_type{}() : lowest_type{}();
#endif
        }
    };

   template <>
   struct arithmetic_convert_impl<float,double,void>
   {
      constexpr float operator()(double const & s) const
      {
         return static_cast<float>(s);
      }
   };
 
}//impl_detail
 
template <typename TargetType,typename SourceType>
 
QUAN_CONSTEXPR typename quan::where_<
   quan::meta::and_<
      std::is_arithmetic<SourceType>,
      quan::meta::and_<
         std::is_arithmetic<TargetType>,
         quan::meta::not_<std::is_same<TargetType,bool> >
      >
>,
TargetType
>::type arithmetic_convert(SourceType const & s)
{
    return impl_detail::arithmetic_convert_impl<TargetType,SourceType>{}(s);
}


 
template <typename TargetType,typename SourceType>
inline
 
QUAN_CONSTEXPR typename quan::where_<
quan::meta::and_<
std::is_arithmetic<SourceType>,
std::is_same<TargetType,bool>
>,
TargetType
>::type arithmetic_convert(SourceType const & s)
{
    return (s == static_cast<SourceType>(0) )? false : true;
}
 /*
// udts
   template <typename TargetType,typename SourceType>
   inline
   QUAN_CONSTEXPR typename quan::where_<
   quan::meta::and_<
   quan::meta::not_<std::is_arithmetic<SourceType> >,
   quan::meta::and_<
   quan::meta::not_<std::is_arithmetic<TargetType> >,
   std::is_convertible<SourceType, TargetType>
   >
   >,
   TargetType
   >::type
   arithmetic_convert(SourceType const & s)
   {
       return quan::implicit_cast<TargetType>(s);
   }
*/
   template <typename Target, typename Source>
   inline QUAN_CONSTEXPR
   typename quan::where_<
         quan::meta::and_<
            std::is_arithmetic<Target>,
            quan::meta::is_mathematic_angle<Source>
         >
         , Target
   >::type
   arithmetic_convert(Source const & s)
   {
     return arithmetic_convert<Target>(s.numeric_value());
   }

   template <typename Target, typename Source>
   inline QUAN_CONSTEXPR
   typename quan::where_<
         quan::meta::and_<
            quan::meta::is_angle<Target>,
            quan::meta::is_angle<Source>
         >
         , Target
   >::type
   arithmetic_convert(Source const & s)
   {
     return Target{s};
   }
 
 
}
 
#endif
 
 
