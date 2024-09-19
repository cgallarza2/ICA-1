#include "userInterfaceFunctions.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


void printAccountFunctions(vector<bankAccountType*>& accountVector) {
	char functionChoice;

	do {
		clearScreen();

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

		cout << "Enter your choice:";
		cin >> functionChoice;
		cin.ignore(10000, '\n');

		switch (functionChoice) {
			case '1':
				cout << "printing";
				break;
			case '2':
				cout << "Depositing money will occur here";
				accountVector = printDeposit(accountVector);
				break;
			case '3':
				cout << "Withdrawing money will occur here";
				break;
			case '4':
				cout << "Creating a monthly statement will occur here";
				break;
			case '5':
				cout << "Returning to main menu.";
				break;
			default:
				clearScreen();
				cout << "*** " << functionChoice << " is an Invalid Response***" << endl;
				cout << "Please enter a response 1-5." << endl;
				break;
		}
	} while(functionChoice != '5');

	return;
}