
#ifndef SPL191_1_ORDERPAIR_H
#define SPL191_1_ORDERPAIR_H

#include "Dish.h"

class OrderPair {
public:
    OrderPair(int c_id , Dish dish);
    Dish getDish();
    int getC_ID();

private:
    int id;
    Dish dish;
};


#endif //SPL191_1_ORDERPAIR_H
