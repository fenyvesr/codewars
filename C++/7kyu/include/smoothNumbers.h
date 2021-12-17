/*!
***     \file        smoothNumbers.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b2f6ad842b27ea689000082
***
***     \par    Description:
***                  The concept of "smooth number" is applied to all those numbers whose prime factors are lesser than or equal to 7: 60 is a smooth number (2 * 2 * 3 * 5), 111 is not (3 * 37).\n
***                  More specifically, smooth numbers are classified by their highest prime factor and your are tasked with writing a isSmooth/is_smooth function that returns a string with this classification as it follows:
***                  - 2-smooth numbers should be all defined as a "power of 2", as they are merely that;
***                  - 3-smooth numbers are to return a result of "3-smooth";
***                  - 5-smooth numbers will be labelled as "Hamming number"s (incidentally, you might appreciate this nice kata on them);
***                  - 7-smooth numbers are classified as "humble number"s;
***                  - for all the other numbers, just return non-smooth.\n
***     \par    Examples:
***                  isSmooth(16) == "power of 2"\n
***                  isSmooth(36) == "3-smooth"\n
***                  isSmooth(60) == "Hamming number"\n
***                  isSmooth(98) == "humble number"\n
***                  isSmooth(111) == "non-smooth"\n
***                  The provided input n is always going to be a positive number > 1.
***
**/

#ifndef _SMOOTH_NUMBERS_H_
#define _SMOOTH_NUMBERS_H_

#include <string> /* Needed for std::string */

/*!
    \brief       This function decides what kind of number the input is.
    \param[in] n Input number.
    \returns     The type of the input number.
    \par Example:
         16 shall return "power of 2"
*/
std::string smoothNumbers(unsigned long n);

/*! \brief This function tests the smoothNumbers function. **/
void smoothNumbersTest ();

#endif /* _SMOOTH_NUMBERS_H_ */
