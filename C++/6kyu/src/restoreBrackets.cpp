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

std::string restore_brackets(std::string_view s){
    std::string result{ s };
    /* The variable 'c' keeps track of the number of child nodes at each depth */
    short c[256]{};
    /* The variable 'd' keeps track of the current depth of nested brackets. It is initialized to 0, indicating that we are at the outermost level of the string. */
    short d{ 0 };
    for(size_t i{ 0 }; i < result.size(); ++i){
        /* Close all nested levels, where the number of children is two */
        for(; (0!= d) && (2 == c[d]); ++c[--d]) result.insert(i++, 1, ']');
        /* Check for new nested bracket */
        ('[' == result[i]) ? c[++d] = 0 : ++c[d];
    }
    /* Close remaining nested brackets */
    return result.append(d,']');
}
