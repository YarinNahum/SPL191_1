#include "vector"
#include "../include/Customer.h"
#include "../include/Dish.h"

VegetarianCustomer::VegetarianCustomer(std::string name, int id):Customer(name , id) {}

std::string VegetarianCustomer::toString() const
{
    std::string ret = getName() + "," + "veg ";
    return ret;
}

std::vector<int> VegetarianCustomer::order(const std::vector<Dish> &menu)
{
    std::vector<Dish> vegetarian;
    std::vector<Dish> beverage;
    for(auto dish : menu)
    {
        if(dish.getType() == VEG)
            vegetarian.push_back(dish);
        if(dish.getType() == BVG)
            beverage.push_back(dish);
    }
    if(!hasOrdered())
    {
        setOrdered(true);
    }

    std::vector<int> output;

    int minId = vegetarian[0].getId();

    for(auto dish: vegetarian)
    {
        if (dish.getId() < minId)
        {
            minId = dish.getId();
        }
    }

    int max = beverage[0].getPrice();
    int maxId = beverage[0].getId();

    for(auto dish: beverage)
    {
        if (dish.getPrice() > max | (dish.getPrice() == max & dish.getId() < maxId))
        {
            max = dish.getPrice();
            maxId = dish.getId();
        }
    }

    output.push_back(minId);
    output.push_back(maxId);

    return output;
}

Customer* VegetarianCustomer::clone() {
    return new VegetarianCustomer(*this);
}