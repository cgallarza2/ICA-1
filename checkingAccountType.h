
#ifndef checkingAccountType_H
#define checkingAccountType_H

#include <string>

#include "bankAccountType.h"

using namespace std;

class checkingAccountType: public bankAccountType
{
	public:
		checkingAccountType(string n, int acctNumber, double bal, string pass, string user);

		virtual void writeCheck(double amount) = 0;
};

#endif
