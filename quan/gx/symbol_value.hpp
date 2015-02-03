#ifndef QUAN_GX_SCALAR_SYMBOL_VALUE_HPP_INCLUDED
#define QUAN_GX_SCALAR_SYMBOL_VALUE_HPP_INCLUDED
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

#include <string>
#include <quan/gx/abc_symbol.hpp>
/*
  a value with name min max etc.
*/

namespace quan{ namespace gx{

   template <typename T>
   struct symbol_value : abc_symbol<T>{
      symbol_value(
        std::string const & name, 
        std::string const & text, // dependent on num space sepped values
       T const& value, T const & min, T const & max)
      :m_name(name),m_text(text),m_value(value),m_min(min),m_max(max){}
      T&  ref(){return m_value;};
      T const &  cref() const{return m_value;};
      std::string name() const { return m_name;};
      T const &  min()const{ return m_min;};
      T const &  max() const{ return m_max;};
      std::string text()const { return m_text;}

   private:
      std::string m_name;
      std::string m_text;
      T m_value;
      T m_min;
      T m_max;
   };

}}


#endif // QUAN_GX_SYMBOL_VALUE_HPP_INCLUDED
