//
// Created by ravidlevy99 on 11/7/18.

//
#include <string>
#include "../include/Dish.h"

Dish::Dish(int d_id, std::string d_name, int d_price, DishType d_type): id(d_id), name(d_name), price(d_price), type(d_type){}

Dish::Dish(const Dish &other): id(other.id), name(other.name), price(other.price), type(other.type){}

int Dish::getId() const
{
    return id;
}

std::string Dish::getName() const
{
    return name;
}

int Dish::getPrice() const
{
    return price;
}

DishType Dish::getType() const
{
    return type;
}

bool Dish::operator>(Dish &other)
{
    //Do your own calculations here
    if (other.getPrice() < getPrice())
        return true;
    if(other.getPrice() == getPrice())
        return other.getId() < getId();
    return false;
}
//SPL191_1_DISH_H