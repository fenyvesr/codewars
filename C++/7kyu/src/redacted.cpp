/*!
***     \file        redacted.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b662d286d0db722bd000013
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/5b662d286d0db722bd000013.
***
**/
#include "redacted.h"

#include <algorithm> /* Needed for std::equal */

bool redacted(std::string_view doc1, std::string_view doc2)
{
    /* Iterating over the two input strings and comparing the characters. */
    return std::equal(doc1.begin(), doc1.end(),
                      doc2.begin(), doc2.end(),
                      [](const char& a, const char& b){ return (a == b) || ( 'X' == a && '\n' != b ); });
}
