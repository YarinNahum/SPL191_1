//
// Created by yarin on 11/11/18.
//
#include "../include/Action.h"
#include "../include/Restaurant.h"
#include "../include/Table.h"

Order::Order(int id): tableId(id) {}

void Order::act(Restaurant &restaurant) {
    if(getStatus() == PENDING) {
        description ="";
        Table* t = restaurant.getTable(tableId);
        if (t == nullptr || !t->isOpen()) {
            error("Error: table does not exits or is not open\n");
            description = getErrorMsg();
        }
        else {
            t->order(restaurant.getMenu());
            complete();
        }
    }
}

std::string Order::toString() const
{
    if(getStatus() == ERROR)
        return "order " + std::to_string(tableId) + " Error: table does not exits or is not open\n";
    return "order " + std::to_string(tableId) + " Completed\n";
}

BaseAction* Order::clone() const
{
    return new Order(tableId);
}