
#ifndef serviceChargeCheckingType_H
#define serviceChargeCheckingType_H

#include <string>
#include "checkingAccountType.h"

using namespace std;

class serviceChargeCheckingType: public checkingAccountType
{
	public:
		serviceChargeCheckingType(string n, int acctNumber, double bal, string pass, string user);
		serviceChargeCheckingType(string n, int acctNumber, double bal,
											double servChargeAmount,
											double servChargeCheck, string pass, string user);

		double getServiceChargeAccount();
		void setServiceChargeAccount(double amount);
		double getServiceChargeChecks();
		void setServiceChargeChecks(double amount);
		int getNumberOfChecksWritten();
		void setNumberOfChecksWritten(int num);
		void postServiceCharge();
		void writeCheck(double amount);
		virtual void createMonthlyStatement();
		virtual void print();

	protected: 
		double serviceChargeAccount;
		double serviceChargeCheck;
		int numberOfChecksWritten;

	private:
		static const double ACCOUNT_SERVICE_CHARGE; // = 10.00;
		static const int MAXIMUM_NUM_OF_CHECKS; // = 5;
		static const double SERVICE_CHARGE_EXCESS_NUM_OF_CHECKS; // = 5;
};

#endif
