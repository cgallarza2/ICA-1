#ifndef USERINTERFACEFUNCTIONS_H
#define USERINTERFACEFUNCTIONS_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

extern const int SCREEN_WIDTH; // = 100;

void printWelcomeMenu();
void printMainMenu();
void printCheckingAccount();
void printSavingsAccount();
void printCertificateOfDeposit();
void clearScreen();

#endif
