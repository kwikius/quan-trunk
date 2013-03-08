

#include <quan/gx/static_rgb_color.hpp>

  std::shared_ptr<quan::gx::abc_color> quan::gx::rgb::colors::black {new quan::gx::static_rgb_color<unsigned char,0,0,0>};
  std::shared_ptr<quan::gx::abc_color> quan::gx::rgb::colors::white {new quan::gx::static_rgb_color<unsigned char,0xff,0xff,0xff>};
   std::shared_ptr<quan::gx::abc_color> quan::gx::rgb::colors::red {new  quan::gx::static_rgb_color<unsigned char,0xff,0,0>} ;
    std::shared_ptr<quan::gx::abc_color> quan::gx::rgb::colors::green { new  quan::gx::static_rgb_color<unsigned char,0,0xff,0> };
   std::shared_ptr<quan::gx::abc_color> quan::gx::rgb::colors::blue  {new  quan::gx::static_rgb_color<unsigned char,0,0,0xff>};
  std::shared_ptr<quan::gx::abc_color> quan::gx::rgb::colors::yellow { new  quan::gx::static_rgb_color<unsigned char,0xff,0xff,0>};
   std::shared_ptr<quan::gx::abc_color> quan::gx::rgb::colors::aqua {new  quan::gx::static_rgb_color<unsigned char,0,0xff,0xff>};
  std::shared_ptr<quan::gx::abc_color> quan::gx::rgb::colors::silver{ new   quan::gx::static_rgb_color<unsigned char,0xC0,0xC0,0xC0>};
   std::shared_ptr<quan::gx::abc_color> quan::gx::rgb::colors::gray { new  quan::gx::static_rgb_color<unsigned char,0x80,0x80,0x80> };
