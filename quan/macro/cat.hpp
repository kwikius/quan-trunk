#ifndef QUAN_MACRO_CAT_HPP_INCLUDED
#define QUAN_MACRO_CAT_HPP_INCLUDED
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

#define QUAN_MACRO_CAT(A,B) QUAN_MACRO_CAT_IMPL(A,B)
#define QUAN_MACRO_CAT_IMPL(A,B) QUAN_MACRO_CAT_IMPL2(A,B)
#define QUAN_MACRO_CAT_IMPL2(A,B) A##B 

#endif

