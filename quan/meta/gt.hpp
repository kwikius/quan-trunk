#ifndef QUAN_META_GT_HPP_INCLUDED
#define QUAN_META_GT_HPP_INCLUDED

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/meta/bool.hpp>

namespace quan{ namespace meta{

      template<typename TL,typename TR>
      struct gt_ : bool_<((TL::value) > (TR::value))>{};
            
}}

#endif
