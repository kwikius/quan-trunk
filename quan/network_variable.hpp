#ifndef QUAN_NETWORK_VARIABLE_HPP_INCLUDED
#define QUAN_NETWORK_VARIABLE_HPP_INCLUDED

#include <quan/byte_order.hpp>

namespace quan{
/*
 saved in network byte order
 accessed as host byte order
 This works since inevitably its coverted to a void* and a size for transport over the network
*/
   template <typename T>
   struct network_variable{
      network_variable(T v):m_value{ quan::detail::host_to_network<T>{}(v)}{}
      network_variable():m_value{}{}
      operator T() const
      { 
         return quan::detail::network_to_host<T>{}(m_value);
      }

      network_variable & operator = (T v)
      { 
         m_value = quan::detail::host_to_network<T>{}(v);
         return *this;
      }
      private:
      T m_value;
   };
}

#endif // QUAN_NETWORK_VARIABLE_HPP_INCLUDED
