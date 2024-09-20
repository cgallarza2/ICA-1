#include <fstream> //file
#include <sstream> //file

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
 
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
	 //string username;
	 //string password;

	 char mainChoice;

	 vector<bankAccountType *> accountsList;
	 string userr = "Tipi";

	 accountsList = createAccount(accountsList, userr + ".txt", 1, "test1", 12392, 100.00, 0, 0);
	 accountsList = createAccount(accountsList, userr + ".txt", 3, "test2", 12423, 200.00, 0, 0);
	 accountsList = createAccount(accountsList, userr + ".txt", 4, "test4", 12567, 500.00, 0, 0);
	 accountsList = createAccount(accountsList, userr + ".txt", 6, "test3", 62433, 300.00, .12, 2);
	 accountsList = createAccount(accountsList, userr + ".txt", 5, "test5", 98058, 1000.00, 0, 0);

	 do {
		 printWelcomeMenu();
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
				 printAccountFunctions();
				 break;
			 case '4':
				 cout << "Exiting... " << endl;
				 break;
			 default:
				 clearScreen();
				 cout << "*** " << mainChoice << " *** is Invalid" << endl;
				 cout << "Please enter a valid choice (1-4)." << endl;
				 break;
		 }
	 } while (mainChoice != '4');


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


	

    //cout << "January:\n-------------" << endl;
    //for (int i = 0; i < accountsList.size(); i++)
    //{
    //    accountsList[i]->createMonthlyStatement();
   //     accountsList[i]->print();
    //    cout << endl;
    //}

    //cout << "\nFebruary:\n-------------" << endl;
    //for (int i = 0; i < accountsList.size(); i++)
    //{
    //    accountsList[i]->createMonthlyStatement();
    //    accountsList[i]->print();
    //    cout << endl;
    //}
//
    //for (int i = 0; i < accountsList.size(); i++)
    ////{
    //     accountsList[i]->withdraw(500);
    //}
//
    //cout << "\nMarch:\n-------------" << endl;
    //for (int i = 0; i < accountsList.size(); i++)
    //{
    //    accountsList[i]->createMonthlyStatement();
    //    accountsList[i]->print();
   //     cout << endl;
   // }

    return 0;
}
