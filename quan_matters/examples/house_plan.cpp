// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/length.hpp>
#include <quan/out/area.hpp>

struct room{
    quan::length::m length;
    quan::length::m width;
    room(quan::length::m const & l, quan::length::m const & w)
    : length(l) , width(w){}
    quan::area::m2 area() { return length * width;}
};

// area of house

int main()
{
    typedef  quan::length::m width;
    typedef  quan::length::m length;
   
    room kitchen(length(6),width(3) );
    room lounge(length(5), width(3.6));
    room bedroom1(length(3.6), width(3));
    room bedroom2(length(3.6), width(2.7));
    room bedroom3(length(2.1), width(3.6) );

    quan::area::m2 a 
    = kitchen.area()
    + lounge.area()
    + bedroom1.area()
    + bedroom2.area()
    + bedroom3.area();

    std::cout << "floor area = "<< a <<'\n';
}
