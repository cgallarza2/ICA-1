#ifndef highInterestSavingsType_H
#define highInterestSavingsType_H

#include <string>
#include "savingsAccountType.h"
using namespace std;

class highInterestSavingsType: public savingsAccountType
{
public:
	highInterestSavingsType(string n, int acctNumber, double bal);
	highInterestSavingsType(string n, int acctN, double balance,
							  double intRate, double minBalance);

	int getAccountType() override;
	int getType();
	double getMinimumBalance();
	bool verifyMinimumBalance(double amount);
	virtual void withdraw(double amount);
	virtual void print();

protected:
	double minimumBalance;
	int type;

private:
	static const double MINIMUM_BALANCE; // = 2500.00
	static const double INTEREST_RATE; // = 0.05;
	static const int TYPE;
};

#endif
