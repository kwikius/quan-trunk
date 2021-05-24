#ifndef QUAN_BYTE_ORDER_HPP_INCLUDED
#define QUAN_BYTE_ORDER_HPP_INCLUDED

#include <arpa/inet.h>
#include <cstdint>

#include <quan/where.hpp>
#include <quan/meta/is_fixed_quantity.hpp>
#include <quan/meta/is_angle.hpp>
#include <quan/meta/or.hpp>

namespace quan{

   inline uint32_t hton_u32(uint32_t hostlong)
   {
      return ::htonl(hostlong);
   }

   inline uint32_t ntoh_u32(uint32_t netlong)
   {
      return ::ntohl(netlong);
   }

   inline int32_t ntoh_i32(int32_t hostlong)
   {
      return (int32_t)(::ntohl((uint32_t)(hostlong)));
   }

   inline int32_t hton_i32(int32_t hostlong)
   {
      return (int32_t)(::htonl((uint32_t)(hostlong)));
   }

   inline uint16_t hton_u16(uint16_t hostshort)
   {
      return ::htons(hostshort);
   }

   inline int16_t hton_i16(int16_t hostshort)
   {
      return (int16_t)(::htons((uint16_t)(hostshort)));
   }

   inline uint16_t ntoh_u16(uint16_t netshort)
   {
      return ::ntohs(netshort);
   }

   inline int16_t ntoh_i16(int16_t hostshort)
   {
      return (int16_t)(::ntohs((uint16_t)(hostshort)));
   }

   inline double hton_f64(double x)	
   {
       static_assert(sizeof(int) == 4,"");
       static_assert(sizeof(double) == 8,""); 
     
       int * p = (int*)&x;
       int tmp = p[0];
       p[0] = ::htonl(p[1]);
       p[1] = ::htonl(tmp);

       return x;
   }

   inline double ntoh_f64(double x)	
   {
       static_assert(sizeof(int) == 4,"");
       static_assert(sizeof(double) == 8,""); 
     
       int * p = (int*)&x;
       int tmp = p[0];
       p[0] = ::ntohl(p[1]);
       p[1] = ::ntohl(tmp);

       return x;
   }

   inline float hton_f32(float x)	
   {
       static_assert(sizeof(int32_t) == 4,"");
       static_assert(sizeof(float) == 4,""); 

       int32_t * p = (int32_t *)&x;
       *p = ::htonl(*p);
       return x;
   }

   inline float ntoh_f32(float x)	
   {
       static_assert(sizeof(int) == 4,"");
       static_assert(sizeof(float) == 4,""); 

       int32_t * p = (int32_t *)&x;
       *p = ::ntohl(*p);
       return x;
   }

   namespace detail{

      template <typename T, typename Where = void>
      struct host_to_network;

      template <typename T, typename Where = void>
      struct network_to_host;

      template <> struct host_to_network<uint32_t>
      {
         uint32_t operator()(uint32_t v) const
         {
            return quan::hton_u32(v);
         }
      };

      template <> struct host_to_network<int32_t>
      {
         int32_t operator()(int32_t v) const
         {
            return quan::hton_i32(v);
         }
      };

      template <> struct network_to_host<uint32_t>
      {
         uint32_t operator()(uint32_t v) const
         {
            return quan::ntoh_u32(v);
         }
      };

      template <> struct network_to_host<int32_t>
      {
         int32_t operator()(int32_t v) const
         {
            return quan::ntoh_i32(v);
         }
      };

      template <> struct host_to_network<uint16_t>
      {
         uint16_t operator()(uint16_t v) const
         {
            return quan::hton_u16(v);
         }
      };

      template <> struct host_to_network<int16_t>
      {
         int16_t operator()(int16_t v) const
         {
            return quan::hton_i16(v);
         }
      };

      template <> struct network_to_host<uint16_t>
      {
         uint16_t operator()(uint16_t v) const
         {
            return quan::ntoh_u16(v);
         }
      };

      template <> struct host_to_network<float>
      {
         float operator()(float v) const
         {
            return quan::hton_f32(v);
         }
      };

      template <> struct network_to_host<float>
      {
         float operator()(float v) const
         {
            return quan::ntoh_f32(v);
         }
      };

      template <> struct host_to_network<double>
      {
         double operator()(double v) const
         {
            return quan::hton_f64(v);
         }
      };

      template <> struct network_to_host<double>
      {
         double operator()(double v) const
         {
            return quan::ntoh_f64(v);
         }
      };


   template <typename T>
   struct host_to_network<
      T, 
      typename quan::where_<
         quan::meta::or_<
            quan::meta::is_fixed_quantity<T>,
            quan::meta::is_angle<T>,
            quan::meta::is_incoherent_temperature<T>
         >
     >::type
   >{

      T operator()(T v) const
      {
         return T{host_to_network<typename T::value_type>{}(v.numeric_value())};
      }
   };

   template <typename T>
   struct network_to_host<
      T,
      typename quan::where_<
         quan::meta::or_<
            quan::meta::is_fixed_quantity<T>,
            quan::meta::is_angle<T>,
            quan::meta::is_incoherent_temperature<T>
         >
     >::type
   >{

      T operator()(T v) const
      {
         return T{network_to_host<typename T::value_type>{}(v.numeric_value())};
      }
   };

}}//quan::detail


#endif // QUAN_BYTE_ORDER_HPP_INCLUDED
