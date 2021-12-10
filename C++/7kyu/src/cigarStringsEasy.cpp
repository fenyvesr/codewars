/*!
***     \file        cigarStringsEasy.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b64d2cd83d64828ce000039
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/5b64d2cd83d64828ce000039 and its test function.
***
**/
#include "cigarStringsEasy.h"

#include <cassert> /*!< Needed for assert */
#include <regex>   /*!< Needed for std::regex, std::sregex_iterator */

std::string cigarStringsEasy(const std::string& cigar, const std::string& nuc_seq) {
    size_t k = 0; /*!< Value containing the length of the genome coded by the cigar string. */
    std::regex re("\\d+"); /*!< Regular expression describing a number. */

    /* Iterating over the cigar string and accumulating the numbers it contains. */
    for (auto it = std::sregex_iterator(cigar.begin(), cigar.end(), re); it != std::sregex_iterator(); k += std::stoi(it++->str()));
    /* If the numbers do not add up to the length of the amino acid sequence, then it is an invalid cigar string. */
    /* Otherwise, it is a successful reading only if the cigar string has an xM format. */
    return k != nuc_seq.size() ? "Invalid cigar" : std::to_string(k) + "M" == cigar ? "True" : "False";
}

void cigarStringsEasyTest (){
    assert(("Wrong value for \"ACTGC\" and \"5M\"", "True" == cigarStringsEasy("5M","ACTGC")));
    assert(("Wrong value for \"ACTGC\" and \"3M2S\"", "False" == cigarStringsEasy("3M2S","ACTGC")));
    assert(("Wrong value for \"ACTGC\" and \"5M\"", "Invalid cigar" == cigarStringsEasy("4M2S","ACTGC")));
}
