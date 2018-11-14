//
// Created by ravidlevy99 on 11/14/18.
//

#include "Restaurant.h"

extern Restaurant* backup;

BackupRestaurant::BackupRestaurant() {}

void BackupRestaurant::act(Restaurant &restaurant)
{
    if(backup != nullptr)
        delete backup;

    backup = new Restaurant(restaurant);
    complete();
}

std::string BackupRestaurant::toString() const
{
    return "backup\n";
}

BaseAction* BackupRestaurant::clone() const
{
    return new BackupRestaurant();
}