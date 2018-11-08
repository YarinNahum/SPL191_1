#include "vector"
#include "Customer.h"
#include "Dish.h"


VegetarianCustomer::VegetarianCustomer(std::string name, int id): Customer(name , id) {}
std::string VegetarianCustomer::toString() const
{

    std::string ret = "Name:" + getName() + ". " + "Customer Type: Vegetarian.";
    return ret;
}

std::vector<int> VegetarianCustomer::order(const std::vector<Dish> &menu)
{
    if(!hasOrdered())
    {
        vegetarian = strategy(menu, VEG);
        beverage = strategy(menu, BVG);
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
        if (dish.getPrice() > max)
        {
            max = dish.getPrice();
            maxId = dish.getId();
        }
    }

    output.push_back(minId);
    output.push_back(maxId);

    return output;
}