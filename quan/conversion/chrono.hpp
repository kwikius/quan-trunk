#ifndef QUAN_CONVERSION_CHRONO_HPP_INCLUDED
#define QUAN_CONVERSION_CHRONO_HPP_INCLUDED

#include <quan/time.hpp>
#include <chrono>
#include <quan/meta/eval_if.hpp>
#include <quan/meta/bool.hpp>
#include <quan/meta/conversion_factor.hpp>

namespace quan::meta{

   namespace detail{
      template <typename StdRatio, typename Exp = rational<0> >
      struct conversion_factor_from_chrono_ratio_impl {

         using type = eval_if_t< 
            std::ratio_greater<StdRatio,std::ratio<10> >,
            conversion_factor_from_chrono_ratio_impl<
               std::ratio_divide<StdRatio,std::ratio<10> >,
               binary_op_t<Exp, plus,rational<1> >
            >,
            std::ratio_less<StdRatio,std::ratio<1> >,
            conversion_factor_from_chrono_ratio_impl<
               std::ratio_multiply<StdRatio,std::ratio<10> >,
               binary_op_t<Exp, minus,rational<1> >
            >,
            conversion_factor<Exp,rational<StdRatio::num,StdRatio::den> >
         >;
      };

      template <typename QuanExp, typename QuanMux>
      struct chrono_ratio_from_conversion_factor_impl{
         using type = eval_if_t< 
            binary_op_t<QuanExp,less,rational<0> >,
            chrono_ratio_from_conversion_factor_impl<
               binary_op_t<QuanExp, plus,rational<1> >,
               binary_op_t<QuanMux,divides,rational<10> >
            >,
            binary_op_t<QuanExp,greater,rational<0> >,
            chrono_ratio_from_conversion_factor_impl<
               binary_op_t<QuanExp, minus,rational<1> >,
               binary_op_t<QuanMux,times,rational<10> >
            >,
            std::ratio<QuanMux::numerator,QuanMux::denominator>
         >;
      };

   }//detail

   template <typename ConversionFactor>
   using chrono_ratio_from_conversion_factor 
     = typename detail::chrono_ratio_from_conversion_factor_impl<
         typename quan::meta::get_exponent<ConversionFactor>::type,
         typename quan::meta::get_multiplier<ConversionFactor>::type
      >::type;

   template <typename StdRatio>
   using conversion_factor_from_chrono_ratio 
      = typename detail::conversion_factor_from_chrono_ratio_impl<
         StdRatio
      >::type;

} //quan::meta

namespace quan{
   
   template <typename V, typename R>
   inline constexpr 
   quan::fixed_quantity<
      quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         quan::meta::conversion_factor_from_chrono_ratio<R>
      >,
      V
   >
   from_chrono(std::chrono::duration<V,R> const & in)
   {
     using result_type = quan::fixed_quantity<
      quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         quan::meta::conversion_factor_from_chrono_ratio<R>
      >,
      V
   >;
     return result_type{in.count()};
   }

   template <typename U, typename V>
   inline constexpr 
   std::chrono::duration<
      V,
      quan::meta::chrono_ratio_from_conversion_factor<
         typename quan::meta::get_conversion_factor<U>::type
      >
   >
   to_chrono(quan::fixed_quantity<U,V> const & in)
   {
      using result_type = std::chrono::duration<
         V,
         quan::meta::chrono_ratio_from_conversion_factor<
            typename quan::meta::get_conversion_factor<U>::type
         >
      >;
     return result_type{in.numeric_value()};
   }
}

#endif // QUAN_CONVERSION_CHRONO_HPP_INCLUDED
