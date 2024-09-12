#include "userInterfaceFunctions.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


void printCertificateOfDeposit() {
	char codChoice;

	do {
		clearScreen();

		cout << string(SCREEN_WIDTH, '=') << endl;
		cout << left;
		cout << setw(39) << "=" << setw(60) << "Bank Management System" << "=" << endl;
		cout << setw(42) << "=" << setw(57) << "Account Options" << "=" << endl;
		cout << setw(SCREEN_WIDTH - 1) << "=" << "=" << endl;
		cout << setw(21) << "=" << setw(78) << "1. Retrieve Account Owner's Name" << "=" << endl;
		cout << setw(21) << "=" << setw(78) << "2. Retrieve Account Owner's AcctNumber" << "=" << endl;
		cout << setw(21) << "=" << setw(78) << "3. Retrieve Account Owner's Balance" << "=" << endl;
		cout << setw(21) << "=" << setw(78) << "4. Deposit Money" << "=" << endl;
		cout << setw(21) << "=" << setw(78) << "5. Withdraw Money" << "=" << endl;
		cout << setw(21) << "=" << setw(78) << "6. Create Monthly Statement" << "=" << endl;
		cout << setw(21) << "=" << setw(78) << "7. Return to Main Menu" << "=" << endl;
		cout << setw(SCREEN_WIDTH - 1) << "=" << "=" << endl;
		cout << right;
		cout << string(SCREEN_WIDTH, '=') << endl << endl;

		cout << "Enter your choice:";
		cin >> codChoice;
		cin.ignore(10000, '\n');

		switch (codChoice) {
			case '1':
				cout << "Retrieving account owner's name will occur here";
				break;
			case '2':
				cout << "Retrieving accoutn owner's account number will occur here";
				break;
			case '3':
				cout << "Retrieving Account Owner's balance will occur here";
				break;
			case '4':
				cout << "Depositing money will occur here";
				break;
			case '5':
				cout << "Withdrawing money will occur here";
				break;
			case '6':
				cout << "Creating a monthly statement will occur here";
				break;
			case '7':
				cout << "Returning to main menu.";
				break;
			default:
				clearScreen();
				cout << "*** " << codChoice << " is an Invalid Response***" << endl;
				cout << "Please enter a response 1-7." << endl;
		}
	} while(codChoice != '7');

	return;
}
