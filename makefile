# All Targets
all: rest

# Tool invocations
rest: bin/AlchoholicCustomer.o bin/BackupRestaurant.o bin/BaseAction.o bin/CheapCustomer.o bin/Close.o bin/CloseAll.o bin/Customer.o bin/Dish.o bin/Main.o bin/MoveCustomer.o bin/OpenTable.o bin/Order.o bin/PrintActionsLog.o bin/PrintMenu.o bin/PrintTableStatus.o bin/Restaurant.o bin/RestoreRestaurant.o bin/SpicyCustomer.o bin/Table.o bin/VegetarianCustomer
	g++ -o bin/rest bin/AlchoholicCustomer.o bin/BackupRestaurant.o bin/BaseAction.o bin/CheapCustomer.o bin/Close.o bin/CloseAll.o bin/Customer.o bin/Dish.o bin/Main.o bin/MoveCustomer.o bin/OpenTable.o bin/Order.o bin/PrintActionsLog.o bin/PrintMenu.o bin/PrintTableStatus.o bin/Restaurant.o bin/RestoreRestaurant.o bin/SpicyCustomer.o bin/Table.o bin/VegetarianCustomer
	
# Depends on the source and header files

bin/AlchoholicCustomer.o: src/AlchoholicCustomer.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/AlchoholicCustomer.o src/AlchoholicCustomer.cpp

bin/BaseAction.o: src/BaseAction.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/BaseAction.o src/BaseAction.cpp

bin/BackupRestaurant.o: src/BackupRestaurant.cpp
   	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/BackupRestaurant.o src/BackupRestaurant.cpp

bin/CheapCustomer.o: src/CheapCustomer.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/CheapCustomer.o src/CheapCustomer.cpp

bin/Close.o: src/Close.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Close.o src/Close.cpp

bin/CloseAll.o: src/CloseAll.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/CloseAll.o src/CloseAll.cpp

bin/Customer.o: src/Customer.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Customer.o src/Customer.cpp

bin/Dish.o: src/Dish.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Dish.o src/Dish.cpp

bin/Main.o: src/Main.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Main.o src/Main.cpp

bin/MoveCustomer.o: src/MoveCustomer.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/MoveCustomer.o src/MoveCustomer.cpp

bin/OpenTable.o: src/OpenTable.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/OpenTable.o src/OpenTable.cpp

bin/Order.o: src/Order.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Order.o src/Order.cpp

bin/PrintActionsLog.o: src/PrintActionsLog.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PrintActionsLog.o src/PrintActionsLog.cpp

bin/PrintMenu.o: src/PrintMenu.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PrintMenu.o src/PrintMenu.cpp

bin/PrintTableStatus.o: src/PrintTableStatus.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PrintTableStatus.o src/PrintTableStatus.cpp

bin/Restaurant.o: src/Restaurant.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Restaurant.o src/Restaurant.cpp

bin/RestoreRestaurant.o: src/RestoreRestaurant.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/RestoreRestaurant.o src/RestoreRestaurant.cpp

bin/SpicyCustomer.o: src/SpicyCustomer.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/SpicyCustomer.o src/SpicyCustomer.cpp

bin/Table.o: src/Table.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Table.o src/Table.cpp

bin/VegetarianCustomer.o: src/VegetarianCustomer.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/VegetarianCustomer.o src/VegetarianCustomer.cpp

# Cleaning build directory
clean: 
	rm -f bin/*
