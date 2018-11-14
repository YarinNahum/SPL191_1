cmake_minimum_required(VERSION 3.12)
project(SPL191_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(SPL191_1 alchoholicCustomer.cpp BaseAction.cpp BackupRestaurant.cpp
        CheapCustomer.cpp Close.cpp CloseAll.cpp Customer.cpp Dish.cpp Main.cpp MoveCustomer.cpp
        OpenTable.cpp Order.cpp PrintActionsLog.cpp PrintMenu.cpp PrintTableStatus.cpp
        Restaurant.cpp RestoreRestaurant.cpp SpicyCustomer.cpp Table.cpp VegetarianCustomer.cpp)