/*!
***     \file        subArrayElementsSum.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b5e0ef007a26632c400002a
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/5b5e0ef007a26632c400002a and its test function.
***
**/
#include "subArrayElementsSum.h"

#include <numeric> /* Needed for std::accumulate */

long subArrayElementsSum(const std::vector<std::vector<int>>& arr, int d){
  /* Summing the required members in the input vectors */
  return std::accumulate(arr.cbegin(), arr.cend(), 0,
                         [i{arr.size()}, d](const long& acc, auto& b) mutable {
                           return acc + (--i >= b.size() ? d : b[i]);
                         });
}
