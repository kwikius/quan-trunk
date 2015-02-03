#ifndef QUAN_ANONYMOUS_QUANTITY_HPP_INCLUDED
#define QUAN_ANONYMOUS_QUANTITY_HPP_INCLUDED

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
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

//anonymous_quantity to match named quantities

namespace quan{namespace meta{ namespace components{

  template <typename FixedQuantity>
   struct of_anonymous_quantity{
      template<typename CharType>
      static const CharType* unprefixed_symbol(); // undefined
      static const char* abstract_quantity_name()
      {
         return "anonymous_quantity";
      }
      typedef typename FixedQuantity::unit::abstract_quantity abstract_quantity;
      typedef typename abstract_quantity::dimension dimension;

      typedef of_anonymous_quantity type;
   };

}}}

#endif
