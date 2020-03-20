#ifndef INTEGER_HPP_INCLUDED
#define INTEGER_HPP_INCLUDED
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

#include <quan/config.hpp>
#if !defined QUAN_NO_EXCEPTIONS
#include <cstdint>
#include <type_traits>

#include <stdexcept>

#include <quan/where.hpp>
#include <quan/implicit_cast.hpp>
#include <quan/meta/signed_unsigned.hpp>
#include <quan/meta/integer_max.hpp>
#include <limits>

/* 
 range checked int throws range_error on ops if result is out of range
 
 check first with is_well_formed()
 also check after construction
 int may be signed or unsigned but currently must be 32 bts or less
*/

#include <quan/meta/binary_op.hpp>
#include <quan/meta/integer_max.hpp>
#include <quan/meta/gt.hpp>
#include <quan/meta/or.hpp>
#include <quan/meta/or.hpp>
#include <quan/meta/identity.hpp>
#include <quan/meta/signed_unsigned.hpp>

namespace quan{

    template <typename Int>
    struct integer;

}

namespace quan { namespace meta {

  namespace impl {
  template <typename I, typename Op>
     struct binary_op_impl<
         quan::integer<I>, Op,quan::integer<I> ,
         typename quan::where_<not_<is_assignment_operator<Op> > >::type
     > : identity <quan::integer<I> >{};
  }
      
}}

namespace quan{
   //
   template <typename Int>
   struct integer {
      bool is_well_formed() const   
      {
        return ! m_out_of_range;
      }
      typedef Int int_type;
      typedef int64_t internal_type;
      typedef typename quan::meta::to_unsigned<
         int_type
      >::type unsigned_int_type;
      static_assert(std::is_integral<Int>::value,"Int must be integral");
      static_assert( (quan::meta::integer_max<unsigned_int_type>::value) 
         <= (quan::meta::integer_max<int32_t>::value),
             "Int size must be <= that of int32_t");
      // mask for low bits
      static const internal_type bitmask 
         = static_cast<uint64_t>((static_cast<unsigned_int_type>(-1)));
      
     // prevent conversions
      template<typename T>
      integer ( T const & in,  typename quan::where_<
          std::is_same<T,int32_t>, void*
       >::type = 0 ) :  m_value{in},m_out_of_range{false}
     {
       range_check();
     }

      integer & operator = ( integer const & in)
      {
         m_value = in.m_value;
         range_check();
         throw_on_out_of_range();
         return *this;
      }

      integer & operator *= ( integer const & in)
      {
         throw_on_out_of_range();
         m_value *= in.m_value;
         range_check();
         return *this;
      }
      integer operator *(integer rhs)const
      {
         integer temp = *this;
         temp *= rhs;
         return temp;
      }

      integer & operator /= ( integer const & in)
      {
         throw_on_out_of_range();
         m_value /= in.m_value;
         return *this;
      }
      integer operator /(integer rhs)const
      {
         integer temp = *this;
         temp /= rhs;
         return temp;
      }

      integer & operator %= ( integer const & in)
      {
         throw_on_out_of_range();
         m_value %= in.m_value;
         return *this;
      }
      integer operator %(integer rhs)const
      {
         integer temp = *this;
         temp %= rhs;
         return temp;
      }

      integer & operator += ( integer const & in)
      {
         throw_on_out_of_range();
         m_value += in.m_value;
         range_check();
         return *this;
      }

      integer operator +(integer rhs) const
      {
         integer temp = *this;
         temp += rhs;
         return temp;
      }
     

      integer & operator -= ( integer const & in)
      {
         throw_on_out_of_range();
         m_value -= in.m_value;
         range_check();
         return *this;
      }

      integer operator -(integer rhs)const
      {
         integer temp = *this;
         temp -= rhs;
         return temp;
      }

      integer & operator <<= ( integer const & in)
      {
          throw_on_out_of_range();
         m_value <<= in.m_value;
         //remove high bits
         m_value  &= bitmask;
         return *this;
      }
      integer operator <<(integer rhs)const
      {
         integer temp = *this;
         temp <<= rhs;
         return temp;
      }

      integer & operator >>= ( integer const & in)
      {
         throw_on_out_of_range();
         m_value  &= bitmask;
         m_value  >>= in.m_value;
         return *this;
      }
      integer operator >>(integer rhs)const
      {
         integer temp = *this;
         temp >>= rhs;
         return temp;
      }

      integer & operator &= ( integer const & in)
      {
         throw_on_out_of_range();
         m_value &= in.m_value;
         return *this;
      }
      integer operator &(integer rhs)const
      {
         integer temp = *this;
         temp &= rhs;
         return temp;
      }

      integer & operator ^= ( integer const & in)
      {
         throw_on_out_of_range();
         m_value ^= in.m_value;
         m_value &= bitmask;
         return *this;
      }
      integer operator ^(integer rhs)const
      {
         integer temp = *this;
         temp ^= rhs;
         return temp;
      }

      integer & operator |= ( integer const & in)
      {
         throw_on_out_of_range();
         m_value |= in.m_value;
         return *this;
      }

      integer operator |(integer rhs)const
      {
         integer temp = *this;
         temp |= rhs;
         return temp;
      }

      bool operator < (integer const & rhs)const
      {
         throw_on_out_of_range();
         rhs.throw_on_out_of_range();
        return this->m_value < rhs.m_value;
      }
      bool operator <= (integer const & rhs)const
      {
         throw_on_out_of_range();
         rhs.throw_on_out_of_range();
        return this->m_value <= rhs.m_value;
      }
      bool operator == (integer const & rhs)const
      {
        throw_on_out_of_range();
        rhs.throw_on_out_of_range();
        return this->m_value == rhs.m_value;
      }
      bool operator != (integer const & rhs)const
      {
        throw_on_out_of_range();
        rhs.throw_on_out_of_range();
        return this->m_value != rhs.m_value;
      }
      bool operator >= (integer const & rhs)const
      {
        throw_on_out_of_range();
        rhs.throw_on_out_of_range();
        return this->m_value >= rhs.m_value;
      }
      bool operator > (integer const & rhs)const
      {
        throw_on_out_of_range();
        rhs.throw_on_out_of_range();
        return this->m_value > rhs.m_value;
      }
      int64_t get_numeric_value() const { return m_value;}
     
     private:
        internal_type m_value ;
        bool m_out_of_range;
        void range_check()   
        {
           if  ( ( m_value > std::numeric_limits<int_type>::max())
               ||( m_value < std::numeric_limits<int_type>::min())
               ) {
                     m_out_of_range = true;
           }
           else{
              m_out_of_range = false;
           }
        }
        void throw_on_out_of_range() const
        {
#if defined QUAN_NO_EXCEPTIONS
         assert (!m_out_of_range);
#else
          if ( m_out_of_range){
            throw std::out_of_range("quan::integer out of range");
          }
#endif
        }
   };

  template <typename Int>
  inline
  std::ostream & operator << (std::ostream & os,integer<Int> const & val)
  {
    return os << val.get_numeric_value() << '\n';

  }
   
}//quan

#endif // QUAN_NO_EXCEPTIONS
#endif // INTEGER_HPP_INCLUDED
