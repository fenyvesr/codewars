/*!
***     \file        allocateRooms.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/6638277786032a014d3e0072
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/6638277786032a014d3e0072.
***
**/
#include "allocateRooms.h"

#include <queue>      /* Needed for std::priority_queue */
#include <tuple>      /* Needed for std::tuple */
#include <vector>     /* Needed for std::vector */
#include <utility>    /* Needed for std::pair */
#include <algorithm>  /* Needed for std::sort */
#include <functional> /* Needed for std::greater */

std::vector<int> allocateRooms(const std::vector<std::vector<int>>& customers) {
    std::vector<std::tuple<int, int, int>> mapping{};
    for (int i{ 0 }; i < static_cast<int>(customers.size()); mapping.emplace_back(customers[i][0], customers[i][1], i), ++i);
    std::sort(mapping.begin(), mapping.end());
    std::priority_queue< std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<> > rooms;
    std::vector<int> allocation(customers.size());
    for (auto [arrive, leave, idx] : mapping)
        (rooms.empty() || rooms.top().first >= arrive)
            ? rooms.emplace(leave, allocation[idx] = rooms.size() + 1) // NOSONAR - assignment intended in expression.
            : (allocation[idx] = rooms.top().second, rooms.pop(), rooms.emplace(leave, allocation[idx])); // NOSONAR - comma operator is intended for performance.
    return allocation;
}
