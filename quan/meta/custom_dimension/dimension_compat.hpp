#ifndef QUAN_META_CUSTOM_DIMENSION_COMPAT_HPP_INCLUDED
#define QUAN_META_CUSTOM_DIMENSION_COMPAT_HPP_INCLUDED

#include <quan/meta/custom_dimension/dimension.hpp>

namespace quan{ namespace  meta{

   template <typename D>
   struct is_dimensionless<
      D, 
      typename quan::where_<quan::meta::is_dimension<D> >::type
   > : std::is_same<D, quan::meta::dimension<> >{};

   template <typename DL, typename DR>
   struct  dimensionally_equivalent<
      DL,DR,
      typename quan::where_<
         quan::meta::and_<
            quan::meta::is_dimension<DL>,
            quan::meta::is_dimension<DR>
         >
      >::type
    > : quan::meta::detail::are_equal_dimensions<DL,DR>{};

   template <typename D>
   struct get_quantity_system;

   struct si_unit_system;

   template <typename ...D>
   struct get_quantity_system< dimension<D...> >{ typedef si_unit_system type;};

  namespace impl{

      template <typename DL, typename DR>
      struct binary_op_impl<
         DL,quan::meta::times,DR,
         typename quan::where_<
            quan::meta::and_<
               quan::meta::is_dimension<DL>,
               quan::meta::is_dimension<DR>
            >
         >::type
      > : quan::meta::detail::add_dimensions< DL,DR>{};

      template <typename DL, typename DR>
      struct binary_op_impl<
         DL,quan::meta::divides,DR,
         typename quan::where_<
            quan::meta::and_<
               quan::meta::is_dimension<DL>,
               quan::meta::is_dimension<DR>
            >
         >::type
      > : quan::meta::detail::subtract_dimensions< DL,DR>{};

      template <typename D,typename Exp>
      struct binary_op_impl<
         D,quan::meta::pow,Exp,
         typename quan::where_< quan::meta::is_dimension<D> >::type
      > : quan::meta::detail::multiply_dimension<
            D, std::ratio<Exp::numerator,Exp::denominator> 
      >{};
      
  } // impl

  template <typename D>
  struct unary_operation< 
      reciprocal, D, typename quan::where_< quan::meta::is_dimension<D> >::type
  > : quan::meta::detail::negate_dimension<D>{};

 // get_length_dimension etc
   

}} //quan::meta

#endif // QUAN_META_CUSTOM_DIMENSION_COMPAT_HPP_INCLUDED
