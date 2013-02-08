#ifndef QUAN_FUN_OUTPUT_HPP_INCLUDED
#define QUAN_FUN_OUTPUT_HPP_INCLUDED

#include <iostream>
#include <string>
namespace quan{ namespace fun{namespace detail{

   template <typename CharType>
   struct output_{
      std::basic_ostream<CharType> & os;
      std::basic_string<CharType> sep;
      output_(
         std::basic_ostream<CharType> & os_in,
         std::basic_string<CharType> const & sep_in
      ):os(os_in), sep(sep_in){}

      template <typename T>
      struct result{
         typedef std::basic_ostream<CharType> & type;
      };

      template <typename T>
      typename result<T>::type
      operator()(T const & t)const
      {
         return os << t << sep;
      }
      private:
      output_ & operator =( output_& in);
   };
   }//detail

   template <typename CharType>
   inline
   detail::output_<CharType>
   output(std::basic_ostream<CharType>& os, std::basic_string<CharType>const & sep)
   {
      return detail::output_<CharType>(os,sep);
   }

   template <typename CharType>
   inline
   detail::output_<CharType>
   output(std::basic_ostream<CharType>& os, CharType const * sep)
   {
      return detail::output_<CharType>(os,sep);
   }

   template <typename CharType>
   inline
   detail::output_<CharType>
   output(std::basic_ostream<CharType>& os, CharType  sep)
   {
      std::basic_string<CharType> ss;
      ss += sep;
      return detail::output_<CharType>(os,ss);
   }

}}//quan::fun

#endif

