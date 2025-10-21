// Investment.cpp
// Implements the Investment class functions.
// Follows Airgead Banking coding standards for clarity and security.

#include "Investment.h"
using namespace std;

// Constructor initializes member variables
Investment::Investment(double initialInvestment,
                       double monthlyDeposit,
                       double annualInterest,
                       int years) {
    m_initialInvestment = initialInvestment;
    m_monthlyDeposit = monthlyDeposit;
    m_annualInterest = annualInterest;
    m_years = years;
}

// --------------------------------------------------------------------
// Report #1 – Without Monthly Deposits
// Calculates yearly balances using annual compounding.
// --------------------------------------------------------------------
void Investment::displayWithoutMonthlyDeposit() const {
    double totalBalance = m_initialInvestment;
    double interestRate = m_annualInterest / 100.0;

    cout << "\n\n   Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "===============================================================" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
    cout << "---------------------------------------------------------------" << endl;

    for (int year = 1; year <= m_years; ++year) {
        double interestEarned = totalBalance * interestRate;
        totalBalance += interestEarned;

        cout << fixed << setprecision(2);
        cout << year << "\t\t$" << setw(12) << totalBalance
             << "\t\t$" << setw(12) << interestEarned << endl;
    }
}

// --------------------------------------------------------------------
// Report #2 – With Monthly Deposits
// Calculates balances with monthly compounding and deposits.
// --------------------------------------------------------------------
void Investment::displayWithMonthlyDeposit() const {
    double totalBalance = m_initialInvestment;
    double monthlyRate = (m_annualInterest / 100.0) / 12.0;

    cout << "\n\n   Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "===============================================================" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
    cout << "---------------------------------------------------------------" << endl;

    for (int year = 1; year <= m_years; ++year) {
        double interestEarnedYear = 0.0;

        for (int month = 1; month <= 12; ++month) {
            double monthlyInterest = (totalBalance + m_monthlyDeposit) * monthlyRate;
            totalBalance += m_monthlyDeposit + monthlyInterest;
            interestEarnedYear += monthlyInterest;
        }

        cout << fixed << setprecision(2);
        cout << year << "\t\t$" << setw(12) << totalBalance
             << "\t\t$" << setw(12) << interestEarnedYear << endl;
    }
}
