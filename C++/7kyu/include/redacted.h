/*!
***     \file        redacted.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b662d286d0db722bd000013
***
***     \par    Description:
***                  Your job is to compare two confidential documents that have come into your possession.\n
***                  The first document has parts redacted, and the other one doesn't.\n
***                  But the original (unredacted) document might be a fake!\n
***                  You need to compare the two documents and decide if it is possible they are the same or not.
***
**/

#ifndef _REDACTED_H_
#define _REDACTED_H_

#include <string>

/*!
    \brief          This function decides whether the two documents are possivly the same.
    \param[in] doc1 Redacted document.
    \param[in] doc2 Original document.
    \returns        Whether the two documents are possibly the same.
    \par Example:
         "TOP SECRET:\\nThe missile launch code for Sunday XXXXXXXXXX is:\\nXXXXXXXXXXXXXXXXX"\n
         "TOP SECRET:\\nThe missile launch code for Sunday 5th August is:\\n7-ZERO-8X-ALPHA-1"\n
         shall return true.
*/
bool redacted(const std::string &doc1, const std::string &doc2);

/*! \brief This function tests the redacted function. **/
void redactedTest ();

#endif /* _REDACTED_H_ */