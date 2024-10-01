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



void addAccount(string username, string password) {
	ofstream userList;
	string user;
	string pass;

	userList.open("userList.txt", ios::app);
	if (userList.is_open()){
		userList << endl << username << " " << password << endl;

		userList.close();
	}
}



vector<bankAccountType*> populateAccounts(vector<bankAccountType*> accountVector, string txtFile) {

	ifstream accounts;
	int type;
	string name;
	int acctNumber;
	double balance;
	double intRate;
	int maturityMon;

	int sessionID;

	accounts.open(txtFile);
	if (accounts.is_open()){
		accounts >> sessionID;

		while (!accounts.eof()) {
			accounts >> type;
			if (type == -9999) {
				accounts.close();
				return accountVector;
			}

			accounts >> name;
			accounts >> acctNumber;
			accounts >> balance;

			if (type == 6) {
			accounts >> intRate;
			accounts >> maturityMon;
			}

			switch (type) {
				case 1: {
					accountVector.push_back(new savingsAccountType(name, acctNumber, balance));
					break;
				}
				case 2: {
					accountVector.push_back(new highInterestSavingsType(name, acctNumber, balance));
					break;
				}
				case 3: {
					accountVector.push_back(new noServiceChargeCheckingType(name, acctNumber, balance));
					break;
				}
				case 4: {
					accountVector.push_back(new serviceChargeCheckingType(name, acctNumber, balance));
					break;
				}
				case 5: {
					accountVector.push_back(new highInterestCheckingType(name, acctNumber, balance));
					break;
				}
				case 6: {
					accountVector.push_back(new certificateOfDepositType(name, acctNumber, balance, intRate, maturityMon));
					break;
				}
				default:
					cout << "Error while attempting to push an account!" << endl;
					break;
			}
		}

		accounts.close();
	}
	return accountVector;
}



vector<bankAccountType*> createAccount(vector<bankAccountType*> accountVector, string txtFile, int a_type, string a_name, int a_acctNumber, double a_balance, double a_intRate = 0, int a_maturityMon = 0, int sessionID = 1212) {

	ofstream accounts;
	int type = a_type;
	string name = a_name;
	int acctNumber = a_acctNumber;
	double balance = a_balance;
	double intRate = a_intRate;
	int maturityMon = a_maturityMon;

	accounts.open(txtFile);
	if (accounts.is_open()){

		if (type == -9999) {
			accounts.close();
			return accountVector;
		}

		switch (type) {
			case 1: {
				accountVector.push_back(new savingsAccountType(name, acctNumber, balance));
				break;
			}
			case 2: {
				accountVector.push_back(new highInterestSavingsType(name, acctNumber, balance));
				break;
			}
			case 3: {
				accountVector.push_back(new noServiceChargeCheckingType(name, acctNumber, balance));
				break;
			}
			case 4: {
				accountVector.push_back(new serviceChargeCheckingType(name, acctNumber, balance));
				break;
			}
			case 5: {
				accountVector.push_back(new highInterestCheckingType(name, acctNumber, balance));
				break;
			}
			case 6: {
				accountVector.push_back(new certificateOfDepositType(name, acctNumber, balance, intRate, maturityMon));
				break;
			}
			default:
				cout << "Error while attempting to push an account!" << endl;
				break;
		}

		updateUserAccounts(accountVector, txtFile, sessionID);
	}
	return accountVector;
}



void updateUserAccounts (vector<bankAccountType*> accountVector, string txtFile, int sessionID) {
	ofstream accounts;

	accounts.open(txtFile);
	if (accounts.is_open()) {
		accounts << sessionID << endl << endl;

		for (int i = 0; i < accountVector.size(); i++) {
			accounts << accountVector[i]->getType() << endl;
			accounts << accountVector[i]->getName() << endl;
			accounts << accountVector[i]->getAccountNumber() << endl;
			accounts << accountVector[i]->getBalance() << endl;

			if (accountVector[i]->getType() == 6) {
				accounts << accountVector[i]->getInterestRate() << endl;
				accounts << accountVector[i]->getMaturityMonths() << endl;
			}

			accounts << endl;
		}

		accounts << "-9999";

		accounts.close();
	}
}


//Account Options Functions
//print account info
void printAccountInfo(const vector<bankAccountType*> accountVector) { //pass in account vector
    cout << "\n**********************************" << endl;
	for (const auto account : accountVector) { //iterate through account vector (print all accounts)
        //cout << "Account type: " << account->getType() << endl;
        switch (account->getType()) {
            case 1: cout << "Account type: Checking" << endl; break;
            case 2: cout << "Account type: High Interest Checking" << endl; break;
            case 3: cout << "Account type: Service Charge Checking" << endl; break;
            case 4: cout << "Account type: No Service Charge Checking" << endl; break;
            case 5: cout << "Account type: Savings" << endl; break;
            case 6: cout << "Account type: High Interest Savings" << endl; break;
            case 7: cout << "Account type: Certificate of Deposit (C.O.D.)" << endl;
                cout << "Interest rate: " << account->getInterestRate() << "%" << endl;
                cout << "Maturity months: " << account->getMaturityMonths() << endl;
                break;
            default: cout << "Account type: Not Found" << endl; break;
        }
        cout << "Account name: " << account->getName() << endl;
        cout << "Account number: " << account->getAccountNumber() << endl;
        cout << "Balance: $" << account->getBalance() << endl;

        cout << "**********************************" << endl; //seperate accounts
    }
}


//deposit function
bool depositToAccount(vector<bankAccountType*> accountVector, int accountType, double amount) { //pass in user input account type and amount
    cout << "\n**********************************" << endl;
	for (auto account : accountVector) { //iterate through account vector
        if (account->getType() == accountType) { //check type
            account->deposit(amount); // deposit()
            cout << "Successfully deposited $" << amount << " to account type " << accountType << "..." << endl;
            return true; // deposit made
        }
    }
    cout << "Account type " << accountType << " not found." << endl; //TODO: add switch cases for accountType
    return false; // false if account not found
}


//withdraw function
bool withdrawToAccount(vector<bankAccountType*> accountVector, int accountType, double amount) {
    for (auto account : accountVector) { //iterate
        if (account->getType() == accountType) { //check type to withdraw
            if (account->getBalance() >= amount) { //check balance greater than 0 (check for if withdraw 
                account->withdraw(amount); // withdraw()
                cout << "Successfully withdrew $" << amount << " from account type " << accountType << "..." << endl;
                return true; // withdraw made
            } else {
                cout << "Insufficient funds in account number " << accountType << "." << endl;
                return false; // false, not enough in balance
            }
        }
    }
    cout << "Account type " << accountType << " not found." << endl; //TODO: add switch cases for accountType
    return false; // false if account not found
}

