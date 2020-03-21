
#if ! defined __MBED__
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

#include <quan/gx/wxwidgets/graphics_context.hpp>
#include <quan/gx/primitives/simple_text.hpp>

void quan::gx::wxwidgets::graphics_context::draw_text(
   quan::gx::primitives::simple_text<mm> const & text
) const
{
   auto const pos = device_transform_in(text.get_position());
   // TODO add font
   m_pDC->DrawText(
      text.get_text()
      ,quan::arithmetic_convert<int>(pos.x)
      ,quan::arithmetic_convert<int>(pos.y)
   );
}

#endif

