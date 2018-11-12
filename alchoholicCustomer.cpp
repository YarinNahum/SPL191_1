#include "vector"
#include "Customer.h"
#include "Dish.h"
#include "algorithm"
#include <iostream>

AlchoholicCustomer::AlchoholicCustomer(std::string name, int id):Customer(name , id), rank(-1){}

std::string AlchoholicCustomer::toString() const {
    std::string ret = getName() + "," + "alc ";
    return ret;
}

void AlchoholicCustomer::setRank(int value)
{
    rank = value;
}

std::vector<int> AlchoholicCustomer::order(const std::vector<Dish> &menu)
{
    std::vector<int> output;

    if(rank != 0)
    {

        if (!hasOrdered())
        {
            alchocol = strategy(menu, ALC);
            std::sort(alchocol.begin(), alchocol.end(), std::greater<Dish>());
            setRank(alchocol.size());
            setOrdered(true);
        }
        else
            setRank(getRank() - 1);

        output.push_back(alchocol.at(rank-1).getId());
    }
    else
    {
        std::cout << "This Alchoholic Customer has already ordered the most expenensive alchoholic beverage in the menu \n";
    }

    return output;
}