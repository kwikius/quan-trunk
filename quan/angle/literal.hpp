#ifndef QUAN_ANGLE_LITERAL_HPP_INCLUDED
#define QUAN_ANGLE_LITERAL_HPP_INCLUDED

   #define QUAN_ANGLE_LITERAL(UnitSuffix)  \
   constexpr inline quan::angle:: UnitSuffix operator "" _ ## UnitSuffix ( long double v) \
   { \
      return quan::angle:: UnitSuffix {static_cast<double>(v)}; \
   } \
\
   constexpr inline quan::angle_<int32_t>:: UnitSuffix operator "" _ ## UnitSuffix ( unsigned long long int v) \
   { \
      return quan::angle_<int32_t>:: UnitSuffix {static_cast<int32_t>(v)}; \
   }


#endif // QUAN_ANGLE_LITERAL_HPP_INCLUDED
