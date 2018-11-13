//
// Created by yarin on 11/13/18.
//
#include "Action.h"
#include "Restaurant.h"

PrintActionsLog::PrintActionsLog() {}

void PrintActionsLog::act(Restaurant &restaurant) {
    for(auto i : restaurant.getActionsLog())
    {
        std::cout << i->toString();
    }
    complete();
}

std::string PrintActionsLog::toString() const {
    return  "log";
}