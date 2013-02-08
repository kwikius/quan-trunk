#ifndef QUAN_BYTESIZE_FROM_BITSIZE_HPP_INCLUDED
#define QUAN_BYTESIZE_FROM_BITSIZE_HPP_INCLUDED
/*
  for storage that cant be at bit level
  make a byte the smallest size
*/
namespace quan{
   
   inline
   std::size_t 
   bytesize_from_bitsize(std::size_t bitsize)
   {
      std::size_t rem = ( (bitsize % 8U) ==0) ? 0:1;
      return bitsize / std::size_t{8} + rem ;
   }
}

#endif // QUAN_BYTESIZE_FROM_BITSIZE_HPP_INCLUDED
