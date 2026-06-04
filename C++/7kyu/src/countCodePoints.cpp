/*!
***     \file        countCodePoints.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/68b8e7f8ce76e77dcfb77e8a
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/68b8e7f8ce76e77dcfb77e8a.
***
**/
#include "countCodePoints.h"

#include <cstddef>   /* Needed for std::byte */
#include <algorithm> /* Needed for std::count_if */

std::size_t CountCodepoints(std::string_view utf8)
{
    /* Counting the number of codepoints in the UTF-8 string by counting the number of bytes that are not continuation bytes. */
    return std::count_if(utf8.begin(), utf8.end(), [](unsigned char c){ return (std::byte{c} & std::byte{0xC0}) != std::byte{0x80}; });
}
