#include "../include/Table.h"
#include <vector>
#include "../include/Customer.h"
#include "../include/Dish.h"
#include "iostream"


Table::Table(int t_capacity) : capacity(t_capacity), open(false),
                               customersList(std::vector<Customer *>()), orderList(std::vector<OrderPair>()) {}

int Table::getCapacity() const {
    return capacity;
}

Customer *Table::getCustomer(int id) {
    for (int i = 0; i < customersList.size(); i++) {
        if (customersList[i]->getId() == id)
            return customersList[i];
    }
    std::cout << "Cannot get a customer that isn't at the table. \n";

}

bool Table::isOpen() {
    return open;
}

void Table::openTable() {
    open = true;
}

void Table::closeTable() {
    open = false;
}

void Table::addCustomer(Customer *customer) {
    if (customersList.size() == capacity)
        std::cout << "Cannot add a customer to a full table \n";
    else {
        customersList.push_back(customer);
    }
}

void Table::setOrderList(std::vector<OrderPair> newOrderList) {
    orderList.clear();
    for(auto OP : newOrderList)
        orderList.push_back(OP);
}

std::vector<Customer *> &Table::getCustomers() {
    return customersList;
}

std::vector<OrderPair> &Table::getOrders() {
    return orderList;
}

int Table::getBill() {
    int bill = 0;
    for(auto order: orderList)
        bill += order.second.getPrice();
    return bill;
}

void Table::removeCustomer(int id) {
    for (int i = 0; i < customersList.size(); i++)
        if (customersList[i]->getId() == id) {
            customersList[i] = nullptr;
            customersList.erase(customersList.begin() + i);
        }

}

void Table::closeThisTable() {
    closeTable();
    for (int i = 0; i < customersList.size(); i++) {
        delete (customersList[i]);
    }
    customersList.clear();
    orderList.clear();
}

void Table::order(const std::vector<Dish> &menu) {
    std::string description = "";
    for (int i = 0; i < customersList.size(); i++) {
        std::vector<int> customerOrder = customersList[i]->order(menu);
        for (auto ID: customerOrder)
            for (auto dish: menu)
                if (ID == dish.getId()) {
                    orderList.push_back(OrderPair(customersList[i]->getId(), dish));
                    std::string cName = customersList[i]->getName();
                    std::string dName = dish.getName();
                    description += cName + " ordered " + dName + "\n";
                }
    }
    std:: cout << description;
}

Table* Table::clone() {
    return new Table(*this);
}

//Rule of 5

Table::Table(const Table &other) {
    copy(other);
}
void Table::copy(const Table &other) {
    this->open = other.open;
    this->capacity = other.capacity;
    for(auto i : other.customersList)
        this->customersList.push_back((i->clone()));
    for(auto i : other.orderList)
        this->orderList.push_back(i);

}

void Table::clear() {
    for(auto i : customersList)
        delete (i);
    customersList.clear();
    orderList.clear();
    open = false;
}
Table:: ~Table()
{
    clear();
}

Table& Table::operator=(const Table &other) {
    if(this == &other)
        return *this;
    clear();
    copy(other);
}

Table& Table::operator=(Table &&other) {
    if(this == &other)
        return *this;
    clear();
    copy(other);
    for(int i =0 ; i< other.customersList.size() ; i++)
        other.customersList[i] =nullptr;
    return *this;
}

Table::Table(Table &&other) {
    copy(other);
    for(int i = 0 ; i < other.customersList.size() ; i++)
        other.customersList[i] = nullptr;
    other.customersList.clear();
}



