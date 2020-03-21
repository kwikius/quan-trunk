/*
Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses.
*/

#if ! defined __MBED__

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

#endif
