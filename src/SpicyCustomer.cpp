#include "vector"
#include "../include/Customer.h"
#include "../include/Dish.h"

SpicyCustomer::SpicyCustomer(std::string name, int id):Customer(name , id) {}

std::string SpicyCustomer::toString() const {
    return getName() + ",spc ";
}

std::vector<int> SpicyCustomer::order(const std::vector<Dish> &menu)
{
    std::vector<int> output;
    std::vector<Dish> spicy;
    std::vector<Dish> beverage;
    for(auto dish : menu)
    {
        if(dish.getType() == SPC)
            spicy.push_back(dish);
        if(dish.getType() == BVG)
            beverage.push_back(dish);
    }

    if(!hasOrdered())
    {
        int max = spicy[0].getPrice();
        int maxId = spicy[0].getId();

        for (auto dish: spicy)
        {
            if (dish.getPrice() > max | (dish.getPrice() == max & dish.getId() < maxId))
            {
                max = dish.getPrice();
                maxId = dish.getId();
            }
        }

        setOrdered(true);
        output.push_back(maxId);
    }

    else
    {
        int min = beverage[0].getPrice();
        int minId = beverage[0].getId();

        for (auto dish: beverage)
        {
            if (dish.getPrice() < min | (dish.getPrice() == min & dish.getId() < minId))
            {
                min = dish.getPrice();
                minId = dish.getId();
            }
        }

        output.push_back(minId);
    }

    return output;
}

Customer* SpicyCustomer::clone() {
    return new SpicyCustomer(*this);
}
