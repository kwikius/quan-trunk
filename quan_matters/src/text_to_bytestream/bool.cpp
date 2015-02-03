

#include <cstring>
#include <quan/conversion/text_to_bytestream/bool.hpp>

namespace {
   const char expected_bool[] = "expected \"true\" or \"false\"";
}

/*
   add function ptrs to sig for alloc fail and user error?
*/
bool quan::text_to_bytestream<bool>::apply(quan::dynarray<uint8_t>& dest, quan::dynarray<char> const & src)
//bool cstring_to_rep_Bool(quan::dynarray<uint8_t>& dest, quan::dynarray<char> const & src)
{
     // input is "true" or "false"
     uint8_t val = 0;
     if (src.get_num_elements() == 5) {
          if ( strcmp(src.get(),"true") == 0 ) {
               val = 1;
          } else {
              // user_error(expected_bool);
               return false;
          }
     } else {
          if ( src.get_num_elements() == 6) {
               if ( strcmp(src.get(),"false") != 0 ) {
                  //  user_error(expected_bool);
                    return false;
               }
          } else {
              // user_error(expected_bool);
               return false;
          }
     }
     static_assert(sizeof(bool) == sizeof(uint8_t), "invalid bool size");
     if (!dest.realloc (sizeof(uint8_t))) {
        //  main_alloc_failed();
          return false;
     }
     *dest.get() = val;
     return true;
}