#ifndef certificateOfDepositType_H
#define certificateOfDepositType_H

#include "bankAccountType.h"
#include <string>

using namespace std;

class certificateOfDepositType: public bankAccountType
{
public:
	certificateOfDepositType(string n, int acctNumber, double bal, string pass, string user);
	certificateOfDepositType(string n, int acctNumber, double bal,
								double intRate, int maturityMon, string pass, string user);

	double getInterestRate();

	void setInterestRate(double rate);
	double getCurrentCDMonth();
	void setCurrentCDMonth(int month);
	double getMaturityMonths();
	void setMaturityMonths(int month);
	void postInterest();
	void withdraw(double amount);
	void withdraw();
	void createMonthlyStatement();

	void print();

private:
	static const double INTEREST_RATE; // = 0.05;
	static const int NUMBER_OF_MATURITY_MONTHS; // = 6;

	double interestRate;
	int maturityMonths;

	int cdMonth;
};

#endif
