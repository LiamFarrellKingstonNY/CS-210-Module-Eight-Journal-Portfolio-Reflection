// main.cpp
// Developer: Liam Farrell
// Class: CS 210 - Project Two (Airgead Banking)
// Purpose: Console application that prompts user for investment information
//          and displays yearly growth reports with and without monthly deposits.

#include <iostream>
#include <limits>  
#include "Investment.h"
using namespace std;

// Helper: Input validation for positive numeric values
double getPositiveDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= 0) {
            return value;
        } else {
            cout << "  Invalid input. Please enter a positive number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Helper: Input validation for positive integers
int getPositiveInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value > 0) {
            return value;
        } else {
            cout << "  Invalid input. Please enter a positive integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main() {
    char again = 'Y';
    cout << "==============================================" << endl;
    cout << "     Airgead Banking Investment Calculator" << endl;
    cout << "==============================================" << endl;

    while (toupper(again) == 'Y') {
        // Collect input
        double initialInvestment = getPositiveDouble("Enter Initial Investment Amount: $");
        double monthlyDeposit    = getPositiveDouble("Enter Monthly Deposit: $");
        double annualInterest    = getPositiveDouble("Enter Annual Interest Rate (e.g., 5 for 5%): ");
        int years                = getPositiveInt("Enter Number of Years: ");

        // Create Investment object
        Investment myInvestment(initialInvestment, monthlyDeposit, annualInterest, years);

        cout << "\nPress Enter to continue to reports...";
        cin.ignore();
        cin.get();

        // Display both reports
        myInvestment.displayWithoutMonthlyDeposit();
        myInvestment.displayWithMonthlyDeposit();

        cout << "\nWould you like to run another scenario? (Y/N): ";
        cin >> again;
        cout << endl;
    }

    cout << "Program Finished. Thank you for using Airgead Banking!" << endl;
    return 0;
}
