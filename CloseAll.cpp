//
// Created by yarin on 11/12/18.
//

#include "Action.h"
#include "Table.h"
#include "Restaurant.h"

CloseAll::CloseAll() {}

void CloseAll::act(Restaurant &restaurant) {
    if(getStatus() == PENDING)
    {
        for (int i = 0; i < restaurant.getTables().size(); i++) {
            if (restaurant.getTables()[i]->isOpen()) {
                Close *c = new Close(i);
                c->act(restaurant);
                description += c->toString();
                delete c;
            }
        }
        complete();
    }
    restaurant.CloseRestaurant();
}

std::string CloseAll::toString() const {
    return description;
}