#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "userInterfaceFunctions.h"
#include "bankAccountType.h"
#include "savingsAccountType.h"
#include "highInterestSavingsType.h"
#include "noServiceChargeCheckingType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "certificateOfDepositType.h"
#include "checkingAccountType.h"
#include "fileManagementFunctions.h"


using namespace std;

vector<bankAccountType *> printCreateNewUser(vector<bankAccountType *> accountVector) //pass by reference: to persist changes to vector
{
	string name, username, password;
	int acctNumber, accountType; //account number should be generated i++
	double balance = 0; //start with 0 balance
	int sessionID = 1212; //make random later


	clearScreen();

	cout << string(SCREEN_WIDTH, '*') << endl;
	cout << left;
	cout << setw(11) << "*" << setw(88) << "Welcome to Bank Account Creation!" << "*" << endl;
	cout << string(SCREEN_WIDTH, '*') << endl << endl;
	
	cout << "Create a username: ";
	cin >> username;
	
	cout << "Create a password: "; //add hashing later //add clearing terminal typing
	cin >> password;
	
	addAccount(username, password); //to userList
	
	//cout << string(SCREEN_WIDTH, '*') << endl;
	cout << "Enter your given name: ";
	cin >> name;
	cout << "Enter the account number: ";
	cin >> acctNumber;
	//cout << "Enter the account balance: ";
	//cin >> balance;


	clearScreen();
	cout << string(SCREEN_WIDTH, '*') << endl;
	cout << left;
	cout << setw(11) << "*" << setw(88) << "The various bank account types we have to offer!" << "*" << endl;
	cout << string(SCREEN_WIDTH, '*') << endl;
	cout << setw(11) << "*" << setw(88) << "1. Basic Checking" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "2. High Interest Checking" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "3. Service Charge Checking" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "4. No Service Charge Checking" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "5. Basic Savings" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "6. High Interest Savings" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "7. Certificate of Deposit" << "*" << endl;
	cout << setw(SCREEN_WIDTH - 1) << "*" << "*" << endl;
	cout << right;
	cout << string(SCREEN_WIDTH, '*') << endl << endl;

	cout << "Please enter the bank account type (1-7): ";
	cin >> accountType;

	string filename = username + ".txt"; //username.txt
	ofstream accountFile(filename, ios::app);
	
	if (accountFile.is_open()){
		accountVector = createAccount(accountVector, filename, accountType, name, acctNumber, balance, 0, 0, sessionID); //to accountvector
		printAccountInfo(accountVector); //testing 
	} //error checking in createAccount
//return;
return accountVector; //needs to return account vector
}
/*
	string filename = username + "_account.txt"; //username_account.txt
	ofstream accountFile(filename, ios::app);
	if (accountFile.is_open()){
		accountFile << accountType << endl; //user specifies in menus 
		accountFile << name << endl; //user enters
		accountFile << acctNumber << endl; //user does not enter
		accountFile << balance << endl; //user does not enter
		accountFile << password << endl; //store in hash, when printing dehash
		accountFile << username << endl; //user enters 
		accountFile.close();
		cout << "Account Created" << endl;
	}else{
		cout << "Unable to make account" << endl;
	}
*/