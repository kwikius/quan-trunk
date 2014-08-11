#ifndef QUAN_LEXER_TOKEN_STREAM_HPP_INCLUDED
#define QUAN_LEXER_TOKEN_STREAM_HPP_INCLUDED
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

#include <quan/diagnostic/report.hpp>
#include <stdexcept>

namespace quan{ namespace lexer{

   struct token_stream_eof : std::logic_error{
      token_stream_eof(): std::logic_error("quan::token_stream_eof"){}
      token_stream_eof(quan::diagnostic::report::ptr const & r) 
      : std::logic_error(r?r->str():std::string("")){}
   };

   struct token_stream_underflow : std::logic_error{
      token_stream_underflow(): std::logic_error("quan::token_stream_underflow"){}
      token_stream_underflow(quan::diagnostic::report::ptr const & r) 
      : std::logic_error(r?r->str():std::string("")){}
   };

   //bad,fail

   template <typename EnvironmentType>
   struct token_stream{

      virtual ~token_stream(){}
      typedef EnvironmentType environment_type;
      typedef typename environment_type::pos_type pos_type;
      typedef typename environment_type::token_class_type token_class_type;
      typedef typename environment_type::token_type token_type;
      typedef typename environment_type::bool_type bool_type;
      typedef typename environment_type::token_cookie_type token_cookie_type;
      
      virtual pos_type get_position()const=0;
      virtual void putback()=0; //may throw
		virtual void rewind(pos_type pos); //may throw
      virtual token_type		   current()const=0;
      virtual token_class_type   current_class()const=0;
      virtual token_cookie_type const &  get_cookie() const=0;
      virtual token_cookie_type &  get_cookie()=0;
      virtual token_type		   next()=0;//may throw

      token_class_type	next_class()//may throw
      {
         next();
         return current_class();
      }
      
      template <token_class_type ID>
      bool_type next_class_is() //may throw
      {
         return bool_type(next_class() == ID);
      }

      template <token_class_type ID>
      bool_type current_class_is()const
      {
         return bool_type(current_class() == ID);
      }
      template <token_type ID>
      bool_type next_is()//may throw
      {
         return bool_type(next() == ID);
      }
      template <token_type ID>
      bool_type current_is()const
      {
         return bool_type(current() == ID);
      }
   
      template <token_class_type ID>
      bool_type next_class_not()//may throw
      {
         return ! next_class_is<ID>();
      }
      template <token_class_type ID>
      bool_type current_class_not()const
      {
         return ! current_class_is<ID>();
      }
      template <token_type ID>
      bool_type next_not()//may throw
      {
         return !next_is<ID>();
      }
      template <token_type ID>
      bool_type current_not()const
      {
         return ! current_is<ID>();
      }
   };

}}//quan::lexer

#endif

