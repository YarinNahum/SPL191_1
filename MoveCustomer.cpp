//
// Created by ravidlevy99 on 11/11/18.
//
#include "Action.h"
#include "Table.h"
#include "Restaurant.h"
#include "Customer.h"
#include <iostream>

MoveCustomer::MoveCustomer(int src, int dst, int customerId):srcTable(src), dstTable(dst), id(customerId) {}

void MoveCustomer::act(Restaurant &restaurant)
{
    Table* source = restaurant.getTable(srcTable);
    Table* destination = restaurant.getTable(dstTable);
    Customer* customer = source->getCustomer(id);

    for (int i = 0; i < source->getOrders().size(); i++)
        if(source->getOrders()[i].first == customer->getId())
        {
            destination->getOrders().push_back(source->getOrders()[i]);
            source->getOrders().erase(source->getOrders().begin()+i);
        }

    source->removeCustomer(id);
    destination->addCustomer(customer);

    std::cout << toString();
}

std::string MoveCustomer::toString() const
{
    return  "move" + std::to_string(srcTable) + " " + std::to_string(dstTable) + " " + std::to_string(id) + "\n";
}
