
#include "Customer.h"
#include "Table.h"
#include "Action.h"
#include "Restaurant.h"


OpenTable::OpenTable(int id, std::vector<Customer *> &customersList): tableId(id) , customers(customersList), {}

void OpenTable::act(Restaurant &restaurant) {
    if(getStatus() == PENDING) {
        Table* t = restaurant.getTable(tableId);
        if (t == nullptr || t->isOpen()) {
            error("Table does not exits or is already open\n");
        } else {
            t->setNumOfCustomers(customers.size());
            t->setCustomerList(customers);
            t->openTable();
            description = "";
            complete();
        }
    }
}

std::string OpenTable::toString() const {
    return description;
}
