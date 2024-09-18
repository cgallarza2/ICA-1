
//Implementation file date

#include <iostream>
#include <string>
#include <iomanip>
#include "noServiceChargeCheckingType.h"

using namespace std;

const double noServiceChargeCheckingType::MIN_BALANCE = 1000.00;
const double noServiceChargeCheckingType::INTEREST_RATE = 0.02;
const int noServiceChargeCheckingType::TYPE = 3;

noServiceChargeCheckingType::noServiceChargeCheckingType(string n, 
										int acctNumber, double bal)
									: checkingAccountType(n, acctNumber, bal)
{
	minimumBalance = MIN_BALANCE;
	interestRate = INTEREST_RATE;
	type = TYPE;
}

noServiceChargeCheckingType::noServiceChargeCheckingType(string n,
										int acctNumber, double bal,
										double minBalance, double intRate)
									: checkingAccountType(n, acctNumber, bal)
{
	minimumBalance = minBalance;
	interestRate = intRate;
}

double noServiceChargeCheckingType::getMinimumBalance()
{
	return minimumBalance;
}

int noServiceChargeCheckingType::getType()
{
	return type;
}

void noServiceChargeCheckingType::setMinimumBalance(double minBalance)
{
	minimumBalance = minBalance;
}

bool noServiceChargeCheckingType::verifyMinimumumBalance(double amount)
{
	return (balance - amount >= minimumBalance);
}

void noServiceChargeCheckingType::writeCheck(double amount)
{
	if (verifyMinimumumBalance(amount))
		balance = balance - amount;
}

void noServiceChargeCheckingType::withdraw(double amount)
{
	if (verifyMinimumumBalance(amount))
		balance = balance - amount;
}

void noServiceChargeCheckingType::createMonthlyStatement()
{
}

void noServiceChargeCheckingType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "No Service Charge Check. " << getName() << "\t ACCT# " 
		  << getAccountNumber() << "\tBalance $" << getBalance();
}
