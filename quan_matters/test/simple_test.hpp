#ifndef QUAN_UNIT_TEST_HPP_INCLUDED
#define QUAN_UNIT_TEST_HPP_INCLUDED

#include <quan/meta/binary_op.hpp>

#ifdef __AVR__
#include <quan/avr/iostream_dummy.hpp>
#else
#include <iostream>
#endif
/// count errors
extern int errors;
inline
void check_function( const char* filename ,  long line,const char* pred, bool pred1)
{
    if(! pred1){
        std::cout << filename << ":" << line  << "( " << pred << " ) failed\n";
        errors ++;
    }
 #ifdef QUAN_CHECK_VERBOSE 
     else {
       std::cout << filename << ":" << line  << "( " << pred << " ) succeeded\n";
    }
 #endif
}
template<typename Ta, typename Tb, typename Te>
inline
void check_close_function(
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
    }
}
template<typename Ta, typename Tb>
inline
void check_equal_function( const char* filename ,long line,
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
    }
}

#define QUAN_CHECK(x) check_function( __FILE__ , __LINE__ , #x, x);
#define QUAN_CHECK_CLOSE(a,b,e) check_close_function( __FILE__ , __LINE__ , #a , #b ,#e, a, b, e)
#define QUAN_CHECK_EQUAL(a,b) check_equal_function( __FILE__ , __LINE__ , #a , #b , a , b )

// best show we've been on success
inline
int epilogue(const char* file)
{
    if (errors){
        std::cout << file << " FAIL: found " << errors << " errors\n";
    }
    else{
        std::cout << file << " PASS (no errors)\n";
    }
    return errors;
}

#define EPILOGUE return epilogue(__FILE__);
#define QUAN_EPILOGUE return epilogue(__FILE__);

// incoherent-multiplier correct to 6 decimals
// hence unreasonable expect greater accuaracy
// 1 e-12 may be optimistic
#ifndef FP_MAX_DIFFERENCE
#define FP_MAX_DIFFERENCE 1e-12
#endif

#endif



