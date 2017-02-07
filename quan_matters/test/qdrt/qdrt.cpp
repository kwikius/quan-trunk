

#include <quan_matters/test/simple_test.hpp>
#include <quan/out/angle.hpp>
#include <cstdint>
#include <cstdio>
#include <quan/min.hpp>

namespace {
   QUAN_ANGLE_LITERAL(rad)
}

/*
 preconditions: counts_rev must be greater than count
*/
quan::angle::rad get_angular_position(uint32_t count, uint32_t counts_rev)
{
    return quan::angle::two_pi * static_cast<QUAN_FLOAT_TYPE>(count)/counts_rev;
}


/*
 preconditions: old_count_in, new_count_in  must be greater than counts_rev_in
 old_count_in, new_count_in must be convertible to signed without overflow
 (Maybe make these signed anyway ?. No since they shouldnt be negative)
 // convert to signed next size in fun?
*/
// old count and new count can never be >= counts_rev
// There are 2 possibilities
// either there has been an overflow ( + or -) where new count has passed through zero
// or not. Decide there has been overflow if the abs diff is greater than half the counts_rev
// In practise requires always taking new reading before half a revolution 
// has passed from the old reading
int32_t get_count_diff(uint32_t old_count_in, uint32_t new_count_in, uint32_t counts_rev_in)
{
   // error basically
   if( (old_count_in >= counts_rev_in) || (new_count_in >= counts_rev_in)){
      return counts_rev_in;
   }
   // convert all to signed arithmetic
   int32_t const old_count = old_count_in;
   int32_t const new_count = new_count_in;
   int32_t counts_rev = counts_rev_in;

   int32_t const diff = new_count - old_count;
   if ( diff < -counts_rev/2){
     return diff + counts_rev;
   }else{
     if ( diff > counts_rev/2){
        return diff - counts_rev;
     }else{
        return diff;
     }
   }   
}
/*
As above
*/
quan::angle::rad get_angle_diff( quan::angle::rad const & old_bearing, quan::angle::rad const & new_bearing)
{
    quan::angle::rad const diff = unsigned_modulo(new_bearing) - unsigned_modulo(old_bearing);
    if ( diff < -quan::angle::pi){
       return diff + 2 * quan::angle::pi;
    }else{
      if (diff > quan::angle::pi){
         return diff - 2 * quan::angle::pi;
      }else {
         return diff;
      }
    }
}
/*
  assume bearing quadrants NE, NW, SE, SW
  assumed angles represents bearings (  in radians), e.g 0 at top face North and increasing clockwise
*/
void angle_diff_test()
{
    QUAN_CHECK(get_angle_diff(1_rad, 2_rad) == 1_rad);
    QUAN_CHECK(get_angle_diff(2_rad, 1_rad) == -1_rad);

    QUAN_CHECK(get_angle_diff(-quan::angle::pi/4, quan::angle::pi/4) == quan::angle::pi/2);
    QUAN_CHECK(get_angle_diff(quan::angle::pi/4, -quan::angle::pi/4) == -quan::angle::pi/2);

    auto NE = quan::angle::pi / 4;
    auto NW_pos = (quan::angle::pi * 7) / 4;
    auto NW_neg = -quan::angle::pi / 4;
    auto SE = (quan::angle::pi * 3) / 4;
    auto SW_pos = (quan::angle::pi * 5) / 4;
    auto SW_neg = (quan::angle::pi * -3) / 4;
    
    // old NW to new NE sign should be positive
    QUAN_CHECK(get_angle_diff(NW_pos,NE) == quan::angle::pi/2);
    QUAN_CHECK(get_angle_diff(NW_neg,NE) == quan::angle::pi/2);

    // old NE to new NW sign should be negative 
    QUAN_CHECK(get_angle_diff(NE,NW_pos) == -quan::angle::pi/2);
    QUAN_CHECK(get_angle_diff(NE,NW_neg) == -quan::angle::pi/2);

    // old NE to new SE should be positive
    QUAN_CHECK(get_angle_diff(NE,SE) == quan::angle::pi/2);

    // old SE to new NE should be positive
    QUAN_CHECK(get_angle_diff(SE,NE) == -quan::angle::pi/2);

    // old SE to ne SW should be positive
    QUAN_CHECK(get_angle_diff(SE,SW_pos) == quan::angle::pi/2);
    QUAN_CHECK(get_angle_diff(SE,SW_neg) == quan::angle::pi/2);

    // old SW to ne SE should be positive
    QUAN_CHECK(get_angle_diff(SW_pos,NW_pos) == quan::angle::pi/2);
    QUAN_CHECK(get_angle_diff(SW_neg,NW_pos) == quan::angle::pi/2);

    // NW SW should be neg
    QUAN_CHECK(get_angle_diff(NW_pos,SW_pos) == -quan::angle::pi/2);
    QUAN_CHECK(get_angle_diff(NW_neg,SW_pos) == -quan::angle::pi/2);
    QUAN_CHECK(get_angle_diff(NW_pos,SW_neg) == -quan::angle::pi/2);
    QUAN_CHECK(get_angle_diff(NW_neg,SW_neg) == -quan::angle::pi/2);

    // NW SW should be pos
    QUAN_CHECK(get_angle_diff(SW_pos,NW_pos) == quan::angle::pi/2);
    QUAN_CHECK(get_angle_diff(SW_neg,NW_pos) == quan::angle::pi/2);
    QUAN_CHECK(get_angle_diff(SW_pos,NW_neg) == quan::angle::pi/2);
    QUAN_CHECK(get_angle_diff(SW_neg,NW_neg) == quan::angle::pi/2);
}

void count_diff_test()
{
   //################## NB ###########################################################
   QUAN_CHECK(get_count_diff(19,0,18) == 18); // this is a test of violating invariant
   //#################################################################################
   QUAN_CHECK(get_count_diff(19,0,20) == 1);
   QUAN_CHECK(get_count_diff(0,19,20) == -1);
   QUAN_CHECK(get_count_diff(19,3,20) == 4);
   QUAN_CHECK(get_count_diff(3,18,20) == -5);
   QUAN_CHECK(get_count_diff(11,10,20) == -1);
   QUAN_CHECK(get_count_diff(10,15,20) == 5);
   QUAN_CHECK(get_count_diff(300,1000,1200) == -500);
   QUAN_CHECK(get_count_diff(1000,300,1200) == 500);
}

void angular_position_conversion_test()
{
    QUAN_CHECK(quan::angle::deg{get_angular_position(2400,9600)}.numeric_value() == 90.f);
    QUAN_CHECK(quan::angle::deg{get_angular_position(1,2)}.numeric_value() == 180.f);
    QUAN_CHECK(get_angular_position(1,4) == quan::angle::pi / 2.f);
    QUAN_CHECK(get_angular_position(1,4).numeric_value() == quan::angle::pi / 2.f);
}

int errors = 0;
void test_all_channels();
int main()
{
    angular_position_conversion_test();
    count_diff_test();
    angle_diff_test();
    test_all_channels();

    QUAN_EPILOGUE
}

namespace{

   union{
      uint32_t uint32_arr[7];
      uint8_t  byte_arr[28];
   } output_data;

   bool put_channel( uint8_t channel_number, uint16_t value_in)
   {
      if (channel_number < 16U){
         uint32_t const value = quan::min(value_in,0x7FF);
         uint32_t const start_bitpos = channel_number * 11U;
         uint32_t const idxu32 = start_bitpos / 32U;
         uint32_t const lshiftu32 = start_bitpos % 32U;
         constexpr uint32_t lshift_max = (32U - 11U);
         if ( lshiftu32 > lshift_max ){
            uint32_t const rshiftu32 = 32U - lshiftu32;
            uint32_t const temp = output_data.uint32_arr[idxu32 +1] & ~(0x7FF >> rshiftu32);
            output_data.uint32_arr[idxu32 +1] = temp | (value >> rshiftu32);
         }
         uint32_t const temp = output_data.uint32_arr[idxu32] & ~(0x7FF << lshiftu32);
         output_data.uint32_arr[idxu32] = temp | (value << lshiftu32);
         return true;
      }else{
         // TODO digi channels, failsafe
         return false;
      }
   }
   /*
      reverse process
   */
   bool get_channel(uint8_t channel_number, uint16_t & value_out)
   {
      if ( channel_number < 16U){

         uint32_t const start_bitpos = channel_number * 11U;
         uint32_t const idxu32 = start_bitpos / 32U;
         uint32_t const lshiftu32 = start_bitpos % 32U;
         constexpr uint32_t lshift_max = (32U - 11U);
         uint16_t result = (output_data.uint32_arr[idxu32] & (0x7FF << lshiftu32)) >> lshiftu32;
         if ( lshiftu32 > lshift_max ){
            uint32_t const rshiftu32 = 32U - lshiftu32;
            result |= (output_data.uint32_arr[idxu32 +1] & (0x7FF >> rshiftu32)) << rshiftu32;
         }
         value_out = result;
         return true;
      }else{
          // TODO digi channels, failsafe
         return false;
      }
   }

}

void test_all_channels()
{
   for (uint16_t val = 0;val <= 0x7FF;++val){ 
      for ( uint32_t chan = 0; chan < 16; ++chan){
         put_channel(chan,val);
         uint16_t result = 0;
         bool const got_channel = get_channel(chan ,result);
         QUAN_CHECK_IJ(got_channel,val,chan);
         if ( got_channel){
            QUAN_CHECK_IJ( result == val, val,chan)
         }
      }
   }
}

