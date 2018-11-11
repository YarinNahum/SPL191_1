//
// Created by ravidlevy99 on 11/8/18.
//

#include <vector>
#include <string>
#include "Customer.h"
#include <iostream>


Customer::Customer(std::string c_name, int c_id): name(c_name), id(c_id){}
std::string Customer::getName() const
{
    return name;
}

int Customer::getId() const
{
    return id;
}