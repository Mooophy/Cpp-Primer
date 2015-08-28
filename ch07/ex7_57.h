//
//  ex7_57.h
//  Exercise 7.57
//
//  Created by pezy on 11/25/14.
//

#ifndef CP5_ex7_57_h
#define CP5_ex7_57_h

#include <string>

class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; }
    
private:
    std::string owner;
    double amount;
    static double interestRate;
    static constexpr double todayRate = 42.42;
    static double initRate() { return todayRate; }
};

double Account::interestRate = initRate();

#endif
