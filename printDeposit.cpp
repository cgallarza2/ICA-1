#include "userInterfaceFunctions.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> //file

vector<bankAccountType*> printDeposit(vector<bankAccountType*> accountVector, string txtFile, double balance){

	int type;
	double depositAmount;
	int index = -1; //store index
	
	clearScreen();
	cout << string(SCREEN_WIDTH, '*') << endl;
	cout << left;
	cout << setw(31) << "*" << setw(68) << "Welcome to the Bank Management System!" << "*" << endl;
	cout << cout << setw(11) << "*" << setw(88) << "which account do you want to deposit to?" << endl;
	cout << setw(SCREEN_WIDTH - 1) << "*" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "1. High Interest Checking (" << HIGHINTCHK_RATE << " interest rate, No monthly charge, " << HIGHINTCHK_MIN_BAL << " minimum balance)" << endl;
	cout << setw(11) << "*" << setw(88) << "2. Service Charge Checking (No interest rate, " << ACCT_SERV_CHARGE << " monthly charge, Max of " << MAX_NUM_CHECKS << " checks, No minimum balance)" << endl;
	cout << setw(11) << "*" << setw(88) << "3. No Service Charge Checking (" << NOSERV_CHRG_CHK_INT_RATE << " interest rate, No monthly charge, unlimited checks, " << NOSERV_CHRG_CHK_MIN_BAL << " minimum balance)" << endl;
	cout << setw(11) << "*" << setw(88) << "4. Basic Savings (" << SAVINGS_INT_RATE << " interest rate)" << endl;
	cout << setw(11) << "*" << setw(88) << "5. High Interest Savings (" << HIGHINTSAVE_INT_RATE << " interest rate, " << HIGHINTSAVE_MIN_BAL << " minimum balance)" << endl;
	cout << setw(11) << "*" << setw(88) << "6. Certificate of Deposit (" << COD_INT_RATE << " interest rate, )" << NUM_MATURITY_MON << " maturity months)" << endl;
	cout << setw(SCREEN_WIDTH - 1) << "*" << "*" << endl;
	cout << right;
	cout << string(SCREEN_WIDTH, '*') << endl << endl;

	cout << "Please enter the number associated to the bank account you want to deposit (1-7):";
	cin >> type;
	
	//valid input check
	if (type < 1 || type > 6){
		cout << "error wrong input" << endl;
		return accountVector;
	}
	
	//iterate vector, if account type already exists
	for (int i = 0; i < accountVector.size(); i++) {
			accountVector[i]->getBalance() << endl;
				//get account type
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
				//accountsVector(highInterestCheckingType(name, acctNumber, balance));
				accountVector.push_back(new highInterestCheckingType(name, acctNumber, balance));
				//accountsVector.deposit();
				accountVector.back()->deposit(depositAmount);
				break;
			case 2:
				//accountsVector(highInterestCheckingType(name, acctNumber, balance));
				accountVector.push_back(new serviceChargeCheckingType(name, acctNumber, balance));
				//accountsVector.deposit();
				accountVector.back()->deposit(depositAmount);
				break;
			case 3:
				//accountsVector(highInterestCheckingType(name, acctNumber, balance));
				accountVector.push_back(new noServiceChargeCheckingType(name, acctNumber, balance));
				//accountsVector.deposit();
				accountVector.back()->deposit(depositAmount);
				break;
			case 4:
				//accountsVector(highInterestCheckingType(name, acctNumber, balance));
				accountVector.push_back(new savingsAccountType(name, acctNumber, balance));
				//accountsVector.deposit();
				accountVector.back()->deposit(depositAmount);
				break;
			case 5:
				//accountsVector(highInterestCheckingType(name, acctNumber, balance));
				accountVector.push_back(new highInterestSavingsType(name, acctNumber, balance));
				//accountsVector.deposit();
				accountVector.back()->deposit(depositAmount);
				break;
			case 6:
				//accountsVector(highInterestCheckingType(name, acctNumber, balance));
				accountVector.push_back(new certificateOfDepositType(name, acctNumber, balance));
				//accountsVector.deposit();
				accountVector.back()->deposit(depositAmount);
				break;
			default:
				cout << "*** " << type << " is an invalid selection***" << endl;
				break;
		}
	}
} // printMainMenu();

return accountVector; // return updated vector