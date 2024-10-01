#ifndef FILEMANAGEMENTFUNCTIONS_H
#define FILEMANAGEMENTFUNCTIONS_H

#include <string>
#include <iostream>
#include <iomanip> // setprecision
#include <fstream>
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

bool attemptLogIn(string username, string password);
void addAccount(string username, string password);

//Account File IO
vector<bankAccountType*> populateAccounts(vector<bankAccountType*> accountVector, string txtFile);
vector<bankAccountType*> createAccount(vector<bankAccountType*> accountVector, string txtFile, int a_type, string a_name, int a_acctNumber, double a_balance, double a_intRate, int a_maturityMon, int sessionID);
void updateUserAccounts (vector<bankAccountType*> accountVector, string txtFile, int sessionID);

//account options functions
void printAccountInfo(vector<bankAccountType*> accountVector);
bool depositToAccount(vector<bankAccountType*> accountVector, int accountType, double amount);
bool withdrawToAccount(vector<bankAccountType*> accountVector, int accountType, double amount);

#endif
