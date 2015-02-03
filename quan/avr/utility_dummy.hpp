#ifndef QUAN_AVR_UTLITY_DUMMY_HPP_INCLUDED
#define QUAN_AVR_UTLITY_DUMMY_HPP_INCLUDED
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


namespace std{

  template<typename T1, typename T2>
  struct pair{
     pair(T1 const& t1, T2 const& t2): first(t1),second(t2){}
     T1 first;
     T2 second;
  };
}


#endif // QUAN_AVR_UTLITY_DUMMY_HPP_INCLUDED
