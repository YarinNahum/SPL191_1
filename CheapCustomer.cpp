#include "vector"
#include "Customer.h"
#include "Dish.h"
#include "iostream"

CheapCustomer::CheapCustomer(std::string name, int id):Customer(name , id){}

std::string CheapCustomer::toString() const {
    std::string ret = "Name:" + getName() + ". " + "Customer Type: Cheap.";
    return ret;
}

std::vector<int> CheapCustomer::order(const std::vector<Dish> &menu)
{
    std::vector<int> output;

    if(!hasOrdered())
    {
        int min = menu[0].getPrice();
        int minId = menu[0].getId();

        for (auto dish: menu)
        {
            if (dish.getPrice() < min)
            {
                min = dish.getPrice();
                minId = dish.getId();
            }
        }

        setOrdered(true);
        output.push_back(minId);
    }
    else
    {
        std::cout << "This Cheap Customer has already ordered";
    }

    return output;
}

