#ifndef QUAN_CONVERSION_TYPE_TO_NAME_HPP_INCLUDED
#define QUAN_CONVERSION_TYPE_TO_NAME_HPP_INCLUDED

#include <cstdint>
#include <quan/three_d/vect_def.hpp>

namespace quan{

    template <typename T> struct type_to_name;

   #define QUAN_TYPE_TO_NAME(T) template <> struct type_to_name<T>{ \
        static  constexpr const char* apply() {return #T ;} \
   };
    
   QUAN_TYPE_TO_NAME(bool)
   QUAN_TYPE_TO_NAME(float)
   QUAN_TYPE_TO_NAME(double)
   QUAN_TYPE_TO_NAME(char)
   QUAN_TYPE_TO_NAME(int8_t)
   QUAN_TYPE_TO_NAME(int16_t)
   QUAN_TYPE_TO_NAME(int32_t)
   QUAN_TYPE_TO_NAME(int64_t)
   QUAN_TYPE_TO_NAME(uint8_t)
   QUAN_TYPE_TO_NAME(uint16_t)
   QUAN_TYPE_TO_NAME(uint32_t)
   QUAN_TYPE_TO_NAME(uint64_t)
   #undef QUAN_QUAN_TYPE_TO_NAME
   // technically not array... but we will see!
   template <> struct type_to_name<quan::three_d::vect<float> >{
      static constexpr  const char* apply() { return "float[3]";}
   };
   template <> struct type_to_name<quan::three_d::vect<int32_t> >{
      static constexpr  const char* apply() { return "int32_t[3]";}
   };
}

#endif // QUAN_CONVERSION_TYPE_TO_NAME_HPP_INCLUDED
