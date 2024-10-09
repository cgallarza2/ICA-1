//Implementation file

#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include "bankAccountType.h"

using namespace std;
//security - added password to constructor
bankAccountType::bankAccountType(string n, int acctNumber, double bal)
{
	name = n;
	accountNumber = acctNumber;
	balance = bal;
}


int bankAccountType::getAccountNumber()
{
	return accountNumber;
}

double bankAccountType::getBalance()
{
	return balance;
}

void bankAccountType::setBalance(double newBalance)
{
	balance = newBalance;
}

string bankAccountType::getName()
{
	return name;
}

string bankAccountType::getUsername()
{
	return username;
}

int bankAccountType::getType()
{
return 0;
}

double bankAccountType::getInterestRate()
{
return 0;
}

int bankAccountType::getMaturityMonths()
{
return 0;
}

void bankAccountType::setName(string n)
{
	name = n;
}

void bankAccountType::deposit(double amount)
{
	if (amount <= 0) {
		throw std::invalid_argument("You must enter an amount greater than zero. Please try again.");
	}
	balance = balance + amount;
}

void bankAccountType::withdraw(double amount)
{
	if (amount <= 0) {
		throw std::invalid_argument("You must enter an amount greater than zero. Please try again.");
	}
	if (amount > balance) {
		throw std::runtime_error("Your withdrawal amount is invalid. Please try again.");
	}
	balance = balance - amount;
}

void bankAccountType::print()
{
	cout << fixed << showpoint << setprecision (2);
	cout << name << " " << accountNumber << " balance : $"
		  << balance;
}
