/*!
***     \file        setTable.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/6646c0c08b97085ca216d346
***
***     \par    File description
***                  This source contains the solution implementation for https://www.codewars.com/kata/6646c0c08b97085ca216d346.
***
**/
#include "setTable.h"

#include <array>
#include <algorithm>

std::vector<std::string> set_table(const std::vector<std::string>& the_dead){
    constexpr std::size_t tableSize{ 12 };
    /* Seating */
    std::vector<std::string> table( tableSize, "_____" );
    /* Last visited distance */
    std::array<std::size_t, 4> d{ 0 };
    /* Iterate over the names */
    for(auto& name : the_dead)
        for(std::size_t k{ std::string("QUTHCRDMZWEVOXING_JFABKPLY_S").find(name[0]) / 9 }, c{ 3 * k }; d[k] < tableSize; ++d[k]){
            std::size_t i{ (c + tableSize + (d[k] % 2 ? -int(d[k] + 1) / 2 : d[k] / 2)) % tableSize };
            if( table[i] == "_____" ) { table[i] = name, ++d[k] ; break; }
        }
    return table;
}
