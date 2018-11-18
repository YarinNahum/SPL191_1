#ifndef TABLE_H_
#define TABLE_H_

#include <vector>
#include "Customer.h"
#include "Dish.h"

typedef std::pair<int, Dish> OrderPair;

class Table{
public:
    Table(int t_capacity);
    int getCapacity() const;
    void addCustomer(Customer* customer);
    void removeCustomer(int id);
    Customer* getCustomer(int id);
    std::vector<Customer*>& getCustomers();
    std::vector<OrderPair>& getOrders();
    void order(const std::vector<Dish> &menu);
    void openTable();
    void closeTable();
    int getBill();
    int getNumOfCustomers() const;
    bool isOpen();
    void setNumOfCustomers(int num);
    void closeThisTable();
    void setCustomerList(const std::vector<Customer *> vector);
    Table(const Table& other); // Copy constructor
    Table* clone();
    ~Table();
    Table &operator=(const Table &other);
    void clear();
    void copy(const Table &other);
    Table &operator= (Table&& other);
    Table(Table&& other);
    void setOrderList(std::vector<OrderPair> newOrderList);

private:
    int capacity;
    int numOfCustomers;
    int bill;
    bool open;
    std::vector<Customer*> customersList;
    std::vector<OrderPair> orderList; //A list of pairs for each order in a table - (customer_id, Dish)
};


#endif