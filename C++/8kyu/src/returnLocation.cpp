/*!
***     \file        returnLocation.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Test the solution for https://www.codewars.com/kata/57f037927b45ef77b3000260/
***
***     \par    File description
***                  This source tests the functionality implemented in returnLocation.h
***
**/

#include "returnLocation.h"

Person::Person(int x, int y, int z)
    : m_x(x), m_y(y), m_z(z){}

void Person::location(int& x, int& y, int& z) const
{
    x = m_x;
    y = m_y;
    z = m_z;
}
