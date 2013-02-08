#ifndef QUAN_GX_SCALAR_SYMBOL_VALUE_HPP_INCLUDED
#define QUAN_GX_SCALAR_SYMBOL_VALUE_HPP_INCLUDED

#include <string>
#include <quan/gx/abc_symbol.hpp>
/*
  a value with name min max etc.
*/

namespace quan{ namespace gx{

   template <typename T>
   struct symbol_value : abc_symbol<T>{
      symbol_value(
        std::string const & name, 
        std::string const & text, // dependent on num space sepped values
       T const& value, T const & min, T const & max)
      :m_name(name),m_text(text),m_value(value),m_min(min),m_max(max){}
      T&  ref(){return m_value;};
      T const &  cref() const{return m_value;};
      std::string name() const { return m_name;};
      T const &  min()const{ return m_min;};
      T const &  max() const{ return m_max;};
      std::string text()const { return m_text;}

   private:
      std::string m_name;
      std::string m_text;
      T m_value;
      T m_min;
      T m_max;
   };

}}


#endif // QUAN_GX_SYMBOL_VALUE_HPP_INCLUDED
