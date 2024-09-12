#include "userInterfaceFunctions.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


void printCheckingAccount() {
	char checkingChoice;

	do {
		clearScreen();

		cout << string(SCREEN_WIDTH, '=') << endl;
		cout << left;
		cout << setw(39) << "=" << setw(60) << "Bank Management System" << "=" << endl;
		cout << setw(42) << "=" << setw(57) << "Checking Account" << "=" << endl;
		cout << setw(SCREEN_WIDTH - 1) << "=" << "=" << endl;
		cout << setw(6) << "=" << setw(93) << "1. Basic Checking" << "=" << endl;
		cout << setw(6) << "=" << "2. High Interest Checking (***% interest, no mon charge, *** min balance)" << string(20, ' ') << "=" << endl;
		cout << setw(6) << "=" << "3. Service Charge Checking (no interest, *** mon charge, limit checks, no min balance)" << string(7, ' ') << "=" << endl;
		cout << setw(6) << "=" << "4. No service Charge Checking (***% interest, no mon charge, unlim checks, *** min balance" << string(3, ' ') << "=" << endl;
		cout << setw(6) << "=" << setw(93) << "5. Return to Main Menu" << "=" << endl;
		cout << setw(SCREEN_WIDTH - 1) << "=" << "=" << endl;
		cout << right;
		cout << "=" << string(SCREEN_WIDTH, '=') << endl << endl;

		cout << "Enter your choice: ";
		cin >> checkingChoice;
		cin.ignore(10000, '\n');

		switch (checkingChoice) {
			case '1':
				cout << "Basic Checking will be here";
				break;
			case '2':
				cout << "High Interest Checking will be here";
				break;
			case '3':
				cout << "Service Charge Chekcing will be here";
				break;
			case '4':
				cout << "No Service Charge Checking will be here";
				break;
			case '5':
				cout << "Returning to main menu." << endl;
				break;
			default:
				clearScreen();
				cout << "*** " << checkingChoice << " is an Invalid Response ***" << endl;
				cout << "Please enter a response 1-5";
		}
	} while (checkingChoice != '5');


	return;
}
