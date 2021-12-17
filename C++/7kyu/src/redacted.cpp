/*!
***     \file        redacted.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b662d286d0db722bd000013
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/5b662d286d0db722bd000013 and its test function.
***
**/
#include "cigarStringsEasy.h"

#include <cassert>   /* Needed for assert */
#include <algorithm> /* Needed for std::equal */

bool redacted(const std::string& doc1, const std::string& doc2)
{
    /* Iterating over the two input strings and comparing the characters. */
    return std::equal(doc1.begin(), doc1.end(),
                      doc2.begin(), doc2.end(),
                      [](const char& a, const char& b){ return (a == b) || ( 'X' == a && '\n' != b ); });
}

void redactedTest (){
    assert(("Wrong value for \"TOP SECRET:\nThe missile launch code for Sunday XXXXXXXXXX is:\nXXXXXXXXXXXXXXXXX\" and \"TOP SECRET:\nThe missile launch code for Sunday 5th August is:\n7-ZERO-8X-ALPHA-1\"", true == redacted("TOP SECRET:\nThe missile launch code for Sunday XXXXXXXXXX is:\nXXXXXXXXXXXXXXXXX","TOP SECRET:\nThe missile launch code for Sunday 5th August is:\n7-ZERO-8X-ALPHA-1")));
    assert(("Wrong value for \"The name of the mole is Professor XXXXX\" and \"The name of the mole is Professor Dinglemouse\"", false == redacted("The name of the mole is Professor XXXXX","The name of the mole is Professor Dinglemouse")));
    assert(("Wrong value for \"XXXXXXXX XXXXXXX XXXXXXXXXXXXXXXXXXX\nXXXX XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX XXXXXXXXX XXXXXXXXXXXXX XXXXX\" and \"Area-51. Medical Report. 23/Oct/1969\nE.T. subject 4 was given an asprin after reporting sick for duty today\"", true == redacted("XXXXXXXX XXXXXXX XXXXXXXXXXXXXXXXXXX\nXXXX XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX XXXXXXXXX XXXXXXXXXXXXX XXXXX","Area-51. Medical Report. 23/Oct/1969\nE.T. subject 4 was given an asprin after reporting sick for duty today")));


}
