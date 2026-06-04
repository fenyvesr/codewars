/*!
***     \file        countCodePoints.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/68b8e7f8ce76e77dcfb77e8a
***
***     \par    Description:
***                  In languages where "strings" are really sequences of 8-bit bytes
***                  (C/C++, PHP, OCaml, Go, Lua...), UTF-8 is a possible encoding for
***                  them and usually has some level of language support. However, the
***                  function/method/property to retrieve the string's length actually
***                  returns the number of bytes in the string, not the number of codepoints.
***
**/

#pragma once

#include <string_view> /* Needed for std::string_view */

/*!
    \brief       This function counts the number of codepoints in a UTF-8 string
    \param[in]   utf8 The UTF-8 encoded string to analyze
    \returns     The number of codepoints in the string
    \par Examples:
         "Aÿ♠🙉" shall return 4\n
         "㐷©∏!重" shall return 5
*/
std::size_t CountCodepoints(std::string_view utf8);
