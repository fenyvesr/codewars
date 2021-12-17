/*!
***     \file        tramCapacity.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b190aa7803388ec97000054
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/5b190aa7803388ec97000054 and its test function.
***
**/
#include "tramCapacity.h"

#include <cassert>   /* Needed for assert */
#include <numeric>   /* Needed for std::partial_sum */
#include <algorithm> /* Needed for std::transform, std::max_element */
#include <iterator>  /* Needed for std::back_inserter */

int tramCapacity(int stops, const std::vector<int>& a, const std::vector<int>& b){
    return std::inner_product(
        a.cbegin(), 
        std::min(a.cbegin() + stops, a.cend()), /* End after the last stop is reached or when the vector ends. */
        b.cbegin(),
        std::vector<int>{ 0, 0 }, /* The accumulated value contains the max capacity needed and the current number of passengers. */
        [](const auto& acc, const int& delta) {return std::vector<int>{
        std::max(acc[0], acc[1] + delta), /* Updating the maximum capacity. */
            acc[1] + delta }; }, /* Updating the current number of passengers on the tram. */
        [](const int& a, const int& b) { return b - a; } /* Change in the number of people on the tram */
        )[0]; /* Giving back the first element in the array, defining the maximum capacity */
}

void tramCapacityTest (){
    assert(("Wrong value for 4, {0, 2, 4, 4} and {3, 5, 2, 0}"                                      , 6  == tramCapacity(4,  {0, 2, 4, 4},                   {3, 5, 2, 0})));
    assert(("Wrong value for 2, {0, 2, 4, 4} and {3, 5, 2, 0}"                                      , 6  == tramCapacity(2,  {0, 2, 4, 4},                   {3, 5, 2, 0})));
    assert(("Wrong value for 1, {0, 2, 4, 4} and {3, 5, 2, 0}"                                      , 3  == tramCapacity(1,  {0, 2, 4, 4},                   {3, 5, 2, 0})));
    assert(("Wrong value for 10, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} and {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}" , 25 == tramCapacity(10, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, {9, 8, 7, 6, 5, 4, 3, 2, 1, 0})));
    assert(("Wrong value for 5, {0, 2, 4, 14, 2} and {3, 5, 14, 0, 0}"                              , 16 == tramCapacity(5,  {0, 2, 4, 14, 2},               {3, 5, 14, 0, 0})));
}
