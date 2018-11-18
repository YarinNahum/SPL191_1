//
// Created by yarin on 11/11/18.
//

#include "../include/Restaurant.h"
#include "../include/Action.h"
#include "../include/Table.h"

Close::Close(int id): tableId(id), Bill(0) {}

void Close::act(Restaurant &restaurant) {
    Table *t = restaurant.getTable(tableId);
    if(t == nullptr || !t->isOpen()) {
        error("Error: table does not exits or is not open\n");
        description = getErrorMsg();
    }
    else
    {
        Bill = t->getBill();
        t->closeThisTable();
        std::cout << "Table " + std::to_string(tableId) + " was closed. Bill " + std::to_string(Bill) +"NIS\n";
        complete();
    }
}

std::string Close::toString() const {
    if(getStatus() == ERROR)
         return "close " + std::to_string(tableId) + " Error: table does not exits or is not open\n";
    return "close " + std::to_string(tableId) + " Completed\n";
}

BaseAction* Close::clone() const
{
    return new Close(tableId);
}