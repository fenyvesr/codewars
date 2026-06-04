/*!
***     \file        fixStringCase.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/69269262ced9e95dc63abd1e
***
***     \par    Description:
***                  Write a function to help Alice find out the count
***                  of times the given integers have to be reordered
***                  and thus know how many Jumbler spins to make
***                  before betting large and getting a huge payout!!
**/

#pragma once

#include <vector> /* Needed for std::vector */

/*!
    \brief         The pattern Alice discovers goes as follows:

                   - select the value at index zero
                   - (if the value is 0 do not continue)
                   - else, the value is our search index
                   - go to new value found at the search index
                   - remove this new value from its place in order
                   - reposition this new value onto the front of the list
                   - (if the new value is zero, the reorderings will cease)
                   - else, repeat all instructions with this new ordering
    \param[in]     indices The vector of indices representing the jumbling pattern.
    \returns       The number of reorderings required.
    \par Examples:
          Given the numbers 2, 0, 3, 1, we select 2 as the search.
*/
unsigned jumbler(const std::vector<std::size_t>& indices) ;
