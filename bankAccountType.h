#ifndef bankAccountType_H
#define bankAccountType_H

#include <string>
using namespace std;

class bankAccountType
{
	public:

		bankAccountType(string n, int acctNumber, double bal);
		int getAccountNumber();
		double getBalance();
		string getName();
		void setName(string n);
		virtual void withdraw(double amount);
		void deposit (double amount);
		virtual void createMonthlyStatement() = 0;
		virtual void print();
		virtual int getType();
		virtual double getInterestRate();
		virtual int getMaturityMonths();

		virtual void getAccountType() = 0;
	protected:
		int accountNumber;
		string name;
		double balance;

		string password; //security
		string username;
};

#endif
