#ifndef QUAN_CONCEPTS_STD_CONTAINER_HPP_INCLUDED
#define QUAN_CONCEPTS_STD_CONTAINER_HPP_INCLUDED

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

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <list>
#include <vector>
#include <quan/is_model_of.hpp>

namespace quan{

   struct StdContainer_;

   namespace impl{

      template <typename T>
      struct is_model_of_impl<StdContainer_, std::list<T> > : quan::meta::true_{};

      template <typename T>
      struct is_model_of_impl<StdContainer_, std::vector<T> > : quan::meta::true_{};
   }


}//quan

#endif

