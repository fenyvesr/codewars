/*!
***     \file        returnLocationTest.cpp
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Test the solution for https://www.codewars.com/kata/57f037927b45ef77b3000260/
***
***     \par    File description
***                  This source tests the functionality implemented in returnLocation.h
***
***     \warning
***
**/

#include <cassert>
#include "returnLocation.h"

/*!
***     \brief This function tests the constructor and the location method of the Person class.
**/
void returnLocationTest(){
    Person* person = new Person(1, 2, 3);
    int x = 0, y = 0, z = 0;
    person->location(x, y, z);
    assert(("Wrong value of x", 1 == x));
    assert(("Wrong value of y", 2 == y));
    assert(("Wrong value of z", 3 == z));
}