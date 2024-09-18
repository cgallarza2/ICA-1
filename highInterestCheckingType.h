#ifndef highInterestCheckingType_H
#define highInterestCheckingType_H

#include <string>
#include "noServiceChargeCheckingType.h"
using namespace std;

class highInterestCheckingType: public noServiceChargeCheckingType
{
	public:
		highInterestCheckingType(string n, int acctNumber, double bal);
		highInterestCheckingType(string n, int acctNumber, double bal,
										double minBal, double intRate);
		int getType();
		double getInterestRate();
		void setInterestRate(double intRate);
		void postInterest();
		void createMonthlyStatement();
		virtual void print();

	protected:
		int type;

	private:
		static const double INTEREST_RATE; // = 0.05
		static const double MIN_BALANCE; // = 5000.00
		static const int TYPE;
};

#endif
