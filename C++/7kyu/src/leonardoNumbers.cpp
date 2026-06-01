/*!
***     \file        leonardoNumbers.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b2117eea454c89d4400005f
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/5b2117eea454c89d4400005f and its test function.
***
**/
#include "leonardoNumbers.h"

#include <iterator> /* Needed for prev, next */

std::vector<int> leonardoNumbers (int n, int L0, int L1, int add){
    std::vector<int> result({L0,L1}); /* Vector containing the first two Leonardo numbers. */
    /* The next Leonardo numbers can be added to the vector by the given algorithm */
    while(2 != n--) result.push_back(add + *prev(result.end()) + *prev(prev(result.end())));
    return result;
}
