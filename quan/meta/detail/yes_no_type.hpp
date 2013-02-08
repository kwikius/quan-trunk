#ifndef QUAN_META_IMPL_DETAIL_YES_NO_TYPE_HPP_INCLUDED
#define QUAN_META_IMPL_DETAIL_YES_NO_TYPE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2006
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

namespace quan{ namespace meta{ namespace detail{

      struct yes_type{};

      struct no_type{
         char array [2 * sizeof(yes_type)];
      };
}}}

#endif


