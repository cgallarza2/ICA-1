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

using namespace std;
  
int main()
{
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
