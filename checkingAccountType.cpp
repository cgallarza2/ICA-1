
//Implementation file

#include <iostream>
#include <string>
#include "checkingAccountType.h"

using namespace std;

checkingAccountType::checkingAccountType(string n, int acctNumber, double bal)
						  : bankAccountType(n, acctNumber, bal)
{
}
