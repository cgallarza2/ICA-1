#include <fstream> //file
#include <sstream> //file

#include <iostream>
#include <iomanip>
#include <vector>
 
#include "bankAccountType.h"
#include "savingsAccountType.h"
#include "highInterestSavingsType.h"
#include "noServiceChargeCheckingType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "certificateOfDepositType.h"
#include "checkingAccountType.h"
#include "userInterfaceFunctions.h"

using namespace std;
  
extern const int SCREEN_WIDTH = 100;

int main()
{
	 char mainChoice;
	 clearScreen();

	 do {
		 printMainMenu();

		 cin >> mainChoice;
		 cin.ignore(10000, '\n');

		 switch (mainChoice) {
			 case '1':
				 printCheckingAccount();
				 break;
			 case '2':
				 printSavingsAccount();
				 break;
			 case '3':
				 printCertificateOfDeposit();
				 break;
			 case '4':
				 cout << "Exiting..." << endl;
				 break;
			 default:
				 clearScreen();
				 cout << "*** " << mainChoice << " *** is Invalid" << endl;
				 cout << "Please enter a valid choice (1-4)." << endl;
				 break;
		 }
	 } while (mainChoice != '4');

    vector<bankAccountType *> accountsList;

    accountsList.push_back(new savingsAccountType("Bill", 10200, 2500, "password", "username"));
    accountsList.push_back(new highInterestSavingsType("Susan", 10210, 2000, "password", "username"));
    accountsList.push_back(new noServiceChargeCheckingType("John", 20100, 
                                                    3500, "password", "username"));
    accountsList.push_back(new serviceChargeCheckingType("Ravi", 30100, 1800, "password", "username"));
    accountsList.push_back(new highInterestCheckingType("Sheila", 20200, 
                                                 6000, "password", "username"));
    accountsList.push_back(new certificateOfDepositType("Hamid", 51001, 18000, "password", "username",
                                                0.075, 18));

	int accountType;
	cout << "Enter the corrosponding number to the type of account you wish to add:" << endl;
	cout << "1. Savings Account" << endl;
	cout << "2. High Interest Savings Account" << endl;
	cout << "3. No Service Charge Checking Account" << endl;
	cout << "4. Service Charge Checking Account" << endl;
	cout << "5. High Interest Checking Account" << endl;
	cout << "6. Certificate of Deposit" << endl;
	cin >> accountType;
	cin.ignore (999, '\n');

	string name, username, password;
	int acctNumber;
	double balance;

	cout << "Enter the name of the account owner:";
	getline (cin, name);
	cout << "Enter the account number:";
	cin >> acctNumber;
	cout << "Enter the account balance:";
	cin >> balance;
	cin.ignore();
	cout << "Enter the account username:";
	getline(cin, username);
	cout << "Enter the account password:";
	getline(cin, password);

	switch (accountType) {
		case 1: {
			accountsList.push_back(new savingsAccountType(name, acctNumber, balance, password, username));
			break;
		}
		case 2: {
			double interestRate;
			cout << "Enter the interest rate:";
			cin >> interestRate;
			accountsList.push_back(new highInterestSavingsType(name, acctNumber, balance, password,
			username, interestRate, 2500));
			break;
		}
		case 3: {
			double minBalance, intRate;
			cout << "Enter the minimum balance:";
			cin >> minBalance;
			cout << "Enter the interest rate:";
			cin >> intRate;
			accountsList.push_back(new noServiceChargeCheckingType(name, acctNumber, balance, password,
			username, minBalance, intRate));
			break;
		}
		case 4: {
			double serviceChargeAccount, serviceChargeCheck;
			cout << "Enter the service charge for the account:";
			cin >> serviceChargeAccount;
			cout << "Enter the service charge per check:";
			cin >> serviceChargeCheck;
			accountsList.push_back(new serviceChargeCheckingType(name, acctNumber, balance, password, username,
			serviceChargeAccount, serviceChargeCheck));
			break;
		}
		case 5: {
			double minBalance, intRate;
			cout << "Enter the mininum balance:";
			cin >> minBalance;
			cout << "Enter the interest rate:";
			cin >> intRate;
			accountsList.push_back(new highInterestCheckingType(name, acctNumber, balance, password,
			username, minBalance, intRate));
			break;
		}
		case 6: {
			double interestRate;
			int maturityMonths;
			cout << "Enter the interest rate:";
			cin >> interestRate;
			cout << "Enter the maturity months:";
			cin >> maturityMonths;
			accountsList.push_back(new certificateOfDepositType(name, acctNumber, balance, password, username,
			interestRate, maturityMonths));
			break;
		}
		default:
			cout << "Invalid selection. Please try again." << endl;
			break;
}

    cout << "January:\n-------------" << endl;
    for (int i = 0; i < accountsList.size(); i++)
    {
        accountsList[i]->createMonthlyStatement();
        accountsList[i]->print();
        cout << endl;
    }

    cout << "\nFebruary:\n-------------" << endl;
    for (int i = 0; i < accountsList.size(); i++)
    {
        accountsList[i]->createMonthlyStatement();
        accountsList[i]->print();
        cout << endl;
    }

    for (int i = 0; i < accountsList.size(); i++)
    {
         accountsList[i]->withdraw(500);
    }

    cout << "\nMarch:\n-------------" << endl;
    for (int i = 0; i < accountsList.size(); i++)
    {
        accountsList[i]->createMonthlyStatement();
        accountsList[i]->print();
        cout << endl;
    }

    return 0;
}
