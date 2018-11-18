cmake_minimum_required(VERSION 3.12)
project(SPL191_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(SPL191_1 src/AlchoholicCustomer.cpp src/BaseAction.cpp src/BackupRestaurant.cpp
        src/CheapCustomer.cpp src/Close.cpp src/CloseAll.cpp src/Customer.cpp src/Dish.cpp src/Main.cpp src/MoveCustomer.cpp
        src/OpenTable.cpp src/Order.cpp src/PrintActionsLog.cpp src/PrintMenu.cpp src/PrintTableStatus.cpp
        src/Restaurant.cpp src/RestoreRestaurant.cpp src/SpicyCustomer.cpp src/Table.cpp src/VegetarianCustomer.cpp)