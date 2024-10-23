#ifndef USERINTERFACEFUNCTIONS_H
#define USERINTERFACEFUNCTIONS_H

#include <string>
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

//colors
const string green = "\033[32m";
const string yellow = "\033[33m";
const string reset = "\033[0m";
const string flashing = "\033[5m";
const string red = "\033[0;31m";

void clearScreen();

//login menu
void loginMenu(vector<bankAccountType *> &accountsVector, int sessionID, string &username);
vector<bankAccountType *> createNewUser(vector<bankAccountType *> accountVector, int sessionID, string &username);
//user menus
void printUserMenu();
vector<bankAccountType *> printUserOptions(vector<bankAccountType *> &accountVector, int sessionID, string username);
//employee menus
void printEmployeeMenu();
vector<bankAccountType *> printEmployeeOptions(vector<bankAccountType *> &accountVector, int sessionID, string username);
//account options
void printDeposit();
void printWithdraw();

#endif
