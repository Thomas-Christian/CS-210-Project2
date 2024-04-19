#include <iostream>
#include "investment.h"
#include <conio.h>

int main() {
    
    // Variable Decleration 
    double initialInvestmentAmount;
    double monthlyDeposit;
    double annualInterest;
    int numberOfYears;
    char endChar = NULL;
    bool inputComplete = false;

    std::cout <<
    "Data Input:\n " << 
    std::endl;

    // Input validation for initial investment amount
    do {
        std::cout << "Enter Initial Investment Amount: $";
        if (!(std::cin >> initialInvestmentAmount) || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
        }
    } while (initialInvestmentAmount <= 0);

    // Input validation for monthly deposit
    do {
        std::cout << "Enter Monthly Deposit: $";
        if (!(std::cin >> monthlyDeposit) || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
        }
    } while (monthlyDeposit <= 0);

    // Input validation for annual interest rate
    do {
        std::cout << "Enter Annual Interest (Percent): %";
        if (!(std::cin >> annualInterest) || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
        }
    } while (annualInterest <= 0);

    // Input validation for number of years
    do {
        std::cout << "Enter Number of Years: ";
        if (!(std::cin >> numberOfYears) || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
        }
    } while (numberOfYears <= 0);

    std::cout << "Press any key to continue...\n";
    endChar = _getch();

    // Make sure all values are entered
    inputComplete = (initialInvestmentAmount != NULL && monthlyDeposit != NULL && annualInterest != NULL && numberOfYears != NULL && endChar != NULL) ? true : false;

    if (inputComplete = true) {
        Investment investment(initialInvestmentAmount, monthlyDeposit, annualInterest, numberOfYears);
            investment.displayInvestmentGrowth();
            investment.displayInvestmentGrowthNoDeposit();
    }

    return 0;
}