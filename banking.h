#include <string>
#ifndef banking_h
#define banking_h
using namespace std;

class Banking
{
private:
    // Investment input data

    // Number of years for the investment
    int NumYears = 0;

    // Initial amount deposited
    double InitialInvestment = 0.0;

    // Monthly contribution amount
    double MonthlyDeposit = 0.0;

    // Annual interest rate(entered as a percentage)
    double InterestRate = 0.0;

public:
    Banking() = default;

    // Public interface for setting and retrieving investment data
    void SetNumYears(int years);
    void SetInitialInvestment(double initialInvestment);
    void SetMonthlyDeposit(double monthlyDeposit);
    void SetInterestRate(double interestRate);

    int GetNumYears() const;
    double GetInitialInvestment() const;
    double GetMonthlyDeposit() const;
    double GetInterestRate() const;

    // Displays yearly balances and interest earned with and without monthly deposits
    void displayBalances();
};

#endif