//Implementation file 
	
#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include "savingsAccountType.h"

using namespace std;

const double savingsAccountType::INTEREST_RATE = 0.03;
const int savingsAccountType::TYPE = 1;

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
	if (amount <= 0) {
		throw std::invalid_argument("You must enter a number greater than zero. Please try again.");
	}
	balance = balance + amount;
}

void savingsAccountType::withdraw(double amount)
{
	if (amount <= 0) {
		throw std::invalid_argument("You must enter an amount greater than zero. Please try again.");
	}
	if (amount > balance) {
		throw std::runtime_error("Your withdrawal amount is invalid. Please try again.");
	}
	balance = balance - amount;
}

void savingsAccountType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Savings account: " << getName() << "\t ACCT# " 
		  << getAccountNumber() << "\tBalance: $" << getBalance();
}
