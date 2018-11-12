//
// Created by yarin on 11/13/18.
//
#include "Action.h"
#include "Restaurant.h"

PrintActionsLog::PrintActionsLog() {}

void PrintActionsLog::act(Restaurant &restaurant) {
    description = "";
    for(auto i : restaurant.getActionsLog())
    {
        description += i->toString();
    }
    complete();
}

std::string PrintActionsLog::toString() const {
    return  description;
}