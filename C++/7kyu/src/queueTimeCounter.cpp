/*!
***     \file        queueTimeCounter.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b538734beb8654d6b00016d
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/5b538734beb8654d6b00016d and its test function.
***
**/
#include "queueTimeCounter.h"

long long queueTimeCounter(const std::vector<int>& queuers, int pos){
  long long res =  0; /* Variable containing the time needed for standing in the queue. */
  /* Everyone before our friend counts with min(k,k_i) minutes, while and everyone after him counts with min(k-1, k_i), where
     our friend wants k tickets, and the i-th person wants k_i tickets. */
  for(size_t i = 0; i < queuers.size(); res += std::min(queuers[pos] - static_cast<int>(i > pos), queuers[i]), ++i);
  return res;
}
