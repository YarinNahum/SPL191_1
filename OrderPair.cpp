
#include "OrderPair.h"

OrderPair::OrderPair(int c_id, Dish dish):id(c_id), dish(dish) {}
int OrderPair::getC_ID() {return id;}
Dish OrderPair::getDish() {return dish;}
