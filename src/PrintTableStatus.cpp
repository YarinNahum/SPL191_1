//
// Created by ravidlevy99 on 11/12/18.
//

#include "../include/Action.h"
#include "../include/Restaurant.h"
#include "../include/Table.h"
#include "../include/Customer.h"

PrintTableStatus::PrintTableStatus(int id): tableId(id){}

void PrintTableStatus::act(Restaurant &restaurant)
{
    if(getStatus() == PENDING)
    {
        Table* t = restaurant.getTable(tableId);

        if(t == nullptr || !t->isOpen())
            std::cout<< "Table " + std::to_string(tableId) + " status: closed\n";

        else
        {
            std::cout<< "Table " + std::to_string(tableId) + " status: open\n";
            std::cout<< "Customers:\n";
            for(auto customer: t->getCustomers())
            {
                std::cout<< std::to_string(customer->getId()) + " " + customer->getName() + "\n";
            }

            std::cout<< "Orders:\n";
            for(auto order: t->getOrders())
            {
                std::cout<< order.second.getName() + " " + std::to_string(order.second.getPrice()) + "NIS " +  std::to_string(order.first) + "\n";
            }
            std::cout<< "Current Bill: " + std::to_string(t->getBill()) + "NIS\n";
        }
        complete();
    }
}

std::string PrintTableStatus::toString() const
{
    return "status " + std::to_string(tableId) + " Completed\n";
}

BaseAction* PrintTableStatus::clone() const
{
    return new PrintTableStatus(tableId);
}