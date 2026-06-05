/*!
***     \file        restoreBrackets.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/66d36190e3fb412d34b4c25f
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/66d36190e3fb412d34b4c25f.
***
**/
#include "restoreBrackets.h"

#include <vector> /* Needed for std::vector */

std::string restore_brackets(std::string_view s) {
    /* Contains the result */
    std::string r{ };
    /* Vector keeping track of the number of children nodes */
    std::vector<short> b{ 0 };
    /* Iterates over the input*/
    for (const auto c : s) {
        /* Closes all nodes with two children */
        for (; 2 == b.back(); r += ']', b.pop_back(), ++b.back());
        c == '[' ? (b.push_back(0), 0) : ++b.back();
        r+=c;
    }
    /* Closes the left over levels */
    return r.append(b.size() - 1, ']');
}
