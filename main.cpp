#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <limits>
#include <stdexcept>
 
#include "bankAccountType.h"
#include "savingsAccountType.h"
#include "highInterestSavingsType.h"
#include "noServiceChargeCheckingType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "certificateOfDepositType.h"
#include "checkingAccountType.h"
#include "userInterfaceFunctions.h"
#include "fileManagementFunctions.h"

using namespace std;
  
extern const int SCREEN_WIDTH = 100;
extern const double SAVINGS_INT_RATE = 0.03;
extern const double HIGHINTSAVE_MIN_BAL = 2500.00;
extern const double HIGHINTSAVE_INT_RATE = 0.05;
extern const double COD_INT_RATE = 0.05;
extern const int NUM_MATURITY_MON = 6;
extern const double ACCT_SERV_CHARGE = 10.00;
extern const int MAX_NUM_CHECKS = 5;
extern const double SERV_CHARGE_EXCESS_NUM_CHECKS = 5;
extern const double NOSERV_CHRG_CHK_MIN_BAL = 1000.00;
extern const double NOSERV_CHRG_CHK_INT_RATE = 0.02;
extern const double HIGHINTCHK_RATE = 0.05;
extern const double HIGHINTCHK_MIN_BAL = 5000.00;

int main()
{

	int sessionID = generateSessionID();
	string username;
	char mainChoice;
	vector<bankAccountType *> accountVector;
	bool isEmployee = false;

	try {
		do {
			loginMenu(accountVector, sessionID, username);
			if (username.find("_employee") != string::npos) {
				isEmployee = true;
			}
			if (isEmployee) {
				printEmployeeMenu();
			} else {
				printUserMenu();
			}
			cin >> mainChoice;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw invalid_argument("Invalid selection. Please enter a valid number.");
			}

			switch(mainChoice) {
				case '1': //could make into account settings
					if (isEmployee) {
						//for now go to employee options
						printEmployeeOptions(accountVector, sessionID, username);
					} else {
						//for now go to user options
						printUserOptions(accountVector, sessionID, username);
					}
					break;
				case '2': //could make into account logs
					if (isEmployee) {
						//for now go to employee options
						printEmployeeOptions(accountVector, sessionID, username);
					} else {
						//for now go to user options 
						printUserOptions(accountVector, sessionID, username);
					}
					break;
				case '3'://options
					if (isEmployee) {
						//for now display employee stuff 
						printEmployeeOptions(accountVector, sessionID, username);
					} else {
						printUserOptions(accountVector, sessionID, username);
					}
					break;
				case '4': //log out
					cout << "\nExiting... " << endl;
					break;
				default:
					clearScreen();
					cout << "Invalid choice. Returning to main menu.\n";
					break;
			}
		} while (mainChoice != '4');
} catch (const invalid_argument &e) {
    cout << "Error: " << e.what() << "\nReturning to the main menu...\n";
}


	//string username, password;
	//accountsList = populateAccounts(accountsList, username + ".txt");
    //accountsList.push_back(new savingsAccountType("Bill", 10200, 2500, "password", "username"));
    //accountsList.push_back(new highInterestSavingsType("Susan", 10210, 2000, "password", "username"));
    //accountsList.push_back(new noServiceChargeCheckingType("John", 20100, 
                                                    //3500, "password", "username"));
    //accountsList.push_back(new serviceChargeCheckingType("Ravi", 30100, 1800, "password", "username"));
    //accountsList.push_back(new highInterestCheckingType("Sheila", 20200, 
                                                 //6000, "password", "username"));
    //accountsList.push_back(new certificateOfDepositType("Hamid", 51001, 18000, "password", "username",
                                                //0.075, 18));

    return 0;
}
