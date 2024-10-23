#include "userInterfaceFunctions.h" //defined
#include "fileManagementFunctions.h" //print / deposit / withdraw

vector<bankAccountType *> printUserOptions(vector<bankAccountType *> &accountVector, int sessionID, string username) {
	char functionChoice;
	bool firstTimeInScreen = true;

	do {
		if (firstTimeInScreen) {
			clearScreen();
			firstTimeInScreen = false;
		}

		for (const auto account : accountVector) {
			cout <<  red << "USER" << green << " logged in: " << account->getName() << reset << endl;
			break;
		}
		cout << yellow << string(SCREEN_WIDTH, '*') << reset << endl;
		cout << left;
		cout << setw(39) << "\033[33m*" << reset << setw(60) << "Bank Management System" << "\t   \033[33m*" << reset << endl;
		cout << setw(42) << "\033[33m*" << reset << setw(57) << "Account Options" << "\t   \033[33m*" << reset << endl;
		cout << setw(SCREEN_WIDTH - 1) << "*" << "*" << endl;
		cout << setw(21) << "\033[33m*" << reset << setw(78) << "1. Print Account Info" << "\t   \033[33m*" << reset << endl;
		cout << setw(21) << "\033[33m*" << reset << setw(78) << "2. Deposit Money" << "\t   \033[33m*" << reset << endl;
		cout << setw(21) << "\033[33m*" << reset << setw(78) << "3. Withdraw Money" << "\t   \033[33m*" << reset << endl;
		cout << setw(21) << "\033[33m*" << reset << setw(78) << "4. Create Monthly Statement" << "\t   \033[33m*" << reset << endl;
		cout << setw(21) << "\033[33m*" << reset << setw(78) << "5. Return to login" << "\t   \033[33m*" << reset << endl;
		cout << yellow << setw(SCREEN_WIDTH - 1) << "*" << "*" << reset << endl;
		cout << right;
		cout << yellow << string(SCREEN_WIDTH, '*') << reset << endl << endl;

		cout << "Enter your choice: ";
		cin >> functionChoice;

		string txtFile = username + ".txt";
		int accountType;
		double amount;

		switch (functionChoice) {
			case '1': //print user data
				printAccountInfo(accountVector);
				break;
			case '2': //deposit
				printDeposit();
				cout << "Enter account type (1-6): ";
				cin >> accountType;
				cout << "Enter deposit amount: " ;
				cin >> amount;

				if (checkID(sessionID, username)) {
					depositToAccount(accountVector, accountType, amount);
					updateUserAccounts(accountVector, txtFile, sessionID);
				}
				else {
					cout << red << "Sorry! It appears a more recent session has been detected. Please login again!" << reset << endl;
					cin.ignore();
				}

				break;
			case '3': //withdraw
				printWithdraw();
				cout << "Enter account type (1-6): ";
				cin >> accountType;
				cout << "Enter withdraw amount: ";
				cin >> amount;

				if (checkID(sessionID, username)) {
					withdrawToAccount(accountVector, accountType, amount);
					updateUserAccounts(accountVector, txtFile, sessionID);
				}
				else {
					cout << red << "Sorry! It appears a more recent session has been detected. Please login again!" << reset << endl;
					cin.ignore();
				}
				break;
			case '4': //create monthly statement
				createStatement(accountVector);
				break;
			case '5':
				cout << red << "Returning to login..." << reset;
				updateUserAccounts(accountVector, txtFile, sessionID);
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
