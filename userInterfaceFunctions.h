#ifndef USERINTERFACEFUNCTIONS_H
#define USERINTERFACEFUNCTIONS_H

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "bankAccountType.h" // vector
#include "savingsAccountType.h"
#include "highInterestSavingsType.h"
#include "noServiceChargeCheckingType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "certificateOfDepositType.h"
#include "checkingAccountType.h"

using namespace std;

extern const int SCREEN_WIDTH; // = 100;
extern const double SAVINGS_INT_RATE; // = 0.03;
extern const double HIGHINTSAVE_MIN_BAL; // = 2500.00;
extern const double HIGHINTSAVE_INT_RATE; // = 0.05;
extern const double COD_INT_RATE; // = 0.05;
extern const int NUM_MATURITY_MON; // = 6;
extern const double ACCT_SERV_CHARGE; // = 10.00;
extern const int MAX_NUM_CHECKS; // = 5;
extern const double SERV_CHARGE_EXCESS_NUM_CHECKS; // = 5;
extern const double NOSERV_CHRG_CHK_MIN_BAL; // 1000.00;
extern const double NOSERV_CHRG_CHK_INT_RATE; // = 0.02;
extern const double HIGHINTCHK_RATE; // = 0.05;
extern const double HIGHINTCHK_MIN_BAL; // = 5000.00

// vector<bankAccountType *> accountsList;

void printWelcomeMenu();
void printMainMenu();
void printCheckingAccount();
void printSavingsAccount();
void printAccountFunctions();
void printCreateNewUser();
void clearScreen();

#endif
