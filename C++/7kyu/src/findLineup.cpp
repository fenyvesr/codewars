/*!
***     \file        findLineup.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/6914c975e159c8f7e120cc84
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/6914c975e159c8f7e120cc84.
***
**/
#include "findLineup.h"

#include <algorithm> /* Needed for std::all_of */

std::vector<std::size_t> find_lineup(const std::vector<std::size_t>& distances){
    /* The result vector containing the order of the people in the lineup. */
    std::vector<std::size_t> result(distances.size());
    /* Iterating over the input vector and filling the result vector based on the distances. */
    return std::all_of(distances.begin(), distances.end(),
        [&, i = std::size_t{0}](std::size_t d) mutable {
            return d < result.size() && !result[d] && (result[d] = ++i);}
    ) ? result : std::vector<std::size_t>{};
}
