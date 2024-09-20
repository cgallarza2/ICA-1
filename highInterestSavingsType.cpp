//Implementationfile

#include <iostream>
#include <string>
#include <iomanip>
#include "highInterestSavingsType.h"

using namespace std;

const double highInterestSavingsType::MINIMUM_BALANCE = 2500.00;
const double highInterestSavingsType::INTEREST_RATE = 0.05;
const int highInterestSavingsType::TYPE = 2;

highInterestSavingsType::highInterestSavingsType(string n, int acctNumber, 
														double bal)
						  : savingsAccountType(n, acctNumber, bal, INTEREST_RATE)
{
	minimumBalance = MINIMUM_BALANCE;
	type = TYPE;
}

highInterestSavingsType::highInterestSavingsType(string n, int acctN, double balance, double intRate,
													  double minBalance)
						      : savingsAccountType(n, acctN, balance, intRate)
{
	minimumBalance = minBalance;
}

double highInterestSavingsType::getMinimumBalance()
{
	return minimumBalance;
}

int highInterestSavingsType::getType()
{
	return type;
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
