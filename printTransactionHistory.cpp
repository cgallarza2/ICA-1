#include "userInterfaceFunctions.h"
#include <iostream>

void printTransactionHistory(){

	ifstream history;
	string event;

	clearScreen();

	cin.ignore();

	history.open("completeTransactionHistory.txt");
	if (history.is_open()) {
		cout << endl << "Complete Transaction History: \n" << endl;
		cout << "\033[33m____________________________________________________________________________________________________" << reset << endl;
		cout << setw(21) << "\033[33m--" << reset << setw(78) << "" << "\t   \033[33m|" << reset << endl;
		while (!history.eof()) {
			for (int i = 0; i < 30; i++) {
				if (!history.eof()) {
					getline(history, event);
					cout << setw(21) << "\033[33m--" << reset << setw(78) << event << "\t   \033[33m|" << reset << endl;
				}
			}
			if (!history.eof()) {
				cout << "\033[33m___________________________________________________________________________________________________|" << reset << endl << endl;
				cout << "Please press \"Enter\" to proceed..." << endl;
				cin.ignore();
				cout << "\033[33m____________________________________________________________________________________________________" << reset << endl;
			}
		}
		cout << "\033[33m___________________________________________________________________________________________________|" << reset << endl << endl;

		history.close();
	}
	return;

}
