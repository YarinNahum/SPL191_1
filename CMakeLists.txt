cmake_minimum_required(VERSION 3.12)
project(SPL191_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(SPL191_1 Main.cpp Dish.cpp Restaurant.cpp Customer.cpp VegetarianCustomer.cpp CheapCustomer.cpp SpicyCustomer.cpp alchoholicCustomer.cpp PriceComperator.cpp PriceComperator.h)