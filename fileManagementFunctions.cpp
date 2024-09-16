#include "fileManagementFunctions.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "bankAccountType.h"
#include "savingsAccountType.h"
#include "highInterestSavingsType.h"
#include "noServiceChargeCheckingType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "certificateOfDepositType.h"
#include "checkingAccountType.h"

using namespace std;

bool attemptLogIn(string username, string password) {
	ifstream userList;
	string user;
	string pass;

	userList.open("userList.txt");
	if (userList.is_open()){

		while (!userList.eof()) {
			userList >> user;
			userList >> pass;

			if (user == username && pass == password) {
				cout << "Log-In Successful!" << endl;
				userList.close();
				return true;
			}
		}

		userList.close();
		cout << "Please try again!" << endl;
		return false;
	}
	
	return false;
}



vector<bankAccountType*> populateAccounts(vector<bankAccountType*> accountVector, string txtFile) {

	ifstream accounts;
	int type;
	string name;
	int acctNumber;
	double balance;
	string password;
	string username;

	accounts.open(txtFile);
	if (accounts.is_open()){
		while (!accounts.eof()) {
			accounts >> type;
			if (type == 0) {
				accounts.close();
				return accountVector;
			}
			accounts >> name;
			accounts >> acctNumber;
			accounts >> balance;
			accounts >> password;
			accounts >> username;

			switch (type) {
				case 1: {
					accountVector.push_back(new savingsAccountType(name, acctNumber, balance, password, username));
					break;
				}
				default:
					cout << "Error!" << endl;
					break;
			}
		}

		accounts.close();
	}
	return accountVector;
}
