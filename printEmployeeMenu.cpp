#include "userInterfaceFunctions.h"

void printEmployeeMenu(){
	clearScreen();
	cout << red << "EMPLOYEE" << reset << endl;
	cout << yellow << string(SCREEN_WIDTH, '*') << reset << endl;
	cout << left;
	cout << setw(31) << "\033[33m*" << reset << setw(68) << "Bank Management System" << "\t   \033[33m*" << reset << endl;
	cout << setw(39) << "\033[33m*" << reset << setw(60) << "Employee Menu" << "\t   \033[33m*" << reset << endl;
    cout << setw(39) << "\033[33m*" << reset << setw(60) << "1. Create Account" << "\t   \033[33m*" << reset << endl;
    cout << setw(39) << "\033[33m*" << reset << setw(60) << "2. Manage User Accounts" << "\t   \033[33m*" << reset << endl;
    //cout << setw(39) << "\033[33m*" << reset << setw(60)<< "3. View Logs" << "\t   \033[33m*" << reset << endl;
    cout << setw(39) << "\033[33m*" << reset << setw(60)<< "3. \033[31mLog out" << "\t   \033[33m*" << reset << endl;
	cout << right;
	cout << yellow << string(SCREEN_WIDTH, '*') << reset << endl;
    cout << "Enter your choice: ";
	return;
}