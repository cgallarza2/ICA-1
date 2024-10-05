#include "userInterfaceFunctions.h"
#include "fileManagementFunctions.h" //print / deposit / withdraw
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


void printAccountFunctions(vector<bankAccountType *> accountVector) {
	char functionChoice;
	bool firstTimeInScreen = true;
	int sessionID = 1212;

	do {
		if (firstTimeInScreen) {
			clearScreen();
			firstTimeInScreen = false;
		}

		cout << string(SCREEN_WIDTH, '=') << endl;
		cout << left;
		cout << setw(39) << "=" << setw(60) << "Bank Management System" << "=" << endl;
		cout << setw(42) << "=" << setw(57) << "Account Options" << "=" << endl;
		cout << setw(SCREEN_WIDTH - 1) << "=" << "=" << endl;
		cout << setw(21) << "=" << setw(78) << "1. Print Account Info" << "=" << endl;
		cout << setw(21) << "=" << setw(78) << "2. Deposit Money" << "=" << endl;
		cout << setw(21) << "=" << setw(78) << "3. Withdraw Money" << "=" << endl;
		cout << setw(21) << "=" << setw(78) << "4. Create Monthly Statement" << "=" << endl;
		cout << setw(21) << "=" << setw(78) << "5. Return to Main Menu" << "=" << endl;
		cout << setw(SCREEN_WIDTH - 1) << "=" << "=" << endl;
		cout << right;
		cout << string(SCREEN_WIDTH, '=') << endl << endl;

		cout << "Enter your choice: ";
		cin >> functionChoice;

		string txtFile;
		int accountType;
		double amount;
		
		switch (functionChoice) {
			case '1': //print user data
				printAccountInfo(accountVector);
				break;
			case '2': //deposit
				printDeposit();
				cout << "Enter account type (1-7): ";
				cin >> accountType;
				cout << "Enter deposit amount: " ;
				cin >> amount;
				depositToAccount(accountVector, accountType, amount);

				break;
			case '3': //withdraw
				printWithdraw();
				cout << "Enter account type (1-7): ";
				cin >> accountType;
				cout << "Enter withdraw amount: ";
				cin >> amount;
				withdrawToAccount(accountVector, accountType, amount);
				break;
			case '4': //create monthly statement
				createStatement(accountVector);
				break;
			case '5':
				cout << "Returning to main menu.";
				break;
			default:
				clearScreen();
				cout << "*** " << functionChoice << " is an Invalid Response***" << endl;
				cout << "Please enter a response (1-5)" << endl;
				break;
		}
	} while(functionChoice != '5');

	return;
}
