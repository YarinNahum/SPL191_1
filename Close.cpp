//
// Created by yarin on 11/11/18.
//

#include "Restaurant.h"
#include "Action.h"
#include "Table.h"

Close::Close(int id): tableId(id), Bill(0) {}

void Close::act(Restaurant &restaurant) {
    Table *t = restaurant.getTable(tableId);
    if(t == nullptr || !t->isOpen())
        std::cout << "Table does not exits or is not open\n";
    else
    {
        Bill = t->getBill();
        t->closeThisTable();
        std::cout << toString();
    }
}

std::string Close::toString() const {
    std:: string output = "Table " + std::to_string(tableId) + " was closed. Bill " + std::to_string(Bill) +"NIS\n";
    return output;
}


