#ifndef QUAN_BIT_HPP_INCLUDED
#define QUAN_BIT_HPP_INCLUDED
/*
 Copyright (c) 2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/
#if defined bit
#undef bit
#endif

namespace quan{

    template <typename ValueType, typename ValueType1>
    inline constexpr ValueType bit(ValueType1 n) 
   {return static_cast<ValueType>(1) << n;}

}

#endif // QUAN_BIT_HPP_INCLUDED
