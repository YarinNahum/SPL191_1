//
// Created by yarin on 11/12/18.
//

#include "Action.h"
#include "Table.h"
#include "Restaurant.h"

CloseAll::CloseAll():output("") {}

void CloseAll::act(Restaurant &restaurant) {
    if(getStatus() == COMPLETED)
    for(int i = 0 ; i < restaurant.getTables().size() ; i ++)
    {
        if(restaurant.getTables()[i]->isOpen())
        {
            Close *c = new Close(i);
            c->act(restaurant);
            output += c->toString();
            delete(c);
        }
    }
    restaurant.CloseRestaurant();

}

std::string CloseAll::toString() const {
    return output;
}