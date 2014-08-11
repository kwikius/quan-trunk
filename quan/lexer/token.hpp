#ifndef QUAN_LEXER_TOKEN_HPP_INCLUDED
#define QUAN_LEXER_TOKEN_HPP_INCLUDED
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

#include <quan/lexer/attribute.hpp>
#include <cassert>

namespace quan{ namespace lexer{

   struct token{
        token(): attribute{0}{}
        int get_id() const{ return (attribute != nullptr )?attribute->get_id(): 0;}
        lexer::attribute * attribute;
       ~token(){if (attribute != nullptr){delete attribute;}}
         filepos get_filepos()
         { 
            if (attribute != nullptr) {return attribute->get_filepos();}
            else {return filepos{};}
         }
         template <typename T>
          T * get_attr()const
         {
             auto p = dynamic_cast<T*> (this->attribute);
             assert(p != nullptr);
             return p;
         }

          template <typename T>
          T * move_attr()const
         {
             auto p = dynamic_cast<T*> (this->attribute);
             assert(p != nullptr);
             this->attribute = nullptr;
             return p;
         }
   };
}}

#endif
