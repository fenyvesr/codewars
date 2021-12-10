/*!
***     \file        everyPossibleSumOfTwoDigits.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b4e474305f04bea11000148
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/5b4e474305f04bea11000148 and its test function.
***
**/
#include "everyPossibleSumOfTwoDigits.h"

#include <cassert> /*!< Needed for assert */
#include <string>  /*!< Needed for std::string, std::to_string */

std::vector<int> everyPossibleSumOfTwoDigits(int n) {
    std::vector<int> res; /*!< Vector containing the sum of the digit pairs. */
    std::string digits(std::to_string(n)); /*!< String containing the digits of the number. */
    /* Iterating over the digits n*(n-1)/2 times. */
    for (auto itExt = digits.begin(); itExt != prev(digits.end()); ++itExt)
        for (auto itInt = next(itExt); itInt != digits.end(); res.push_back(*itExt + *itInt++ - 2 * '0'));
    return res;
}

void everyPossibleSumOfTwoDigitsTest (){
    assert(("Wrong value for 156"    , std::vector <int>{ 6, 7, 11 } == everyPossibleSumOfTwoDigits(156)));
    assert(("Wrong value for 81596"  , std::vector <int>{ 9, 13, 17, 14, 6, 10, 7, 14, 11, 15 } == everyPossibleSumOfTwoDigits(81596)));
    assert(("Wrong value for 3852"   , std::vector <int>{ 11, 8, 5, 13, 10, 7 } == everyPossibleSumOfTwoDigits(3852)));
    assert(("Wrong value for 3264128", std::vector <int>{ 5, 9, 7, 4, 5, 11, 8, 6, 3, 4, 10, 10, 7, 8, 14, 5, 6, 12, 3, 9, 10 } == everyPossibleSumOfTwoDigits(3264128)));
    assert(("Wrong value for 999999" , std::vector <int>{ 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 } == everyPossibleSumOfTwoDigits(999999)));
}
