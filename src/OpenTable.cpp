
#include "../include/Customer.h"
#include "../include/Table.h"
#include "../include/Action.h"
#include "../include/Restaurant.h"

OpenTable::OpenTable(int id, std::vector<Customer *> &customersList):description(""), tableId(id),customers(std::vector<Customer*>()) {
    for(auto c : customersList)
        customers.push_back(c);
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
        for(auto c : customers) {
            if(c != nullptr)
                delete c;
            c = nullptr;
        }
    }
    else {
        if(t->isOpen()) {
            error("Error: Table does not exist or is already open\n");
            for(auto c : customers) {
                if(c != nullptr)
                    delete c;
                c = nullptr;
            }
        }
        else {
            t->openTable();
            for(auto c : customers) {
                t->addCustomer(c);
            }
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
    for(auto customer: customers) {
        if (customer != nullptr) {
            customer = nullptr;
        }
    }
    customers.clear();
}

//Rule of 3

OpenTable::~OpenTable()
{
    clear();
}

OpenTable::OpenTable(const OpenTable& openTable):description(openTable.description), tableId(openTable.tableId), customers(std::vector<Customer*>())
{
    if (openTable.getStatus() == COMPLETED)
        complete();
    else if(openTable.getStatus() == ERROR)
        error(openTable.getErrorMsg());
    copy(openTable);
}

OpenTable::OpenTable(OpenTable&& openTable):description(openTable.description), tableId(openTable.tableId), customers(std::vector<Customer*>())
{
    copy(openTable);
    for(int i = 0 ; i < (int)(openTable.customers.size()) ; i++) {
        openTable.customers[i] = nullptr;
    }
    openTable.description.clear();
}

