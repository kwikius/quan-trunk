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
         typedef typename Q::unit unit;
         typedef typename Q::value_type value_type;
         typedef typename unit::conversion_factor conversion_factor;
         typedef typename log10_ratio<typename conversion_factor::multiplier>::type log10_ratio_multiplier;
         // TODO: move quan from quan::meta::rational to std::ratio
         // meanwhile convert to std::ratio
         typedef typename std::ratio<
            quan::meta::numerator<typename conversion_factor::exponent>::value,
            quan::meta::denominator<typename conversion_factor::exponent>::value
         >::type exponent;

         // add log10 of multiplier to exponent to make a coherent conversion factor with multiplier of 1
         typedef typename std::ratio_add<exponent,log10_ratio_multiplier>::type ratio_log10;

         // assemble the coherent quantity
         typedef quan::fixed_quantity<
            quan::meta::unit<
               typename unit::abstract_quantity,
               quan::meta::conversion_factor<
                  quan::meta::rational<ratio_log10::num, ratio_log10::den>
               >
            >,
            value_type
         > type;
      };

   }} // meta::impl

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

} // quan

#endif // QUAN_FIXED_QUANTITY_OPERATIONS_MAKE_COHERENT_HPP_INCLUDED
