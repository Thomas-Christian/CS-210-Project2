#ifndef INVESTMENT_H
#define INVESTMENT_H

class Investment {
public:
    Investment(double initialInvestmentAmount, double monthlyDeposit, double annualInterest, int numberOfYears);
    void displayInvestmentGrowth();
    void displayInvestmentGrowthNoDeposit();
private:
    double initialInvestmentAmount;
    double monthlyDeposit;
    double annualInterest;
    int numberOfYears;
};

#endif
