CFLAGS = -Wall -Werror -Wpedantic -std=c++20 -O0 -g
CC = g++

OBJECTS = main.o bankAccountType.o savingsAccountType.o highInterestSavingsType.o certificateOfDepositType.o serviceChargeCheckingType.o checkingAccountType.o noServiceChargeCheckingType.o highInterestCheckingType.o

run-tests: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp bankAccountType.o savingsAccountType.o highInterestSavingsType.o certificateOfDepositType.o

highInterestSavingsType.o: highInterestSavingsType.cpp highInterestSavingsType.h bankAccountType.o  savingsAccountType.o

savingsAccountType.o: savingsAccountType.cpp savingsAccountType.h bankAccountType.o

certificateOfDepositType.o: certificateOfDepositType.cpp certificateOfDepositType.h bankAccountType.o

bankAccountType.o: bankAccountType.cpp bankAccountType.h

serviceChargeCheckingType.o: serviceChargeCheckingType.cpp serviceChargeCheckingType.h checkingAccountType.o

highInterestCheckingType.o: highInterestCheckingType.cpp highInterestCheckingType.h noServiceChargeCheckingType.o

noServiceChargeCheckingType.o: noServiceChargeCheckingType.cpp noServiceChargeCheckingType.h checkingAccountType.o

checkingAccountType.o: checkingAccountType.cpp checkingAccountType.h bankAccountType.o

clean:
	rm -f run-tests *.o *~
