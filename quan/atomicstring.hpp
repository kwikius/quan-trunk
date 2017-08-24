#ifndef QUAN_ATOMICSTRING_HPP_INCLUDED
#define QUAN_ATOMICSTRING_HPP_INCLUDED
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

#include <iostream>
#include <map>

#include <quan/detail/c_str_wrapper.hpp>

namespace quan{

   template <typename CharType>
   struct atomicstring{
         
         struct idtable{
            
            typedef std::map<detail::cstr_wrapper<CharType>,CharType const *> maptype;

            maptype map;

            struct  item{
               item(CharType * alloc_in, item * next_in)
               :m_alloc(alloc_in),next(next_in){}
               CharType  * m_alloc;
               item* next;
            };
            item* list;
            ~idtable()
            {
#ifndef QUAN_BOEHM_GC
               while (list){
                  item * temp = list;
                  list = list->next;
                  delete [] temp->m_alloc;
                  delete temp;
               }
#endif
            }

            CharType const * add_item( CharType const * str)
            {
               size_t item_size = detail::get_strlen(str) +1; 
#ifdef QUAN_BOEHM_GC
              item * it = quan::gc_malloc<item>(quan::gc_array_malloc<CharType>(item_size),list);
#else
               item * it = new item(new CharType[item_size],list);
#endif
               list = it;
               detail::do_strcpy(it->m_alloc,str);
               map[detail::cstr_wrapper<CharType>(it->m_alloc)] = it->m_alloc;
               return it->m_alloc;
               
            }

            void print_items(std::basic_ostream<CharType> & out)
            {
               item * i = list;
               while(i){
                  out << i->m_alloc <<'\n';
                  i = i->next;
               }
                  
            }

            void print_map_items(std::basic_ostream<CharType> & out)
            {
               for( typename idtable::maptype::const_iterator i =symtable.map.begin();
                  i != symtable.map.end();++i){
                  out << i->second <<'\n';
               }
                  
            }

            idtable():list(0){
            }
            
         };
         atomicstring()
         {
            init("");
         }
         // default copy ctor and equals ok
         atomicstring(CharType const * in)
         {
           init(in);
         }
         atomicstring(std::basic_string<CharType> const & in)
         {
          init(in.c_str());
         }
         CharType const * get_rep() const
         {
            return rep;
         }
         CharType const * to_c_str() const
         {
            return rep;
         }

         operator std::basic_string<CharType>()const { return this->get_rep();}

         operator const CharType* ()const { return this->get_rep();}

         int cmp ( CharType const * str) const 
         {
             return  quan::detail::comp(quan::detail::cstr_wrapper<CharType>(rep),
                         quan::detail::cstr_wrapper<CharType>(str));
         }
         
      private:
       void init(CharType const * in)
       {
         detail::cstr_wrapper<CharType> id(in);
   
         typename idtable::maptype::const_iterator i = symtable.map.find(id);
         if( i != symtable.map.end()) {
            rep = i->second;
         }else{
            rep = symtable.add_item(in); 
         }
      }
      
      CharType const * rep;
      static idtable symtable;
   };

   template <typename CharType>
   inline 
   bool operator == (
      atomicstring<CharType> const & lhs,
      atomicstring<CharType> const & rhs
   ){
      return lhs.get_rep() == rhs.get_rep();
   }
   template <typename CharType>
   inline 
   bool operator == (
      atomicstring<CharType> const & lhs,
      CharType const * rhs
   ){
      return lhs.cmp(rhs) == 0;
   }
   template <typename CharType>
   inline 
   bool operator == (
      CharType const * lhs,
      atomicstring<CharType> const & rhs
   ){
      return rhs.cmp(lhs) == 0;
   }

   template <typename CharType>
   inline 
   bool operator == (
      atomicstring<CharType> const & lhs,
      std::basic_string<CharType> const & rhs
   ){
      return lhs.cmp(rhs.c_str()) == 0;
   }
   template <typename CharType>
   inline 
   bool operator == (
      std::basic_string<CharType> const & lhs,
      atomicstring<CharType> const & rhs
   ){
      return rhs.cmp(lhs.c_str()) == 0;
   }

   template <typename CharType>
   inline 
   bool operator != (
      atomicstring<CharType> const & lhs,
      atomicstring<CharType> const & rhs
   ){
      return lhs.get_rep() != rhs.get_rep();
   }

   template <typename CharType>
   inline 
   bool operator != (
      atomicstring<CharType> const & lhs,
      CharType const * rhs
   ){
      return lhs.cmp(rhs) != 0;
   }

   template <typename CharType>
   inline 
   bool operator != (
      CharType const * lhs,
      atomicstring<CharType> const & rhs
   ){
      return rhs.cmp(lhs) != 0;
   }

   template <typename CharType>
   inline 
   bool operator != (
      std::basic_string<CharType> const & lhs,
      atomicstring<CharType> const & rhs
   ){
      return rhs.cmp(lhs.c_str()) != 0;
   }

   template <typename CharType>
   inline 
   bool operator != (
      atomicstring<CharType> const & lhs,
      std::basic_string<CharType> const & rhs
   ){
      return lhs.cmp(rhs.c_str()) != 0;
   }
  

   template <typename CharType>
   inline 
   bool operator < (
      atomicstring<CharType> const & lhs,
      atomicstring<CharType> const & rhs
   ){
      return lhs.get_rep() < rhs.get_rep();
   }
  
   template <typename CharType>
   typename atomicstring<CharType>::idtable atomicstring<CharType>::symtable; 
              
   template <typename CharType>
   inline
   std::basic_ostream<CharType> & operator << (
         std::basic_ostream<CharType> & os, 
         atomicstring<CharType> const & atom
   ){
     return  os << atom.get_rep();
      
   }
}


#endif
