#ifndef QUAN_GX_ABC_SCALAR_SYMBOL_HPP_INCLUDED
#define QUAN_GX_ABC_SCALAR_SYMBOL_HPP_INCLUDED
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

namespace quan{ namespace gx{

   template <typename T>
   struct abc_symbol{

      virtual ~abc_symbol(){}
      virtual T&  ref()=0;
      virtual T const &  cref() const=0;
      virtual std::string name() const=0;
      virtual std::string text() const=0;
      virtual T const &  min() const=0;
      virtual T const &  max() const=0;
      
   };

}}

#endif // QUAN_GX_ABC_SCALAR_SYMBOL_HPP_INCLUDED
