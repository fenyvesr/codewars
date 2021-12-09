/*!
***     \file        offloadYourWork.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b3e1dca3da310a4390000f3
***
***     \par    Description:
***                  You are the best freelancer in the city. Everybody knows you, but what they don't know, is that you are actually offloading your work to other freelancers and you rarely need to do any work. You're living the life!\n
***                  To make this process easier you need to write a method called workNeeded to figure out how much time you need to contribute to a project.\n
***                  Giving the amount of time in minutes needed to complete the project and an array of pair values representing other freelancers' time in [Hours, Minutes] format ie. [[2, 33], [3, 44]] calculate how much time you will need to contribute to the project (if at all) and return a string depending on the case.\n
***                  If we need to contribute time to the project then return "I need to work x hour(s) and y minute(s)"\n
***                  If we don't have to contribute any time to the project then return "Easy Money!"
***
**/

#ifndef _OFFLOAD_YOUR_WORK_H_
#define _OFFLOAD_YOUR_WORK_H_

#include <vector>
#include <string>

/*!
    \brief                    This function evaluates whether you have to work at all and if yes, then how much you have to work.
    \param[in] projectMinutes Time needed for the project.
    \param[in] freelancers    Time available from our freelancers.
    \returns                  Whether we need to work and if yes, then how much.
    \par Example:
                  141 and {{1,55}, {0,25}} shall return "I need to work 0 hour(s) and 1 minute(s)".
*/
std::string offloadYourWork(int projectMinutes, std::vector<std::pair<int, int>> freelancers);

/*! \brief This function tests the offloadYourWork function. **/
void offloadYourWorkTest ();

#endif /* _OFFLOAD_YOUR_WORK_H_ */