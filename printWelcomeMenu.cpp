#include "userInterfaceFunctions.h" //constructor
#include "fileManagementFunctions.h" //login
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
	
	//colors
	const string green = "\033[32m";
    const string yellow = "\033[33m";
    const string reset = "\033[0m";
    const string flashing = "\033[5m";

	do{
		clearScreen();
		cout << flashing; //not working
		cout << "\t\t\t " << yellow << "/" << green << "$$$$$$$" << yellow << "   /" << green << "$$$$$$" << yellow << "  /" << green << "$$" << yellow << "   /" << green << "$$" << yellow << " /" << green << "$$" << yellow << "   /" << green << "$$" << endl;
		cout << "\t\t\t" << yellow << "|" << green << " $$" << yellow <<"__" << green <<" $$ " << yellow << " /" << green << "$$" << yellow << "__ " << green << " $$" << yellow << "|" << green << " $$$ " << yellow << "|" << green << " $$" << yellow << "|" << green << " $$  " << yellow << "/" << green << "$$" << yellow << "/" << endl;
		cout << "\t\t\t" << yellow << "|" << green << " $$  " << yellow << "\\" << green << " $$" << yellow << "|" << green << " $$  " << yellow << "\\ " << green << "$$" << yellow << "|" << green << " $$$$" << yellow << "|" << green << " $$" << yellow << "|" << green << " $$ " << yellow << "/" << green << "$$" << yellow << "/" << endl;
		cout << "\t\t\t" << yellow << "|" << green << " $$$$$$$ " << yellow << "|" << green << " $$$$$$$$" << yellow << "|" << green << " $$ $$ $$" << yellow << "|" << green << " $$$$$" << yellow << "/" << endl;
		cout << "\t\t\t" << yellow << "|" << green << " $$" << yellow << "__" << green << "  $$" << yellow << "|" << green << " $$" << yellow << "__" << green << "  $$" << yellow << "|" << green << " $$  $$$$" << yellow << "|" << green << " $$  $$" << endl;
		cout << "\t\t\t" << yellow << "|" << green << " $$  " << yellow << "\\" << green << " $$" << yellow << "|" << green << " $$  " << yellow << "|" << green << " $$" << yellow << "|" << green << " $$" << yellow << "\\" << green << "  $$$" << yellow << "|" << green << " $$" << yellow << "\\" << green << " $$" << endl;
		cout << "\t\t\t" << yellow << "|" << green << " $$$$$$$/" << yellow << "|" << green << " $$  " << yellow << "|" << green <<" $$" << yellow << "|" << green << " $$ " << yellow << "\\" << green << "  $$" << yellow << "|" << green << " $$ " << yellow << "\\" << green << " $$" << endl;
		cout << "\t\t\t" << yellow << "|_______/ |__/  |__/|__/  \\__/|__/  __/" << endl << endl;
		cout << reset;
		
		cout << yellow << string(SCREEN_WIDTH, '*') << reset << endl;
		cout << left;
		cout << setw(39) << "\033[33m*" << reset << setw(60) << "Bank Managment System" << "\t   \033[33m*" << reset << endl;
		cout << setw(42) << "\033[33m*" << reset << setw(57) << "Login Menu" << "\t   \033[33m*\033[0m" << endl;
		cout << yellow << setw(SCREEN_WIDTH - 1) << "*" << "*" << reset << endl;
		cout << setw(11) << "\033[33m*" << reset << setw(88) << "1. Login" << "\t   \033[33m*" << reset << endl;
		cout << setw(11) << "\033[33m*" << reset << setw(88) << "2. Create New User" << "\t   \033[33m*" << reset << endl;
		cout << yellow << setw(SCREEN_WIDTH - 1) << "*" << "*" << reset << endl;
		cout << right;
		cout << yellow << string(SCREEN_WIDTH, '*') << reset << endl << endl;

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
				else {
					i = 0;
				}
			}
			break;
		case '2':
			accountVector = printCreateNewUser(accountVector, sessionID, username);
			return;
		default:
			clearScreen();
			cout << "Please enter valid input" << endl;
			break;
		}

	} while(welcomeChoice != '2');
	return;

}
