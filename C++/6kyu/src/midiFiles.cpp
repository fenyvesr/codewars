/*!
***     \file        midiFiles.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/6a020680357f9fb3614e6502
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/6a020680357f9fb3614e6502.
***
**/
#include "midiFiles.h"

#include <numeric>   /* Needed for std::accumulate */

std::vector<int> encode(int n) {
    std::vector<int> result;
    do result.push_back((n & 0x7F) | (result.empty() ? 0x00 : 0x80)); while (n >>= 7);
    return {result.rbegin(), result.rend()};
}

int decode(const std::vector<int>& data) {
    return std::accumulate(data.begin(), data.end(), 0, [&, active = true](int acc, int b) mutable {
        return active ? (active = bool(b & 0x80), (acc << 7) | (b & 0x7F)) : acc; }); // NOSONAR - comma operator is intended for performance purposes.
}
