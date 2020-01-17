#ifndef QUAN_FIXED_QUANTITY_OPERATIONS_MAKE_COHERENT_HPP_INCLUDED
#define QUAN_FIXED_QUANTITY_OPERATIONS_MAKE_COHERENT_HPP_INCLUDED

#include <ratio>
#include <quan/meta/log10_ratio.hpp>
#include <quan/fixed_quantity/fixed_quantity.hpp>
#include <quan/where.hpp>
#include <quan/meta/make_coherent.hpp>

namespace quan{ namespace meta{

   namespace impl {

      // turn a possibly incoherent quantity into a coherent quantity
      template <typename Q>
      struct make_coherent_impl<
         Q,
         typename quan::where_<quan::meta::is_fixed_quantity<Q> >::type
      >{

         typedef Q q_type;
         typedef typename q_type::unit unit;
         typedef typename q_type::value_type value_type;
         typedef typename unit::conversion_factor conversion_factor;
         typedef typename unit::abstract_quantity  abstract_quantity;
         typedef typename conversion_factor::multiplier multiplier;
         // do log10(multiplier) 
         typedef typename log10_ratio<typename conversion_factor::multiplier>::type ratio_log10_mux;
         
         typedef typename conversion_factor::exponent exponent;
         static constexpr auto expnume = quan::meta::numerator<exponent>::value;
         static constexpr auto expdenom = quan::meta::denominator<exponent>::value;

         // add mux to exponent to make a coherent conversion factor with multiplier of 1
         typedef typename std::ratio_add<ratio_log10_mux,std::ratio<expnume,expdenom> >::type ratio_log10;

         // assemble the coherent quantity
         typedef quan::fixed_quantity<
             quan::meta::unit<
               abstract_quantity,
               quan::meta::conversion_factor<
                  quan::meta::rational<ratio_log10::num, ratio_log10::den>
               >
             >,
            value_type
         > type;
      };
   } //impl

} // meta

   template <typename Q>
   inline constexpr
   typename quan::eval_where<
      quan::meta::is_fixed_quantity<Q>,
      quan::meta::make_coherent<Q>
   >::type
   make_coherent( Q const & q)
   {
      return q;
   }

} // quan::meta

#endif // QUAN_FIXED_QUANTITY_OPERATIONS_MAKE_COHERENT_HPP_INCLUDED
