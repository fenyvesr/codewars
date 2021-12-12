/*!
***     \file        smoothNumbers.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b2f6ad842b27ea689000082
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/5b2f6ad842b27ea689000082 and its test function.
***
**/
#include "smoothNumbers.h"

#include <cassert> /*!< Needed for assert */

std::string smoothNumbers(unsigned long n){
    int max; /*!< The maximum divisor. */
    /* Divinding n with the divisor. */
    for (max = 2; 1 != n && max <= 7; max += (0 == n % max) ? 0 : 1, n /= (0 == n % max) ? max : 1);
    /* Deciding the return string based on the maximum divisor. */
    return 2 == max ? "power of 2"
         : 3 == max ? "3-smooth"
         : 5 == max ? "Hamming number"
         : 7 == max ? "humble number"
         : "non-smooth";
}

void smoothNumbersTest (){
    assert(("Wrong value for 16"  , "power of 2"     == smoothNumbers(16 )));
    assert(("Wrong value for 36"  , "3-smooth"       == smoothNumbers(36 )));
    assert(("Wrong value for 60"  , "Hamming number" == smoothNumbers(60 )));
    assert(("Wrong value for 98"  , "humble number"  == smoothNumbers(98 )));
    assert(("Wrong value for 111" , "non-smooth"     == smoothNumbers(111)));
}
