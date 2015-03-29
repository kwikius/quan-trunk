#ifndef QUAN_STM32_FLASH_FLASH_TYPE_TAGS_HPP_INCLUDED
#define QUAN_STM32_FLASH_FLASH_TYPE_TAGS_HPP_INCLUDED

#include <cstdint>
#include <quan/three_d/vect.hpp>

namespace quan { namespace stm32{ namespace flash{

   enum flash_type_tags { 
         Bool 
         ,Float
         ,Int8
         ,Int16
         ,Int32
         ,Uint8
         ,Uint16
         ,Uint32
         ,Vect3I32  
         ,Vect3F
         ,NumTypeTags
     }; // Use NumTypeTags to check array sizes etc

   // use these local templates to map types to ids and vice versa
   template <typename T> struct type_to_flash_id;
   template <uint32_t id> struct flash_id_to_type;

    //--------- for Bool
   template <> struct type_to_flash_id<bool> {
      static constexpr uint32_t value = flash_type_tags::Bool;
   };
   template <> struct flash_id_to_type<flash_type_tags::Bool>{
      typedef bool type;
   };

   //--------- for Float
   template <> struct type_to_flash_id<float> {
      static constexpr uint32_t value = flash_type_tags::Float;
   };
   template <> struct flash_id_to_type<flash_type_tags::Float>{
      typedef float type;
   };

    //--------- for Int8
   template <> struct type_to_flash_id<int8_t> {
      static constexpr uint32_t value = flash_type_tags::Int8;
   };
   template <> struct flash_id_to_type<flash_type_tags::Int8>{
      typedef int8_t type;
   };

    //--------- for Int16
   template <> struct type_to_flash_id<int16_t> {
      static constexpr uint32_t value = flash_type_tags::Int16;
   };
   template <> struct flash_id_to_type<flash_type_tags::Int16>{
      typedef int16_t type;
   };
   
    //--------- for Int32
   template <> struct type_to_flash_id<int32_t> {
      static constexpr uint32_t value = flash_type_tags::Int32;
   };
   template <> struct flash_id_to_type<flash_type_tags::Int32>{
      typedef int32_t type;
   };

    //--------- for Uint8
   template <> struct type_to_flash_id<uint8_t> {
      static constexpr uint32_t value = flash_type_tags::Uint8;
   };
   template <> struct flash_id_to_type<flash_type_tags::Uint8>{
      typedef uint8_t type;
   };

    //--------- for Uint16
   template <> struct type_to_flash_id<uint16_t> {
      static constexpr uint32_t value = flash_type_tags::Uint16;
   };
   template <> struct flash_id_to_type<flash_type_tags::Uint16>{
      typedef uint16_t type;
   };
   
    //--------- for Uint32
   template <> struct type_to_flash_id<uint32_t> {
      static constexpr uint32_t value = flash_type_tags::Uint32;
   };
   template <> struct flash_id_to_type<flash_type_tags::Uint32>{
      typedef uint32_t type;
   };

   //--------- for Vect3I32
   template <> struct type_to_flash_id<quan::three_d::vect<int32_t> > {
      static constexpr uint32_t value = flash_type_tags::Vect3I32;
   };
   template <> struct flash_id_to_type<flash_type_tags::Vect3I32>{
      typedef quan::three_d::vect<int32_t> type;
   };

   //--------- for Vect3F
   template <> struct type_to_flash_id<quan::three_d::vect<float> > {
      static constexpr uint32_t value = flash_type_tags::Vect3F;
   };
   template <> struct flash_id_to_type<flash_type_tags::Vect3F>{
      typedef quan::three_d::vect<float> type;
   };

   template <typename T> inline uint32_t get_flash_typeid(){ return type_to_flash_id<T>::value;}

}}}


#endif // QUAN_STM32_FLASH_FLASH_TYPE_TAGS_HPP_INCLUDED
