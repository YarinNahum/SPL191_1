# All Targets
all: rest

# Tool invocations
rest: bin/AlchoholicCustomer.o bin/BackupRestaurant.o bin/BaseAction.o bin/CheapCustomer.o bin/Close.o bin/CloseAll.o bin/Customer.o bin/Dish.o bin/Main.o bin/MoveCustomer.o bin/OpenTable.o bin/Order.o bin/PrintActionsLog.o bin/PrintMenu.o bin/PrintTableStatus.o bin/Restaurant.o bin/RestoreRestaurant.o bin/SpicyCustomer.o bin/Table.o bin/VegetarianCustomer.o
	g++ -o bin/rest bin/AlchoholicCustomer.o bin/BackupRestaurant.o bin/BaseAction.o bin/CheapCustomer.o bin/Close.o bin/CloseAll.o bin/Customer.o bin/Dish.o bin/Main.o bin/MoveCustomer.o bin/OpenTable.o bin/Order.o bin/PrintActionsLog.o bin/PrintMenu.o bin/PrintTableStatus.o bin/Restaurant.o bin/RestoreRestaurant.o bin/SpicyCustomer.o bin/Table.o bin/VegetarianCustomer.o
	
# Depends on the source and header files

bin/AlchoholicCustomer.o: src/AlchoholicCustomer.cpp include/Customer.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/AlchoholicCustomer.o src/AlchoholicCustomer.cpp

bin/BaseAction.o: src/BaseAction.cpp include/Action.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/BaseAction.o src/BaseAction.cpp

bin/BackupRestaurant.o: src/BackupRestaurant.cpp include/Action.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/BackupRestaurant.o src/BackupRestaurant.cpp

bin/CheapCustomer.o: src/CheapCustomer.cpp include/Customer.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/CheapCustomer.o src/CheapCustomer.cpp

bin/Close.o: src/Close.cpp include/Action.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Close.o src/Close.cpp

bin/CloseAll.o: src/CloseAll.cpp include/Action.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/CloseAll.o src/CloseAll.cpp

bin/Customer.o: src/Customer.cpp include/Customer.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Customer.o src/Customer.cpp

bin/Dish.o: src/Dish.cpp include/Dish.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Dish.o src/Dish.cpp

bin/Main.o: src/Main.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Main.o src/Main.cpp

bin/MoveCustomer.o: src/MoveCustomer.cpp include/Action.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/MoveCustomer.o src/MoveCustomer.cpp

bin/OpenTable.o: src/OpenTable.cpp include/Action.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/OpenTable.o src/OpenTable.cpp

bin/Order.o: src/Order.cpp include/Action.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Order.o src/Order.cpp

bin/PrintActionsLog.o: src/PrintActionsLog.cpp include/Action.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PrintActionsLog.o src/PrintActionsLog.cpp

bin/PrintMenu.o: src/PrintMenu.cpp include/Action.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PrintMenu.o src/PrintMenu.cpp

bin/PrintTableStatus.o: src/PrintTableStatus.cpp include/Action.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PrintTableStatus.o src/PrintTableStatus.cpp

bin/Restaurant.o: src/Restaurant.cpp include/Restaurant.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Restaurant.o src/Restaurant.cpp

bin/RestoreRestaurant.o: src/RestoreRestaurant.cpp include/Action.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/RestoreRestaurant.o src/RestoreRestaurant.cpp

bin/SpicyCustomer.o: src/SpicyCustomer.cpp include/Customer.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/SpicyCustomer.o src/SpicyCustomer.cpp

bin/Table.o: src/Table.cpp include/Table.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Table.o src/Table.cpp

bin/VegetarianCustomer.o: src/VegetarianCustomer.cpp include/Customer.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/VegetarianCustomer.o src/VegetarianCustomer.cpp

# Cleaning build directory
clean:
	rm -f bin/*
