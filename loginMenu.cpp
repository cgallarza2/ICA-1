#include "userInterfaceFunctions.h" //defined
#include "fileManagementFunctions.h" //login user, login employee

bool loginMenu(vector<bankAccountType *> &accountVector, int sessionID, string &username){
	char welcomeChoice;
	char password[100];
	bool loggedIn = false;
	int i = 0;
	int ch;
	clearScreen();
	do{
		cout << "\t\t\t " << yellow << "/" << flashing << green << "$$$$$$$" << reset << yellow << "   /" << flashing << green << "$$$$$$" << reset << yellow << "  /" << flashing << green <<  "$$" << reset << yellow << "   /" << flashing << green << "$$" << reset << yellow << " /" << flashing << green << "$$" << reset << reset << yellow << "   /" << flashing << green << "$$" << reset << endl;
		cout << "\t\t\t" << yellow << "|" << flashing << green << " $$" << reset << yellow <<"__" << flashing << green <<" $$ " << reset << yellow << " /" << flashing << green << "$$" << reset << yellow << "__ " << flashing << green << " $$" << reset << yellow << "|" << flashing << green << " $$$ " << reset << yellow << "|" << flashing << green << " $$" << reset << yellow << "|" << flashing << green << " $$  " << reset << yellow << "/" << flashing << green << "$$" << reset << yellow << "/" << endl;
		cout << "\t\t\t" << yellow << "|" << flashing << green << " $$  " << reset << yellow << "¥" << flashing << green << " $$" << reset << yellow << "|" << flashing << green << " $$  " << reset << yellow << "¥ " << flashing << green << "$$" << reset << yellow << "|" << flashing << green << " $$$$" << reset << yellow << "|" << flashing << green << " $$" << reset << yellow << "|" << flashing << green << " $$ " << reset << yellow << "/" << green << flashing << "$$" << reset << yellow << "/" << endl;
		cout << "\t\t\t" << yellow << "|" << flashing << green << " $$$$$$$ " << reset << yellow << "|" << flashing << green << " $$$$$$$$" << reset << yellow << "|" << flashing << green << " $$ $$ $$" << reset << yellow << "|" << flashing << green << " $$$$$" << reset << yellow << "/" << endl;
		cout << "\t\t\t" << yellow << "|" << flashing << green << " $$" << reset << yellow << "__" << flashing << green << "  $$" << reset << yellow << "|" << flashing << green << " $$" << reset << yellow << "__" << flashing << green << "  $$" << reset << yellow << "|" << flashing << green << " $$  $$$$" << reset << yellow << "|" << flashing << green << " $$  $$" << reset << endl;
		cout << "\t\t\t" << yellow << "|" << flashing << green << " $$  " << reset << yellow << "¥" << flashing << green << " $$" << reset << yellow << "|" << flashing << green << " $$  " << reset << yellow << "¥" << flashing << green << " $$" << reset << yellow << "|" << flashing << green << " $$" << reset << yellow << "¥" << flashing << green << "  $$$" << reset << yellow << "|" << flashing << green << " $$" << reset << yellow << "¥" << flashing <<  green << " $$" << reset << endl;
		cout << "\t\t\t" << yellow << "|" << flashing << green << " $$$$$$$/" << reset << yellow << "|" << flashing << green << " $$  " << reset << yellow << "|" << flashing << green <<" $$" << reset << yellow << "|" << flashing << green << " $$ " << reset << yellow << "¥" << flashing << green << "  $$" << reset << yellow << "|" << flashing << green << " $$ " << reset << yellow << "¥" << flashing << green << " $$" << reset << endl;
		cout << "\t\t\t" << yellow << "|_______/ |__/  |__/|__/  ¥__/|__/  ¥__/" << endl << endl;
		cout << reset;
		
		
		cout << yellow << string(SCREEN_WIDTH, '*') << reset << endl;
		cout << left;
		cout << setw(39) << "\033[33m*" << reset << setw(60) << "Bank Managment System" << "\t   \033[33m*" << reset << endl;
		cout << setw(42) << "\033[33m*" << reset << setw(57) << "Login Menu" << "\t   \033[33m*\033[0m" << endl;
		cout << yellow << setw(SCREEN_WIDTH - 1) << "*" << "*" << reset << endl;
		cout << setw(11) << "\033[33m*" << reset << setw(88) << "\033[32m1. Login" << "\t   \033[33m*" << reset << endl;
		//cout << setw(11) << "\033[33m*" << reset << setw(88) << "2. Create New User" << "\t   \033[33m*" << reset << endl; //only employee 
		cout << setw(11) << "\033[33m*" << reset << setw(88) << "\033[31m2. Log out" << "\t   \033[33m*" << reset << endl;
		cout << yellow << setw(SCREEN_WIDTH - 1) << "*" << "*" << reset << endl;
		cout << right;
		cout << yellow << string(SCREEN_WIDTH, '*') << reset << endl << endl;

		cout << "Enter your choice: ";
		cin >> welcomeChoice;
		cin.ignore(1000, '\n');

		switch(welcomeChoice) {
		case '1'://needs hashing
			while (!loggedIn) {
			cout << "Enter username: ";
			getline(cin, username);
			cout << "Enter password: ";
				while ((ch = getch()) != '\n') {
					if (ch == 127 || ch == 8) {  // handle password clearing
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

				if (attemptLogIn(username, password)) { //user login
					loggedIn = true;
					string txtFile = username + ".txt";
					accountVector = populateAccounts(accountVector, txtFile);
					updateUserAccounts(accountVector, txtFile, sessionID);
					return false;
				}
				else {
					username += "_employee";
					if (attemptEmployeeLogIn(username, password)) {//employee login
						loggedIn = true;
						string txtFile = username + ".txt";
						//could make employee have different stuff in account here
						accountVector = populateAccounts(accountVector, txtFile);
						updateUserAccounts(accountVector, txtFile, sessionID);
						return false;
					} else {
						i = 0;
						cout << red << "\nInvalid username or password. Try again.\n" << reset;
					}
				}
			}
        break;
		//only employee can create account NEED to move to employee options
		/* case '2':
			accountVector = createNewUser(accountVector, sessionID, username);
			return false; */
		case '2':
			cout << red << "Logging out..." << reset << endl;
			return true;
		default:
			clearScreen();
			cout << red << "Please enter valid input" << reset << endl;
			break;
		}

	} while(welcomeChoice != '2');
	return false;

}
