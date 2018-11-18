//
// Created by ravidlevy99 on 11/14/18.
//

#include "../include/Restaurant.h"

extern Restaurant* backup;

RestoreResturant::RestoreResturant() {}

void RestoreResturant::act(Restaurant &restaurant)
{
    if(backup == nullptr)
        error("No backup available\n");

    else
    {
        restaurant = *backup;
        complete();
    }
}

std::string RestoreResturant::toString() const
{
    if(getStatus() == ERROR)
        return "restore Error: No backup available\n";
    return "restore Completed \n";
}

BaseAction* RestoreResturant::clone() const
{
    return new RestoreResturant();
}