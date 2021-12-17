/*!
***     \file        tramCapacity.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b190aa7803388ec97000054
***
***     \par    Description:
***                  Linear Kingdom has exactly one tram line. It has n stops, numbered from 1 to n in the order of tram's movement. At the i-th stop ai passengers exit the tram, while bi passengers enter it. The tram is empty before it arrives at the first stop.\n
***                  Calculate the tram's minimum capacity such that the number of people inside the tram never exceeds this capacity at any time. Note that at each stop all exiting passengers exit before any entering passenger enters the tram.
***
**/

#ifndef _TRAM_CAPACITY_H_
#define _TRAM_CAPACITY_H_

#include <vector> /* Needed for std::vector, std::vector::cbegin, std::vector::cend, std::vector::size, std::vector::begin */

/*!
    \brief           This function evaluates how much capacity the tram needs with the given input parameters.
    \param[in] stops Number of stops the tram takes.
    \param[in] a     Vector containing the number of passengers taking off at a given station.
    \param[in] b     Vector containing the number of passengers getting on at a given station.
    \returns         How much passenger capacity the tram needs on the given line.
    \par Example:
         4, {0, 2, 4, 4} and {3, 5, 2, 0} shall return 6.
*/
int tramCapacity(int stops, const std::vector<int>& a, const std::vector<int>& b);

/*! \brief This function tests the tramCapacity function. **/
void tramCapacityTest ();

#endif /* _TRAM_CAPACITY_H_ */