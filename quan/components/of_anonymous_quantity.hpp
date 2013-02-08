#ifndef QUAN_ANONYMOUS_QUANTITY_HPP_INCLUDED
#define QUAN_ANONYMOUS_QUANTITY_HPP_INCLUDED

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

//anonymous_quantity to match named quantities

namespace quan{namespace meta{ namespace components{

  template <typename FixedQuantity>
   struct of_anonymous_quantity{
      template<typename CharType>
      static const CharType* unprefixed_symbol(); // undefined
      static const char* abstract_quantity_name()
      {
         return "anonymous_quantity";
      }
      typedef typename FixedQuantity::unit::abstract_quantity abstract_quantity;
      typedef typename abstract_quantity::dimension dimension;

      typedef of_anonymous_quantity type;
   };

}}}

#endif
