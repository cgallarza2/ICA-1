#include "fileManagementFunctions.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

bool attemptLogIn(string username, string password) {
	ifstream userList;
	string user;
	string pass;

	userList.open("userList.txt");
	if (userList.is_open()){

		while (!userList.eof()) {
			userList >> user;
			userList >> pass;

			if (user == username && pass == password) {
				cout << "Log-In Successful!" << endl;
				userList.close();
				return true;
			}
		}

		userList.close();
		cout << "Please try again!" << endl;
		return false;
	}
	
	return false;
}
