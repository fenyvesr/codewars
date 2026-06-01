/*!
***     \file        fixStringCase.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b180e9fedaa564a7000009a
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/5b180e9fedaa564a7000009a and its test function.
***
**/
#include "fixStringCase.h"

#include <iterator>  /* Needed for std::back_inserter */
#include <algorithm> /* Needed for std::transform, std::count_if */

std::string fixStringCase(std::string_view str) {
    /* A string to contain the transformed input. */
    std::string res;
    /* A function reference deciding whether upper or lower case letters are needed in the output string. */
    auto func = str.size() < 2 * std::count_if(str.cbegin(), str.cend(), isupper) ? toupper : tolower;
    /* Transforming the input string with the previously choosen function. */
    std::transform(str.cbegin(), str.cend(), std::back_inserter(res), func);
    return res;
}
