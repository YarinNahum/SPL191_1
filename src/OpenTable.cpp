
#include "../include/Customer.h"
#include "../include/Table.h"
#include "../include/Action.h"
#include "../include/Restaurant.h"

OpenTable::OpenTable(int id, std::vector<Customer *> &customersList): tableId(id){
    for(auto i : customersList) {
        customers.push_back(i->clone());
        delete i;
        i = nullptr;
    }
    customersList.clear();
}

void OpenTable::act(Restaurant &restaurant) {
    Table* t = restaurant.getTable(tableId);
    description = "open " + std::to_string(tableId) + " ";
    for(auto i : customers)
    {
        description += i->toString();
    }
    if(t == nullptr) {
        error(description + "Error: Table does not exist or is already open\n");
        description = getErrorMsg();
    }
    else {
        if(t->isOpen()) {
            error("Error: Table does not exist or is already open\n");
        }
        else {
            for(auto c : customers) {
                t->addCustomer(c);
            }
            t->openTable();
            complete();
        }
    }
}

std::string OpenTable::toString() const {
    if(getStatus() == COMPLETED)
        return description + "Completed\n";
    else
        return description + getErrorMsg();
}

BaseAction* OpenTable::clone() const
{
    return new OpenTable(*this);
}

void OpenTable::copy(const OpenTable &openTable)
{
    for(auto customer: openTable.customers)
    {
        customers.push_back(customer);
    }
    if (openTable.getStatus() == COMPLETED)
        complete();
    else if(openTable.getStatus() == ERROR)
        error(openTable.getErrorMsg());
}

void OpenTable::clear()
{
    for(auto customer: customers)
    {
        if(customer != nullptr) {
            delete customer;
            customer = nullptr;
        }
    }
    description = nullptr;
    customers.clear();
}

//Rule of 5

OpenTable::~OpenTable()
{
    clear();
}

OpenTable::OpenTable(const OpenTable& openTable): tableId(openTable.tableId)
{
    description = openTable.description;
    copy(openTable);
}

OpenTable::OpenTable(OpenTable&& openTable): tableId(openTable.tableId), description(openTable.description)
{
    copy(openTable);
    for(int i = 0 ; i < openTable.customers.size() ; i++) {
        openTable.customers[i] = nullptr;
    }
    openTable.description.clear();
}

OpenTable& OpenTable::operator=(const OpenTable &other) {
    if(this == &other)
        return *this;
    clear();
    copy(other);
}

OpenTable& OpenTable::operator=(OpenTable &&other) {
    if(this == &other)
        return *this;
    clear();
    copy(other);
    for(int i = 0; i < other.customers.size() ; i++)
        other.customers[i] = nullptr;
    return *this;
}