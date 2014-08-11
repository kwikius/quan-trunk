#ifndef QUAN_CONVERSION_STRING_CONVERT_HPP_INCLUDED
#define QUAN_CONVERSION_STRING_CONVERT_HPP_INCLUDED
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


#include <quan/convert.hpp>
#include <climits>
#include <cstdint>

namespace quan{ namespace detail{

	template<int N > struct converter <const char(&)[N],float>
   {
      private:
		 
        static const char array[N];
        int conversion_error;

      public:
        converter():conversion_error{0}{}
        typedef const char(& array_ref) [N];

        typedef const char (array_type) [N];
        array_ref operator()( float in) 
        {
				for ( int i = 0; i < N;++i){
				  array[i] = '\0';
				}
            
        }
   };

   template<int N > typename converter<const char(&)[N],float>::array_type converter<const char(&)[N],float>::array;

}}

#endif // QUAN_CONVERSION_STRING_CONVERT_HPP_INCLUDED
