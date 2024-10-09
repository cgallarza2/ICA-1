#include "userInterfaceFunctions.h"

void printDeposit(){

	clearScreen();
	cout << string(SCREEN_WIDTH, '*') << endl;
	cout << left;
	cout << setw(11) << "*" << setw(20) << " " << setw(68) << "Which account do you want to deposit to?" << "*" << endl;
	cout << setw(SCREEN_WIDTH - 1) << "*" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "1. High Interest Checking" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "2. Service Charge Checking" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "3. No Service Charge Checking" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "4. Basic Savings" << "*" << endl;
	cout << setw(11) << "*" << setw(88) << "5. High Interest Savings" << "*"<< endl;
	cout << setw(11) << "*" << setw(88) << "6. Certificate of Deposit" << "*" << endl;
	cout << setw(SCREEN_WIDTH - 1) << "*" << "*" << endl;
	cout << right;
	cout << string(SCREEN_WIDTH, '*') << endl << endl;
}
