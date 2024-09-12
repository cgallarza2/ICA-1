#include "userInterfaceFunctions.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


void printSavingsAccount() {
	char savingsChoice;

	do {
		clearScreen();

		cout << string(SCREEN_WIDTH, '=') << endl;
		cout << left;
		cout << setw(39) << "=" << setw(60) << "Bank Management System" << "=" << endl;
		cout << setw(42) << "=" << setw(57) << "Savings Account" << "=" << endl;
		cout << setw(SCREEN_WIDTH - 1) << "=" << "=" << endl;
		cout << setw(11) << "=" << setw(88) << "1. Basic Savings (***% interest)" << "=" << endl;
		cout << setw(11) << "=" << setw(88) << "2. High-Interest Savings (***% interest, minimum balance)" << "=" << endl;
		cout << setw(11) << "=" << setw(88) << "3. Return to Main Menu" << "=" << endl;
		cout << setw(SCREEN_WIDTH - 1) << "=" << "=" << endl;
		cout << right;
		cout << string(SCREEN_WIDTH, '=') << endl << endl;

		cout << "Enter your choice: ";
		cin >> savingsChoice;
		cin.ignore(10000, '\n');

		switch (savingsChoice) {
			case '1':
				cout << "Basic Savings will be here";
				break;
			case '2':
				cout << "High Interest Savings will be here";
				break;
			case '3':
				cout << "Returning to main menu.";
				break;
			default:
				clearScreen();
				cout << "*** " << savingsChoice << " is an Invalid Response***" << endl;
				cout << "Please enter a response 1-3." << endl;
		}
	} while (savingsChoice != '3');

	return;
}
