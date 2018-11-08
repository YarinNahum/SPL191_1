#include "vector"
#include "Customer.h"
#include "Dish.h"


VegetarianCustomer::VegetarianCustomer(std::string name, int id): Customer(name , id) {}
std::string VegetarianCustomer::toString() const
{

    std::string ret = "Name:" + getName() + ". " + "Customer Type: Vegetarian.";
    return ret;
}

std::vector<Dish>& VegetarianCustomer::strategie(const std::vector<Dish> &menu)
{
    std::vector<Dish*> list;
    for(auto i: menu)
    {
        if(menu.at(i).

    }
}