/*!
***     \file        midiFiles.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/6a020680357f9fb3614e6502
***
***     \par    Description:
***                  In MIDI files, timestamps are stored as integers representing the number of
***                  "ticks" since the previous event in the file.
***                  
***                  Because these timestamps are relative to one another, most values tend to be
***                  fairly small. In order to save space, MIDI files use a special integer encoding
***                  format called a Variable Length Quantity (VLQ).
***                  
***                  A MIDI VLQ stores an integer using one or more bytes:
***                  
***                     The lower 7 bits of each byte contain the actual data
***                     The highest bit indicates whether another byte follows
***                         1 means another byte follows
***                         0 means this is the final byte
***
**/

#pragma once

#include <vector>      /* Needed for std::vector */

/*!
    \brief       This function should convert an integer into a MIDI VLQ byte sequence.
    \param[in]   n The integer to encode.
    \returns     A vector of integers representing the MIDI VLQ byte sequence.
    \par Examples:
            128 shall return [0x81, 0x00]\n
            2097151 shall return [0xFF, 0xFF, 0x7F]
*/
std::vector<int> encode(int n);

/*!
    \brief       This function should convert a MIDI VLQ byte sequence back into an integer.
    \param[in]   data The MIDI VLQ byte sequence to decode.
    \returns     The integer represented by the MIDI VLQ byte sequence.
    \par Examples:
            [0x81, 0x00] shall return 128\n
            [0xFF, 0xFF, 0x7F] shall return 2097151
*/
int decode(const std::vector<int>& data);
