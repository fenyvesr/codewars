/*!
***     \file        removeDuplicateWords.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b39e3772ae7545f650000fc
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/5b39e3772ae7545f650000fc and its test function.
***
**/
#include "removeDuplicateWords.h"

#include <cassert>   /*!< Needed for assert */
#include <vector>    /*!< Needed for std::vector, std::back_inserter, std::vector::begin, std::vector::end */
#include <numeric>   /*!< Needed for std::accumulate */
#include <algorithm> /*!< Needed for std::copy_if */
#include <sstream>   /*!< Needed for std::istringstream, std::istream_iterator */

std::string removeDuplicateWords(const std::string& str) {
    std::istringstream iss(str); /*!< Input string stream based on the input string. */
    std::vector<std::string> words; /*!< Collection of the words in the input string. */
    /* We are copying the words from the input stream into the word collection in case it is not yet present. */
    std::copy_if(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), std::back_inserter(words),
        [&words](const auto& word) { return words.end() == std::find(words.begin(), words.end(), word); });
    /* Concatenating the word collection with spaces. */
    return std::accumulate(words.begin(), words.end(), std::string(),
        [](std::string& acc, const std::string& word) {return acc + (acc.size() ? " " : "") + word; });
}

void removeDuplicateWordsTest (){
    assert(("Wrong value for \"alpha beta beta gamma gamma gamma delta alpha beta beta gamma gamma gamma delta\"" , "alpha beta gamma delta" == removeDuplicateWords("alpha beta beta gamma gamma gamma delta alpha beta beta gamma gamma gamma delta")));
    assert(("Wrong value for \"my cat is cat fat\"" , "my cat is fat" == removeDuplicateWords("my cat is cat fat")));
}
