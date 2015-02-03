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


#include <quan/uav/msg_protocol.hpp>
#include <quan/out/angle.hpp>
#include <quan/out/length.hpp>

#include <iostream>

int main()
{
   typedef quan::uav::frsky::lat_msg lat_msg;
   typedef quan::uav::frsky::gps_alt_msg gps_alt_msg;

   auto angle = quan::angle::deg{359.45678915};
   std::cout << "lat = " << angle << " (" << std::hex << quan::arithmetic_convert<uint32_t>(angle.numeric_value() * 1e7) << ")\n";
   lat_msg msg{angle};

    auto buf = msg.get(); 

    std::cout << "header = " << std::hex << static_cast<int>(buf[0]) << "\n";
    std::cout << "id     = " << std::hex << static_cast<int>(buf[1]) << "\n";
    for (int i = 0;i < 4;++i){
           std::cout << "data[" << i << "] = " << std::hex << static_cast<int>(buf[2 + i]) << "\n";
    } 
    std::cout << "cksum  = " << std::hex << static_cast<int>(buf[lat_msg::length -1]) << "\n";

    auto alt =quan::length::m{150000};
    std::cout << "alt = " << alt << " (" << std::hex << quan::arithmetic_convert<int32_t>(alt.numeric_value() * 1e3) << ")\n";
    gps_alt_msg msg1{alt};

    buf = msg1.get(); 

    std::cout << "header = " << std::hex << static_cast<int>(buf[0]) << "\n";
    std::cout << "id     = " << std::hex << static_cast<int>(buf[1]) << "\n";
    for (int i = 0;i < 4;++i){
           std::cout << "data[" << i << "] = " << std::hex << static_cast<int>(buf[2 + i]) << "\n";
    } 
    std::cout << "cksum  = " << std::hex << static_cast<int>(buf[lat_msg::length -1]) << "\n";

    
}
