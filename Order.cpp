//
// Created by yarin on 11/11/18.
//
#include "Action.h"
#include "Restaurant.h"
#include "Table.h"

Order::Order(int id): tableId(id) {}

void Order::act(Restaurant &restaurant) {
    if(getStatus() == PENDING) {
        Table* t = restaurant.getTable(tableId);
        if (t == nullptr || !t->isOpen()) {
            error("Error: table does not exits or is not open\n");
            description = getErrorMsg();
        }
        else {
            t->order(restaurant.getMenu());
            for (auto i : t->getOrders()) {
                std::string cName = t->getCustomer(i.first)->getName();
                std::string dName = i.second.getName();
                description += cName + " ordered " + dName + "\n";

            }
            complete();
        }
    }
}

std::string Order::toString() const
{
    return description;
}
