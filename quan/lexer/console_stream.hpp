#ifndef QUAN_LEXER_CONSOLE_STREAM_HPP_INCLUDED
#define QUAN_LEXER_CONSOLE_STREAM_HPP_INCLUDED
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

#include <quan/lexer/char_istream.hpp>
#include <iostream>
#include <stack>
#include <fstream>
#include <stdexcept>
#include <string>

namespace quan{ namespace lexer{

   template <typename CharType>
   struct console_istream : quan::lexer::istream<CharType>{
      
      console_istream(
         std::basic_string<char_type> const & terminator,
         std::basic_string<char_type> const & message)
     : m_row(source_pos::off_type(0)),
      m_cursor(0),
      m_terminator(terminator),
      m_eof(false)
      {
         std::cout << message;
         getline(std::cin,m_buffer,'\n');
         if ( m_buffer.substr(0,terminator.size()) == terminator){
            m_eof = true;
         }
         m_columns.push(source_pos::off_type(0));
      }
      console_istream& get(char_type& ch_out){

         if(m_eof){
             throw overflow("console_istream overflow");
         }

         if (m_cursor >= m_buffer.size()){
            std::string str;
            getline(std::cin,str,'\n');
            m_buffer += '\n' + str ;
         }

         char_type ch = m_buffer.at(m_cursor);
         ch_out = ch;
         ++m_cursor;
         if (isspace(ch)){
            if((m_buffer.size() >= (m_cursor  + m_terminator.size()) ) 
               && (m_buffer.at(m_cursor) == m_terminator.at(0)) ){
               if (m_buffer.substr(m_cursor,m_terminator.size()) == m_terminator){
                  m_buffer = m_buffer.substr(0,m_cursor);
                  m_eof = true;
               }
            }
         }
         if ( (m_cursor > 0 ) && m_buffer.at(m_cursor-1) =='\n'){
            m_columns.push(source_pos::off_type(0));
            ++m_row;
         }else{
            ++m_columns.top();
         }

         return *this;
      }
		console_istream& putback(){
        
         if(--m_cursor < 0){
            ++m_cursor;
            throw underflow("console_istream underflow2");
         }
         if ( m_eof){
            m_eof = false;
         }
         if ( m_buffer.at(m_cursor) =='\n'){
            --m_row;
            m_columns.pop();
         }
         //sync std::cin ...
         return *this;
      }

		int_type peek()
      {
         if (m_eof){
            return eof_char();
         }
         if (m_cursor >= m_buffer.size()){
            std::string str;
            getline(std::cin,str,'\n');
            m_buffer += '\n' + str ;
         }

         char_type ch = m_buffer.at(m_cursor);
         if (isspace(ch)){
            ++m_cursor;
            if((m_buffer.size() >= (m_cursor  + m_terminator.size()) ) 
               && (m_buffer.at(m_cursor) == m_terminator.at(0)) ){
              
               if (m_buffer.substr(m_cursor,m_terminator.size()) == m_terminator){
                  m_buffer = m_buffer.substr(0,m_cursor);
                  --m_cursor;
                  return eof_char();
               }
            }else{
               --m_cursor;
            }
         }
         return ch;
      }
	   source_pos get_source_pos()const {return source_pos(m_row,m_columns.top());}

      template <typename CharType>
      struct stream_id;
      
      template <>
      struct stream_id<char>{
          static const char* get()
         {
          return "std::cin";
         }  
      };

      template <>
      struct stream_id<wchar_t>{
          static const char* get()
         {
          return "std::wcin";
         }  
      };

      std::string get_stream_id()const 
      {
         return stream_id<char_type>::get();
      }
      bool eof(){return m_eof;}
      bool bad(){ return false;}
      bool good() { return ! eof();}
      bool fail() { return  eof();}
      void save( std::string const & file_name)
      {
         std::ofstream out(file_name.c_str());
         out << m_buffer;
      }
   private:
      std::stack<source_pos::off_type> m_columns;
      typedef typename std::basic_string<char_type>::size_type size_type;
      source_pos::off_type m_row;
      size_type m_cursor;
      std::basic_string<char_type> m_buffer;
      std::basic_string<char_type> m_terminator;
      bool m_eof;

   };

}}//quan::lexer

#endif

