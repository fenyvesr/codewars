/*!
***     \file        offloadYourWork.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b3e1dca3da310a4390000f3
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/5b3e1dca3da310a4390000f3 and its test function.
***
**/
#include "offloadYourWork.h"

#include <cassert> /* Needed for assert*/

std::string offloadYourWork(int projectMinutes, std::vector<std::pair<int, int>> freelancers){
    /* We can reduce the project minutes by the available freelancer resource minutes. */
    for (auto freelancer : freelancers)
        projectMinutes -= freelancer.first * 60 + freelancer.second;
    /* If the corrected project minutes are positive, then we have to work. Otherwise our freelancers can do the job instead of us. */
    return (projectMinutes > 0) ? "I need to work " + std::to_string(projectMinutes / 60) + " hour(s) and " + std::to_string(projectMinutes % 60) + " minute(s)"
                                : "Easy Money!";
}

void offloadYourWorkTest (){
    assert(("Wrong value for 60 and {{1,0}}"             , "Easy Money!"                              == offloadYourWork(60 , {{1,0}         })));
    assert(("Wrong value for 60 and {{0,0}}"             , "I need to work 1 hour(s) and 0 minute(s)" == offloadYourWork(60 , {{0,0}         })));
    assert(("Wrong value for 141 and {{1,55}, {0,25}}"   , "I need to work 0 hour(s) and 1 minute(s)" == offloadYourWork(141, {{1,55}, {0,25}})));
}
