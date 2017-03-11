#ifndef QUAN_UNIT_TEST_HPP_INCLUDED
#define QUAN_UNIT_TEST_HPP_INCLUDED
/*
 Test for Aerflite/ArduPilot

 Copyright (c) 2003-2017 Andy Little.

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

#include <quan/meta/binary_op.hpp>
#include <AP_HAL/AP_HAL.h>

extern const AP_HAL::HAL& hal;

extern int errors;

// return true if no errors, else false
inline
bool check_function( const char* filename,long line,const char* pred, bool pred1)
{
   if(! pred1){
     // std::cout << filename << ":" << line  << "( " << pred << " ) failed\n";
      hal.console->printf("%s:%ld( %s ) failed\n",filename,line,pred);
      errors ++;
      return false;
   } else {
      #ifdef QUAN_CHECK_VERBOSE 
     // std::cout << filename << ":" << line  << "( " << pred << " ) succeeded\n";
      hal.console->printf("%s:%ld( %s ) succeeded\n",filename,line,pred);
      #endif
      return true;
   }
}

#if 0
//TODO
// return true if no errors, else false
template<typename Ta, typename Tb, typename Te>
inline
bool check_close_function(
const char* filename ,long line,
const char* predac,const char* predbc,const char* epsc,Ta vala, Tb valb, Te eps)
{
    Te absval = (vala - valb >= 0 )? vala - valb : valb - vala;
    Te abs_eps = ( eps >=0) ? eps : -eps;
    if (! (absval < abs_eps)){
        std::cout << filename << ":" << line
        << "( " << predac << " == " << predbc << " +/- " << epsc << " ) failed\n"
        << "actual error = " << absval <<'\n';
        errors ++;
        return false;
    }else{
        return true;
    }
}

// return true if no errors, else false
template<typename Ta, typename Tb>
inline
bool check_equal_function( const char* filename ,long line,
const char* predac,const char* predbc,Ta vala, Tb valb)
{
    typedef typename quan::meta::binary_op<
        Ta,quan::meta::minus,Tb
    >::type Te;
    Te  absval = (vala - valb >= 0) ? vala - valb : valb - vala;
    if (! (absval == Te(0) )){
        std::cout << filename << ":" << line
        << "( " << predac << " == " << predbc << " ) failed\n"
        << "actual error = " << absval <<'\n';
        errors ++;
        return false;
    }else{
       return true;
    }
}
#endif

#define QUAN_CHECK(x) check_function( __FILE__ , __LINE__ , #x, x);
#define QUAN_CHECK_I(x,i) if (!check_function( __FILE__ , __LINE__ , #x, x) ) { std::cout << "   at iteration[" << i << "]\n\n";}
#define QUAN_CHECK_IJ(x,i,j) if (!check_function( __FILE__ , __LINE__ , #x, x) ) { std::cout << "   at iteration[" << i << ',' << j << "]\n\n";}
#if 0
#define QUAN_CHECK_CLOSE(a,b,e) check_close_function( __FILE__ , __LINE__ , #a , #b ,#e, a, b, e)
#define QUAN_CHECK_EQUAL(a,b) check_equal_function( __FILE__ , __LINE__ , #a , #b , a , b )
#endif
// best show we've been on success
inline
int epilogue(const char* file)
{
    if (errors){
       // std::cout << file << " FAIL: found " << errors << " errors\n";
        hal.console->printf("%s FAIL: found %d errors\n",file,errors);
    }
    else{
       // std::cout << file << " PASS (no errors)\n";
      hal.console->printf("%s  PASS (no errors)\n",file);
    }
    return errors;
}

#define EPILOGUE epilogue(__FILE__); while (1){ asm volatile ("nop":::);}

#define QUAN_EPILOGUE return epilogue(__FILE__);

// incoherent-multiplier correct to 6 decimals
// hence unreasonable expect greater accuaracy
// 1 e-12 may be optimistic
#ifndef FP_MAX_DIFFERENCE
#define FP_MAX_DIFFERENCE 1e-12
#endif

#endif



