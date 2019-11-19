#ifndef QUAN_FIXED_QUANTITY_LITERAL_HPP_INCLUDED
#define QUAN_FIXED_QUANTITY_LITERAL_HPP_INCLUDED

#include <quan/config.hpp>

   #define QUAN_QUANTITY_REAL_LITERAL(QuantityName,UnitSuffix)  \
   constexpr inline quan:: QuantityName :: UnitSuffix operator "" _ ## UnitSuffix ( long double v) \
   { \
      return quan:: QuantityName :: UnitSuffix {static_cast<QUAN_FLOAT_TYPE>(v)}; \
   } 

   #define QUAN_QUANTITY_LITERAL(QuantityName,UnitSuffix)  \
   constexpr inline quan:: QuantityName :: UnitSuffix operator "" _ ## UnitSuffix ( long double v) \
   { \
      return quan:: QuantityName :: UnitSuffix {static_cast<QUAN_FLOAT_TYPE>(v)}; \
   } \
\
   constexpr inline quan:: QuantityName ## _<int32_t>:: UnitSuffix operator "" _ ## UnitSuffix ( unsigned long long int v) \
   { \
      return quan:: QuantityName ## _<int32_t>:: UnitSuffix {static_cast<int32_t>(v)}; \
   } \
\
   constexpr inline quan:: QuantityName ## _<uint32_t>:: UnitSuffix operator "" _ ## UnitSuffix ## _U ( unsigned long long int v) \
   { \
      return quan:: QuantityName ## _<uint32_t>:: UnitSuffix {static_cast<uint32_t>(v)}; \
   } 

#endif // QUAN_FIXED_QUANTITY_LITERAL_HPP_INCLUDED
