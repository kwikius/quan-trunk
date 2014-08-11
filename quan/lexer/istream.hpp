#ifndef QUAN_LEXER_ISTREAM_HPP_INCLUDED
#define QUAN_LEXER_ISTREAM_HPP_INCLUDED
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

#include <iosfwd>
#include <stdexcept>
#include <string>
#include <stack>

#include <quan/lexer/check_point.hpp>
#include <quan/lexer/file_error.hpp>

namespace quan{ namespace lexer{

   template<typename CharType>
   struct istream{
      static std::stack<check_point> check_points;
      typedef CharType char_type;
      typedef typename std::char_traits<CharType>::int_type int_type;
      static int_type eof_char(){ return std::char_traits<CharType>::eof();}
      struct underflow : std::logic_error{
         underflow(std::string const & str):std::logic_error(str){}
      };
      struct overflow : std::logic_error{
         overflow(std::string const &str):std::logic_error(str){}
      };
      void push_check_point(std::string const & info)const
      {
         check_points.push(check_point(info,this->get_source_pos(),this->get_stream_id()));
      }
      void pop_check_point()const
      {
         check_points.pop();
      }
      check_point get_check_point()const
      {
         if ( check_points.size()){
         return check_points.top();
         }
         return check_point("throw point" ,this->get_source_pos(),this->get_stream_id());
      }
      virtual ~istream(){};
      virtual istream& get(char_type& ch)=0;
		virtual istream& putback()=0;
		virtual int_type peek()=0;
	   virtual source_pos get_source_pos()const =0;
      virtual std::string get_stream_id() const =0;
      virtual bool eof() =0;
      virtual bool good() =0;
      virtual bool bad() =0;
      virtual bool fail()=0;
      virtual void suspend(){}
      virtual void resume(){}
      char_type get()
      {
         char_type ch;
         get(ch);
         return ch;
      }
   };

   template<typename CharType>
   struct scoped_check_point{

      scoped_check_point(istream<CharType> const & is_in, std::string const & text)
      :is(is_in)
      {
         is.push_check_point(text);
      }

      ~scoped_check_point()
      {
         is.pop_check_point();
      }
      private:
      istream<CharType> const & is;
   };

   template <typename CharType>
   std::stack<quan::lexer::check_point>
   quan::lexer::istream<CharType>::check_points
      = std::stack<quan::lexer::check_point>();

   template<typename CharType>
   inline void do_opt_space(istream<CharType> & is)
   {
     for(;;){
         if(!is.good()){
            throw file_error<CharType>(is,"bad file ... expected optional whitespace");
         }
         if( is.eof()){
            return;
         }

         if (isspace(is.peek())){
            is.get();
         }
         else{
            return;
         }
     }
   }

}}//quan::lexer

#endif

