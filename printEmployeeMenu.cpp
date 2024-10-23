#include "userInterfaceFunctions.h"

void printEmployeeMenu(){
	clearScreen();
	cout << red << "EMPLOYEE" << reset << endl;
	cout << yellow << string(SCREEN_WIDTH, '*') << reset << endl;
	cout << left;
	cout << setw(39) << "\033[33m*" << reset << setw(60) << "Employee Menu" << "\t   \033[33m*" << reset << endl;
    cout << setw(39) << "\033[33m*" << reset << setw(60) << "1. Manage User Accounts" << "\t   \033[33m*" << reset << endl;
    cout << setw(39) << "\033[33m*" << reset << setw(60) << "2. View Reports" << "\t   \033[33m*" << reset << endl;
    cout << setw(39) << "\033[33m*" << reset << setw(60)<< "3. Employee Options" << "\t   \033[33m*" << reset << endl;
    cout << setw(39) << "\033[33m*" << reset << setw(60)<< "4. Log out" << "\t   \033[33m*" << reset << endl;
	cout << right;
	cout << yellow << string(SCREEN_WIDTH, '*') << reset << endl;
    cout << "Enter your choice: ";
	return;
}