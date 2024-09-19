#include "userInterfaceFunctions.h"

#include "bankAccountType.h" //0
#include "highInterestCheckingType.h" //1
#include "serviceChargeCheckingType.h" //2
#include "noServiceChargeCheckingType.h" //3
#include "savingsAccountType.h" //4
#include "highInterestSavingsType.h" //5
#include "certificateOfDepositType.h" //6

#include <iostream>
#include <iomanip>
#include <string>
#include <vector> //vector
#include <iostream>
#include <fstream>

using namespace std;

vector<bankAccountType*> printDeposit(vector<bankAccountType*>& accountVector){

	int type;
	double depositAmount;
	int index = -1; //store index

	clearScreen();
	cout << string(SCREEN_WIDTH, '*') << endl;
	cout << left;
	cout << setw(31) << "*" << setw(68) << "Welcome to the Bank Management System!" << "*" << endl;
	cout << setw(31) << "*" << setw(68) << "which account do you want to deposit to?" << "*" << endl;
	cout << setw(SCREEN_WIDTH - 1) << "*" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "1. High Interest Checking" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "2. Service Charge Checking" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "3. No Service Charge Checking" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "4. Basic Savings" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "5. High Interest Savings" << "*" << endl;
	cout << setw(11) << "*" << setw(88)  << "6. Certificate of Deposit" << "*" << endl;
	cout << setw(SCREEN_WIDTH - 1) << "*" << "*" << endl;
	cout << right;
	cout << string(SCREEN_WIDTH, '*') << endl << endl;

	cout << "Please enter the number associated to the bank account you want to deposit (1-7): ";
	cin >> type;

	//valid input check
	if (type < 1 || type > 6){
		cout << "error wrong input" << endl;
		return accountVector;
	}

	//iterate vector, if account type already exists
	for (int i = 0; i < accountVector.size(); i++) {
			accounts << accountVector[i]->getBalance() << endl;
				//get account type based off constructors (override)
			if (accountVector[i]->getAccountType() == type){
				index = i; //store in the index
				break;
			}
	}

	//flag to check already in vector
	if (index != -1) {
			cout << "Already type in vector";
			return accountVector;
	}

	//otherwise, get user deposit input
	cout << "Enter deposit amount: ";
	cin >> depositAmount;

	//deposit based on selected account type
		switch (type) {
			case 1:
				//accountVector.push_back(new highInterestCheckingType(name, acctNumber, balance));
				//accountsVector->deposit();
				//accountVector.back()->deposit(depositAmount);
				accountVector[index]->deposit(depositAmount);
				break;
			case 2:
				//accountVector.push_back(new serviceChargeCheckingType(name, acctNumber, balance));
				//accountsVector->deposit();
				accountVector[index]->deposit(depositAmount);
				break;
			case 3:
				//accountVector.push_back(new noServiceChargeCheckingType(name, acctNumber, balance));
				//accountsVector.deposit();
				accountVector[index]->deposit(depositAmount);
				break;
			case 4:
				//accountVector.push_back(new savingsAccountType(name, acctNumber, balance));
				//accountsVector->deposit();
				accountVector[index]->deposit(depositAmount);
				break;
			case 5:
				//accountVector.push_back(new highInterestSavingsType(name, acctNumber, balance));
				//accountsVector->deposit();
				accountVector[index]->deposit(depositAmount);
				break;
			case 6:
				//accountVector.push_back(new certificateOfDepositType(name, acctNumber, balance));
				//accountsVector->deposit();
				accountVector[index]->deposit(depositAmount);
				break;
			default:
				cout << "*** " << type << " is an invalid selection***" << endl;
				break;
		}

	return accountVector; // return updated vector
} 