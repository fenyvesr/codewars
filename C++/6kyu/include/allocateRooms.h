/*!
***     \file        allocateRooms.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/6638277786032a014d3e0072
***
***     \par    Description:
***                  Given a list of customers where each customer requests a room in a hotel with a specific size
***                  and must be allocated to a room that fits the request. The function returns an allocation mapping
***                  customers to room indices (or -1 if no room available). See the kata for full details.
***
**/

#pragma once

#include <vector>

/*!
    \brief       Allocates rooms to customers based on requested sizes.
    \param[in] customers A list of customers where each customer is represented by a vector<int> describing their requirements.
    \returns     A vector<int> with the allocated room index for each customer, or -1 when no room can be allocated.
    \warning     Follow the allocation rules described in the kata; constraints up to large sizes apply.
*/
std::vector<int> allocateRooms(const std::vector<std::vector<int>>& customers);
