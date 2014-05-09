/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Alan.W
 *  @date       26  DEC 2013
 *  @remark
 ***************************************************************************/

//!
//! Exercise 12.23:
//! Write a program to concatenate two string literals, putting the result in a
//! dynamically allocated array of char.
//! Write a program to concatenate two library strings that have the same value
//! as the literals used in the first program.
//!

#include <iostream>


/**
 * @brief       concatenate two string literals and return it stored in dynamic memory.
 * @attention   dont forget free it using delete[].
 */
char *
concat_litral(const char * const s1, const char * const s2);

/**
 * @brief       concatenate two string literals and return it stored in dynamic memory.
 * @attention   dont forget free it using delete[].
 */
char*
concat_litral(const std::string& s1, const std::string& s2);


int main()
{
    /**
     * @brief test for 12.23 part 1.
     */
    /*
    char s1[80], s2[40];
    std::cin >> s1 >> s2;

    char * d_str= concat_litral(s1, s2);
    std::cout << d_str;

    delete [] d_str;
    */

    /**
     * @brief test for 12.23 part 2.
     */
    std::string s1, s2;
    std::cin >> s1 >> s2;

    char * d_str= concat_litral(s1, s2);
    std::cout << d_str;

    delete [] d_str;


    return 0;
}

/**
 * @brief       concatenate two string literals and strore it in dynamic memory and return it
 * @attention   dont forget free it using delete[].
 * @note        note the 'const' used in this function.
 */
char*
concat_litral(const char * const s1, const char * const s2)
{
    //! allocate the dynamic array and define a movable pointer to it
    char* const result = new char[sizeof(s1) + sizeof(s2) + 10];
    char* m_result = result;

    //! define the movable pointers to s1 and s2
    const char* m_s1 = s1;
    const char* m_s2 = s2;

    //! copy s1 to result
    while(*m_s1 != '\0')
    {
        *m_result = *m_s1;
        ++m_result;
        ++m_s1;
    }

    //! copy s2 to result
    while(*m_s2 != '\0')
    {
        *m_result = *m_s2;
        ++m_result;
        ++m_s2;
    }

    //! append '\0' at the end
    *m_result = '\0';

    return result;
}

/**
 * @brief       concatenate two library string and return it stored in dynamic memory.
 * @note        library can be iterated through using for range .
 */
char*
concat_litral(const std::string &s1, const std::string &s2)
{
    //! allocate the dynamic array and define a movable pointer to it
    char* const result = new char[sizeof(s1) + sizeof(s2) + 10];
    char* m_result = result;

    //! copy s1 to result using for range
    for (const auto &c : s1)
    {
        *m_result = c;
        ++m_result;
    }

    //! append s2 to result using for range
    for (const auto &c : s2)
    {
        *m_result = c;
        ++m_result;
    }

    //! append '\0' at the end
    *m_result = '\0';

    return result;

}
