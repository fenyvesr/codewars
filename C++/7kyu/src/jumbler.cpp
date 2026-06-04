/*!
***     \file        jumbler.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/69269262ced9e95dc63abd1e
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/69269262ced9e95dc63abd1e.
***
**/
#include "jumbler.h"

#include <algorithm> /* Needed for std::rotate */

unsigned jumbler(const std::vector<std::size_t>& indices) {
    /* A vector to contain the current permutation. */
    std::vector<std::size_t> p{ indices };
    /* The number of reorderings. */
    unsigned n{ 0 };
    /* Repeatedly reordering the vector based on the first element. */
    for(; 0 != p[0U]; std::rotate(p.begin(), p.begin() + p[0U], p.begin() + p[0U] + 1U), ++n);
    return n;
}