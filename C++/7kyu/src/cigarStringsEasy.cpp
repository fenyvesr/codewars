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

#include <cassert>
#include <regex>

std::string cigarStringsEasy(const std::string& cigar, const std::string& nuc_seq) {
    size_t k = 0;
    std::regex re("\\d+");
    for (auto it = std::sregex_iterator(cigar.begin(), cigar.end(), re); it != std::sregex_iterator(); k += std::stoi(it++->str()));
    return k != nuc_seq.size() ? "Invalid cigar" : std::to_string(k) + "M" == cigar ? "True" : "False";
}

void cigarStringsEasyTest (){
    assert(("Wrong value for \"ACTGC\" and \"5M\"", "True" == cigarStringsEasy("5M","ACTGC")));
    assert(("Wrong value for \"ACTGC\" and \"3M2S\"", "False" == cigarStringsEasy("3M2S","ACTGC")));
    assert(("Wrong value for \"ACTGC\" and \"5M\"", "Invalid cigar" == cigarStringsEasy("4M2S","ACTGC")));
}
