#include "userInterfaceFunctions.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


void printSavingsAccount() {
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

	return;
}
