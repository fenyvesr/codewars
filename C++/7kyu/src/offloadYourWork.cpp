/*!
***     \file        offloadYourWork.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b3e1dca3da310a4390000f3
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/5b3e1dca3da310a4390000f3.
***
**/
#include "offloadYourWork.h"

#include <numeric> /* Needed for std::accumulate */

std::string offloadYourWork(int projectMinutes, const std::vector<std::pair<int, int>>& freelancers){
    /* We can reduce the project minutes by the available freelancer resource minutes. */
    projectMinutes -= std::accumulate(
        freelancers.begin(), freelancers.end(), 0,
        [](int sum, const auto& freelancer) {
            return sum + freelancer.first * 60 + freelancer.second;
        });
    /* If the corrected project minutes are positive, then we have to work. Otherwise our freelancers can do the job instead of us. */
    return (projectMinutes > 0) ? "I need to work " + std::to_string(projectMinutes / 60) + " hour(s) and " + std::to_string(projectMinutes % 60) + " minute(s)"
                                : "Easy Money!";
}
