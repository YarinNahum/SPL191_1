#include "vector"
#include "Customer.h"
#include "Dish.h"


VegetarianCustomer::VegetarianCustomer(std::string name, int id): Customer(name , id){
}
std::string VegetarianCustomer::toString() const {

    std::string ret = "Name:" + getName() + ". " + "Customer Type: Vegetarian.";
    return ret;
}
