//
// Created by yarin on 11/13/18.
//
#include "../include/Action.h"
#include "../include/Restaurant.h"

PrintActionsLog::PrintActionsLog() {}

void PrintActionsLog::act(Restaurant &restaurant) {
    for(auto i : restaurant.getActionsLog())
    {
        std::cout << i->toString();
    }
    complete();
}

std::string PrintActionsLog::toString() const {
    return  "log Completed\n";
}

BaseAction* PrintActionsLog::clone() const
{
    return new PrintActionsLog();
}