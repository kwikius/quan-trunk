#ifndef QUAN_REFLECT_ABSTRACT_QUANTITY_NAME_HPP_INCLUDED
#define QUAN_REFLECT_ABSTRACT_QUANTITY_NAME_HPP_INCLUDED 

#include <quan/components/of_anonymous_quantity.hpp>
#include <quan/meta/static_unit_concept.hpp>
#include <quan/meta/eval_if.hpp>
#include <string>

namespace quan{namespace reflect{

   template <typename Quantity>
   std::string abstract_quantity_name(Quantity const & )
   {
      typedef typename Quantity::unit unit;

      typedef typename quan::meta::eval_if<
         quan::meta::is_named_quantity<Quantity>,
         quan::meta::get_named_quantity_traits<
            typename Quantity::unit
         >,
         meta::components::of_anonymous_quantity<Quantity>
      >::type result;
      
      return typename result::abstract_quantity_name();
   }
}}
#endif
