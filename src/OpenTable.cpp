
#include "../include/Customer.h"
#include "../include/Table.h"
#include "../include/Action.h"
#include "../include/Restaurant.h"

OpenTable::OpenTable(int id, std::vector<Customer *> &customersList): tableId(id), customers(customersList), description("") {}

void OpenTable::act(Restaurant &restaurant) {
    Table* t = restaurant.getTable(tableId);
    description = "open " + std::to_string(tableId) + " ";
    for(auto i : customers)
    {
        description += i->toString();
    }
    if(t == nullptr) {
        error(description + "Error: Table does not exist or is already open");
        description = getErrorMsg();
    }
    else {
        if(t->isOpen()) {
            error("Error: Table does not exist or is already open\n");
        }
        else {
            for(auto C : customers)
                t->addCustomer(C);
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
}

void OpenTable::clear()
{
    for(auto customer: customers)
    {
        delete customer;
    }
    description= nullptr;
    customers.clear();
}

//Rule of 5

OpenTable::~OpenTable()
{
    clear();
}

OpenTable::OpenTable(const OpenTable& openTable): tableId(openTable.tableId), description(openTable.description)
{
    copy(openTable);
}

OpenTable::OpenTable(OpenTable&& openTable): tableId(openTable.tableId), description(openTable.description)
{
    copy(openTable);
    for(int i = 0 ; i < openTable.customers.size() ; i++)
    {
        openTable.customers[i] = nullptr;
    }
    openTable.customers.clear();
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
    other.clear();
    for(int i = 0; i < other.customers.size() ; i++)
        other.customers[i] = nullptr;
    return *this;

}