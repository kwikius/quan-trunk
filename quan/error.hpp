#ifndef QUAN_ERROR_HPP_INCLUDED
#define QUAN_ERROR_HPP_INCLUDED

#include <cstdint>
#include <quan/detail/function_id.hpp>
#include <quan/detail/error_id.hpp>

namespace quan{ 
// for the app to define
   void error( int32_t function_id, int32_t error_id);

}


#endif // QUAN_ERROR_HPP_INCLUDED
