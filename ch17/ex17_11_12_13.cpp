/***************************************************************************
*  @file       main.cpp
*  @author     gau fung
*  @date       25  May 2015
*  @remark     This code is for the exercises from C++ Primer 5th Edition
*  @note
***************************************************************************/
//
// Exercise 17.11:
// Define a data structure that contains an integral object to track responses
// to a true/false quiz containing 10 questions. What changes, if any, would
// you need to make in your data structure if the quiz had 100 questions?
//
// Exercise 17.12:
// Using the data structure from the previous question, write a function that
// takes a question number and a value to indicate a true/false answer and
// updates the quiz results accordingly.
//
// Exercise 17.13:
// Write an integral object that contains the correct answers for the
// true/false quiz. Use it to generate grades on the quiz for the data
// structure from the previous two exercises.
//

#ifndef QUIZ
#define QUIZ
#include <iostream>
#include <bitset>
#include <utility>
#include <string>
#include <iostream>

//class Quiz
template<std::size_t N>
class Quiz
{
public:
    //constructors
    Quiz() = default;
    Quiz(std::string& s) :bitquiz(s){ }

    //generate grade
    template<std::size_t M>
    friend std::size_t grade(Quiz<M> const&, Quiz<M> const&);

    //print
    template<std::size_t M>
    friend std::ostream& operator<<(std::ostream&, Quiz<M> const&);

    //update bitset
    void update(std::pair<std::size_t, bool>);
private:
    std::bitset<N> bitquiz;
};
#endif

template<std::size_t N>
void Quiz<N>::update(std::pair<std::size_t, bool> pair)
{
    bitquiz.set(pair.first, pair.second);
}

template<std::size_t M>
std::ostream& operator<<(std::ostream& os, Quiz<M> const& quiz)
{
    os << quiz.bitquiz;
    return os;
}

template<std::size_t M>
std::size_t grade(Quiz<M> const& corAns, Quiz<M> const& stuAns)
{
    auto result = stuAns.bitquiz ^ corAns.bitquiz;
    result.flip();
    return result.count();
}


int main()
{
    //Ex17_11
    std::string s = "1010101";
    Quiz<10> quiz(s);
    std::cout << quiz << std::endl;

    //EX17_12
    quiz.update(std::make_pair(1, true));
    std::cout << quiz << std::endl;

    //Ex17_13
    std::string answer = "10011";
    std::string stu_answer = "11001";
    Quiz<5> ans(answer), stu_ans(stu_answer);
    std::cout << grade(ans, stu_ans) << std::endl;

    return 0;
}
