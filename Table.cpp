#include "Table.h"
#include <vector>
#include "Customer.h"
#include "Dish.h"
#include "iostream"


Table::Table(int t_capacity): capacity(t_capacity), numOfCustomers(0),open(false),
                              customersList(std::vector<Customer*>()) ,orderList(std::vector<OrderPair>()) {
}
int Table::getCapacity() const {
    return capacity;
}
Customer* Table::getCustomer(int id) {
    for(int i = 0 ; i < customersList.size() ; i++)
        if(customersList[i]->getId() == id)
            return customersList[i];
     std::cout << "Cannot get a customer that isnt at the table. \n";

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
    if(numOfCustomers == capacity)
        throw std::invalid_argument("Cannot add a customer to a full table");
    customersList.push_back(customer);
    numOfCustomers++;

}
int Table::getNumOfCustomers() {
    return numOfCustomers;
}
std::vector<Customer*>& Table::getCustomers() {
    return customersList;
}

std::vector<OrderPair>& Table::getOrders() {
    return orderList;
}
int Table::getBill() {
    int Bill = 0;
    for(int i = 0 ; i < orderList.size() ; i++)
        Bill+= orderList[i].second.getPrice();
    return Bill;
}
void Table::removeCustomer(int id) {
    for(int i = 0 ; i <customersList.size(); i++)
        if(customersList[i]->getId() == id)
            customersList.erase(customersList.begin()+i);
}
void Table::order(const std::vector<Dish> &menu) {
    for(int i = 0 ; i < customersList.size() ; i++)
    {

    }
}

