/*!
***     \file        cigarStringsEasy.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b64d2cd83d64828ce000039
***
***     \par    Description:
***                  DNA sequencing data can be stored in many different formats. In this Kata, we will be looking at SAM formatting. It is a plain text file where every line (excluding the first header lines) contains data about a "read" from whatever sample the file comes from. Rather than focusing on the whole read, we will take two pieces of information: the cigar string and the nucleotide sequence.\n
***                  The cigar string is composed of numbers and flags. It represents how the read aligns to what is known as a reference genome. A reference genome is an accepted standard for mapping the DNA.\n
***                  The nucleotide sequence shows us what bases actually make up that section of DNA. They can be represented with the letters A, T, C, or G.\n
***                  Example Read: ('36M', 'ACTCTTCTTGCGAAAGTTCGGTTAGTAAAGGGGATG')\n
***                  The M in the above cigar string stands for "match", and the 36 stands for the length of the nucleotide sequence. Since all 36 bases are given the 'M' distinction, we know they all matched the reference.\n
***                  Example Read: ('20M10S', 'ACTCTTCTTGCGAAAGTTCGGTTAGTAAAG')\n
***                  In the above cigar string, only 20 have the "M" distinction, but the length of the actual string of nucleotides is 30. Therefore we know that read did not match the reference. (Don't worry about what the other letters mean. That will be covered in a later kata.)\n
***                  Your job for this kata is to create a function that determines whether a cigar string fully matches the reference and accounts for all bases. If it does fully match, return True. If the numbers in the string do not match the full length of the string, return 'Invalid cigar'. If it does not fully match, return False.
***
**/

#ifndef _CIGAR_STRINGS_EASY_H_
#define _CIGAR_STRINGS_EASY_H_

#include <string>

/*!
    \brief       This function decides whether the cigar string is valid and whether the read was successful or not.
    \param[in] cigar   The cigar string.
    \param[in] nuc_seq The reference genome.
    \returns           A string describing whether the cigar string is valid or whether the read was successful or not.
    \par Examples:
         "36M", "ACTCTTCTTGCGAAAGTTCGGTTAGTAAAGGGGATG" shall return "True"\n
         "20M10S", "ACTCTTCTTGCGAAAGTTCGGTTAGTAAAG" shall return "False"
*/
std::string cigarStringsEasy(const std::string& cigar, const std::string& nuc_seq);

/*! \brief This function tests the cigarStringsEasy function. **/
void cigarStringsEasyTest ();

#endif /* _CIGAR_STRINGS_EASY_H_ */