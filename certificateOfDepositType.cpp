
//Implementation file date

#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include "certificateOfDepositType.h"

using namespace std;

const double certificateOfDepositType::INTEREST_RATE = 0.05;
const int certificateOfDepositType::NUMBER_OF_MATURITY_MONTHS = 6;
const int certificateOfDepositType::TYPE = 6;

certificateOfDepositType::certificateOfDepositType(string n, int acctNumber, double bal)
							: bankAccountType(n, acctNumber, bal)
{
	interestRate = INTEREST_RATE;
	maturityMonths = 0;
	cdMonth = 0;
	type = TYPE;
}

certificateOfDepositType::certificateOfDepositType(string n, int acctNumber, double bal, double intRate,
														 int maturityMon)
							    : bankAccountType(n, acctNumber, bal)
{
	interestRate = intRate;
	maturityMonths = maturityMon;
	cdMonth = 0;
	type = TYPE;
}

double certificateOfDepositType::getInterestRate()
{
	return interestRate;
}

void certificateOfDepositType::setInterestRate(double rate)
{
	interestRate = rate;
}

double certificateOfDepositType::getCurrentCDMonth()
{
	return cdMonth;
}

void certificateOfDepositType::setCurrentCDMonth(int month)
{
	cdMonth = month;
}

int certificateOfDepositType::getMaturityMonths()
{
	return maturityMonths;
}

void certificateOfDepositType::setMaturityMonths(int month)
{
	maturityMonths = month;
}

int certificateOfDepositType::getType()
{
	return type;
}

void certificateOfDepositType::postInterest()
{
	balance = balance + balance * interestRate;
}

void certificateOfDepositType::deposit(double amount)
{

	balance = balance + amount;
}

void certificateOfDepositType::withdraw(double amount)
{
	balance = balance - amount;
}

void certificateOfDepositType::createMonthlyStatement()
{
	postInterest();
	cdMonth++;
}

void certificateOfDepositType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Certificate of Deposit: " << getName() << "\t\t ACCT# "
		  << getAccountNumber() << "\tBalance: $" << getBalance();
}
