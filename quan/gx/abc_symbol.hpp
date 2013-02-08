#ifndef QUAN_GX_ABC_SCALAR_SYMBOL_HPP_INCLUDED
#define QUAN_GX_ABC_SCALAR_SYMBOL_HPP_INCLUDED

namespace quan{ namespace gx{

   template <typename T>
   struct abc_symbol{

      virtual ~abc_symbol(){}
      virtual T&  ref()=0;
      virtual T const &  cref() const=0;
      virtual std::string name() const=0;
      virtual std::string text() const=0;
      virtual T const &  min() const=0;
      virtual T const &  max() const=0;
      
   };

}}

#endif // QUAN_GX_ABC_SCALAR_SYMBOL_HPP_INCLUDED
