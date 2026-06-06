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

#include <range/v3/view/iota.hpp>        /* Needed for ranges::views::iota */
#include <range/v3/action/sort.hpp>      /* Needed for ranges::actions::sort */
#include <range/v3/view/transform.hpp>   /* Needed for ranges::views::transform */
#include <range/v3/range/conversion.hpp> /* Needed for ranges::to */

#include <queue>      /* Needed for std::priority_queue */
#include <tuple>      /* Needed for std::tuple */
#include <vector>     /* Needed for std::vector */
#include <cstddef>    /* Needed for std::size_t */
#include <utility>    /* Needed for std::pair */
#include <functional> /* Needed for std::greater */

std::vector<int> allocateRooms(const std::vector<std::vector<int>>& customers) {
    auto mapping = ranges::views::iota(std::size_t{0}, customers.size())
                 | ranges::views::transform([&customers](auto i) { return std::tuple{customers[i][0], customers[i][1], static_cast<int>(i)}; })
                 | ranges::to<std::vector>()
                 | ranges::actions::sort;
    std::priority_queue< std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<> > rooms;
    std::vector<int> allocation(customers.size());
    for (auto [arrive, leave, idx] : mapping)
        (rooms.empty() || rooms.top().first >= arrive)
            ? rooms.emplace(leave, allocation[idx] = rooms.size() + 1) // NOSONAR - assignment intended in expression.
            : (allocation[idx] = rooms.top().second, rooms.pop(), rooms.emplace(leave, allocation[idx])); // NOSONAR - comma operator is intended for performance.
    return allocation;
}
