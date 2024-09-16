#ifndef FILEMANAGEMENTFUNCTIONS_H
#define FILEMANAGEMENTFUNCTIONS_H

#include <string>
#include <iostream>
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
vector<bankAccountType*> populateAccounts(vector<bankAccountType*> accountVector, string txtFile);

#endif

