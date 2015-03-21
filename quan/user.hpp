#ifndef QUAN_USER_HPP_INCLUDED
#define QUAN_USER_HPP_INCLUDED

#include <cstdint>

namespace quan{ 
// for the app to define
   void user_message (const char* str);
   void user_error(const char* str);
   void user_flush_sptx();
   uint32_t user_in_avail();
   char user_get();
   void report_errors();
}

#endif // QUAN_USER_HPP_INCLUDED
