#include "userInterfaceFunctions.h"

using namespace std;

void clearScreen()
{
	cout << "\033[2J\033[H";

	return;
}
