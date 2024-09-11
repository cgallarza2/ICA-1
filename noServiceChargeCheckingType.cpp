
//Implementation file date

#include <iostream>
#include <string>
#include <iomanip>
#include "noServiceChargeCheckingType.h"

using namespace std;

const double noServiceChargeCheckingType::MIN_BALANCE = 1000.00;
const double noServiceChargeCheckingType::INTEREST_RATE = 0.02;

noServiceChargeCheckingType::noServiceChargeCheckingType(string n, 
										int acctNumber, double bal, string pass, string user)
									: checkingAccountType(n, acctNumber, bal, pass, user)
{
	minimumBalance = MIN_BALANCE;
	interestRate = INTEREST_RATE;
}

noServiceChargeCheckingType::noServiceChargeCheckingType(string n,
										int acctNumber, double bal, string pass, string user,
										double minBalance, double intRate)
									: checkingAccountType(n, acctNumber, bal, pass, user)
{
	minimumBalance = minBalance;
	interestRate = intRate;
}

double noServiceChargeCheckingType::getMinimumBalance()
{
	return minimumBalance;
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
