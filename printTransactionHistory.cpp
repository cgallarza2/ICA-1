#include "userInterfaceFunctions.h"

void printTransactionHistory(){

	ifstream history;
	string event;

	clearScreen();

	history.open("completeTransactionHistory.txt");
	if (history.is_open()) {
		cout << endl << "Complete Transaction History: \n" << endl;
		cout << "\033[33m____________________________________________________________________________________________________" << reset << endl;
		cout << setw(21) << "\033[33m--" << reset << setw(78) << "" << "\t   \033[33m|" << reset << endl;
		while (!history.eof()) {
			getline(history, event);
			cout << setw(21) << "\033[33m--" << reset << setw(78) << event << "\t   \033[33m|" << reset << endl;
		}
		cout << "\033[33m___________________________________________________________________________________________________|" << reset << endl << endl;

		history.close();
	}
	return;

}
