CFLAGS = -Wall -Werror -Wpedantic -std=c++20 -O0 -g
CC = g++

OBJECTS = main.o bankAccountType.o savingsAccountType.o highInterestSavingsType.o certificateOfDepositType.o serviceChargeCheckingType.o checkingAccountType.o noServiceChargeCheckingType.o highInterestCheckingType.o clearScreen.o printMainMenu.o printCheckingAccount.o printSavingsAccount.o printCertificateOfDeposit.o

run-tests: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp bankAccountType.o savingsAccountType.o highInterestSavingsType.o certificateOfDepositType.o printMainMenu.o

highInterestSavingsType.o: highInterestSavingsType.cpp highInterestSavingsType.h bankAccountType.o  savingsAccountType.o

savingsAccountType.o: savingsAccountType.cpp savingsAccountType.h bankAccountType.o

certificateOfDepositType.o: certificateOfDepositType.cpp certificateOfDepositType.h bankAccountType.o

bankAccountType.o: bankAccountType.cpp bankAccountType.h

serviceChargeCheckingType.o: serviceChargeCheckingType.cpp serviceChargeCheckingType.h checkingAccountType.o

highInterestCheckingType.o: highInterestCheckingType.cpp highInterestCheckingType.h noServiceChargeCheckingType.o

noServiceChargeCheckingType.o: noServiceChargeCheckingType.cpp noServiceChargeCheckingType.h checkingAccountType.o

checkingAccountType.o: checkingAccountType.cpp checkingAccountType.h bankAccountType.o

clearScreen.o: clearScreen.cpp userInterfaceFunctions.h

printMainMenu.o: printMainMenu.cpp userInterfaceFunctions.h

printCheckingAccount.o: printCheckingAccount.cpp userInterfaceFunctions.h

printSavingsAccount.o: printSavingsAccount.cpp userInterfaceFunctions.h

printCertificateOfDeposit.o: printCertificateOfDeposit.cpp userInterfaceFunctions.h

clean:
	rm -f run-tests *.o *~
