#ifndef QUAN_ST_TR1_IS_CONVERTIBLE_HPP_INCLUDED
#define QUAN_ST_TR1_IS_CONVERTIBLE_HPP_INCLUDED
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
#ifdef QUAN_USE_QUAN_STD_TR1

#include <quan/meta/detail/yes_no_type.hpp>

#include <quan/std/tr1/integral_constant.hpp>

#include <quan/where.hpp>
#include <quan/std/tr1/is_arithmetic.hpp>
#include <quan/meta/and.hpp>

namespace quan{ namespace meta{namespace detail{
   
   template <typename To>
   struct is_convertible_tester{
      static yes_type f( To const & p);
      static no_type f(...);
   };

   template <typename From>
   struct returns_from{
      static From get();
   };

   template <typename From,typename To,typename Where = void>
   struct is_convertible_impl{
      typedef is_convertible_tester<To> base;
      static const int res = sizeof( base::f( ( returns_from<From>::get()) ) );
      typedef  std::integral_constant< bool,( res == sizeof(yes_type))> type;
      static const bool value = type::value;
   };

   //prevent warnings for arithmetic types
   template <typename From,typename To>
   struct is_convertible_impl<
      From,To,
      typename quan::where_<
         quan::meta::and_<
            std::is_arithmetic<From>,
            std::is_arithmetic<To>
         >
      >::type
   > : std::integral_constant<bool,true>{};
 //prevent warnings for pointers
   template <typename From>
   struct is_convertible_impl<
      From *,bool
   > : std::integral_constant<bool,true>{};

   template <typename From>
   struct is_convertible_impl<
      From * const,bool
   > : std::integral_constant<bool,true>{};
   
}}}

namespace std{

   template <typename From, typename To>
   struct is_convertible : quan::meta::detail::is_convertible_impl<From,To>::type{};

}
//#if (defined _MSC_VER)
//#pragma warning (default : 4244)
//#endif

#else
#include <type_traits>
#endif

#endif

