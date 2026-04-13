# investment-app


## Overview
The Investment Banking Application is a console-based C++ program that calculates investment growth over time. It allows users to input financial data and view yearly balances and interest earned, both with and without additional monthly deposits.

This application demonstrates object-oriented programming, input validation, and financial calculations using compound interest.

---

## Features
- Accepts user input for:
  - Initial investment amount
  - Monthly deposit
  - Annual interest rate
  - Number of years
- Validates input to ensure non-negative numeric values
- Handles invalid (non-numeric) input gracefully
- Calculates and displays:
  - Yearly balances without monthly deposits
  - Yearly balances with monthly deposits
- Allows users to perform multiple calculations in one session

---

## How It Works
1. The user is prompted to enter investment details.
2. Input is validated to ensure it is numeric and non-negative.
3. The program calculates monthly compound interest.
4. Results are displayed in two scenarios:
   - Without additional monthly deposits
   - With additional monthly deposits
5. The user can choose to run another calculation or exit.

---

## Technologies Used
- C++
- Standard Library (`iostream`, `iomanip`, `limits`)

---

## File Structure

├── main.cpp # Handles user input and program flow
├── banking.h # Class definition for Banking
├── banking.cpp # Implements calculation logic
└── README.md # Project documentation


---

## Concepts Demonstrated
- Object-Oriented Programming (Classes and Encapsulation)
- Input Validation and Error Handling
- Looping and Control Flow
- Financial Calculations (Compound Interest)

---

## Author
Christopher Natale
