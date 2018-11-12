//
// Created by yarin on 11/11/18.
//

#include "Restaurant.h"
#include "Action.h"
#include "Table.h"

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
        description = "Table " + std::to_string(tableId) + " was closed. Bill " + std::to_string(Bill) +"NIS\n";
        complete();
    }
}

std::string Close::toString() const {
    return description;
}


