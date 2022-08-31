#include <iostream>

#include <quan/two_d/out/vect.hpp>
#include <quan/two_d/out/line.hpp>
#include <quan/two_d/box.hpp>
#include <quan/two_d/clip.hpp>

/*
Using clip, clip a line so anything inside the box is clipped
*/

int main()
{
  using vect_t = quan::two_d::vect<double>;
  using point_t = vect_t;
  using box_t = quan::two_d::box<double>;
  using line_t = quan::two_d::line<vect_t>;
  using clip_t = quan::two_d::clip<double>;
  using trisect_t = quan::two_d::trisect<double>;

  // clip box
  box_t box{0,1,1,0};

  clip_t clip{box};

  point_t p1{-0.1,0.1};
  point_t p2{1.1,0.9};

  line_t line{p2,p1};

  std::cout << "input line = " << line <<'\n';

  trisect_t trisect{box};
  auto tr = trisect(line);
  std::cout << "trisect = " << tr <<'\n';

  auto result = clip(line);

  if ( result.first){
    // some part of line is in clipped region
     auto clipped_line = result.second;
     std::cout << "in box clipped line = " << clipped_line <<'\n';
     if  (line.from != clipped_line.from){
        // from part is clipped
        line_t line1{line.from,clipped_line.from};
         std::cout << "output line 1 = " << line1 <<'\n';
     }
     if  (line.to != clipped_line.to){
        // to part is clipped
        line_t line2{line.to,clipped_line.to};
        std::cout << "output line 2 = " << line2 <<'\n';
     }
    // line was clipped
  }else{

  }
}
