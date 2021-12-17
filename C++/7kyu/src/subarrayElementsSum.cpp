/*!
***     \file        subarrayElementsSum.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b5e0ef007a26632c400002a
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/5b5e0ef007a26632c400002a and its test function.
***
**/
#include "subarrayElementsSum.h"

#include <cassert> /* Needed for assert */
#include <numeric> /* Needed for std::accumulate */

long subarrayElementsSum(const std::vector<std::vector<int>>& arr, int d){
  /* Summing the required members in the input vectors */
  return std::accumulate(arr.cbegin(), arr.cend(), 0,
                         [i{arr.size()}, d](const long& acc, auto& b) mutable {
                           return acc + (--i >= b.size() ? d : b[i]);
                         });
}

void subarrayElementsSumTest (){
    assert(("Wrong value for {{3, 2, 1, 0}, {4, 6, 5, 3, 2}, {9, 8, 7, 4}}", 16 == subarrayElementsSum({{3, 2, 1, 0}, {4, 6, 5, 3, 2}, {9, 8, 7, 4}})));
    assert(("Wrong value for {{3}, {4, 6, 5, 3, 2}, {9, 8, 7, 4}}", 15 == subarrayElementsSum({{3}, {4, 6, 5, 3, 2}, {9, 8, 7, 4}})));
    assert(("Wrong value for {{3, 2, 1, 0}, {4, 6, 5, 3, 2}, {}}", 7 == subarrayElementsSum({{3, 2, 1, 0}, {4, 6, 5, 3, 2}, {}})));
    assert(("Wrong value for {{3, 2, 1, 0}, {4, 6, 5, 3, 2}, {}} and 5", 12 == subarrayElementsSum({{3, 2, 1, 0}, {4, 6, 5, 3, 2}, {}}, 5)));
    assert(("Wrong value for {{3, 2}, {4}, {}}", 0 == subarrayElementsSum({{3, 2}, {4}, {}})));
}
