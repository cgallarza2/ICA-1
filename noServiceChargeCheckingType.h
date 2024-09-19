#ifndef noServiceChargeCheckingType_H
#define noServiceChargeCheckingType_H

#include <string>
#include "checkingAccountType.h"
using namespace std;

class noServiceChargeCheckingType: public checkingAccountType
{
	public:
		noServiceChargeCheckingType(string n, int acctNumber, double bal);
		noServiceChargeCheckingType(string n, int acctNumber, double bal,
											double minBalance, double intRate);

		int getType();
		double getMinimumBalance();
		void setMinimumBalance(double minBalance);
		bool verifyMinimumumBalance(double amount);
		void writeCheck(double amount);
		void withdraw(double amount);
		virtual void createMonthlyStatement();
		virtual void print();
		int getAccountType() override;

	protected:
		double minimumBalance;
		double interestRate;
		int type;

	private:
		static const double MIN_BALANCE; // = 1000.00;
		static const double INTEREST_RATE; // = 0.02;
		static const int TYPE;

};

#endif
