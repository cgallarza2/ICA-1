#include "userInterfaceFunctions.h"

void printDeposit(){

	clearScreen();
	cout << yellow << string(SCREEN_WIDTH, '*') << reset << endl;
	cout << left;
	cout << setw(11) << "\033[33m*" << reset << setw(20) << " " << setw(68) << "Which account do you want to deposit to?" << "\t   \033[33m*" << reset << endl;
	cout << setw(SCREEN_WIDTH - 1) << "*" << "*" << endl;
	cout << setw(11) << "\033[33m*" << reset << setw(88) << "1. High Interest Checking" << "\t   \033[33m*" << reset << endl;
	cout << setw(11) << "\033[33m*" << reset << setw(88) << "2. Service Charge Checking" << "\t   \033[33m*" << reset << endl;
	cout << setw(11) << "\033[33m*" << reset << setw(88) << "3. No Service Charge Checking" << "\t   \033[33m*" << reset << endl;
	cout << setw(11) << "\033[33m*" << reset << setw(88) << "4. Basic Savings" << "\t   \033[33m*" << reset << endl;
	cout << setw(11) << "\033[33m*" << reset << setw(88) << "5. High Interest Savings" << "\t   \033[33m*" << reset << endl;
	cout << setw(11) << "\033[33m*" << reset << setw(88) << "6. Certificate of Deposit" << "\t   \033[33m*" << reset << endl;
	cout << yellow << setw(SCREEN_WIDTH - 1) << "*" << "*" << reset << endl;
	cout << right;
	cout << yellow << string(SCREEN_WIDTH, '*') << reset << endl << endl;
}
