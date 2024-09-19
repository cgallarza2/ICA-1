#ifndef certificateOfDepositType_H
#define certificateOfDepositType_H

#include "bankAccountType.h"
#include <string>

using namespace std;

class certificateOfDepositType: public bankAccountType
{
public:
	certificateOfDepositType(string n, int acctNumber, double bal);
	certificateOfDepositType(string n, int acctNumber, double bal,
								double intRate, int maturityMon);

	virtual double getInterestRate();

	int getAccountType() override;
	virtual int getType();
	void setInterestRate(double rate);
	double getCurrentCDMonth();
	void setCurrentCDMonth(int month);
	virtual int getMaturityMonths();
	void setMaturityMonths(int month);
	void postInterest();
	void withdraw(double amount);
	void withdraw();
	void createMonthlyStatement();

	void print();


private:
	static const double INTEREST_RATE; // = 0.05;
	static const int NUMBER_OF_MATURITY_MONTHS; // = 6;
	static const int TYPE;

	double interestRate;
	int maturityMonths;
	int type;

	int cdMonth;
};

#endif
