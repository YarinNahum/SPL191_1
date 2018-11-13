//
// Created by ravidlevy99 on 11/12/18.
//

#include "Action.h"
#include "Restaurant.h"

void PrintMenu::act(Restaurant &restaurant)
{
    if(getStatus() == PENDING)
    {
        for (auto dish: restaurant.getMenu()) {
            std::cout << dish.getName() + " " + std::to_string(dish.getType()) + " " + std::to_string(dish.getPrice()) + "NIS\n";
        }
        complete();
    }
}

std::string PrintMenu::toString() const
{
    return "menu\n";
}