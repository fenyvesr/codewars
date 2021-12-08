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

#include <cassert>

long long queueTimeCounter(const std::vector<int>& queuers, int pos){
  //your code here
  long long res =  0;
  for(size_t i = 0; i < queuers.size(); res += std::min(queuers[pos] - (i > pos), queuers[i]), ++i);
  return res;
}

void queueTimeCounterTest (){
    assert(("Wrong value for {2, 5, 3, 6, 4} and 0", 6 == queueTimeCounter({2, 5, 3, 6, 4}, 0)));
    assert(("Wrong value for {2, 5, 3, 6, 4} and 1", 18 == queueTimeCounter({2, 5, 3, 6, 4}, 1)));
    assert(("Wrong value for {2, 5, 3, 6, 4} and 2", 12 == queueTimeCounter({2, 5, 3, 6, 4}, 2)));
    assert(("Wrong value for {2, 5, 3, 6, 4} and 3", 20 == queueTimeCounter({2, 5, 3, 6, 4}, 3)));
    assert(("Wrong value for {2, 5, 3, 6, 4} and 4", 17 == queueTimeCounter({2, 5, 3, 6, 4}, 4)));
}
