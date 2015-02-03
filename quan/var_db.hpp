#ifndef QUAN_VAR_DB_HPP_INCLUDED
#define QUAN_VAR_DB_HPP_INCLUDED
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

#include <map>
#include <string>
#include <fstream>
#include <quan/lexer/file_error.hpp>
#include <quan/lexer/file_stream.hpp>
#include <quan/lexer/string_stream.hpp>

namespace quan{

      struct var_db{

         typedef std::map<std::string,std::string> vars_map_type;
         var_db():m_writeable(true){}
      
         var_db(std::string const & file):m_filename(file),m_writeable(false)
         {
            quan::lexer::file_istream<char> res(file);
            
            if( ! res.good()){
               throw quan::lexer::file_error<char>(
                  res,"cant open resource \"" + file + "\"");
            }

            std::string str;
            while (res.getline(str)){
               quan::lexer::string_istream<char>ss(file,str);

               typedef quan::lexer::file_error<char> file_error;

               do_opt_space(ss);
               if ( ss.eof() ){
                  continue;
               }
               char ch;

               ss.get(ch);
               if (ch != '"'){
                  throw file_error(res," resource \"" + file + "\" , expected opening '\"'");
               }
               ss.get(ch);
               std::string key;
               while ( (! ss.eof()) && (ch != '"')){
                  key += ch;
                  ss.get(ch);
               }
               if (ss.eof() ){
                  throw file_error(res," resource \"" + file + "\" , expected closing '\"'");
               }
               do_opt_space(ss);

               ss.get(ch);
              
               if (ch != '"'){
                  throw file_error(res," resource \"" + file + "\" , expected opening '\"'");
               }
               std::string value;
               ss.get(ch);
               while ( (! ss.eof()) && (ch != '"')){
                  value += ch;
                  ss.get(ch);
               }
               if (ss.eof() ){
                  throw file_error(res," resource \"" + file + "\" , expected closing '\"'");
               }
               vars_map_type::iterator riter = m_vars_map.find(key);
               if( riter != m_vars_map.end()){
                  throw file_error(res,"resource duplicate key: \"" + key + "\"");
               }
               m_vars_map[key]= value;
            }
            return;
         }

         template <typename T>
         void get(std::string const & key,T& ref )const
         {
            vars_map_type::const_iterator iter = m_vars_map.find(key);
            if( iter == m_vars_map.end()){
               throw std::runtime_error("input from db \"" + m_filename + "\" failed on \"" + key + "\"");
            }
            std::string str = iter->second;
            std::istringstream istr(str);
            istr >> ref;
            if (istr.bad()){
               throw std::runtime_error("input from db \"" + m_filename + "\" failed on \"" + key + "\"");
            }
            return ;
         }

         bool has_item(std::string const & key)const
         {
            vars_map_type::const_iterator iter = m_vars_map.find(key);
            if( iter == m_vars_map.end()){
               return false;
            }
         }

         template <typename T>
         T get(std::string const & key)const
         {
            vars_map_type::const_iterator iter = m_vars_map.find(key);
            if( iter == m_vars_map.end()){
               throw std::runtime_error("input from db \"" + m_filename + "\" failed on \"" + key + "\"");
            }
            std::string str = iter->second;
            std::istringstream istr(str);
            T val;
            istr >> val;
            if (istr.bad()){
               throw std::runtime_error("input from db \"" + m_filename + "\" failed on \"" + key + "\"");
            }
            return val;
         }

         template <typename T>
         void set(std::string const & name,T const & value)
         {
               std::ostringstream ost;
               ost << value;
               m_vars_map[name] = ost.str();
         }
         void set_read_only()
         {
            m_writeable = false;
         }
         void set_writeable()
         {
             m_writeable = true;
         }
         void write_to_file()const
         {
            if (!m_writeable){
                throw std::runtime_error("db write to file(inputfile)"
                  ": readonly is set on  \"" + m_filename + "\"");
            }
           
            write_to_file_impl(m_filename);
         }
         void write_to_file(std::string const & filename )const
         {
            if ((m_filename == filename) && !m_writeable){
                throw std::runtime_error("db write to file(inputfile)"
                  ": readonly is set on  \"" + filename + "\"");
            }
            
            write_to_file_impl(filename);
         }
         private:

         void write_to_file_impl(std::string const & filename)const
         {
                     
            std::ofstream res(filename.c_str());
            
            if( ! res.good()){
               throw std::runtime_error("db: file failed cant write resource \"" + filename + "\"");
            }
            for (vars_map_type::const_iterator iter = m_vars_map.begin();
            iter != m_vars_map.end();
               ++iter){
               res << '"' << iter->first << "\" \"" << iter->second << "\"\n" ;
            }
            
         }

         vars_map_type m_vars_map;
         std::string m_filename;
         bool m_writeable;
      };
}

#endif
