#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
#include "investment.h"

using namespace std;

// Create Instance of Investment Class
Investment::Investment(double initialInvestmentAmount, double monthlyDeposit, double annualInterest, int numberOfYears)
    : initialInvestmentAmount(initialInvestmentAmount), monthlyDeposit(monthlyDeposit), annualInterest(annualInterest), numberOfYears(numberOfYears) {}

// Growth With Deposits
void Investment::displayInvestmentGrowth() {

    // Header
    std::cout <<
        left <<
        endl <<
        setw(70) << "Balance and Interest With Monthly Deposits\n" + std::string(70, '=') <<
        endl;

    std::cout <<
        endl <<
        left <<
        setw(10) << "Month" <<
        setw(25) << "Starting Balance" <<
        setw(20) << "Ending Balance" <<
        setw(15) << "Interest Earned" <<
        endl;

    double balance = initialInvestmentAmount;

    // Stream To Modify Width of Doubles as Strings
    stringstream stream;

    int numberOfMonths = numberOfYears * 12;

    for (int i = 1; i <= numberOfMonths; ++i) {

        double startingBalance = balance;
        double interest;

        // Calculate Interest
        interest = (balance + monthlyDeposit) * ((annualInterest / 12) / 100.0);

        // Add Interest to Balance
        balance += interest;

        // Add monthy deposit
        balance += monthlyDeposit;

        // Round to the nearest cent
        interest = round(interest * 1000.0) / 1000.0;
        balance = round(balance * 1000.0) / 1000.0;

        // "Modify" Balance to String with 2 decimals
        stream << fixed << setprecision(2) << balance;
        string balanceString = stream.str();
        stream.str("");

        // "Modify" Interest to String with 2 decimals
        stream << fixed << setprecision(2) << interest;
        string interestString = stream.str();
        stream.str("");

        // "Modify" Starting Balance to String with 2 decimals
        stream << fixed << setprecision(2) << startingBalance;
        string startingBalanceString = stream.str();
        stream.str("");

        switch (i) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            // Print the first 5 months
            std::cout <<
                left <<
                fixed <<
                //setprecision(3) <<
                setw(10) << i <<
                setw(25) << "$" + startingBalanceString <<
                setw(20) << "$" + balanceString <<
                setw(15) << "$" + interestString <<
                endl;

            break;

        case 6:
            if (numberOfMonths > 15) {
                // Print "..." to indicate skipped months
                std::cout <<
                    left <<
                    fixed <<
                    //setprecision(3) <<
                    setw(10) << "....." <<
                    setw(25) << "....." <<
                    setw(20) << "....." <<
                    setw(15) << "....." <<
                    endl;
            }
            break;

        default:
            if (numberOfMonths > 15 && i <= numberOfMonths - 5) {
                // Skip printing for middle months
                balance = balance;
            }
            else {
                // Print the last 5 months
                std::cout <<
                    left <<
                    fixed <<
                    //setprecision(3) <<
                    setw(10) << i <<
                    setw(25) << "$" + startingBalanceString <<
                    setw(20) << "$" + balanceString <<
                    setw(15) << "$" + interestString <<
                    endl;
            }
            break;
        }

    }
}

// No Deposits
void Investment::displayInvestmentGrowthNoDeposit() {

    // Header
    std::cout <<
        left <<
        endl <<
        setw(70) << "Balance and Interest Without Monthly Deposits\n" + std::string(70, '=') <<
        endl;

    std::cout <<
        endl <<
        left <<
        setw(10) << "Month" <<
        setw(25) << "Starting Balance" <<
        setw(20) << "Ending Balance" <<
        setw(15) << "Interest Earned" <<
        endl;

    double balance = initialInvestmentAmount;

    // Stream To Modify Width of Doubles as Strings
    stringstream stream;

    int numberOfMonths = numberOfYears * 12;

    for (int i = 1; i <= numberOfMonths; ++i) {

        double startingBalance = balance;
        double interest;

        // Calculate Interest
        interest = (balance + monthlyDeposit) * ((annualInterest / 12) / 100.0);

        // Add Interest to Balance
        balance += interest;

        // Round to the nearest cent
        interest = round(interest * 1000.0) / 1000.0;
        balance = round(balance * 1000.0) / 1000.0;

        // "Modify" Balance to String with 2 decimals
        stream << fixed << setprecision(2) << balance;
        string balanceString = stream.str();
        stream.str("");

        // "Modify" Interest to String with 2 decimals
        stream << fixed << setprecision(2) << interest;
        string interestString = stream.str();
        stream.str("");

        // "Modify" Starting Balance to String with 2 decimals
        stream << fixed << setprecision(2) << startingBalance;
        string startingBalanceString = stream.str();
        stream.str("");

        switch (i) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            // Print the first 5 months
            std::cout <<
                left <<
                fixed <<
                //setprecision(3) <<
                setw(10) << i <<
                setw(25) << "$" + startingBalanceString <<
                setw(20) << "$" + balanceString <<
                setw(15) << "$" + interestString <<
                endl;

            break;

        case 6:
            if (numberOfMonths > 15) {
                // Print "..." to indicate skipped months
                std::cout <<
                    left <<
                    fixed <<
                    //setprecision(3) <<
                    setw(10) << "....." <<
                    setw(25) << "....." <<
                    setw(20) << "....." <<
                    setw(15) << "....." <<
                    endl;
            }
            break;

        default:
            if (numberOfMonths > 15 && i <= numberOfMonths - 5) {
                // Skip printing for middle months
                balance = balance;
            }
            else {
                // Print the last 5 months
                std::cout <<
                    left <<
                    fixed <<
                    //setprecision(3) <<
                    setw(10) << i <<
                    setw(25) << "$" + startingBalanceString <<
                    setw(20) << "$" + balanceString <<
                    setw(15) << "$" + interestString <<
                    endl;
            }
            break;
        }

    }
}
