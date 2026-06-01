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
