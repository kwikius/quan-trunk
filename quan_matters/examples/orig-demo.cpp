// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    Update of the original demo of pqs
*/

#include <quan/out/length.hpp>
#include <quan/out/time.hpp>
#include <quan/out/velocity.hpp>
#include <quan/out/acceleration.hpp>
#include <quan/out/mass.hpp>
#include <quan/out/force.hpp>


//comment out NO_PQS_CONSTANTS_LIBRARY if using constants in a library
#define NO_PQS_CONSTANTS_LIBRARY
#ifdef NO_PQS_CONSTANTS_LIBRARY
//definition of constant of acceleration due to gravity 
#include <quan_matters/src/acceleration_g.cpp>
#endif

int main()
{
    std::cout << "The original demonstration of"
    "\nthe physical quantities type"
    "\nnow implemented in quan_0_2_0\n\n";

    // compare pqs etc of same type/pq_value but different units...
    using quan::length;

    length::m      length1(7);
    length::mm     length2 = length1 ; // == length1 but diff units
    std::cout << length2 << " == " << length1 
    << " is " << std::boolalpha << (length2 == length1)<<'\n';
    std::cout << length1 << " == " << length2 
    << " is " << std::boolalpha << (length1 == length2) <<'\n';
    
    if ( length2 != length1) 
        std::cout << "conversion error is " <<  ((length1 > length2)
                       
                ? length1-length2 : length2-length1)  << '\n';

    if ( length1 != length2) 
        std::cout << "conversion error is " <<  ((length2 > length1)
    
                ? length2-length1 : length1-length2)  << '\n';
    std::cout << "ratio of length1 to length2 is " << length1/length2 <<'\n'
    << std::endl;

//-- calculate length of a hypotenuse for 3,4,5 right angled triangle:

    using quan::pow;
    using quan::sqrt;

    length::mm const    opposite (3000);
    length::m  const    adjacent    (4);
    length::ft          hypotenuse;          // in feet...:-)
    std::cout << "length of hypotenuse for right-angled triangle"
    "\nof opposite-side of length "         << opposite
    << "\nand adjacent-side of length "     << adjacent
    << "\nis "                              << ( hypotenuse = 
            sqrt( pow<2>(adjacent) + pow<2>(opposite) ) ) <<'\n';

    std::cout << " or " << length::km(hypotenuse) << '\n';
    std::cout << "BTW - its a 3,4,5 triangle :-)\n"; 
    std::cout << std::endl;

//-------- calc  dist = u * t + 1/2 a * t*t;

    using quan::time;
    using quan::velocity;
    using quan::acceleration;
   
    time::s                   const time_taken(10);
    velocity::mm_per_min      const initial_velocity( velocity::m_per_s(10) );
    acceleration::m_per_s2    const accel = acceleration::g;
    length::km                distance_travelled
    = initial_velocity * time_taken + 0.5 * accel * pow<2>(time_taken);

    std::cout 
    << "Distance travelled in "        << time_taken 
    << "\nwith initial velocity of "   << initial_velocity
    << "\nand acceleration of "        << accel
    << "\nis "                         << distance_travelled
    << " or " << length::m(distance_travelled) << '\n';
    std::cout << "BTW - " << initial_velocity
    << " is " << velocity::m_per_s(initial_velocity) <<'\n'
    << std::endl;

//------------- calculate a force

    using quan::force;
    using quan::mass;

    mass::g              const m(0.001);    
    velocity::m_per_s    const v0(200);
    velocity::m_per_s    const v1(10000);
    time::us             const t(40);
    force::N                   f;
    std::cout 
    << "For a mass of "                     << m 
    << "\nwith an initial velocity of "     << v0
    << "\nto acquire a final velocity of "  << v1 
    << "\nin "                              << t 
    // note: uses the "newtons" ostream << specialisation
    << "\nrequires a force of " 
    << ( f = m * (v1 - v0) / t ) << '\n';
    // uses the kgf ostream specialisation
    std:: cout << "which is equal to "<< force::kgf(f)
    << std::endl;
   
    return EXIT_SUCCESS;
}


