#include "userInterfaceFunctions.h" //defined
#include "fileManagementFunctions.h" //employee account options functions

vector<bankAccountType *> printEmployeeOptions(vector<bankAccountType *> &accountVector, int sessionID, string username){
	char functionChoice;
	bool firstTimeInScreen = true;

	do {
		if (firstTimeInScreen) {
			clearScreen();
			firstTimeInScreen = false;
		}

		for (const auto account : accountVector) {
			cout << red << "EMPLOYEE" << green << "\t\t\t\t\t\t\t\t logged in: " << account->getName() << reset << endl;
			break;
		}
		cout << yellow << string(SCREEN_WIDTH, '*') << reset << endl;
		cout << left;
		cout << setw(39) << "\033[33m*" << reset << setw(60) << "Bank Management System" << "\t   \033[33m*" << reset << endl;
		cout << setw(42) << "\033[33m*" << reset << setw(57) << "Employee Options" << "\t   \033[33m*" << reset << endl;
		cout << yellow << setw(SCREEN_WIDTH - 1) << "*" << "*" << reset << endl;
		cout << setw(21) << "\033[33m*" << reset << setw(78) << "1. Print User Account Info" << "\t   \033[33m*" << reset << endl;
		cout << setw(21) << "\033[33m*" << reset << setw(78) << "2. Deposit Money to user" << "\t   \033[33m*" << reset << endl;
		cout << setw(21) << "\033[33m*" << reset << setw(78) << "3. Withdraw Money to user" << "\t   \033[33m*" << reset << endl;
		cout << setw(21) << "\033[33m*" << reset << setw(78) << "4. Return to login" << "\t   \033[33m*" << reset << endl;
		cout << yellow << setw(SCREEN_WIDTH - 1) << "*" << "*" << reset << endl;
		cout << right;
		cout << yellow << string(SCREEN_WIDTH, '*') << reset << endl << endl;

		cout << "Enter your choice: ";
		cin >> functionChoice;

		int accountType;
		double amount;
		
		vector<bankAccountType *> userVector;
		string usern, userFile;
		char passw[10];
		
		switch (functionChoice) {
			case '1': //print user data	
				cout << "Enter username: ";
				cin >> usern;
				cin.ignore(1000, '\n');
				cout << "Enter password: ";
				cin >> passw;
				userFile = usern + ".txt";
				if (attemptLogIn(usern, passw)) { //user login
				userVector = populateAccounts(userVector, userFile);				
				printAccountInfo(userVector);
				userVector.clear();
				}
				break;
			case '2': //deposit
				printDeposit();
				cout << "Enter account type (1-6): ";
				cin >> accountType;
				cout << "Enter deposit amount: " ;
				cin >> amount;
				populateAccounts(userVector, userFile);
				depositToAccount(userVector, accountType, amount);
				updateUserAccounts(userVector, userFile, sessionID);
				break;
			case '3': //withdraw
				printWithdraw();
				cout << "Enter account type (1-6): ";
				cin >> accountType;
				cout << "Enter withdraw amount: ";
				cin >> amount;
				populateAccounts(userVector, userFile);
				withdrawToAccount(accountVector, accountType, amount);
				updateUserAccounts(accountVector, userFile, sessionID);
				break; 
			case '4': //return to login
				cout << "Returning to login...";
				accountVector.clear();
				return accountVector;
				break;
			default:
				clearScreen();
				cout << red << "*** " << functionChoice << " is an Invalid Response***" << endl;
				cout << "Please enter a response (1-5)" << reset << endl;
				break;
		}
	} while(functionChoice != '5');

	return accountVector;
}