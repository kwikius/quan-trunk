#ifndef QUAN_AVR_IOSTREAM_HPP_INCLUDED
#define  QUAN_AVR_IOSTREAM_HPP_INCLUDED
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

 #include <quan/avr/cstddef_dummy.hpp>

 namespace std{

     template<typename T>
	  struct basic_ostream{
        basic_ostream & precision(std::size_t) {return *this;}
	  };

	  template <typename T, typename T1>
	  basic_ostream<T> & operator << (basic_ostream<T> & os, T1 const & x)
	  {
			 return os;

         
	  }

     typedef  basic_ostream<char> ostream;

     extern basic_ostream<char> cout ;
     extern basic_ostream<char> cerr ;

    typedef unsigned long size_t;

}

#endif
