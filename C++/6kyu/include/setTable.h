/*!
***     \file        setTable.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/6646c0c08b97085ca216d346
***
***     \par    Description:
***                  In the Great Hall of Ghosts, you must seat deceased members at a 12-seat round table\n
***                  based on their preferred cultural features determined by the first letter of their name.\n
***                  Each ghost chooses the seat closest to their preferred corner feature,\n
***                  with counter-clockwise preference for equidistant seats.\n
***                  Only the first 12 ghosts can be seated; empty seats are marked with "_____".
***
**/

#pragma once

#include <vector>
#include <string>

/*!
    \brief       Assigns ghosts to seats at the Grand Table based on their name preferences.
    \param[in] the_dead The list of names of the deceased (0 to 18 names, each 5 chars long).
    \returns     A vector of 12 names representing the final seating arrangement clockwise from top-left,\n
                 with empty seats represented by "_____".
    \par Examples:
         Input: ['Yojne', 'Xenna', 'Verap', ...] shall return ['Teseb', 'Onets', 'Verap', 'Xenna', 'Ebyam', 'Ycuag', 'Yojne', 'Yrovi', 'Lizuf', 'Skcaw', 'Girnu', 'Tpets']\n
         Seating is determined by:\n
         - QUTHCRDMZ -> Earthenware (corner seat 1)\n
         - WEVOXING -> Waterfall (corner seat 4)\n
         - JFABKPLY -> Fireplace (corner seat 7)\n
         - SSSSSSSSS -> Windowsill (corner seat 10)
*/
std::vector<std::string> set_table(const std::vector<std::string>& the_dead);
