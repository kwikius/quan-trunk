#ifndef QUAN_META_NAME_ANONYMOUS_ABSTRACT_QUANTITY_HPP_INCLUDED
#define QUAN_META_NAME_ANONYMOUS_ABSTRACT_QUANTITY_HPP_INCLUDED

namespace quan{ namespace meta{

//default to no change
   template <typename AbstractQuantity>
   struct name_anonymous_abstract_quantity{
      typedef AbstractQuantity type;
   };

}}

#endif
