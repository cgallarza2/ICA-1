
//Implementation file

#include <iostream>
#include <string>
#include <iomanip>
#include "serviceChargeCheckingType.h"

using namespace std;

const double serviceChargeCheckingType::ACCOUNT_SERVICE_CHARGE = 10.00;
const int serviceChargeCheckingType::MAXIMUM_NUM_OF_CHECKS = 5;
const double serviceChargeCheckingType::SERVICE_CHARGE_EXCESS_NUM_OF_CHECKS = 5;
const int serviceChargeCheckingType::TYPE = 2;

serviceChargeCheckingType::serviceChargeCheckingType(string n, int acctNumber,
																		double bal)
								 :	 checkingAccountType(n, acctNumber, bal)
{
	serviceChargeAccount = ACCOUNT_SERVICE_CHARGE;
	numberOfChecksWritten = 0;
	serviceChargeCheck = 0;
	type = TYPE;
}

serviceChargeCheckingType::serviceChargeCheckingType(string n, int acctNumber, 
																		double bal,
																		double servChargeAmount,
																		double servChargeCheck)
								 : checkingAccountType(n, acctNumber, bal)
{
	serviceChargeAccount = servChargeAmount;
	serviceChargeCheck = servChargeCheck;
	numberOfChecksWritten = 0;
}

double serviceChargeCheckingType::getServiceChargeAccount()
{
	return serviceChargeAccount;
}

void serviceChargeCheckingType::setServiceChargeAccount(double amount)
{
	serviceChargeAccount = amount;
}

double serviceChargeCheckingType::getServiceChargeChecks()
{
	return serviceChargeCheck;
}

void serviceChargeCheckingType::setServiceChargeChecks(double amount)
{
	serviceChargeCheck = amount;
}

int serviceChargeCheckingType::getNumberOfChecksWritten()
{
	return numberOfChecksWritten;
}

void serviceChargeCheckingType::setNumberOfChecksWritten(int num)
{
	numberOfChecksWritten = num;
}

int serviceChargeCheckingType::getType()
{
	return type;
}

void serviceChargeCheckingType::postServiceCharge()
{
	balance = balance - serviceChargeAccount;
}

void serviceChargeCheckingType::writeCheck(double amount)
{
	if (numberOfChecksWritten < MAXIMUM_NUM_OF_CHECKS)
		balance = balance - amount;
	else
		balance = balance - amount - serviceChargeCheck;

	numberOfChecksWritten++;
}

void serviceChargeCheckingType::createMonthlyStatement()
{
	postServiceCharge();
}

void serviceChargeCheckingType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Service Charge Checking: " << getName() << "\t\t ACCT# " 
		  << getAccountNumber() << "\tBalance: $" << getBalance();
}
