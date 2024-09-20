#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "userInterfaceFunctions.h"
#include "bankAccountType.h"
#include "savingsAccountType.h"
#include "highInterestSavingsType.h"
#include "noServiceChargeCheckingType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "certificateOfDepositType.h"
#include "checkingAccountType.h"
#include "fileManagementFunctions.h"


using namespace std;

void printCreateNewUser()
{
	string name, username, password;
	int acctNumber, accountType;
	double balance;

	clearScreen();

	cout << "Welcome to Bank Account Creation!" << endl << endl;
	cout << "Please create a username you would like to use: ";
	getline(cin, username);
	cout << "Please create a safe password: "; //add hashing later
	getline(cin, password);

	addAccount(username, password); //to userList

	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter the account number: ";
	cin >> acctNumber;
	cout << "Enter the account balance: ";
	//cout << balance;
	cin >> balance;

	clearScreen();
	cout << "The various bank account types we have to offer!" << endl;
	cout << "1. Basic Checking" << endl;
	cout << "2. High Interest Checking (" << HIGHINTCHK_RATE << " interest rate, No monthly charge, " << HIGHINTCHK_MIN_BAL << " minimum balance)" << endl;
	cout << "3. Service Charge Checking (No interest rate, " << ACCT_SERV_CHARGE << " monthly charge, Max of " << MAX_NUM_CHECKS << " checks, No minimum balance)" << endl;
	cout << "4. No Service Charge Checking (" << NOSERV_CHRG_CHK_INT_RATE << " interest rate, No monthly charge, unlimited checks, " << NOSERV_CHRG_CHK_MIN_BAL << " minimum balance)" << endl;
	cout << "5. Basic Savings (" << SAVINGS_INT_RATE << " interest rate)" << endl;
	cout << "6. High Interest Savings (" << HIGHINTSAVE_INT_RATE << " interest rate, " << HIGHINTSAVE_MIN_BAL << " minimum balance)" << endl;
	cout << "7. Certificate of Deposit (" << COD_INT_RATE << " interest rate, )" << NUM_MATURITY_MON << " maturity months)" << endl;

	cout << "Please enter the number associated to the bank account you want to create (1-7).";
	cin >> accountType;

	//vector<bankAcocuntType *> accountsList;
	//accountsList = populateAccounts(accountList, username + ".txt");
	
	string filename = username + "_account.txt"; //username_account.txt
	ofstream accountFile(filename, ios::app);
	if (accountFile.is_open()){
		accountFile << accountType << endl; //first
		accountFile << name << endl;
		accountFile << acctNumber << endl;
		accountFile << balance << endl;
		accountFile << password << endl;
		accountFile << username << endl; //last
		accountFile.close();
		cout << "Account Created" << endl;
	}else{
		cout << "Unable to make account" << endl;
	}

	//switch (accountType) {
	//	case 1:
		//	accountsList.push_back(new bankAccountType(name, acctNumber, balance, password, username));
	//		break;
	//	case 2:
		//	accountsList.push_back(new highInterestCheckingType(name, acctNumber, balance, password, username));
	//		break;
	//	case 3:
		//	accountsList.push_back(new serviceChargeCheckingType(name, acctNumber, balance, password, username));
	//		break;
	//	case 4:
		//	accountsList.push_back(new noServiceChargeCheckingType(name, acctNumber, balance, password, username));
	//		break;
	//	case 5:
		//	accountsList.push_back(new savingsAccountType(name, acctNumber, balance, password, username));
	//		break;
	//	case 6:
		//	accountsList.push_back(new highInterestSavingsType(name, acctNumber, balance, password, username));
	//		break;
	//	case 7:
		//	accountsList.push_back(new certificateOfDepositType(name, acctNumber, balance, password, username));
	//		break;
	//	default:
	//		cout << "*** " << accountType << " is an invalid selection***" << endl;
	//		break;
	//}

	return;
}


