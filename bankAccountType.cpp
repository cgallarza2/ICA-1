//Implementation file

#include <iostream>
#include <string>
#include <iomanip>
#include "bankAccountType.h"

using namespace std;
//security - added password to constructor
bankAccountType::bankAccountType(string n, int acctNumber, double bal, string pass, string user)
{
	name = n;
	accountNumber = acctNumber;
	balance = bal;

	password = pass; //security
	username = user;
}

//security
bool bankAccountType::checkPassword(string pass) { return (password == pass); }
string bankAccountType::getUsername() { return username; }
string bankAccountType::setUsername(string user) { username = user;}

int bankAccountType::getAccountNumber()
{
	return accountNumber;
}

double bankAccountType::getBalance()
{
	return balance;
}

string bankAccountType::getName()
{
	return name;
}

void bankAccountType::setName(string n)
{
	name = n;
}

void bankAccountType::withdraw(double amount)
{
	balance = balance - amount;
}

void bankAccountType::deposit(double amount)
{
	balance = balance + amount;
}

void bankAccountType::print()
{
	cout << fixed << showpoint << setprecision (2);
	cout << name << " " << accountNumber << " balance : $"
		  << balance;
}
