#ifndef QUAN_LEXER_FILE_STREAM_HPP_INCLUDED
#define QUAN_LEXER_FILE_STREAM_HPP_INCLUDED
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

#include <quan/lexer/istream.hpp>
#include <quan/smart/gc_alloc.hpp>
#include <stack>
#include <cassert>
#include <fstream>

#include <iostream>

namespace quan{ namespace lexer{

   template<typename CharType>
   struct file_istream : istream<CharType>{
       typedef typename istream<CharType>::char_type char_type;
       typedef typename istream<CharType>::int_type int_type;

       struct bad_file : std::logic_error{
         bad_file(std::string const & str):std::logic_error(str){}
      };

      file_istream(std::string const & str)
      :  m_file_name(str),
         m_stream_ptr(quan::smart::gc_alloc<std::basic_ifstream<char_type> >(str.c_str())),
         m_row(0),
         m_column(0),
         m_cur_char(0),
         m_suspended_pos(0) //,
       //  m_is_suspended(false)
      {
         if( !m_stream_ptr){
            throw bad_file(" bad file::ptr in file_stream ctor with \"" + m_file_name + "\"");
         }
      }

      file_istream& get(char_type& ch)
      {
         m_stream_ptr->get(ch);
         m_cur_char = ch;
         if (m_cur_char == '\n'){
            ++ m_row;
            m_column_stack.push(m_column);
            m_column = 0;
         }
         else{
            ++m_column;
         }
         return *this;
      }

      file_istream& putback()
      {
         m_stream_ptr->unget();
         m_cur_char = static_cast<CharType>(m_stream_ptr->rdbuf()->sgetc());
         if (m_cur_char == '\n'){
            m_column = m_column_stack.top();
            m_column_stack.pop();
            -- m_row;
         }
         else{
            --m_column;
         }
         return *this;
      }

      int_type peek()
      {
         return m_stream_ptr->peek();
      }

      source_pos get_source_pos()const
      {
         return source_pos(
            static_cast<source_pos::off_type>(m_row+1),
            static_cast<source_pos::off_type>(m_column+1)
         );
      }
      std::string get_stream_id()const{ return m_file_name;}
      bool eof(){assert(m_stream_ptr); return m_stream_ptr->eof();}
      bool good(){return m_stream_ptr && m_stream_ptr->good();}
      bool bad()
      {
         if (! m_stream_ptr) return true;
         return  m_stream_ptr->bad();
      }
      bool fail()
      {
         if (! m_stream_ptr) return true;
         return  m_stream_ptr->fail();
      }
      void suspend()
      {
         if (! m_stream_ptr){
            throw std::logic_error("suspending non existent stream");
         }

         m_suspended_pos = m_stream_ptr->tellg();

       //  m_stream_ptr = quan::smart::gc_ptr<std::basic_ifstream<char_type> >();

        // std::cout << "\nsuspend at " << m_suspended_pos << "\n";

      }
      void resume()
      {
        // m_stream_ptr = quan::smart::gc_alloc<std::basic_ifstream<char_type> >(m_file_name.c_str());
         if( !m_stream_ptr){
            throw bad_file(" bad file::ptr in file_stream resume with \"" + m_file_name + "\"");
         }

        // m_stream_ptr->seekg(m_suspended_pos);

       //  std::cout << "\nresume at " << m_stream_ptr->tellg() << "\n";
         if ( m_stream_ptr->fail()){
            throw std::logic_error("resuming bad stream");
         }
      }
      bool getline(std::string & str)
      {
         return std::getline(*m_stream_ptr,str) !=0;
      }
   private:
      std::string m_file_name;
      quan::smart::gc_ptr<std::basic_ifstream<char_type> > m_stream_ptr;
      source_pos::off_type m_row;//first is 0
      std::string::size_type m_column;//first is 0
      CharType m_cur_char;
      std::stack<std::string::size_type> m_column_stack;
      typename std::basic_ifstream<char_type>::pos_type m_suspended_pos;
    //  bool suspended;

   };


}}//quan::lexer

#endif

