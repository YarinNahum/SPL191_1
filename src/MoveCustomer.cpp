//
// Created by ravidlevy99 on 11/11/18.
//
#include "../include/Action.h"
#include "../include/Table.h"
#include "../include/Restaurant.h"
#include "../include/Customer.h"

MoveCustomer::MoveCustomer(int src, int dst, int customerId):srcTable(src), dstTable(dst), id(customerId) {}

void MoveCustomer::act(Restaurant &restaurant)
{
    if(getStatus() == PENDING) {
        Table* source = restaurant.getTable(srcTable);
        Table* destination = restaurant.getTable(dstTable);

        if(source == nullptr || destination == nullptr || !source->isOpen() || !destination->isOpen() || destination->getCustomers().size() < destination->getCapacity()) {
            error("Error: Cannot move customer\n");
            description = getErrorMsg();
        }
        else {
            Customer *customer = source->getCustomer(id);
            if (customer == nullptr) {
                error("Error: cannot move customer\n");
                description = getErrorMsg();
            }
            else {
                std::vector <OrderPair> newOrderList;
                for (int i = 0; i < source->getOrders().size(); i++) // Adding order from the customer to the new table.
                    if (source->getOrders()[i].first == customer->getId())
                        destination->getOrders().push_back(source->getOrders()[i]);
                    else
                        newOrderList.push_back(source->getOrders()[i]); // Setting up a new orderlist without the customers orders.
                source->removeCustomer(id);
                destination->addCustomer(customer);
                source->setOrderList(newOrderList);
                if (source->getCustomers().size() == 0) {
                    BaseAction *close = new Close(srcTable);
                    close->act(restaurant);
                    delete close;
                }

                complete();
            }
        }
    }
}

std::string MoveCustomer::toString() const
{
    return  "move" + std::to_string(srcTable) + " " + std::to_string(dstTable) + " " + std::to_string(id) + "\n";
}

BaseAction* MoveCustomer::clone() const
{
    return new MoveCustomer(srcTable, dstTable, id);
}