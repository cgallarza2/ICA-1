#include "userInterfaceFunctions.h" //constructor
#include "fileManagementFunctions.h" //login function
#include <iostream>
#include <iomanip>
#include <string>

void printWelcomeMenu (vector<bankAccountType *> accountVector){
	char welcomeChoice;
	string username;
	string password;
	bool loggedIn = false;

	do{
		clearScreen();

		cout << string(SCREEN_WIDTH, '*') << endl;
		cout << left;
		cout << setw(39) << "*" << setw(60) << "Bank Managment System" << "*" << endl;
		cout << setw(42) << "*" << setw(57) << "Login Menu" << "*" << endl;
		cout << setw(SCREEN_WIDTH - 1) << "*" << "*" << endl;
		cout << setw(11) << "*" << setw(88) << "1. Login" << "*" << endl;
		cout << setw(11) << "*" << setw(88) << "2. Create New User" << "*" << endl;
		cout << setw(SCREEN_WIDTH - 1) << "*" << "*" << endl;
		cout << right;
		cout << string(SCREEN_WIDTH, '*') << endl << endl;

		cout << "Enter your choice: ";
		cin >> welcomeChoice;
		cin.ignore(1000, '\n');

		switch(welcomeChoice) {
		case '1':
			clearScreen();

			while (!loggedIn) {
				cout << "Enter username:";
				cin >> username;
				cout << "Enter password:";
				cin >> password;

				if (attemptLogIn(username, password)) {
					loggedIn = true;
					return;
				}
			}
			break;
		case '2':
			printCreateNewUser(accountVector);
			return;
		default:
			clearScreen();
			cout << "Please enter valid input" << endl;
			break;
		}

	} while(welcomeChoice != '2');
	return;

}
