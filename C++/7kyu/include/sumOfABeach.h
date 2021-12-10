/*!
***     \file        sumOfABeach.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b37a50642b27ebf2e000010
***
***     \par    Description:
***                  Beaches are filled with sand, water, fish, and sun. Given a string, calculate how many times the words "Sand", "Water", "Fish", and "Sun" appear without overlapping (regardless of the case).
***
**/

#ifndef _SUM_OF_A_BEACH_H_
#define _SUM_OF_A_BEACH_H_

#include <string> /*<! Needed for std::string, std::string::begin, std::string::end */

/*!
    \brief          This function counts how many times sand, water, fish and sun is present in the input string.
    \param[in] s    Input string.
    \returns        How many times sand, water, fish and sun is present in the input string.
    \par Example:
         "gOfIshsunesunFiSh" shall return 4.
*/
int sumOfABeach(std::string s);

/*! \brief This function tests the sumOfABeach function. **/
void sumOfABeachTest ();

#endif /* _SUM_OF_A_BEACH_H_ */