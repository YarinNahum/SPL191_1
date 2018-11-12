
#include "Customer.h"
#include "Table.h"
#include "Action.h"
#include "Restaurant.h"


OpenTable::OpenTable(int id, std::vector<Customer *> &customersList): tableId(id) , customers(customersList) {}

void OpenTable::act(Restaurant &restaurant) {
    if(getStatus() == PENDING) {
        Table* t = restaurant.getTable(tableId);
        if (t == nullptr || t->isOpen()) {
            error("Table does not exits or is already open\n");
        } else {
            t->setNumOfCustomers(customers.size());
            t->setCustomerList(customers);
            t->openTable();
            std::cout << toString();
            complete();
        }
    }
}

std::string OpenTable::toString() const {
    std::string output = "open " + tableId;
    output += " ";
    for(auto i : customers)
    {
        output += i->toString();
        output += " ";
    }
    output += "\n";
    return output;
}

