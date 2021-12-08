/*!
***     \file        returnLocation.h
***
***     \authors     Robert Fenyvesi <fenyvesr@gmail.com>
***
***     \brief       Solution for https://www.codewars.com/kata/57f037927b45ef77b3000260/
***
***     \par    File description
***                  This header contains the solution for https://www.codewars.com/kata/57f037927b45ef77b3000260/ and its test function.
***
***     \warning
***
**/

#ifndef _RETURN_LOCATION_H_
#define _RETURN_LOCATION_H_

/*!
***     \brief This class represents a person.
**/
class Person
{
    public:
        /*! A person can be instantiated with its location by using this constructor. */
        /*!
          \param x Sets this value as the x coordinate of the person.
          \param y Sets this value as the y coordinate of the person.
          \param z Sets this value as the z coordinate of the person.
        */
        Person(int x, int y, int z)
            : m_x(x), m_y(y), m_z(z){}
        
        /*! This function gets the location of a person */
        /*!
          \param[out] x Returns the x coordinate of the person.
          \param[out] y Returns the y coordinate of the person.
          \param[out] z Returns the z coordinate of the person.
        */
        void location(int& x, int& y, int& z)
        {
            x = m_x;
            y = m_y;
            z = m_z;
        }
        
    private:
        int m_x; /*!< \brief The x coordinate of a person. */
        int m_y; /*!< \brief The y coordinate of a person. */
        int m_z; /*!< \brief The z coordinate of a person. */
};

void returnLocationTest ();

#endif /* _RETURN_LOCATION_H_ */