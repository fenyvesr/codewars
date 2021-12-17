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


#include <regex>   /* Needed for std::regex, std::smatch, std::regex_search */
#include <map>     /* Needed for std::map */
#include <cassert> /* Needed for assert */

/*! \brief This string contains the different possibilities as scores. */
std::string numbers = "(nil|one|two|three|four|five|six|seven|eight|nine)";
/*! \brief This map contains the possible number strings with their numerical value. */
std::map<std::string, int> mapString = { {"nil",0},{"one",1},{"two",2},{"three",3},{"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9} };

std::vector<int> convertTheScore(const std::string& s) {
    std::smatch m; /* Contains the match results. */
    /* Searching for the two numbers representing the scores in the input string. */
    std::regex_search(s, m, std::regex(numbers + ".*" + numbers));
    /* Returning the scores as numbers as a pair. */
    return {mapString[m[1]], mapString[m[2]]};
}

void convertTheScoreTest (){
    assert(("Wrong value for \"The score is four nil\"", std::vector<int> {4,0} == convertTheScore("The score is four nil")));
    assert(("Wrong value for \"new score: two three\"", std::vector<int> {2,3} == convertTheScore("new score: two three")));
    assert(("Wrong value for \"two two\"", std::vector<int> {2,2} == convertTheScore("two two")));
    assert(("Wrong value for \"Arsenal just conceded another goal, two nil\"", std::vector<int> {2,0} == convertTheScore("Arsenal just conceded another goal, two nil")));
}