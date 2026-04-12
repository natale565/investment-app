#include <iostream>
#include "banking.h"
#include <iomanip>
using namespace std;

void Banking::SetNumYears(int years)
{
    NumYears = years;
}

void Banking::SetInitialInvestment(double firstInvestment)
{
    InitialInvestment = firstInvestment;
}

void Banking::SetMonthlyDeposit(double monthlyDeposit)
{
    MonthlyDeposit = monthlyDeposit;
}

void Banking::SetInterestRate(double interestRate)
{
    InterestRate = interestRate;
}

int Banking::GetNumYears() const
{
    return NumYears;
}

double Banking::GetInitialInvestment() const
{
    return InitialInvestment;
}

double Banking::GetMonthlyDeposit() const
{
    return MonthlyDeposit;
}

double Banking::GetInterestRate() const
{
    return InterestRate;
}

// Calculates and displays yearly balances and interest earned
// both with and without additional monthly deposits
void Banking::displayBalances()
{
    // Convert years to total number of months
    int months = NumYears * 12;
    double openingBalance = InitialInvestment;

    // Convert annual interest rate percentage to monthly decimal rate
    double monthlyRate = (InterestRate / 100) / 12;
    double yearlyInterest = 0.0;

    cout << fixed << setprecision(2);
    cout << "--------------------------------------------------------------" << endl;
    cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
    cout << "==============================================================" << endl;
    cout << left << setw(10) << "Year" << setw(20) << "Year End Balance" << setw(25) << "Year End Earned Interest" << endl;
    cout << "--------------------------------------------------------------" << endl;

    // Calculate balance growth without additional monthly deposits
    for (int i = 1; i <= months; i++)
    {
        // No monthly deposit added in this loop
        double total = openingBalance;
        // Calculate interest for the current month
        double interest = total * monthlyRate;
        // Update balance after applying interest
        double closingBalance = total + interest;

        yearlyInterest += interest;
        openingBalance = closingBalance;

        // At the end of each year (every 12 months), display results
        if (i % 12 == 0)
        {
            cout << left << setw(10) << (i / 12) << setw(20) << closingBalance << setw(25) << yearlyInterest << endl;

            yearlyInterest = 0.0;
        }
    }

    // Reset values to run second loop with monthly deposits
    openingBalance = InitialInvestment;
    yearlyInterest = 0.0;

    cout << fixed << setprecision(2);
    cout << "--------------------------------------------------------------" << endl;
    cout << "\nBalance and Interest With Additional Monthly Deposits\n";
    cout << "==============================================================" << endl;
    cout << left << setw(10) << "Year" << setw(20) << "Year End Balance" << setw(25) << "Year End Earned Interest" << endl;
    cout << "--------------------------------------------------------------" << endl;

    for (int i = 1; i <= months; i++)
    {
        // Add monthly deposit before calculating interest
        double total = openingBalance + MonthlyDeposit;
        double interest = total * monthlyRate;
        double closingBalance = total + interest;

        yearlyInterest += interest;
        openingBalance = closingBalance;

        if (i % 12 == 0)
        {
            cout << left << setw(10) << (i / 12) << setw(20) << closingBalance << setw(25) << yearlyInterest << endl;

            yearlyInterest = 0.0;
        }
    }
}