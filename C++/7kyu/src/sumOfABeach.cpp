/*!
***     \file        sumOfABeach.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b3e1dca3da310a4390000f3
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/5b3e1dca3da310a4390000f3 and its test function.
***
**/
#include "sumOfABeach.h"

#include <cassert> /*!< Needed for assert */
#include <regex>   /*!< Needed for std::regex, std::regex_constants::icase */

int sumOfABeach(std::string s){
    std::regex re("sand|water|fish|sun", std::regex_constants::icase); /*!< Regular expression case-insensitive for sand, water, fish and sum */
    /* Calculating the number of matches. */
    return std::distance(std::sregex_iterator(s.begin(), s.end(), re), {});
}

void sumOfABeachTest (){
    assert(("Wrong value for \"WAtErSlIde\""                 , 1 == sumOfABeach("WAtErSlIde")));
    assert(("Wrong value for \"GolDeNSanDyWateRyBeaChSuNN\"" , 3 == sumOfABeach("GolDeNSanDyWateRyBeaChSuNN")));
    assert(("Wrong value for \"gOfIshsunesunFiSh\""          , 4 == sumOfABeach("gOfIshsunesunFiSh")));
    assert(("Wrong value for \"cItYTowNcARShoW\""            , 0 == sumOfABeach("cItYTowNcARShoW")));
}
