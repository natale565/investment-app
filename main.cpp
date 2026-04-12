// Collect user input, validate it, and display investment growth reports

#include <iostream>
#include <limits>
#include "banking.h"
using namespace std;

double getDouble(string prompt)
{
    double value;
    cout << prompt;
    cin >> value;

    // Prompt user until a non-negative value is entered
    while (!cin || value < 0)
    {
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input. Please enter a non-negative number." << endl;
            cout << prompt;
            cin >> value;
        }
        else if (value < 0)
        {
            cout << "Invalid Input. Please enter a non-negative number." << endl;
            cout << prompt;
            cin >> value;
        }
    }
    return value;
}

int getInteger(string prompt)
{
    int value;
    cout << prompt;
    cin >> value;

    // Prompt user until a non-negative value is entered
    while (!cin || value < 0)
    {
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input. Please enter a non-negative number." << endl;
            cout << prompt;
            cin >> value;
        }
        else if (value < 0)
        {
            cout << "Invalid Input. Please enter a non-negative number." << endl;
            cout << prompt;
            cin >> value;
        }
    }
    return value;
}

int main()
{
    char choice = 'y';
    while (choice == 'y' || choice == 'Y')
    {
        Banking airgead;

        // Variables to store user input for the investment calculation
        int numYears = 0;
        double initialInvestment = 0.0;
        double monthlyDeposit = 0.0;
        double interestRate = 0.0;

        initialInvestment = getDouble("What is the initial investment?: $");

        monthlyDeposit = getDouble("What is your monthly deposit?: $");

        interestRate = getDouble("What is the annual interest rate?: %");

        numYears = getInteger("What is the number of years?: ");

        // Pass validated user input into the Banking object
        airgead.SetInitialInvestment(initialInvestment);
        airgead.SetMonthlyDeposit(monthlyDeposit);
        airgead.SetInterestRate(interestRate);
        airgead.SetNumYears(numYears);

        cout << endl;
        airgead.displayBalances();

        cout << "\nWould you like to perform another calculation? (y/n): ";
        cin >> choice;
    }

    return 0;
}