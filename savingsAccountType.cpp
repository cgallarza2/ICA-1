//Implementation file 
	
#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include "savingsAccountType.h"

using namespace std;

const double savingsAccountType::INTEREST_RATE = 0.03;
const int savingsAccountType::TYPE = 4;

savingsAccountType::savingsAccountType( string n, int acctNumber, double bal)
					: bankAccountType(n, acctNumber, bal)
{
	interestRate = INTEREST_RATE;
	type = TYPE;
}

savingsAccountType::savingsAccountType(string n, int acctNumber, double bal, double intRate)
					: bankAccountType(n, acctNumber, bal)
{
	setInterestRate(intRate);
}

double savingsAccountType::getInterestRate()
{
	return interestRate;
}

int savingsAccountType::getType()
{
	return type;
}

void savingsAccountType::setInterestRate(double rate)
{
	interestRate = rate;
}

void savingsAccountType::postInterest()
{
	balance = balance + balance * interestRate;
}

void savingsAccountType::createMonthlyStatement()
{
	postInterest();
}

void savingsAccountType::deposit(double amount)
{

	balance = balance + amount;
}

void savingsAccountType::withdraw(double amount)
{

	balance = balance - amount;
}

void savingsAccountType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Savings: " << getName() << "\t\t\t\t ACCT# " 
		  << getAccountNumber() << "\tBalance: $" << getBalance();
}
