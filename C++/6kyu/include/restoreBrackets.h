/*!
***     \file        restoreBrackets.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/66d36190e3fb412d34b4c25f
***
***     \par    Description:
***                  This kata concerns a string composed of 'chunks'.
***                  A chunk is either a single alphabetic character or two chunks enclosed in square brackets.
***                  A 'chunky string' is a string consisting of exactly one chunk.
***                  The input is a valid chunky string with all closing brackets removed.
***                  You must restore the brackets and return the original valid chunky string.
***
**/

#pragma once

#include <string>      /* Needed for std::string */
#include <string_view> /* Needed for std::string_view */

/*!
    \brief       Restores missing closing brackets to a valid chunky string.
    \param[in]   s The input chunky string with closing brackets removed.
    \returns     The original valid chunky string with restored brackets.
    \par Examples:
         "x" shall return "x"\n
         "[xy" shall return "[xy]"\n
         "[x[yy" shall return "[x[yy]]"
*/
std::string restore_brackets(std::string_view s);
