/*!
***     \file        ancestorVariations.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/691863fe0c68b12e8cf47452
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/691863fe0c68b12e8cf47452.
***
**/
#include "ancestorVariations.h"

int ancestor_variations(long long n) {
    int result{ 1 };
    long long base{ 2 };
    for (; n; n >>= 1, base = (base * base) % 1000000007)
        if (n & 1)
            result = (result * base) % 1000000007;
    return result;
}
