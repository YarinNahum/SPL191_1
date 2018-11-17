
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

    customers.clear();
}

//Rule of 5

OpenTable::~OpenTable()
{
    clear();
}

OpenTable::OpenTable(const OpenTable& openTable): tableId(openTable.tableId)
{
    copy(openTable);
}

OpenTable::OpenTable(OpenTable&& openTable): tableId(openTable.tableId)
{
    copy(openTable);
    for(int i = 0 ; i < openTable.customers.size() ; i++)
    {
        openTable.customers[i] = nullptr;
    }
    openTable.customers.clear();
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