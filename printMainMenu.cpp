#include "userInterfaceFunctions.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


void printMainMenu(){
	clearScreen();
	cout << string(SCREEN_WIDTH, '*') << endl;
	cout << left;
	cout << setw(31) << "*" << setw(68) << "Welcome to the Bank Management System!" << "*" << endl;
	cout << setw(45) << "*" << setw(54) << "Main Menu" << "*" << endl;
	cout << setw(SCREEN_WIDTH - 1) << "*" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "1. Access existing Checking Account" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "2. Access exisitng Savings Account" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "3. Access exisitng Certificate of Deposit" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "4. Exit" << "*" << endl;
	cout << setw(SCREEN_WIDTH - 1) << "*" << "*" << endl;
	cout << right;
	cout << string(SCREEN_WIDTH, '*') << endl << endl;
	cout << "Enter your choice: ";

	return;
}
