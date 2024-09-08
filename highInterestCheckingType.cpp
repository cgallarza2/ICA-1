
//Implementation file date

#include <iostream>
#include <string>
#include <iomanip>
#include "highInterestCheckingType.h"

using namespace std;

const double highInterestCheckingType::INTEREST_RATE = 0.05;
const double highInterestCheckingType::MIN_BALANCE = 5000.00;

highInterestCheckingType::highInterestCheckingType(string n, int acctNumber, 
																   double bal)
								: noServiceChargeCheckingType(n, acctNumber, bal)
{
	minimumBalance = MIN_BALANCE;
	interestRate = INTEREST_RATE;
}

highInterestCheckingType::highInterestCheckingType(string n, int acctNumber,
																	double bal, double minBal, 
																	double intRate)
							   : noServiceChargeCheckingType(n, acctNumber, bal, 
																	minBal, intRate)
{
}

double highInterestCheckingType::getInterestRate()
{
	return interestRate;
}

void highInterestCheckingType::setInterestRate(double intRate)
{
	interestRate = intRate;
}

void highInterestCheckingType::postInterest()
{
	balance = balance + balance * interestRate;
}

void highInterestCheckingType::createMonthlyStatement()
{
	postInterest();
}

void highInterestCheckingType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Higher Interest Checking: " << getName() << "\t ACCT# "
		  << getAccountNumber() << "\tBalance: $" << getBalance();
}
