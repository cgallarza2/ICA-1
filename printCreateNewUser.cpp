#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
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

vector<bankAccountType *> printCreateNewUser(vector<bankAccountType *> accountVector, int sessionID, string &username)
{
	string name;
	char password[100];
	int acctNumber, accountType; //account number should be generated i++
	double balance = 0; //start with 0 balance
	int i = 0;
	int ch;


	clearScreen();

	cout << string(SCREEN_WIDTH, '*') << endl;
	cout << left;
	cout << setw(11) << "*" << setw(20) << " "  << setw(68) << "Welcome to Bank Account Creation!" << "*" << endl;
	cout << string(SCREEN_WIDTH, '*') << endl << endl;
	
	cout << "Create a username: ";
	getline(cin, username);
	
	cout << "Create a password: ";	//add hashing later
	while ((ch = getch()) != '\n') {		// clearing typing
		if (ch == 127 || ch == 8) {
			if (i != 0) {
				i--;
				cout << "\b \b";
			}
		} else {
			password[i++] = ch;
			cout << "*";
		}
	}
	password[i] = '\0';
	
	addAccount(username, password); //to userList
	
	cout << "\nEnter your given name: ";
	cin >> name;
	cout << "Enter the account number: ";
	cin >> acctNumber;


	//clearScreen();
	//cout << string(SCREEN_WIDTH, '*') << endl;
	//cout << left;
	//cout << setw(11) << "*" << setw(88) << "The various bank account types we have to offer!" << "*" << endl;
	//cout << string(SCREEN_WIDTH, '*') << endl;
	//cout << setw(11) << "*" << setw(88) << "1. High Interest Checking" << "*" << endl;
	//cout << setw(11) << "*" << setw(88) << "2. Service Charge Checking" << "*" << endl;
	//cout << setw(11) << "*" << setw(88) << "3. No Service Charge Checking" << "*" << endl;
	//cout << setw(11) << "*" << setw(88) << "4. Basic Savings" << "*" << endl;
	//cout << setw(11) << "*" << setw(88) << "5. High Interest Savings" << "*" << endl;
	//cout << setw(11) << "*" << setw(88) << "6. Certificate of Deposit" << "*" << endl;
	//cout << setw(SCREEN_WIDTH - 1) << "*" << "*" << endl;
	//cout << right;
	//cout << string(SCREEN_WIDTH, '*') << endl << endl;

	//cout << "Please enter the bank account type (1-6): ";
	//cin >> accountType;

	string filename = username + ".txt"; //username.txt
	ofstream accountFile(filename, ios::app);
	
	if (accountFile.is_open()){
		for (int i = 1; i < 7; i++) {
			accountVector = createAccount(accountVector, filename, i, name, acctNumber, balance, 0.05, 0, sessionID); //to accountvector
		}
	} //error checking in createAccount
return accountVector;
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
