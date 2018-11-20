//
// Created by yarin on 11/12/18.
//

#include "../include/Action.h"
#include "../include/Table.h"
#include "../include/Restaurant.h"

CloseAll::CloseAll() {}

void CloseAll::act(Restaurant &restaurant) {
    if(getStatus() == PENDING)
    {
        for (int i = 0; i < restaurant.getTables().size(); i++) {
            if (restaurant.getTables()[i]->isOpen()) {
                BaseAction *c = new Close(i);
                c->act(restaurant);
                delete c;
            }
        }
        complete();
    }
    restaurant.CloseRestaurant();
}

std::string CloseAll::toString() const {
    return "closeall Completed\n";
}

BaseAction* CloseAll::clone() const {
    return new CloseAll();
}