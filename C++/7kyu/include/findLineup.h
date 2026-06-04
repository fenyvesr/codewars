/*!
***     \file        findLineup.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/6914c975e159c8f7e120cc84
***
***     \par    Description:
***                  Developers were lined up at the coffee machine, but it broke!
***                  By the time they got to the backup one, they couldn't remember where people had been in the line.
***                  They want to restore the original order. The team lead, Carrol, was first.
***                  Everyone else remembers how many people had been standing between them and Carrol.
***                  Can you help them reconstruct the original order?
***
**/

#pragma once

#include <vector> /* Needed for std::vector */

/*!
    \brief       This function gives back the order of the people in the lineup based on the distances from the first person.
    \param[in]   distances A vector containing the distances of each person from the first person.
    \returns     A vector containing the order of the people in the lineup.
    \par Example:
                 [1, 2, 0] shall return [3, 1, 2]
                 [1, 0, 1] shall return [ ]
*/
std::vector<std::size_t> find_lineup(const std::vector<std::size_t>& distances);
