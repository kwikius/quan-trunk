#ifndef QUAN_BLE_UUID_HPP_INCLUDED
#define QUAN_BLE_UUID_HPP_INCLUDED

#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <cctype>

namespace quan{
  
   namespace ble{

      namespace detail{

         inline void ll_copy_uuid_str_to_ar( const char* & uuid_substr, int decr, uint8_t * & out)
         {
           char ar[5] ;
           strncpy(ar,uuid_substr,4);
           ar[4] = '\0';
           
           union{
              uint16_t v;
              uint8_t  c[2];
           }u;
           u.v = static_cast<uint16_t>(strtol(ar,nullptr,16));
           out[0] = u.c[0];  
           out[1] = u.c[1];

           out +=2;
           uuid_substr -= decr;
         }


         inline void copy_uuid_str_to_ar( const char ( & uuid_str) [16 * 2 + 5], uint8_t (&ar_out)[16])
         {
            const char* ptr = uuid_str + 16*2  ;
            uint8_t * out = ar_out;

            for ( uint8_t i = 0; i < 2; ++i){
               quan::ble::detail::ll_copy_uuid_str_to_ar(ptr,4,out);
            }
            for ( uint8_t i = 0; i < 4; ++i){
               quan::ble::detail::ll_copy_uuid_str_to_ar(ptr,5,out);
            }
            for ( uint8_t i = 0; i < 2; ++i){
               quan::ble::detail::ll_copy_uuid_str_to_ar(ptr,4,out);
            }
         }

         inline void ll_itoasc_uuid(uint8_t value,char* out)
         {
            auto ll_conv = [] (uint8_t c) { return (c < 10) ? (c + '0'): (c + ('a'- 10));};
            out[0] = ll_conv( (value & 0xf0) >> 4U ); // msb is first looking left to right
            out[1] = ll_conv(value & 0xf);
         }

         inline void copy_ar_to_uuid_str( uint8_t const (&ar_in)[16], char (& ar_out)[16*2 + 5])
         {
             int idx = 0;
             for ( int8_t i = 15; i>=0; --i){
                char ar[2] ;
                quan::ble::detail::ll_itoasc_uuid(static_cast<int>(ar_in[i]),ar);

                ar_out[idx] = ar[0];
                ar_out[idx + 1] = ar[1];

                if ( ( idx == 6) || ( idx == 11) || (idx == 16) || ( idx == 21) ){
                   ar_out[idx + 2] = '-';
                   idx +=3;
                }else{
                  idx +=2;
                }
             }
             ar_out[idx] = '\0';
         }

      }//detail

// https://www.ietf.org/rfc/rfc4122.txt
// https://developer.android.com/reference/java/util/UUID

 /*
   string rep e.g 
  "01234567-89ab-cdef-0123-456789abcdef"
      UUID                   = time-low "-" time-mid "-"
                               time-high-and-version "-"
                               clock-seq-and-reserved
                               clock-seq-low "-" node
      time-low               = 4hexOctet
      time-mid               = 2hexOctet
      time-high-and-version  = 2hexOctet
      clock-seq-and-reserved = hexOctet
      clock-seq-low          = hexOctet
      node                   = 6hexOctet

  "tttttttt-xxxx-xxxx-xxxx-xxxxxxxxxxxx" time-low                     bit[127:96]
  "xxxxxxxx-tttt-xxxx-xxxx-xxxxxxxxxxxx" time-mid                     bit[95:80]
  "xxxxxxxx-xxxx-tttt-xxxx-xxxxxxxxxxxx" time-hi-and-version          bit[79:64]
  "xxxxxxxx-xxxx-xxxx-ttxx-xxxxxxxxxxxx" clock-seq-hi-and-reserved    bit[63:56]
  "xxxxxxxx-xxxx-xxxx-xxtt-xxxxxxxxxxxx" clock-seq-low                bit[55:48]
  "xxxxxxxx-xxxx-xxxx-xxxx-tttttttxxxxx" node                         bit[47:0]

//subfields variant
   
  "xxxxxxxx-xxxx-xxxx-txxx-xxxxxxxxxxxx" variant  (top 3 bits)        bit[63:61]
   Msb0  Msb1  Msb2  Description

    0     x     x    Reserved, NCS backward compatibility.

    1     0     x    The variant specified in this document.

    1     1     0    Reserved, Microsoft Corporation backward
                     compatibility

    1     1     1    Reserved for future definition.

  version
4.1.3.  Version
   "xxxxxxxx-xxxx-txxx-xxxx-xxxxxxxxxxxx" version                       bit[79:75]

   The version number is in the most significant 4 bits of the time
   stamp (bits 4 through 7 of the time_hi_and_version field).

   The following table lists the currently-defined versions for this
   UUID variant.

   Msb0  Msb1  Msb2  Msb3   Version  Description

    0     0     0     1        1     The time-based version
                                     specified in this document.

    0     0     1     0        2     DCE Security version, with
                                     embedded POSIX UIDs.


    0     0     1     1        3     The name-based version
                                     specified in this document
                                     that uses MD5 hashing.

    0     1     0     0        4     The randomly or pseudo-
                                     randomly generated version
                                     specified in this document.

    0     1     0     1        5     The name-based version
                                     specified in this document
                                     that uses SHA-1 hashing.

   The version is more accurately a sub-type; again, we retain the term
   for compatibility.
   
*/
      // 128 bit uuid
      struct uuid128{


         uuid128(const char ( & uuid_str) [16 * 2 + 5])
         {
            quan::ble::detail::copy_uuid_str_to_ar(uuid_str,m_array);
         }
         // TODO can construct from uuid16
         /*
         uuid128(const char (&uuid_str) [5] )
         {
            //
         }
         */

         // get the user friendly version
         void to_c_str(char (& ar_out)[16*2 + 5])const
         {
            quan::ble::detail::copy_ar_to_uuid_str(m_array,ar_out);
         }

         static bool verify(const char ( & uuid_str) [16 * 2 + 5])
         {
            for ( int8_t i = 0; i < 16 * 2 + 4; ++i){
               if ((i==8) || ( i== 13) || ( i == 18) || (i == 23)){
                   if ( uuid_str[i] != '-'){
                   //  std::cout << "at [" << static_cast<int>(i) << "] not '-' " << uuid_str[i] <<'\n';
                     return false;
                   }
               }else{
                  if (!isxdigit(uuid_str[i])){
                    //  std::cout << "at [" << static_cast<int>(i) << "] not hex " << uuid_str[i] <<'\n';
                     return false;
                  }
               }
            }
            // check string null terminated
            return uuid_str[36] == '\0';
         }
         // Interpretation of https://www.ietf.org/rfc/rfc4122.txt according to 
         // https://developer.android.com/reference/java/util/UUID#variant()
         // https://en.wikipedia.org/wiki/Universally_unique_identifier#Variants
         uint16_t get_variant() const
         {
             uint16_t constexpr lsbit = 61U;
             uint16_t constexpr byte_idx  =  lsbit / 8U;
             uint16_t constexpr byte_offset = lsbit % 8U;
             uint16_t result =  m_array[byte_idx] >> byte_offset ;
             if ( (result & 0b100) == 0 ){
                return 0;
             }else {
                if( ((result & 0b100 )!= 0 ) && ( (result & 0b10 ) == 0) ){
                     return 2;
                }else{
                  return result;
               }
            }
         }

//// rfc4122 4.1.1
         /*
            Usually random generated so should return 4
         */
         uint8_t get_version() const
         {
             uint16_t constexpr lsbit = 76U;
             uint16_t constexpr byte_idx  =  lsbit / 8U;
             uint16_t constexpr byte_offset = lsbit % 8U;
             return (m_array[byte_idx] & 0xf0) >> byte_offset;
         }

         uint8_t operator[](int i) const
         {
            if ( i < 16){ return m_array[i];} else { return 0;}
         }

         uint8_t const ( & get_uuid() const ) [16]  { return m_array;} 

         operator uint8_t const * () const { return m_array;}
         private:
         uint8_t m_array[16];

      };
/*
      // comparison of uuids is defined in https://www.ietf.org/rfc/rfc4122.txt
    Rules for Lexical Equivalence:
      Consider each field of the UUID to be an unsigned integer as shown
      in the table in section Section 4.1.2.  Then, to compare a pair of
      UUIDs, arithmetically compare the corresponding fields from each
      UUID in order of significance and according to their data type.
      Two UUIDs are equal if and only if all the corresponding fields
      are equal.

      As an implementation note, equality comparison can be performed on
      many systems by doing the appropriate byte-order canonicalization,
      and then treating the two UUIDs as 128-bit unsigned integers.

      UUIDs, as defined in this document, can also be ordered
      lexicographically.  For a pair of UUIDs, the first one follows the
      second if the most significant field in which the UUIDs differ is
      greater for the first UUID.  The second precedes the first if the
      most significant field in which the UUIDs differ is greater for
      the second UUID.
*/

      inline int compare( uuid128 const & lhs, uuid128 const & rhs)
      {
         for ( int8_t i = 15; i != -1 ; --i){
            if ( lhs[i] < rhs[i] ){
               return -1;
            }else{
               if ( lhs[i] > rhs[i]){
                  return 1;
               }
            }
         }
         return 0;
      }

      inline bool operator < ( uuid128 const & lhs, uuid128 const & rhs)
      {
          return compare(lhs,rhs) < 0;
      }

      inline bool operator <= ( uuid128 const & lhs, uuid128 const & rhs)
      {
          return compare(lhs,rhs) <= 0;
      }

      inline bool operator == ( uuid128 const & lhs, uuid128 const & rhs)
      {
          return compare(lhs,rhs) == 0;
      }

      inline bool operator != ( uuid128 const & lhs, uuid128 const & rhs)
      {
          return compare(lhs,rhs) != 0;
      }

      inline bool operator >= ( uuid128 const & lhs, uuid128 const & rhs)
      {
          return compare(lhs,rhs) >= 0;
      }

      inline bool operator > ( uuid128 const & lhs, uuid128 const & rhs)
      {
          return compare(lhs,rhs) > 0;
      }

   }//ble
}//quan


#endif // QUAN_BLE_UUID_HPP_INCLUDED
