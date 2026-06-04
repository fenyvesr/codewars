/*!
***     \file        ancestorVariations.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/691863fe0c68b12e8cf47452
***
***     \par    Description:
***                  You have a father, a grandfather, a great-grandfather, great-great-grandfather, etc...
***                  
***                  Let's say:
***                  - 0 = father
***                  - 1 = grandfather
***                  - 2 = great-grandfather
***                  - 3 = great-great-grandfather
***                  - n = great-great-great- ... (n-1 times) -grandfather
***                  
***                  Given any number n, how many different ways can I call n?
***                  
***                  Since the answer can be very large, return it modulo 1000000007.
***
**/

#ifndef ANCESTOR_VARIATIONS_H
#define ANCESTOR_VARIATIONS_H

/*!
    \brief       Calculates the number of different ways to call an ancestor at generation level n.
    \param[in]   n The generation level (0 = father, 1 = grandfather, 2 = great-grandfather, etc.).
    \returns     The number of different ways to call the ancestor at generation n, modulo 1000000007.
    \par Examples:
         n = 0 shall return 1 (2^0 = 1)\n
         n = 2 shall return 4 (2^2 = 4, great-grandfather can be called in 4 ways)\n
         n = 30 shall return 73741824 (2^30 mod 1000000007)
    \warning The result is returned modulo 1000000007 to handle very large values for n up to 10^18.
*/
int ancestor_variations(long long n);

#endif // ANCESTOR_VARIATIONS_H
