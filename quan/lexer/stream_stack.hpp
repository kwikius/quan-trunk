#ifndef QUAN_LEXER_ISTREAM_STACK_HPP_INCLUDED
#define QUAN_LEXER_ISTREAM_STACK_HPP_INCLUDED
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
#include <quan/smart/gc_ptr.hpp>
#include <quan/smart/lazy_ptr.hpp>
#include <stack>

namespace quan{ namespace lexer{

   template <typename CharType>
   struct istream_stack : istream<CharType>{

      typedef quan::smart::gc_ptr<istream<CharType> > stream_ptr;
private:
      typedef std::stack<stream_ptr> stack_type;
      typedef quan::smart::lazy_ptr<istream<CharType> > stream_lazy_ptr;
      stack_type m_stack;
public:
      void push(stream_ptr const & in)
      {
         if (m_stack.size() !=0){
            stream_lazy_ptr cur = m_stack.top();
            cur->suspend();
         }
         m_stack.push(in);
      }

public:
      istream_stack& get(char_type& ch)
      {
         if (m_stack.size() ==0){
            throw underflow("stream stack underflow in get");
         }
         stream_lazy_ptr cur = m_stack.top();
         cur->get(ch);
         if( cur->eof()){
            m_stack.pop();
            if (m_stack.size() !=0){
              cur = m_stack.top();
              cur->resume();
            }
         }
        
         return *this;
      }
//cant putback through strem
		istream_stack& putback()
      {
         if(m_stack.size() > 0){
            m_stack.top()->putback();
            return *this;
         }
         throw underflow("stream stack underflow in putback");
      }

		int_type peek()
      {
         if (m_stack.size() == 0){
            return eof_char();
         }
         else {
            stack_type t_stack;
            int_type i = eof_char();
            while ( m_stack.size() !=0){
               stream_lazy_ptr cur = m_stack.top();
               i = cur->peek();
               if ( i != eof_char()){
                  break;
               }
               else{
                  if ( t_stack.size() ==0){
                   cur->suspend();
                  }
                  t_stack.push(cur);
                  m_stack.pop();
               }
            }

            while (t_stack.size() != 0){
               stream_lazy_ptr cur = t_stack.top();
               m_stack.push(cur);
               t_stack.pop();
               if ( t_stack.size() ==0){
                  cur->resume();
               }
            }           
            return i;
         }
      }

	   source_pos get_source_pos()const
      {
         if (m_stack.size()==0){
            return source_pos(  
               static_cast<source_pos::off_type>(0),
               static_cast<source_pos::off_type>(0)
            );
         }
         else{
             stream_lazy_ptr cur = m_stack.top();
             return cur->get_source_pos();
         }
      } 
      std::string get_stream_id() const
      {
         if (! m_stack.size()){
            return "stream_stack";
         }
         else{
             stream_lazy_ptr cur = m_stack.top();
             return cur->get_stream_id();
         }
      }
      bool eof(){
         while(m_stack.size() !=0){
            stream_lazy_ptr cur = m_stack.top();
            if ( cur->eof()){
               m_stack.pop();
               if ( m_stack.size() ==0){
                  return true;
               }
               else{
                  m_stack.top()->resume();
               }
            }
            else {
               return false;
            }
         }
         return true;
      }
      bool good()
      {
         if (! m_stack.size()){
            return false;
         }
         else {
            return m_stack.top()->good();
         }
      }
      bool bad()
      {
         if (! m_stack.size()){
            return false;
         }
         else {
            return m_stack.top()->bad();
         }
      }
      bool fail()
      {
         if (! m_stack.size()){
            return true;
         }
         else {
            return m_stack.top()->fail();
         }
      }
   };
}}

#endif
