#include "fileManagementFunctions.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <limits>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
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


int getch(){
	int ch;
	struct termios old_settings, new_settings;
	tcgetattr(STDIN_FILENO, &old_settings);
	new_settings = old_settings;
	new_settings.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
	return ch;
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
void printAccountInfo(const vector<bankAccountType*> accountVector) {
    cout << "\n**********************************\n";
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
            default: cout << "Account type: Not Found \nReturning to account options... \n\n"; break;
        }
        cout << "Account name: " << account->getName() << endl;
        cout << "Account number: " << account->getAccountNumber() << endl;
        cout << "Balance: $" << account->getBalance() << endl;

        cout << "**********************************\n\n";
    }
}


//deposit function
bool depositToAccount(vector<bankAccountType*> accountVector, int accountType, double amount) {
	try { // exception handling for depositing non-numbers
		if (cin.fail()) {
			 cin.clear();
			 cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw invalid_argument("Your deposit amount is invalid. Please try again.");
		}

		if (amount <= 0) { // exception handling for depositing zero or negative numbers
			throw invalid_argument("You must enter an amount greater than zero. Please try again.");
		}

	for (auto account : accountVector) { //iterate through account vector
        if (account->getType() == accountType) { //check type
            account->deposit(amount); // deposit()
            cout << "\nSuccessful deposit of: $" << amount 
					  << "\nBalance: $" << account->getBalance() 
					  << "\nReturning to account options. \n\n";
            return true; // deposit made
			}
		}
    switch (accountType) {
        case 1: cout << "Account Type Not Found: Checking \nReturning to account options... \n\n" << endl; break;
        case 2: cout << "Account Type Not Found: High Interest Checking \nReturning to account options... \n\n" << endl; break;
        case 3: cout << "Account Type Not Found: Service Charge Checking \nReturning to account options... \n\n" << endl; break;
        case 4: cout << "Account Type Not Found: No Service Charge Checking \nReturning to account options... \n\n" << endl; break;
        case 5: cout << "Account Type Not Found: Savings \nReturning to account options... \n\n" << endl; break;
        case 6: cout << "Account Type Not Found: High Interest Savings \nReturning to account options... \n\n" << endl; break;
        case 7: cout << "Account Type Not Found: Certificate of Deposit (C.O.D.) \nReturning to account options... \n\n" << endl;
        default: break;
	    }
	}
	 catch (const invalid_argument& e) {
		 cout << "Error: " << e.what() << endl;
		 cin.clear();
		 cin.ignore(numeric_limits<streamsize>::max(), '\n');
	 }
	 catch (const exception& e) {
		 cout << "An error has occurred: " << e.what() << endl;
	 }
    return false; // false if account not found
}

//withdraw function
bool withdrawToAccount(vector<bankAccountType*> accountVector, int accountType, double amount) {
	 try { // exception handling for withdrawing non-numbers
		  if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw invalid_argument("Your withdrawal amount is invalid. Please try again.");
		  }

		  if (amount <= 0) { // exception handling for withdrawing zero or negative numbers
				throw invalid_argument("You must enter an amount greater than zero. Please try again.");
		  }

    for (auto account : accountVector) { //iterate
        if (account->getType() == accountType) { //check type to withdraw
            if (account->getBalance() >= amount) { //check balance greater than 0 (check if withdraw goes - )
                account->withdraw(amount); // withdraw()
                cout << "\nSuccessful withdraw of: $" << amount 
							<< "\nRemaining balance: $" << account->getBalance() 
							<< "\nReturning to account options... \n\n";
                return true; // withdraw made
            } else {
                throw runtime_error("Your withdrawal amount is invalid. Please try again.");
				}
			}
		}
		switch (accountType) {
        	case 1: cout << "Account type Not Found: Checking \nReturning to account options... \n\n" << endl; break;
         case 2: cout << "Account type Not Found: High Interest Checking \nReturning to account options... \n\n" << endl; break;
    		case 3: cout << "Account type Not Found: Service Charge Checking \nReturning to account options... \n\n" << endl; break;
    		case 4: cout << "Account type Not Found: No Service Charge Checking \nReturning to account options... \n\n" << endl; break;
     		case 5: cout << "Account type Not Found: Savings \nReturning to account options... \n\n" << endl; break;
    		case 6: cout << "Account type Not Found: High Interest Savings \nReturning to account options... \n\n" << endl; break;
     		case 7: cout << "Account type Not Found: Certificate of Deposit (C.O.D.) \nReturning to account options... \n\n" << endl; break;
    		default: break;
			}
    }
	 catch (const invalid_argument& e) {
		  cout << "Error: " << e.what() << endl;
		  cin.clear();
		  cin.ignore(numeric_limits<streamsize>::max(), '\n');
	 }
	 catch (const runtime_error& e) {
		  cout << "Error: " << e.what() << endl;
	 }
	 catch (const exception& e) {
		  cout << "An error has occurred: " << e.what() << endl;
	 }
    return false; // false if account not found
}


void createStatement(vector<bankAccountType*> &accountVector){
	cout << "\nJanuary:\n-------------" << endl;
	for (int i = 0; i < accountVector.size(); i++){
	    accountVector[i]->createMonthlyStatement();
        accountVector[i]->print();
	    cout << endl;
	}

	cout << "\nFebruary:\n-------------" << endl;
	for (int i = 0; i < accountVector.size(); i++){
	    accountVector[i]->createMonthlyStatement();
	    accountVector[i]->print();
	    cout << endl;
	}

	cout << "\nMarch:\n-------------" << endl;
	for (int i = 0; i < accountVector.size(); i++){
	    accountVector[i]->createMonthlyStatement();
	    accountVector[i]->print();
        cout << endl;
    }
}
