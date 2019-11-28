#ifndef QUAN_COMPATIBILITY_MPUSZ_UNITS_HPP_INCLUDED
#define QUAN_COMPATIBILITY_MPUSZ_UNITS_HPP_INCLUDED

#include <units/quantity.h>

#include <quan/meta/binary_op.hpp>
#include <quan/meta/is_scalar.hpp>

namespace quan{ namespace meta{ namespace impl{

   /*
      quan has a different view on what a scalar is to mpusz::units.
      No matter, though confusing, they can work together
   */
   template <units::Quantity Q>
   struct is_scalar_impl<Q> : std::true_type{};

   // quan (has been around since 2003) uses specialisations of binary_op_impl
   // for result type deduction on operations. Back then there was no such thing as decltype and auto etc.
   // Though you can use decltype for deduction, there may be some types
   // that dont have any runtime operations so this type may still be useful
   // though maybe one could define the runtime operators on the meta types anyway
   // anyway here is the basic integration to get units::Quantity working with quan::two_d::vector

   template <units::Quantity Lhs, units::Quantity Rhs>
   struct binary_op_impl<Lhs, quan::meta::plus, Rhs>{
      typedef decltype(Lhs{} + Rhs{}) type;
   };

   template <units::Quantity Lhs, units::Quantity Rhs>
   struct binary_op_impl<Lhs, quan::meta::minus, Rhs>{
      typedef decltype(Lhs{} - Rhs{}) type;
   };

   template <units::Quantity Lhs, units::Quantity Rhs>
   struct binary_op_impl<Lhs, quan::meta::times, Rhs>{
      typedef decltype(Lhs{} * Rhs{}) type;
   };

   template <units::Quantity Lhs, units::Scalar Rhs>
   struct binary_op_impl<Lhs, quan::meta::times, Rhs>{
      typedef decltype(Lhs{} * Rhs{}) type;
   };

   template <units::Scalar Lhs, units::Quantity Rhs>
   struct binary_op_impl<Lhs, quan::meta::times, Rhs>{
      typedef decltype(Lhs{} * Rhs{}) type;
   };

   template <units::Quantity Lhs, units::Quantity Rhs>
   struct binary_op_impl<Lhs, quan::meta::divides, Rhs>{
      typedef decltype(Lhs{} / Rhs{}) type;
   };

   template <units::Quantity Lhs, units::Scalar Rhs>
   struct binary_op_impl<Lhs, quan::meta::divides, Rhs>{
      typedef decltype(Lhs{} / Rhs{}) type;
   };

   template <units::Scalar Lhs, units::Quantity Rhs>
   struct binary_op_impl<Lhs, quan::meta::divides, Rhs>{
      typedef decltype(Lhs{} / Rhs{}) type;
   };

}}}


#endif // QUAN_COMPATIBILITY_MPUSZ_UNITS_HPP_INCLUDED
