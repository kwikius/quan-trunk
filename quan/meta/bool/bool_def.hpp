#ifndef QUAN_META_BOOL_BOOL_DEF_HPP_INCLUDED
#define QUAN_META_BOOL_BOOL_DEF_HPP_INCLUDED

// Copyright Andrew Little 2006-2007

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <type_traits>

namespace quan{ namespace meta{

      template <bool B>
      struct bool_ : std::integral_constant<bool, B>{
         typedef bool_ type;
      };
}}

#endif
