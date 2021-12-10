/*!
***     \file        subarrayElementsSum.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b5e0ef007a26632c400002a
***
***     \par    Description:
***                  Given an array (or list or vector) of arrays (or, guess what, lists or vectors) of integers, your goal is to return the sum of a specific set of numbers, starting with elements whose position is equal to the main array length and going down by one at each step.\n
***                  Say for example the parent array (etc, etc) has 3 sub-arrays inside: you should consider the third element of the first sub-array, the second of the second array and the first element in the third one: [[3, 2, 1, 0], [4, 6, 5, 3, 2], [9, 8, 7, 4]] would have you considering 1 for [3, 2, 1, 0], 6 for [4, 6, 5, 3, 2] and 9 for [9, 8, 7, 4], which sums up to 16.\n
***                  One small note is that not always each sub-array will have enough elements, in which case you should then use a default value (if provided) or 0 (if not provided), as shown in the test cases.
***
**/

#ifndef _SUBARRAY_ELEMENTS_SUM_H_
#define _SUBARRAY_ELEMENTS_SUM_H_

#include <vector>

/*!
    \brief          This function calculates the sum of the required elements
    \param[in] arr  Two dimensional array containing the integers. 
    \param[in] d    Default value in case the required index is out of range.
    \returns        Sum of the required elements.
    \par Examples:
         {{3, 2, 1, 0}, {4, 6, 5, 3, 2}, {9, 8, 7, 4}} shall return 1 + 6 + 9 = 16\n
         {{3}, {4, 6, 5, 3, 2}, {9, 8, 7, 4}} shall return 0 + 6 + 9 = 15\n
         {{3, 2, 1, 0}, {4, 6, 5, 3, 2}, {}} and 5 shall return 1 + 6 + (5) = 12.
*/
long subarrayElementsSum(const std::vector<std::vector<int>>& arr, int d = 0);

/*! \brief This function tests the subarrayElementsSum function. **/
void subarrayElementsSumTest ();

#endif /* _SUBARRAY_ELEMENTS_SUM_H_ */