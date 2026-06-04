/*!
***     \file        largestGreatestCommonDivisor.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/691406025add8e3337a9bf53
***
***     \par    Description:
***                  You are given positive integers a and b (a < b).\n
***                  Find a positive integer k such that gcd(a+k, b+k) is maximized.\n
***                  If there are multiple values of k that satisfy the condition above, return the smallest one.\n
***                  Here gcd(x,y) means the greatest common divisor of x and y.
***
**/

#pragma once

/*!
    \brief       Finds the value k that maximizes gcd(a+k, b+k).
    \param[in]   a The first positive integer (a < b).
    \param[in]   b The second positive integer (a < b).
    \returns     The smallest positive integer k such that gcd(a+k, b+k) is maximized.
    \par Examples:
         a = 12, b = 18 shall return k such that gcd(12+k, 18+k) is maximized\n
         a = 1, b = 2 shall return the smallest k that maximizes the GCD
    \warning Both a and b are positive integers with 1 <= a < b <= 10^18.
*/
constexpr long long get_k(long long a, long long b){
    return b - a - (a % (b-a));
}
