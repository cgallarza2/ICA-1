//Implementationfile

#include <iostream>
#include <string>
#include <iomanip>
#include "highInterestSavingsType.h"

using namespace std;

const double highInterestSavingsType::MINIMUM_BALANCE = 2500.00;
const double highInterestSavingsType::INTEREST_RATE = 0.05;

highInterestSavingsType::highInterestSavingsType(string n, int acctNumber, 
														double bal, string pass, string user)
						  : savingsAccountType(n, acctNumber, bal, INTEREST_RATE, pass, user)
{
	minimumBalance = MINIMUM_BALANCE;
}

highInterestSavingsType::highInterestSavingsType(string n, int acctN, double balance, double intRate,
													  double minBalance, string pass, string user)
						      : savingsAccountType(n, acctN, balance, intRate, pass, user)
{
	minimumBalance = minBalance;
}

double highInterestSavingsType::getMinimumBalance()
{
	return minimumBalance;
}

bool highInterestSavingsType::verifyMinimumBalance(double amount)
{
	return (balance - amount >= minimumBalance);
}

void highInterestSavingsType::withdraw(double amount)
{
	if (verifyMinimumBalance(amount))
		balance = balance - amount;
}

void highInterestSavingsType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "High InterestSavings: " << getName() << "\t ACCT# "
		  << getAccountNumber() << "\tBalance: $" << getBalance();
}
