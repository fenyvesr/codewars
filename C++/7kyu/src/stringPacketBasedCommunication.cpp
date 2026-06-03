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

#include <map>        /* Needed for std::map, std::map::operator[] */
#include <regex>      /* Needed for std::regex, std::regex_match, std::smatch */
#include <stdexcept> /* Needed for std::invalid_argument */
#include <functional> /* Needed for std::function */

/*! \brief This variable contains the instruction codes and the functions to invoke based on the packet. */
const std::map< std::string, std::function<int (const int&, const int&)>, std::less<> > codes = { {"0F12",std::plus<>()}, {"B7A2",std::minus<>()}, {"C3D9", std::multiplies<>()} };

std::string stringPacketBasedCommunication(const std::string& packet) {
    std::smatch m; /* Contains the match results. */
    /* Matching the input packet with a regular expression describing the format. */
    if (!std::regex_match(packet, m, std::regex("(.{4})(0F12|B7A2|C3D9)(\\d{4})(\\d{4})(.{4})")))
        throw std::invalid_argument("Invalid packet format");
    /* Executing the required instruction with the given data. */
    std::string result{ std::to_string(std::min(9999, std::max(0, codes.at(m[2].str())(std::stoi(m[3]), std::stoi(m[4]))))) };
    /* Formatting the output packet. */
    return m[1].str() + "FFFF" + std::string(4 - result.size(),'0') + result + "0000" + m[5].str();
}
