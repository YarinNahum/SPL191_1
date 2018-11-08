//
// Created by ravidlevy99 on 11/8/18.
//

#include <vector>
#include <string>
#include "Customer.h"
#include <iostream>


Customer::Customer(std::string c_name, int c_id): name(c_name), id(c_id), ordered(false){}

std::string Customer::getName() const
{
    return name;
}

int Customer::getId() const
{
    return id;
}

void Customer::setOrdered(bool value)
{
    ordered = value;
}

std::vector<Dish>& Customer::strategy(const std::vector<Dish> &menu, DishType dishType)
{
    std::vector<Dish> output;

    for(auto dish: menu)
    {
        if(dish.getType() == dishType)
            output.push_back(dish);
    }

    return output;
}
