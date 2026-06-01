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

std::string smoothNumbers(unsigned long n){
    int max; /* The maximum divisor. */
    /* Dividing n with the divisor. */
    for (max = 2; 1 != n && max <= 7; max += (0 == n % max) ? 0 : 1, n /= (0 == n % max) ? max : 1);
    /* Deciding the return string based on the maximum divisor. */
    std::string result;

    if(2 == max)
        result = "power of 2";
    else if(3 == max)
        result = "3-smooth";
    else if(5 == max)
        result = "Hamming number";
    else if(7 == max)
        result = "humble number";
    else
        result = "non-smooth";

    return result;
}
