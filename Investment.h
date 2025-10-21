// Investment.h
// Developer: Liam Farrell
// Class: CS 210 - Project Two (Airgead Banking)
// Purpose: Header file for the Investment class that calculates balances and interest
// Notes: Follows Airgead Banking standards and OOP design.

#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <iostream>
#include <iomanip>

class Investment {
private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int    m_years;

public:
    // Constructor
    Investment(double initialInvestment = 0.0,
               double monthlyDeposit = 0.0,
               double annualInterest = 0.0,
               int years = 0);

    // Display reports
    void displayWithoutMonthlyDeposit() const;
    void displayWithMonthlyDeposit() const;
};

#endif // INVESTMENT_H
