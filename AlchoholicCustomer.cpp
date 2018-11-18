#include "vector"
#include "Customer.h"
#include "Dish.h"
#include "string"
#include <iostream>

AlchoholicCustomer::AlchoholicCustomer(std::string name, int id):Customer(name , id), hasFinished(false) , maxIndex(-1), currIndex(-1){}

std::string AlchoholicCustomer::toString() const {
    std::string ret = getName() + "," + "alc ";
    return ret;
}

std::vector<int> AlchoholicCustomer::order(const std::vector<Dish> &menu)
{
    std::vector<int> output;
    std::vector<Dish> alchocol;
    for(auto dish :menu)
        if(dish.getType() == ALC)
            alchocol.push_back(dish);

    if(maxIndex == -1) {
        int tmp = 0;
        for (int i = 1; i < alchocol.size(); i++) { // Finding the most expensive ALC dish.
            if (alchocol[i].getPrice() > alchocol[tmp].getPrice())
                tmp = i;
            else if (alchocol[i].getPrice() == alchocol[tmp].getPrice())
                if (alchocol[i].getId() > alchocol[tmp].getId())
                    tmp = i;

        }
        maxIndex = tmp; // The index in the vector of the most expensive ALC dish in the menu.
    }
    if(currIndex == -1) {
        int tmp = 0;
        for (int i = 1; i < alchocol.size(); i++) {
            if (alchocol[i].getPrice() < alchocol[tmp].getPrice())
                tmp = i;
            else if (alchocol[i].getPrice() == alchocol[tmp].getPrice())
                if (alchocol[i].getId() < alchocol[tmp].getId())
                    tmp = i;

        }
        currIndex = tmp; // Finding the index of the cheapest ALC dish in the menu
    }
    if(!hasFinished)
    {
        for(int i = 0 ; i < alchocol.size() ; i++) // Finding the next index of the dish that the customer order.
        {
            if(alchocol[i].getPrice() > alchocol[currIndex].getPrice())
                currIndex = i;
            else if (alchocol[i].getPrice() == alchocol[currIndex].getPrice())
                if(alchocol[i].getId() > alchocol[currIndex].getId())
                    currIndex = i;
        }
        output.push_back(alchocol[currIndex].getId());
        if(currIndex == maxIndex) // If the dish is the most expensive one, than the customer will no longer be able to order.
            hasFinished = true;
    }
    else
        std::cout << "This Alchoholic Customer has already ordered the most expenensive alchoholic beverage in the menu \n";
    return output;

}

Customer* AlchoholicCustomer::clone() {
    return new AlchoholicCustomer(*this);
}