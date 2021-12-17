/*!
***     \file        fixStringCase.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b180e9fedaa564a7000009a
***
***     \par    Description:
***                  In this Kata, you will be given a string that may have mixed uppercase and lowercase letters and your task is to convert that string to either lowercase only or uppercase only based on:
***                  - make as few changes as possible.
***                  - if the string contains equal number of uppercase and lowercase letters, convert the string to lowercase.
***
**/

#ifndef _FIX_STRING_CASE_H_
#define _FIX_STRING_CASE_H_

#include <string> /* Needed for std::string, std::to_string, std::stoi */

/*!
    \brief         This function changes the case of the characters in a string based on the original number of lower and upper case characters.
    \param[in] str The input string.
    \returns       A string containing either only lower or only upper case characters.
    \par Examples:
         "code" shall return "code"\n
         "CODe" shall return "CODE"
*/
std::string fixStringCase(const std::string& str);

/*! \brief This function tests the fixStringCase function. **/
void fixStringCaseTest ();

#endif /* _FIX_STRING_CASE_H_ */