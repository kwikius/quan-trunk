#ifndef QUAN_TEXOUT_HPP_INCLUDED
#define QUAN_TEXOUT_HPP_INCLUDED
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

#include <quan/fixed_quantity/io/output.hpp>
#include <quan/out/angle.hpp>

namespace quan{

   namespace detail{

      struct tex_stream{
         tex_stream(std::ostream & os): m_os(os){}
         std::ostream & m_os;
         tex_stream(tex_stream& in): m_os(in.m_os){}
      };
     

      //outside math
      inline
      std::string tex_parse_units_str(std::string const & str)
      {
         std::string::const_iterator iter = str.begin(); 

         std::string result;
         while (iter != str.end()){
            if ( (*iter == '-') || (isdigit(*iter)) ){
               result += "$^{";
               if( *iter == '-'){
                  result += '-';
               }
               ++iter;
               while (isdigit(*iter)){
                  result += *iter;
                  ++iter;
               }
               result += "}$";
            }else{
               result += *iter;
               ++iter;
            }
         }
         return result;
      }

       struct mathtex_stream{
         mathtex_stream(std::ostream & os): m_os(os){}
         std::ostream & m_os;
         mathtex_stream(tex_stream& in): m_os(in.m_os){}
      };

      // in math
      inline
      std::string mathtex_parse_units_str(std::string const & str)
      {
         std::string::const_iterator iter = str.begin(); 

         std::string result;
         while (iter != str.end()){
            if ( (*iter == '-') || (isdigit(*iter)) ){
               result += "^{";
               if( *iter == '-'){
                  result += '-';
               }
               ++iter;
               while (isdigit(*iter)){
                  result += *iter;
                  ++iter;
               }
               result += "}";
            }else{
               result += *iter;
               ++iter;
            }
         }
         return result;
      }

      template <typename U, typename V>
      inline
      typename quan::where_<
         quan::meta::is_si<U>,
         std::ostream &
      >::type
      operator << ( tex_stream s, fixed_quantity<U,V> const & q)
      {
         s.m_os << q.numeric_value() << " " << tex_parse_units_str(units_str(q));
         return s.m_os;
      } 

       template <typename U, typename V>
      inline
      typename quan::where_<
         quan::meta::is_si<U>,
         std::ostream &
      >::type
      operator << ( mathtex_stream s, fixed_quantity<U,V> const & q)
      {
         s.m_os << q.numeric_value() << " " << mathtex_parse_units_str(units_str(q));
         return s.m_os;
      } 

      template <typename U, typename V>
      inline
      typename quan::where_<
         quan::meta::not_<quan::meta::is_si<U> >,
         std::ostream &
      >::type
      operator << ( tex_stream s, fixed_quantity<U,V> const & q)
      {
         s.m_os << q.numeric_value() << " " << units_str(q);
         return s.m_os;
      } 

      template <typename U, typename V>
      inline
      typename quan::where_<
         quan::meta::not_<quan::meta::is_si<U> >,
         std::ostream &
      >::type
      operator << ( mathtex_stream s, fixed_quantity<U,V> const & q)
      {
         s.m_os << q.numeric_value() << " " << units_str(q);
         return s.m_os;
      } 

      inline std::ostream &
      operator << (tex_stream s, quan::angle::deg const & a)
      {
         s.m_os << a.numeric_value() << " $^{o}$";
         return s.m_os;
      }

      inline std::ostream &
      operator << (mathtex_stream s, quan::angle::deg const & a)
      {
         s.m_os << a.numeric_value() << " ^{o}";
         return s.m_os;
      }

      template <typename T>
      inline 
      typename quan::where_<
         std::is_arithmetic<T>,
         std::ostream &
      >::type
      operator << (tex_stream s, T const & v)
      {
         s.m_os << v;
         return s.m_os;
      }

      template <typename T>
      inline 
      typename quan::where_<
         std::is_arithmetic<T>,
         std::ostream &
      >::type
      operator << (mathtex_stream s, T const & v)
      {
         s.m_os << v;
         return s.m_os;
      }
      
      struct tex{};
      struct mathtex{};

      tex_stream operator << (std::ostream & os, tex const & t)
      {
         return tex_stream(os);
      }

      mathtex_stream operator << (std::ostream & os, mathtex const & t)
      {
         return mathtex_stream(os);
      }
  
   }//detail

}
  extern  quan::detail::tex tex;
  extern  quan::detail::mathtex mathtex;

#endif
