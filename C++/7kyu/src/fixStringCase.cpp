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

#include <cassert>   /*!< Needed for assert */
#include <algorithm> /*!< Needed for std::transform, std::count_if */
#include <iterator>  /*!< Needed for std::back_inserter */

std::string fixStringCase(const std::string& str) {
    std::string res; /*!< A string to contain the transformed input. */
    /*! A function reference deciding whether upper or lower case letters are needed in the output string. */
    auto func = str.size() < 2 * std::count_if(str.cbegin(), str.cend(), isupper) ? toupper : tolower;
    /* Transforming the input string with the previously choosen function. */
    std::transform(str.cbegin(), str.cend(), std::back_inserter(res), func);
    return res;
}

void fixStringCaseTest (){
    assert(("Wrong value for \"coDe\"", "code" == fixStringCase("coDe")));
    assert(("Wrong value for \"CODe\"", "CODE" == fixStringCase("CODe")));
    assert(("Wrong value for \"COde\"", "code" == fixStringCase("COde")));
}
