//Implementation file 
	
#include <iostream>
#include <string>
#include <iomanip>
#include "savingsAccountType.h"

using namespace std;

const double savingsAccountType::INTEREST_RATE = 0.03;

savingsAccountType::savingsAccountType( string n, int acctNumber, double bal, string pass, string user)
					: bankAccountType(n, acctNumber, bal, pass, user)
{
interestRate = INTEREST_RATE;
}

savingsAccountType::savingsAccountType(string n, int acctNumber, double bal, string pass, string user, double intRate)
					: bankAccountType(n, acctNumber, bal, pass, user)
{
	setInterestRate(intRate);
}

double savingsAccountType::getInterestRate()
{
	return interestRate;
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

void savingsAccountType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Savings account: " << getName() << "\t ACCT# " 
		  << getAccountNumber() << "\tBalance: $" << getBalance();
}

