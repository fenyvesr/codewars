/*!
***     \file        removeDuplicateWords.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b39e3772ae7545f650000fc
***
***     \par    Description:
***                  Your task is to remove all duplicate words from a string, leaving only single (first) words entries.\n
***                  The result for "alpha beta beta gamma gamma gamma delta alpha beta beta gamma gamma gamma delta' shall be "alpha beta gamma delta"
***
**/

#ifndef _REMOVE_DUPLICATE_WORDS_H_
#define _REMOVE_DUPLICATE_WORDS_H_

#include <string> /* Needed for std::string, std::string::size */

std::string removeDuplicateWords(const std::string& str);

/*! \brief This function tests the removeDuplicateWords function. **/
void removeDuplicateWordsTest ();

#endif /* _REMOVE_DUPLICATE_WORDS_H_ */