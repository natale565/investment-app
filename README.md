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

## Project Summary and Problem Solved

This project addresses a personal finance need: understanding how investments grow over time through compound interest. Many people struggle to visualize the long-term impact of consistent monthly contributions versus a one-time lump sum deposit. This program solves this problem by displaying a side by side comparison of yearly projections for both scenarios. This program also gives users the ability to plan their investments of different amounts by giving them the ability to test different initial deposits and monthly deposits with a selected interest rate.

---

## Reflection

### What I did Particularly well

The input validation logic was handled thoroughly. Both getDouble() and getInteger() in main.cpp guard against input validation. non-numeric input which sets cin into a fail state and negative numbers by clearing the stream and re-prompting in a loop, the program never crashes or accepts bad data. The separation of user interaction in main.cpp and calculations in banking.cpp also reflects clean, intentional design.

---

### Where I Could Enhance the Code

Input validation consolidation: The getDouble() and GetInteger() functions share nearly identical logic. A template function or a shared helper could remove the duplicated code.

Output formatting: The displayBalances() method handles both calculation and display. Separating these to one method for computing results into a data structure and another to print them would make the code easier to test and reuse.

File or export output: Adding an option to write results to a .csv or .txt file would make the tool more practical for real financial planning.

### Development Challenges

A challenge I came across while building this program was handling non-numeric input validation. When a user types something like a letter or symbol where a number is expected, cin enters a fail state. This caused an infinite loop within the program. The fix required understanding calling cin.clear() to reset the error and calling cin.ignore() with numeric_limits<streamsize>::max() to remove the bad input from the program before re-prompting. Without both of these steps in the right order, the loop would either re-read the same invalid input repeatedly or crash. Reading through C++ documentation on stream state management and testing the program with bad input helped fix this issue.

This challenge helped reinforce continuous testing of the program and anticipating how users can break input.

Aligning the printed output was another difficulty I faced. Getting the Year, Year End Balance, and Year End Earned Interest columns to line up consistently required learning iomanip's setw() for fixed-width column spacing. At first I hard-coded the display, but noticed once the values started growing larger the data was out of alignment. Switching to setw() for each column value fixed this, as it reserves a consistent amount of space regardless of the size of the number being printed.

---

### Transferable Skills

Several skills from this project apply to future development work:

- Input validation patterns: the loop and reprompt pattern with stream state checking is directly reusable in any console application.

- Class design and encapsulation: Keeping private data behind getters and setters is a foundational object-oriented programming pattern that scales to any language or framework.

- Testing: continuously testing throughout development helped catch bugs early which is a habit that applies to unit testing in any project.

- Formatted console output — iomanip techniques for aligning columns are useful any time tabular data needs to be presented clearly.

---

### How I Made the Program Maintainable, Readable, and Adaptable

- File separation: Input handling lives in main.cpp, logic and display live in banking.cpp, and the public interface is declared in banking.h. Each file has a single, clear purpose. 

- continuous running: Wrapping main() logic in a while loop based on user input makes it easy to add new calculations or modify the menu in the future without restructuring the program

- Descriptive naming: Variables and methods such as openingBalance, yearlyInterest, SetMonthlyDeposit, and displayBalances read like plain English reducing the need for in-depth explanatory comments.

- Inline comments: Key parts of the program such as converting the annual rate to a monthly decimal, or why the opening balance is reset between loops are explained directly in the code as they occur

- Default member initialization: Member variables in banking.h are initialized to zero at the point of declaration, preventing undefined behavior if a setter is accidentally skipped.



## Technologies Used
- C++
- Standard Library (`iostream`, `iomanip`, `limits`)


---

## Concepts Demonstrated
- Object-Oriented Programming (Classes and Encapsulation)
- Input Validation and Error Handling
- Looping and Control Flow
- Financial Calculations (Compound Interest)

---

## Author
Christopher Natale
