#include "Table.h"
#include <vector>
#include "Customer.h"
#include "Dish.h"
#include "iostream"


Table::Table(int t_capacity): capacity(t_capacity), numOfCustomers(0), open(false), bill(0),
                              customersList(std::vector<Customer*>()), orderList(std::vector<OrderPair>()) {}
int Table::getCapacity() const
{
    return capacity;
}

Customer* Table::getCustomer(int id)
{
    for(int i = 0 ; i < customersList.size() ; i++)
    {
        if (customersList[i]->getId() == id)
            return customersList[i];
    }
    std::cout << "Cannot get a customer that isn't at the table. \n";

}

bool Table::isOpen()
{
    return open;
}

void Table::openTable()
{
    open = true;
}

void Table::closeTable()
{
    open = false;
}

void Table::addCustomer(Customer *customer)
{
    if(numOfCustomers == capacity)
        std::cout << "Cannot add a customer to a full table \n";
    else {
        customersList.push_back(customer);
        numOfCustomers++;
    }
}

int Table::getNumOfCustomers()
{
    return numOfCustomers;
}

std::vector<Customer*>& Table::getCustomers()
{
    return customersList;
}

std::vector<OrderPair>& Table::getOrders()
{
    return orderList;
}

int Table::getBill()
{
    int bill = 0;
    for(auto order: orderList)
    {
        bill += order.second.getPrice();
    }
    return bill;
}

void Table::setNumOfCustomers(int num) {
    if(num > capacity)
        std::cout << "Table capacity is lower than the number of customers\n ";
    else
        numOfCustomers = num;
}

void Table::removeCustomer(int id)
{
    for(int i = 0 ; i <customersList.size(); i++)
        if(customersList[i]->getId() == id)
            customersList.erase(customersList.begin()+i);
}
void Table::closeThisTable() {
    setNumOfCustomers(0);
    closeTable();
    for(int i = 0 ; i <orderList.size() ; i++)
    {
        orderList.erase(orderList.begin() +i);
    }
    for(int i = 0 ; i < customersList.size() ; i++)
    {
        delete(customersList[i]);
        customersList.erase(customersList.begin()+i);
    }
}

void Table::order(const std::vector<Dish> &menu)
{

    for(int i = 0 ; i < customersList.size() ; i++)
    {
        std::vector<int> customerOrder = customersList[i]->order(menu);
        for(auto i: customerOrder)
        {
            for(auto dish: menu)
            {
                if(i == dish.getId()) {
                    orderList.push_back(OrderPair(customersList[i]->getId(), dish));
                }
            }
        }
    }
}

void Table::setCustomerList(const std::vector<Customer *> customerList)
{
    customersList = customerList;
}
