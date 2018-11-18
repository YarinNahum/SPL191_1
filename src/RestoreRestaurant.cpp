//
// Created by ravidlevy99 on 11/14/18.
//

#include "../include/Restaurant.h"

extern Restaurant* backup;

RestoreResturant::RestoreResturant() {}

void RestoreResturant::act(Restaurant &restaurant)
{
    if(backup == nullptr)
        error("No backup available");

    else
    {
        restaurant = *backup;
        complete();
    }
}

std::string RestoreResturant::toString() const
{
    return "restore\n";
}

BaseAction* RestoreResturant::clone() const
{
    return new RestoreResturant();
}