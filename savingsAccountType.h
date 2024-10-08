#ifndef savingsAccountType_H
#define savingsAccountType_H

#include <string>
#include "bankAccountType.h"

using namespace std;

class savingsAccountType: public bankAccountType
{
public:
	savingsAccountType(string n, int acctNumber, double bal);

	savingsAccountType(string n, int acctNumber, double bal, double intRate);

	double getInterestRate();
	void setInterestRate(double rate);
	void postInterest();
	virtual void createMonthlyStatement();
	virtual void print();

protected:
	double interestRate;

private:
	static const double INTEREST_RATE; // = 0.03
};

#endif
