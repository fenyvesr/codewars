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

#include <cassert>  /* Needed for assert */
#include <iterator> /* Needed for prev, next */

std::vector<int> leonardoNumbers (int n, int L0, int L1, int add){
    std::vector<int> result({L0,L1}); /* Vector containing the first two Leonardo numbers. */
    /* The next Leonardo numbers can be added to the vector by the given algorithm */
    while(2 != n--) result.push_back(add + *prev(result.end()) + *prev(prev(result.end())));
    return result;
}

void leonardoNumbersTest (){
    assert(("Wrong value for 5, 1, 1, 1" , std::vector<int>{ 1, 1, 3, 5, 9 } == leonardoNumbers(5, 1, 1, 1)));
    assert(("Wrong value for 5, 0, 0, 2" , std::vector<int>{ 0, 0, 2, 4, 8 } == leonardoNumbers(5, 0, 0, 2)));
    assert(("Wrong value for 5, 0, 0, 0" , std::vector<int>{ 0, 0, 0, 0, 0 } == leonardoNumbers(5, 0, 0, 0)));
}
