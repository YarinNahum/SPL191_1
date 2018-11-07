//
// Created by ravidlevy99 on 11/7/18.
#include <string>
//

#ifndef SPL191_1_DISH_H
#define SPL191_1_DISH_H

enum DishType{
    VEG, SPC, BVG, ALC
};

class Dish{
public:
    Dish(int d_id, std::string d_name, int d_price, DishType d_type): id(d_id), name(d_name), price(d_price), type(d_type){}
    int getId()
    {
            return id;
    }
    std::string getName()
    {
            return name;
    }
    int getPrice()
    {
            return price;
    }
    DishType getType()
    {
            return type;
    }
private:
    const int id;
    const std::string name;
    const int price;
    const DishType type;
};


#endif //SPL191_1_DISH_H