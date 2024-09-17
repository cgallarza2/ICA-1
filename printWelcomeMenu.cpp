#include "userInterfaceFunctions.h" //constructor
#include "fileManagementFunctions.h" //login function
#include <iostream>
#include <iomanip>
#include <string>

void printWelcomeMenu (){
	char welcomeChoice;
	string username;
	string password;
	bool loggedIn = false;

	do{
		clearScreen();

		cout << string(SCREEN_WIDTH, '*') << endl;
		cout << left;
		cout << setw(39) << setw(60) << "Bank Managment System" << "*" << endl;
		cout << setw(42) << "*" << setw(57) << "Welcome Menu" << "*" << endl;
		cout << setw(SCREEN_WIDTH - 1) << "*" << "*" << endl;
		cout << setw(6) << "1. Login" << endl;
		cout << setw(6) << "2. Create New User" << endl;
		cout << setw(SCREEN_WIDTH - 1) << "*" << "*" << endl;
		cout << right;
		cout << "*" << string(SCREEN_WIDTH, '*') << endl << endl;

		cout << "Enter your choice: ";
		cin >> welcomeChoice;
		cin.ignore(1000, '\n');

		switch(welcomeChoice) {
		case '1':
			cout << "Login here";
			clearScreen();

			while (!loggedIn) {
				cout << "Enter username:" << endl;
				cin >> username;
				cout << "Enter password:" << endl;
				cin >> password;

				if (attemptLogIn(username, password)) {
					loggedIn = true;
				}else {
					cout << "No user account" << endl;
				}
			}
			break;
		case '2':
			cout << "Create new user here";
			//should go to main menu that we have already
			break;
		default:
			clearScreen();
			cout << "Please enter valid input" << endl;
		}

	} while(welcomeChoice != '2');
	return;

}
