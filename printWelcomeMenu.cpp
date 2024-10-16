#include "userInterfaceFunctions.h" //constructor
#include "fileManagementFunctions.h" //login function
#include <iostream>
#include <iomanip>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

void printWelcomeMenu (vector<bankAccountType *> &accountVector, int sessionID, string &username){
	char welcomeChoice;
	char password[100];
	bool loggedIn = false;
	int i = 0;
	int ch;

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
		case '1'://needs hashing
			clearScreen();

			while (!loggedIn) {
				cout << "Enter username: ";
				getline(cin, username);
				cout << "Enter password: ";
				while ((ch = getch()) != '\n') {		// clearing screen
					if (ch == 127 || ch == 8) {
						if (i != 0) {
							i--;
							cout << "\b \b";
						}
					} else {
						password[i++] = ch;
						cout << "*";
					}
				}
				password[i] = '\0';

				if (attemptLogIn(username, password)) {
					loggedIn = true;
					//populate account vector
					string txtFile  = username + ".txt";
					accountVector = populateAccounts(accountVector, txtFile);
					updateUserAccounts(accountVector, txtFile, sessionID);
					return;
				}
			}
			break;
		case '2':
			accountVector = printCreateNewUser(accountVector, sessionID);
			return;
		default:
			clearScreen();
			cout << "Please enter valid input" << endl;
			break;
		}

	} while(welcomeChoice != '2');
	return;

}
