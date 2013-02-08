#ifndef QUAN_GX_SCALAR_SYMBOL_REF_HPP_INCLUDED
#define QUAN_GX_SCALAR_SYMBOL_REF_HPP_INCLUDED

#include <string>
#include <cassert>
#include <quan/gx/abc_symbol.hpp>

namespace quan{ namespace gx{

   template <typename T>
   struct symbol_ref : abc_symbol<T>{
      symbol_ref(
        std::string const & name, 
        std::string const & text, // dependent on num space sepped values
       T& ref, T const & min, T const & max)
      :m_name(name),m_text(text),m_ref(ref),m_min(min),m_max(max){}
      T&  ref(){return m_ref;};
      T const &  cref() const{return m_ref;};
      std::string name() const { return m_name;};
      T const &  min()const{ return m_min;};
      T const &  max() const{ return m_max;};
      std::string text()const { return m_text;}
   private:
      std::string m_name;
      std::string m_text;
      T & m_ref;
      T m_min;
      T m_max;
      
   };

}}


#endif // QUAN_GX_SYMBOL_HPP_INCLUDED
