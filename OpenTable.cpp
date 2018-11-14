
#include "Customer.h"
#include "Table.h"
#include "Action.h"
#include "Restaurant.h"

OpenTable::OpenTable(int id, std::vector<Customer *> &customersList): tableId(id), customers(customersList) {}

void OpenTable::act(Restaurant &restaurant) {
    Table* t = restaurant.getTable(tableId);
    if(t == nullptr) {
        error("Error: Table does not exits or is already open");
        description = getErrorMsg();
    }
    else {
        description = "open " + std::to_string(tableId) + " ";
        for(auto i :customers )
        {
            description += i->toString();
        }
        t->setNumOfCustomers(customers.size());
        t->setCustomerList(customers);
        t->openTable();
        if(t->isOpen()) {
            error(description + "Error: Table does not exits or is already open\n");
            description = getErrorMsg();
        }
        else {
            description += "Completed\n";
            complete();
        }
    }
}

std::string OpenTable::toString() const {
    return description;
}

BaseAction* OpenTable::clone() const
{
    return new OpenTable(*this);
}

//Rule of 5

OpenTable::OpenTable(OpenTable &openTable): tableId(openTable.tableId) {
    for (auto customer: openTable.customers) {
        customers.push_back(customer->clone());
    }
}