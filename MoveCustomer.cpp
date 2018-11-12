//
// Created by ravidlevy99 on 11/11/18.
//
#include "Action.h"
#include "Table.h"
#include "Restaurant.h"
#include "Customer.h"

MoveCustomer::MoveCustomer(int src, int dst, int customerId):srcTable(src), dstTable(dst), id(customerId) {}

void MoveCustomer::act(Restaurant &restaurant)
{
    if(getStatus() == PENDING) {
        Table* source = restaurant.getTable(srcTable);
        Table* destination = restaurant.getTable(dstTable);

        if(source == nullptr || destination == nullptr || !source->isOpen() || !destination->isOpen() || destination->getCustomers().size() < destination->getCapacity()) {
            error("Error: cannot move customer\n");
            description = getErrorMsg();
        }
        else {
            Customer *customer = source->getCustomer(id);
            if (customer == nullptr) {
                error("Error: cannot move customer\n");
                description = getErrorMsg();
            }
            else {
                for (int i = 0; i < source->getOrders().size(); i++)
                    if (source->getOrders()[i].first == customer->getId()) {
                        destination->getOrders().push_back(source->getOrders()[i]);
                        source->getOrders().erase(source->getOrders().begin() + i);
                    }

                source->removeCustomer(id);
                destination->addCustomer(customer);

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
