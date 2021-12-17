/*!
***     \file        stringPacketBasedCommunication.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b2be37991c7460d17000009
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/5b2be37991c7460d17000009 and its test function.
***
**/
#include "stringPacketBasedCommunication.h"

#include <cassert>    /* Needed for assert */
#include <regex>      /* Needed for std::regex, std::regex_match, std::smatch */
#include <map>        /* Needed for std::map, std::map::operator[] */
#include <functional> /* Needed for std::function */

/*! \brief This variable contains the instruction codes and the functions to invoke based on the packet. */
std::map<std::string, std::function<int (const int&, const int&)>> codes = { {"0F12",std::plus<>()}, {"B7A2",std::minus<>()}, {"C3D9", std::multiplies<>()} };

std::string stringPacketBasedCommunication(std::string packet) {
    std::smatch m; /* Contains the match results. */
    /* Matching the input packet with a regular expression describing the format. */
    std::regex_match(packet, m, std::regex("(.{4})(0F12|B7A2|C3D9)(\\d{4})(\\d{4})(.{4})"));
    /* Executing the required instruction with the given data. */
    std::string result = std::to_string(std::min(9999, std::max(0, codes[m[2]](std::stoi(m[3]), std::stoi(m[4])))));
    /* Formatting the output packet. */
    return m[1].str() + "FFFF" + std::string(4 - result.size(),'0') + result + "0000" + m[5].str();
}

void stringPacketBasedCommunicationTest (){
    assert(("Wrong value for \"H1H10F1200120008F4F4\"" , "H1H1FFFF00200000F4F4" == stringPacketBasedCommunication("H1H10F1200120008F4F4")));
    assert(("Wrong value for \"X7X7B7A201400058L0L0\"" , "X7X7FFFF00820000L0L0" == stringPacketBasedCommunication("X7X7B7A201400058L0L0")));
    assert(("Wrong value for \"R5R5C3D900120008K4K4\"" , "R5R5FFFF00960000K4K4" == stringPacketBasedCommunication("R5R5C3D900120008K4K4")));
}
