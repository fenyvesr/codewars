/*!
***     \file        queueTimeCounter.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b538734beb8654d6b00016d
***
***     \par    Description:
***                  You managed to send your friend to queue for tickets in your stead, but there is a catch: he will get there only if you tell him how much that is going to take. And everybody can only take one ticket at a time, then they go back in the last position of the queue if they need more (or go home if they are fine).\n
***                  Each ticket takes one minutes to emit, the queue is well disciplined, Brit-style, and so it moves smoothly, with no waste of time.\n
***                  You will be given an array/list/vector with all the people queuing and the initial position of your buddy, so for example, knowing that your friend is in the third position (that we will consider equal to the index, 2: he is the guy that wants 3 tickets!) and the initial queue is [2, 5, 3, 4, 6].\n
***                  The first dude gets his ticket and the queue goes now like this [5, 3, 4, 6, 1], then [3, 4, 6, 1, 4] and so on. In the end, our buddy will be queuing for 12 minutes, true story!\n
***                  Build a function to compute it, resting assured that only positive integers are going to be there and you will be always given a valid index; but we also want to go to pretty popular events, so be ready for big queues with people getting plenty of tickets.
***
**/

#ifndef _QUEUE_TIME_COUNTER_H_
#define _QUEUE_TIME_COUNTER_H_

#include <vector>

/*!
    \brief             This function count how many time our friend has to wait in the line.
    \param[in] queuers Array containing how many tickets the queuers would like to buy.
    \param[in] pos     The position of our friend in the queue.
    \returns           The number of minutes our friend ahs to wait.
    \par Example:
        If the initial queue is [2, 5, 3, 4, 6] and our friend is the third, then the first dude gets his ticket and the queue goes now like this [5, 3, 4, 6, 1], then [3, 4, 6, 1, 4] and so on. In the end, our buddy will be queuing for 12 minutes.
    \par Solution:
        Lets say our friend wants \f$\displaystyle k\f$ tickets and the i-th person wants \f$\displaystyle k_i\f$ tickets. In this case everybody who is before him will count for \f$\displaystyle\min(k, k_i)\f$ times while everybody who is after him will count for \f$\displaystyle\min(k-1, k_i)\f$ times.
        We just have to accumulate these values. \f$\displaystyle result = \sum_{i=0}^{pos} \min\left\{queuers[pos],queuers[i]\right\} + \sum_{i=pos+1}^{queuers.size()-1} \min\left\{queuers[pos]-1,queuers[i]\right\}\f$ .
*/
long long queueTimeCounter(const std::vector<int>& queuers, int pos);

/*! \brief This function tests the queueTimeCounter function. **/
void queueTimeCounterTest ();

#endif /* _QUEUE_TIME_COUNTER_H_ */