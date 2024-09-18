#ifndef bankAccountType_H
#define bankAccountType_H

#include <string>
using namespace std;

class bankAccountType
{
	public:
		//security - added password and username to constructor
		bankAccountType(string n, int acctNumber, double bal, string pass, string user);
		int getAccountNumber();
		double getBalance();
		string getName();
		void setName(string n);
		virtual void withdraw(double amount);
		void deposit (double amount);
		virtual void createMonthlyStatement() = 0;
		virtual void print();

		bool checkPassword(string pass); //security
		string getUsername();
		void setUsername(string user);

	protected:
		int accountNumber;
		string name;
		double balance;

		string password; //security
		string username;
};

#endif
