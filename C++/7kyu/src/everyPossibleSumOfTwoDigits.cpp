/*!
***     \file        everyPossibleSumOfTwoDigits.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b4e474305f04bea11000148
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/5b4e474305f04bea11000148.
***
**/
#include "everyPossibleSumOfTwoDigits.h"

#include <string>  /* Needed for std::string, std::to_string */

std::vector<int> everyPossibleSumOfTwoDigits(int n) {
    std::vector<int> res; /* Vector containing the sum of the digit pairs. */
    std::string digits(std::to_string(n)); /* String containing the digits of the number. */
    /* Iterating over the digits n*(n-1)/2 times. */
    for (auto itExt = digits.begin(); itExt != prev(digits.end()); ++itExt)
        for (auto itInt = next(itExt); itInt != digits.end(); res.push_back(*itExt + *itInt++ - 2 * '0'));
    return res;
}
