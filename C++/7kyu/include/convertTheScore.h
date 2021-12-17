/*!
***     \file        convertTheScore.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b6c220fa0a661fbf200005d
***
***     \par    Description:
***                  You are working at a lower league football stadium and you've been tasked with automating the scoreboard.\n
***                  The referee will shout out the score, you have already set up the voice recognition module which turns the ref's voice into a string, but the spoken score needs to be converted into a pair for the scoreboard!\n
***                  e.g. "The score is four nil" should return [4,0]\n
***                  Either teams score has a range of 0-9, and the ref won't say the same string every time e.g.\n
***                  "new score: two three"\n
***                  "two two"\n
***                  "Arsenal just conceded another goal, two nil"
***
**/

#ifndef _CONVERT_THE_SCORE_H_
#define _CONVERT_THE_SCORE_H_

#include <vector> /* Needed for std::vector */
#include <string> /* Needed for std::string, std::to_string, std::stoi */

/*!
    \brief       This function extracts the score information from a string
    \param[in] s Description of the currect scores.
    \returns     The actual scores as numerical values in a vector.
    \par Examples:
         "new score: two three" shall return {2,3}\n
         "Arsenal just conceded another goal, two nil" shall return {2,0}
    \warning The decsription of the scores has to contain exactly two numbers, which can be the followings,
             "nil", "one", "two", "three", "four", "five", "six", "seven", "eight" or "nine".
*/
std::vector<int> convertTheScore(const std::string& s);

/*! \brief This function tests the convertTheScore function. **/
void convertTheScoreTest ();

#endif /* _CONVERT_THE_SCORE_H_ */