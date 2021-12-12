/*!
***     \file        leonardoNumbers.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b37a50642b27ebf2e000010
***
***     \par    Description:
***                  Return the first n Leonardo numbers as an array\n
***                  The Leonardo numbers are a sequence of numbers defined by:\n
***                  \f$L_x = L_{x - 1} + L_{x - 2} + a\f$
***
**/

#ifndef _LEONARDO_NUMBERS_H_
#define _LEONARDO_NUMBERS_H_

#include <vector> /*<! Needed for std::vector */

/*!
    \brief         This function gives back an array containing the first n Leonardo numbers.
    \param[in] n   The number defining how many Leonardo numbers shall be computed.
    \param[in] L0  The 0th Leonardo number.
    \param[in] L1  The 1st Leonardo number.
    \param[in] add The number whihch has to be added to every Leonardo number.
    \returns       A vector containing the first n Leonardo number.
    \par Example:
                 5, 1, 1 and 1 shall return { 1, 1, 3, 5, 9 }.
    \warning       The input n shall be always greater than or equal to 2.
*/
std::vector<int> leonardoNumbers (int n, int L0, int L1, int add);

/*! \brief This function tests the leonardoNumbers function. **/
void leonardoNumbersTest ();

#endif /* _LEONARDO_NUMBERS_H_ */