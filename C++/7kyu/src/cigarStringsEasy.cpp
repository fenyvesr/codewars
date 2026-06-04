/*!
***     \file        cigarStringsEasy.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b64d2cd83d64828ce000039
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/5b64d2cd83d64828ce000039.
***
**/
#include "cigarStringsEasy.h"

#include <regex>   /* Needed for std::regex, std::sregex_iterator */
#include <string>  /* Needed for std::stoi */ 

std::string cigarStringsEasy(std::string_view cigar, std::string_view nuc_seq) {
    size_t k = 0; /* Value containing the length of the genome coded by the cigar string. */
    std::regex re("\\d+"); /* Regular expression describing a number. */

    /* Iterating over the cigar string and accumulating the numbers it contains. */
    using regex_iterator = std::regex_iterator<std::string_view::const_iterator>;
    for (auto it = regex_iterator(cigar.begin(), cigar.end(), re); it != regex_iterator(); k += std::stoi(it++->str()));
    /* If the numbers do not add up to the length of the amino acid sequence, then it is an invalid cigar string. */
    /* Otherwise, it is a successful reading only if the cigar string has an xM format. */
    std::string isSuccessful( std::to_string(k) + "M" == cigar ? "True" : "False" );
    return k != nuc_seq.size() ? std::string("Invalid cigar") : isSuccessful;
}
