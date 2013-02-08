#ifndef QUAN_LEXER_TOKEN_HPP_INCLUDED
#define QUAN_LEXER_TOKEN_HPP_INCLUDED

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
