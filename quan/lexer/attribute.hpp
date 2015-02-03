#ifndef QUAN_LEXER_ATTRIBUTE_HPP_INCLUDED
#define QUAN_LEXER_ATTRIBUTE_HPP_INCLUDED
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

#include <quan/lexer/filepos.hpp>

namespace quan{ namespace lexer{

   

//   struct attribute {
//      filepos const & get_filepos() const { return m_filepos;}
//      int get_id() const { return m_attribute_id;}
//      virtual ~attribute(){}
//    protected:
//       attribute(int id_in, quan::lexer::filepos fp_in): m_attribute_id{id_in},m_filepos{fp_in}{}
//    private:
//       int m_attribute_id;
//       quan::lexer::filepos m_filepos;
//   };
//
//   struct id_attribute : quan::lexer::attribute {
//      int value;
//      id_attribute(quan::lexer::filepos const & fp, int v) : quan::lexer::attribute{v, fp}, value {v} {}
//   };
//
//   template <typename ValueType,int ID>
//   struct value_attribute : attribute {
//      typedef ValueType value_type;
//      value_type value;
//      value_attribute(filepos const & fp, value_type const & v):attribute{ID,fp},value{v}{}
//   };
//
//   template <typename ValueType>
//   struct ptr_attribute : attribute {
//      typedef ValueType * value_type;
//      value_type value;
//      ptr_attribute(filepos const & fp, value_type p):attribute{-1,fp},value{p}{}
//      ~ptr_attribute(){if(value != nullptr){delete value;}}
//   };
//
//   template <typename ValueType> inline
//   ptr_attribute<ValueType>* make_ptr_attribute(filepos const & fp,ValueType* p)
//   {
//      return new ptr_attribute<ValueType>{fp,p};
//   }
//

}}


#endif // QUAN_LEXER_ATTRIBUTE_HPP_INCLUDED
