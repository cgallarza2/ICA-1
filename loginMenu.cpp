#include "userInterfaceFunctions.h" //defined
#include "fileManagementFunctions.h" //login user, login employee

void loginMenu(vector<bankAccountType *> &accountVector, int sessionID, string &username){
	char welcomeChoice;
	char password[100];
	bool loggedIn = false;
	int i = 0;
	int ch;
	clearScreen();
	do{
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
			char choice;			//specify account login
			cout << "\nPress 1. User\t  Press 2. Employee" << reset << endl;
			cout << "Login as: ";
			cin >> choice;
			cin.ignore();
			
		if (choice == '1'){ //login as user	
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

				if (attemptLogIn(username, password)) { //populate user account vector
					loggedIn = true;
					string txtFile  = username + ".txt";
					accountVector = populateAccounts(accountVector, txtFile);
					updateUserAccounts(accountVector, txtFile, sessionID);
					return;
				}
				else {
					i = 0;
				}
			}
		}else if (choice == '2') { // employee log-in
            while (!loggedIn) {
                cout << "Enter employee username: ";
                getline(cin, username);
				username += "_employee"; 
                cout << "Enter employee password: ";
                while ((ch = getch()) != '\n') {
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

                if (attemptEmployeeLogIn(username, password)) { // populate employee account vector
                    loggedIn = true;
                    string txtFile = username + ".txt";
                    accountVector = populateAccounts(accountVector, txtFile);
                    updateUserAccounts(accountVector, txtFile, sessionID);
                    return;
                } else {
                    i = 0;
                }
            }
        } else {
            clearScreen();
            cout << red << "Please select user(1) or employee(2)" << reset << endl;
		}
        break;
		case '2':
			accountVector = createNewUser(accountVector, sessionID, username);
			return;
		default:
			clearScreen();
			cout << red << "Please enter valid input" << reset << endl;
			break;
		}

	} while(welcomeChoice != '3');
	return;

}
