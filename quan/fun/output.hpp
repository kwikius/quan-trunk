#ifndef QUAN_FUN_OUTPUT_HPP_INCLUDED
#define QUAN_FUN_OUTPUT_HPP_INCLUDED
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

#include <iostream>
#include <string>
namespace quan{ namespace fun{
   namespace detail{

   template <typename CharType>
      struct output_{
         std::basic_ostream<CharType> & os;
         std::basic_string<CharType> sep;
         output_(
            std::basic_ostream<CharType> & os_in,
            std::basic_string<CharType> const & sep_in
         ):os(os_in), sep(sep_in){}

         template <typename T>
         struct result{
            typedef std::basic_ostream<CharType> & type;
         };

         template <typename T>
         typename result<T>::type
         operator()(T const & t)const
         {
            return os << t << sep;
         }
         private:
         output_ & operator =( output_& in);
      };
   }//detail

   template <typename CharType>
   inline
   detail::output_<CharType>
   output(std::basic_ostream<CharType>& os, std::basic_string<CharType>const & sep)
   {
      return detail::output_<CharType>(os,sep);
   }

   template <typename CharType>
   inline
   detail::output_<CharType>
   output(std::basic_ostream<CharType>& os, CharType const * sep)
   {
      return detail::output_<CharType>(os,sep);
   }

   template <typename CharType>
   inline
   detail::output_<CharType>
   output(std::basic_ostream<CharType>& os, CharType  sep)
   {
      
      return detail::output_<CharType>(os,std::basic_string<CharType>{sep});
   }

}}//quan::fun

#endif

