#include "userInterfaceFunctions.h" //defined
#include "fileManagementFunctions.h" //add account, add employee account

vector<bankAccountType *> createNewUser(vector<bankAccountType *> accountVector, int sessionID, string &username)
{
	string name;
	char password[100];
	int acctNumber;
	double balance = 0; //start with 0 balance
	int i = 0;
	int ch;
	char userType;

	clearScreen();

	cout << yellow << string(SCREEN_WIDTH, '*') << endl;
	cout << left;
	cout << setw(11) << "\033[33m*" << reset << setw(20) << " "  << setw(68) << "Welcome to Bank Account Creation!" << "\t   \033[33m*" << reset << endl;
	cout << setw(11) << "\033[33m*" << reset << setw(20) << " "  << setw(68) << "Create user as: 1. User or 2. Employee" << "\t   \033[33m*" << reset << endl;
	cout << yellow << string(SCREEN_WIDTH, '*') << reset << endl << endl;
	cout << "create user as: ";
	cin >> userType;
	cin.ignore();
	
	if (userType == '1') { //user
		cout << "Create a username: ";
		getline(cin, username);
		cout << "Create a password: ";	//add hashing later
		while ((ch = getch()) != '\n') {		// clearing typing
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
		cout << "\nEnter your given name: ";
		cin >> name;
		addAccount(username, password);
		acctNumber = generateAccountNumber();
		string filename = username + ".txt";
		ofstream accountFile(filename, ios::app);
		if (accountFile.is_open()){
			for (int i = 1; i < 7; i++) { //create all types of account
				accountVector = createAccount(accountVector, filename, i, name, acctNumber, balance, 0.05, 0, sessionID); //to accountvector
			}
		}
	} else if (userType == '2') {//employee
		cout << "Create a username: ";
		getline(cin, username);
		username += "_employee";
		cout << "Create a password: ";	//add hashing later (save hashed password to database)
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
		cout << "\nEnter your given name: ";
		cin >> name;
		addEmployeeAccount(username, password);
		acctNumber = generateAccountNumber();
		string filename = username + ".txt"; 
		ofstream accountFile(filename, ios::app);
		if (accountFile.is_open()){
			for (int i = 1; i < 7; i++) { //create all types of account
				accountVector = createAccount(accountVector, filename, i, name, acctNumber, balance=314159, 0.05, 0, sessionID); //to accountvector
			}
		}
	}
return accountVector;
}

//int accountType;
//clearScreen();
	//cout << string(SCREEN_WIDTH, '*') << endl;
	//cout << left;
	//cout << setw(11) << "*" << setw(88) << "The various bank account types we have to offer!" << "*" << endl;
	//cout << string(SCREEN_WIDTH, '*') << endl;
	//cout << setw(11) << "*" << setw(88) << "1. High Interest Checking" << "*" << endl;
	//cout << setw(11) << "*" << setw(88) << "2. Service Charge Checking" << "*" << endl;
	//cout << setw(11) << "*" << setw(88) << "3. No Service Charge Checking" << "*" << endl;
	//cout << setw(11) << "*" << setw(88) << "4. Basic Savings" << "*" << endl;
	//cout << setw(11) << "*" << setw(88) << "5. High Interest Savings" << "*" << endl;
	//cout << setw(11) << "*" << setw(88) << "6. Certificate of Deposit" << "*" << endl;
	//cout << setw(SCREEN_WIDTH - 1) << "*" << "*" << endl;
	//cout << right;
	//cout << string(SCREEN_WIDTH, '*') << endl << endl;

	//cout << "Please enter the bank account type (1-6): ";
	//cin >> accountType;