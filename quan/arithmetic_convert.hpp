#ifndef QUAN_ARITHMETIC_CONVERT_HPP_INCLUDED
#define QUAN_ARITHMETIC_CONVERT_HPP_INCLUDED

// Copyright Andrew Little 2006-2007

#include <quan/limits.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/signed_unsigned.hpp>
#include <quan/meta/not.hpp>
#include <quan/meta/or.hpp>
#include <type_traits>
#include <type_traits>
#include <type_traits>
#include <quan/implicit_cast.hpp>
#include <quan/meta/identity.hpp>

#if defined __AVR__
#include <math.h>
#else
#include <cmath>
#endif
#if defined abs
#error "abs is a macro"
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

         return( static_cast<unsigned_or_float_type>(std::numeric_limits<Target>::max()) >= s);
      }
   };
 
   template <typename Target, typename Source,typename Where =void>
   struct arithmetic_convert_impl;
// not narrowing
 
   template <typename Target, typename Source>
   struct arithmetic_convert_impl<
      Target, Source,
      typename quan::where_<
         quan::meta::not_<is_narrowing_conversion<Target, Source> >
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

        if (range_check_impl<Target,Source>()(s)) {
         int sign_s = ( s >=Source(0) ) ? 1 : -1;
         Source abs_s = (sign_s ==1)?s:-s;
         Source abs_intpart =0;;
#ifndef __AVR__
         Source abs_fract = std::modf(abs_s,&abs_intpart);
#else
         Source abs_fract = ::modf(abs_s,&abs_intpart);
#endif
         if (abs_fract < (Source(1)/2)){
            return static_cast<Target>(s);
         }else {
            if (abs_fract > (Source(1)/2)){
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
            : (s > 0) ? highest_type{}() : lowest_type{}();
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
    return impl_detail::arithmetic_convert_impl<TargetType,SourceType>()(s);
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
 
 
}
 
#endif
 
 