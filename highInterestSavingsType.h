#ifndef highInterestSavingsType_H
#define highInterestSavingsType_H

#include <string>
#include "savingsAccountType.h"
using namespace std;

class highInterestSavingsType: public savingsAccountType
{
public:
	highInterestSavingsType(string n, int acctNumber, double bal, string pass, string user);
	highInterestSavingsType(string n, int acctN, double balance, string pass, string user,
							  double intRate, double minBalance);
	double getMinimumBalance();
	bool verifyMinimumBalance(double amount);
	virtual void withdraw(double amount);
	virtual void print();

protected:
	double minimumBalance;

private:
	static const double MINIMUM_BALANCE; // = 2500.00
	static const double INTEREST_RATE; // = 0.05;
};

#endif
