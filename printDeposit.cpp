#include "userInterfaceFunctions.h"
#include <iostream>
#include <iomanip>
//#include <string>


void printDeposit(){

	clearScreen();
	cout << string(SCREEN_WIDTH, '*') << endl;
	cout << left;
	cout << setw(21) << "*" << setw(88) << "Which account do you want to deposit to?" << "*" << endl;
	cout << setw(SCREEN_WIDTH - 1) << "*" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "1. Checking" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "2. High Interest Checking" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "3. Service Charge Checking" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "4. No Service Charge Checking" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "5. Basic Savings" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "6. High Interest Savings" << "*"<< endl;
	cout << setw(11) << "*" << setw(88) << "7. Certificate of Deposit" << "*" << endl;
	cout << setw(SCREEN_WIDTH - 1) << "*" << "*" << endl;
	cout << right;
	cout << string(SCREEN_WIDTH, '*') << endl << endl;
}
