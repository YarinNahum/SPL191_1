//
// Created by ravidlevy99 on 11/12/18.
//

#include "../include/Action.h"
#include "../include/Restaurant.h"

PrintMenu::PrintMenu() {}

void PrintMenu::act(Restaurant &restaurant)
{
    if(getStatus() == PENDING)
    {
        for (auto dish: restaurant.getMenu()) {
            std::string type;
            if(dish.getType() == ALC)
                type = "ALC";
            else if(dish.getType() == VEG)
                type = "VEG";
            else if(dish.getType() == SPC)
                type = "SPC";
            else
                type = "BVG";
            std::cout << dish.getName() + " " + type + " " + std::to_string(dish.getPrice()) + "NIS\n";
        }
        complete();
    }
}

std::string PrintMenu::toString() const
{
    return "menu Completed\n";
}

BaseAction* PrintMenu::clone() const
{
    return new PrintMenu();
}