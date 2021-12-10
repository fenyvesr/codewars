/*!
***     \file        stringPacketBasedCommunication.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/5b2be37991c7460d17000009
***
***     \par    Description:
***                  We need you to implement a method of receiving commands over a network, processing the information and responding.\n
***                  Our device will send a single packet to you containing data and an instruction which you must perform before returning your reply.\n
***                  To keep things simple, we will be passing a single "packet" as a string. Each "byte" contained in the packet is represented by 4 chars.\n
***                  One packet is structured as below:\n
***                  <table>
***                  <tr><th>Header <th>Instruction <th> Data1 <th> Data2 <th> Footer
***                  <tr><td>H1H1   <td>0F12        <td> 0012  <td> 0008  <td> F4F4
***                  </table>
***                  The string received in this case would be - "H1H10F1200120008F4F4"\n
***                  Instruction: The calculation you should perform, always one of the below:
***                              - 0F12 = Addition
***                              - B7A2 = Subtraction
***                              - C3D9 = Multiplication
***                              - FFFF = This instruction code should be used to identify your return value.
***                              .
***                  The Header and Footer are unique identifiers which you must use to form your reply.\n
***                  Data1 and Data2 are the decimal representation of the data you should apply your instruction to. i.e 0109 = 109.\n
***                  Your response must include the received header/footer, a "FFFF" instruction code, and the result of your calculation stored in Data1.\n
***                  Data2 should be zero'd out to "0000".\n
***                  To give a complete example:\n
***                  If you receive message "H1H10F1200120008F4F4", the correct response would be "H1H1FFFF00200000F4F4"\n
***                  In the event that your calculation produces a negative result, the value returned should be "0000", similarly if the value is above 9999 you should return "9999".\n
***                  Goodluck, I look forward to reading your creative solutions!
***
**/

#ifndef _STRING_PACKET_BASED_COMMUNICATION_H_
#define _STRING_PACKET_BASED_COMMUNICATION_H_

#include <string> /*!< Needed for std::string, std::stoi, std::to_string, std::string::size() */

/*!
    \brief            This function executes the instruction in a packet and returns the result as a string
    \param[in] packet Packet containing the instruction and the two data.
    \returns          Result packet.
    \par Example:
         "H1H10F1200120008F4F4" shall return "H1H1FFFF00200000F4F4"
    \warning          The packet has to be valid.
*/
std::string stringPacketBasedCommunication(std::string packet);

/*! \brief This function tests the stringPacketBasedCommunication function. **/
void stringPacketBasedCommunicationTest ();

#endif /* _STRING_PACKET_BASED_COMMUNICATION_H_ */