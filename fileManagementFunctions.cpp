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

	accounts.open(txtFile);
	if (accounts.is_open()){
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



vector<bankAccountType*> createAccount(vector<bankAccountType*> accountVector, string txtFile, int a_type, string a_name, int a_acctNumber, double a_balance, double a_intRate = 0, int a_maturityMon = 0) {

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
	return accountVector;
}


//Account Options Functions
//print account info
void printAccountInfo(string username, string password){
	ifstream accountFile;
	string filename = username + "_account.txt";
	accountFile.open(filename);

	if (accountFile.is_open()) {
		int type, acctNumber;
		string name, password, uname;
		double balance;

		cout << endl << "Account Information for " << username << ":" << endl;
		cout << "******************************" << endl;

		while (accountFile >> type >> name >> acctNumber >> balance >> password >> uname) {
			cout << "Account Type: ";
			switch (type) {
				case 1: cout << "Basic Checking" << endl; break;
				case 2: cout << "High Interest Checking" << endl; break;
				case 3: cout << "Service Charge Checking" << endl; break;
				case 4: cout << "No Service Charge Checking" << endl; break;
				case 5: cout << "Basic Savings" << endl; break;
				case 6: cout << "High Interest Savings" << endl; break;
				case 7: cout << "Certificate of Deposit" << endl; break;
				default: cout << "Not found" << endl; break;
			}

			cout << "Name: " << name << endl;
			cout << "Account Number: " << acctNumber << endl;
			cout << "Balance: $" << balance << endl;
			cout << "Username: " << uname << endl;
			cout << "Password: " << password << endl; //add hashing later
			cout << "*****************************" << endl;

		}
		accountFile.close();
		} else {
			cout << "User " << username << " does not have an account." << endl;
	}
}

//deposit function
void depositToAccount(string username, int accountType, double amount){
	
	ifstream accountFile;
	string filename = username + "_account.txt";
	accountFile.open(filename);
	
	if(!accountFile.is_open()) { cout << "user: " << username << " does not have account on file" << endl; return; }
	
	int type, acctNumber;
	string name, uname, password;
	double balance;
	string updatedData; //store updated data
	
		//read all accounts and keep track of changes
		while (accountFile >> type >> name >> acctNumber >> balance >> password >> uname){
			//check if account type is the one we want to deposit to
			if (type == accountType){
				balance += amount; //update the balance
			} 
			//update the file, to string 
			updatedData += to_string(type) + " " + name + " " + to_string(acctNumber) + " " +
							to_string(balance) + " " + password + " " + uname + "\n"; 
		}
	accountFile.close();
	
	//write updated data back into the user file
	ofstream outputFile(filename);
	if (outputFile.is_open()) {
		outputFile << updatedData; //updated data to the outputfile (single line)
		outputFile.close();
		//cout << "Balance updated " << "New Balance: $" << fixed << setprecision(2) << balance << endl;
	}else {
		cout << "\nUser: " << username << " does not have an account of type: " << type << endl;
	}
}

//withdraw function
void withdrawToAccount(string username, int accountType, double amount){
	
	ifstream accountFile;
	string filename = username + "_account.txt";
	accountFile.open(filename);
	
	if(!accountFile.is_open()) { cout << "user: " << username << " does not have account on file" << endl; return; }
	
	int type, acctNumber;
	string name, uname, password;
	double balance;
	string updatedData; //store updated data
	
		//read all accounts and keep track of changes
		while (accountFile >> type >> name >> acctNumber >> balance >> password >> uname){
			//check if account type is the one we want to withdraw to
			if (type == accountType && balance <= 0){
				balance -= amount; //update the balance
			} else {
				cout << "\nWithdraw was not successful!! Balance must be more than 0" << endl; //loops all accounts rn
			}
			//update the file, to string 
			updatedData += to_string(type) + " " + name + " " + to_string(acctNumber) + " " +
							to_string(balance) + " " + password + " " + uname + "\n"; 
		}
	accountFile.close();
	
	//write updated data back into the user file
	ofstream outputFile(filename);
	if (outputFile.is_open()) {
		outputFile << updatedData; //cout updated data to the outputfile (single file)
		outputFile.close();
		//cout << "Balance updated " << "New Balance: $" << fixed << setprecision(2) << balance << endl;
	}else {
		cout << "\nUser: " << username << " does not have an account of type: " << type << endl;
	}
}