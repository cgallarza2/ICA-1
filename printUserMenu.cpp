#include "userInterfaceFunctions.h"

void printUserMenu(){
	clearScreen();
	cout << red << "USER" << reset << endl;
	cout << yellow << string(SCREEN_WIDTH, '*') << reset << endl;
	cout << left;
	cout << setw(31) << "\033[33m*" << reset << setw(68) << "Welcome to the Bank Management System!" << "\t   \033[33m*" << reset << endl;
	cout << setw(45) << "\033[33m*" << reset << setw(54) << "User Menu" << "\t   \033[33m*" << reset << endl;
	cout << yellow << setw(SCREEN_WIDTH - 1) << "*" << "*" << reset << endl;
	cout << setw(11) << "\033[33m*" << reset << setw(88) << "1. Access settings" << "\t   \033[33m*" << reset << endl;
	cout << setw(11) << "\033[33m*" << reset << setw(88) << "2. Access account" << "\t   \033[33m*" << reset << endl;
	cout << setw(11) << "\033[33m*" << reset << setw(88) << "3. Access account options" << "\t   \033[33m*" << reset << endl;
	cout << setw(11) << "\033[33m*" << reset << setw(88) << "4. Log out" << "\t   \033[33m*" << reset << endl;
	cout << yellow << setw(SCREEN_WIDTH - 1) << "*" << "*"  << reset << endl;
	cout << right;
	cout << yellow << string(SCREEN_WIDTH, '*') << reset << endl << endl;
	cout << "Enter your choice: ";

	return;
}
