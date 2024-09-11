
//Implementation file date

#include <iostream>
#include <string>
#include <iomanip>
#include "highInterestCheckingType.h"

using namespace std;

const double highInterestCheckingType::INTEREST_RATE = 0.05;
const double highInterestCheckingType::MIN_BALANCE = 5000.00;

highInterestCheckingType::highInterestCheckingType(string n, int acctNumber, 
																   double bal, string pass, string user)
								: noServiceChargeCheckingType(n, acctNumber, bal, pass, user)
{
	minimumBalance = MIN_BALANCE;
	interestRate = INTEREST_RATE;
}

highInterestCheckingType::highInterestCheckingType(string n, int acctNumber,
																	double bal, string pass, string user, double minBal, 
																	double intRate)
							   : noServiceChargeCheckingType(n, acctNumber, bal, pass, user,
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
