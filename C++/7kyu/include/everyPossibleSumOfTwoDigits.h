/*!
***     \file        everyPossibleSumOfTwoDigits.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b4e474305f04bea11000148
***
***     \par    Description:
***                  You managed to send your friend to queue for tickets in your stead, but there is a catch: he will get there only if you tell him how much that is going to take. And everybody can only take one ticket at a time, then they go back in the last position of the queue if they need more (or go home if they are fine).\n
***                  Each ticket takes one minutes to emit, the queue is well disciplined, Brit-style, and so it moves smoothly, with no waste of time.\n
***                  You will be given an array/list/vector with all the people queuing and the initial position of your buddy, so for example, knowing that your friend is in the third position (that we will consider equal to the index, 2: he is the guy that wants 3 tickets!) and the initial queue is [2, 5, 3, 4, 6].\n
***                  The first dude gets his ticket and the queue goes now like this [5, 3, 4, 6, 1], then [3, 4, 6, 1, 4] and so on. In the end, our buddy will be queuing for 12 minutes, true story!\n
***                  Build a function to compute it, resting assured that only positive integers are going to be there and you will be always given a valid index; but we also want to go to pretty popular events, so be ready for big queues with people getting plenty of tickets.
***
**/

#ifndef _EVERY_POSSIBLE_SUM_OF_TWO_DIGITS_H_
#define _EVERY_POSSIBLE_SUM_OF_TWO_DIGITS_H_

#include <vector> /* Needed for std::vector, std::vector::begin, std::vector::end, prev, std::vector::push_back */

/*!
    \brief       This function gives back the sum of every pair of digits in a number.
    \param[in] n The number for wich we are interested in the digit pair sums.
    \returns     A vector containing the possible sums.
    \par Example:
                 156 shall return { 6, 7, 11 }
*/
std::vector<int> everyPossibleSumOfTwoDigits(int n);

/*! \brief This function tests the everyPossibleSumOfTwoDigits function. **/
void everyPossibleSumOfTwoDigitsTest ();

#endif /* _EVERY_POSSIBLE_SUM_OF_TWO_DIGITS_H_ */