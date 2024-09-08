#ifndef bankAccountType_H
#define bankAccountType_H

#include <string>
using namespace std;

class bankAccountType
{
	public:
		bankAccountType(string n = "", int acctNumber = 0, double bal = 0);
		int getAccountNumber();
		double getBalance();
		string getName();
		void setName(string n);
		virtual void withdraw(double amount);
		void deposit (double amount);
		virtual void createMonthlyStatement() = 0;
		virtual void print();

	protected:
		int accountNumber;
		string name;
		double balance;
};

#endif
