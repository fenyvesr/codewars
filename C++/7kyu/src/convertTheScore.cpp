/*!
***     \file        convertTheScore.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b6c220fa0a661fbf200005d
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/5b6c220fa0a661fbf200005d and its test function.
***
**/
#include "convertTheScore.h"

#include <map>     /* Needed for std::map */
#include <regex>   /* Needed for std::regex, std::smatch, std::regex_search */

/*! \brief This string contains the different possibilities as scores. */
const std::string numbers = "(nil|one|two|three|four|five|six|seven|eight|nine)";
/*! \brief This map contains the possible number strings with their numerical value. */
const std::map< std::string, int, std::less<> > mapString = { {"nil",0},{"one",1},{"two",2},{"three",3},{"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9} };

std::vector<int> convertTheScore(const std::string& s) {
    std::smatch m; /* Contains the match results. */
    /* Searching for the two numbers representing the scores in the input string. */
    std::regex_search(s, m, std::regex(numbers + ".*" + numbers));
    /* Returning the scores as numbers as a pair. */
    return { mapString.at(m[1].str()), mapString.at(m[2].str()) };
}
