
#include "Customer.h"
#include "Table.h"
#include "Action.h"


OpenTable::OpenTable(int id, std::vector<Customer *> &customersList): tableId(id) , customers(customersList) {}
void OpenTable::act(Restaurant &restaurant) {
    Table* t = restaurant.getTable();
    if(t == nullptr || t->isOpen())
        std::cout << "Table does not exits or is already open";
    else {
        t->setNumOfCustomers(customers.size());
        t->setCustomerList(customers);
        t->openTable();
        std::cout << toString();
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

